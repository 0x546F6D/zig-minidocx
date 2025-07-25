const std = @import("std"); // import the dependency
const zcc = @import("compile_commands");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const linkage = b.option(std.builtin.LinkMode, "linkage", "Link mode") orelse .static;
    const strip = b.option(bool, "strip", "Omit debug information");
    const pie = b.option(bool, "pie", "Produce a Position Independent Executable");

    var build_cpp_ex = b.option(bool, "buildCppEx", "Build minidocx Cpp samples") orelse false;
    var build_c_ex = b.option(bool, "buildCEx", "Build minidocx C samples") orelse false;
    var build_zig_ex = b.option(bool, "buildZigEx", "Build minidocx Zig samples") orelse false;
    const build_ex = b.option(bool, "buildEx", "Build minidocx Cpp/C/Zig samples") orelse false;
    if (build_ex) {
        build_cpp_ex = true;
        build_c_ex = true;
        build_zig_ex = true;
    }

    // available examples
    const example_names: []const []const u8 = &.{
        "general",
        "list",
        "picture",
        "style",
        "table",
    };

    const run_step = b.step("run", "run the build examples, should be used with -DbuildCppEx, -DbuildCEx, and/or -DbuildZigEx");

    const use_minidocx_dep = b.option(bool, "useMDDep", "Use Minidocx original repo") orelse false;
    const minidocx_dep = if (use_minidocx_dep) b.lazyDependency("minidocx", .{}) else undefined;

    const miniz_dep = b.dependency("miniz", .{ .BUILD_HEADER_ONLY = true });
    const pugixml_dep = b.dependency("pugixml", .{ .target = target, .optimize = optimize });

    // make a list of targets that have include files and c source files
    var targets = std.ArrayList(*std.Build.Step.Compile).init(b.allocator);

    // C++ Section
    // Package C++ library
    const cpp_minidocx_mod = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .pic = pie,
        .strip = strip,
        .link_libc = true,
        .link_libcpp = true,
    });

    const cpp_src: []const []const u8 = if (use_minidocx_dep) &.{
        "src/packaging/package.cpp",
        "src/packaging/part.cpp",
        "src/utils/exceptions.cpp",
        "src/utils/file.cpp",
        "src/utils/string.cpp",
        "src/utils/zip.cpp",
        "src/word/main/container.cpp",
        "src/word/main/document.cpp",
        "src/word/main/paragraph.cpp",
        "src/word/main/table.cpp",
    } else &.{
        "cpp/src/packaging/package.cpp",
        "cpp/src/packaging/part.cpp",
        "cpp/src/utils/exceptions.cpp",
        "cpp/src/utils/file.cpp",
        "cpp/src/utils/string.cpp",
        "cpp/src/utils/zip.cpp",
        "cpp/src/word/main/container.cpp",
        "cpp/src/word/main/document.cpp",
        "cpp/src/word/main/paragraph.cpp",
        "cpp/src/word/main/table.cpp",
    };

    cpp_minidocx_mod.addCSourceFiles(.{
        .root = if (use_minidocx_dep) minidocx_dep.?.path("") else b.path(""),
        .files = cpp_src,
        .flags = &.{ "-std=c++20", "-DMINIDOCX_NAMESPACE=md", "-DCLANG", "-Werror" },
    });
    const minidocx_include = if (use_minidocx_dep) minidocx_dep.?.path("include/minidocx") else b.path("cpp/include/minidocx");
    cpp_minidocx_mod.addIncludePath(minidocx_include);
    // cpp_minidocx_mod.addIncludePath(b.path("cpp/include/minidocx"));

    // setup miniz
    cpp_minidocx_mod.addIncludePath(miniz_dep.path(".zig-cache/generated/miniz"));
    // setup pugixml
    cpp_minidocx_mod.linkLibrary(pugixml_dep.artifact("pugixml"));
    // include pugixml.h path for clang compile_command.json
    const pugixml_src = pugixml_dep.builder.dependency(
        "pugixml",
        .{},
    ).builder.path("src");
    cpp_minidocx_mod.addIncludePath(pugixml_src);

    const minidocx_lib = b.addLibrary(.{
        .name = "minidocx",
        .linkage = linkage,
        .root_module = cpp_minidocx_mod,
    });

    b.installArtifact(minidocx_lib);

    targets.append(minidocx_lib) catch @panic("OOM");

    // C Section
    // Build minidocx C wrapper
    const cw_minidocx_mod = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .pic = pie,
        .strip = strip,
        .link_libc = true,
        .link_libcpp = true,
    });

    const c_src: []const []const u8 = &.{
        "c/src/c_wrap_error.cpp",
        "c/src/c_wrap_picture.cpp",
        "c/src/c_wrap_richtext.cpp",
        "c/src/c_wrap_paragraph.cpp",
        "c/src/c_wrap_cell.cpp",
        "c/src/c_wrap_table.cpp",
        "c/src/c_wrap_section.cpp",
        "c/src/c_wrap_parastyle.cpp",
        "c/src/c_wrap_document.cpp",
    };

    cw_minidocx_mod.addCSourceFiles(.{
        .root = b.path(""),
        .files = c_src,
        .flags = &.{ "-std=c++20", "-Werror" },
    });
    cw_minidocx_mod.addIncludePath(b.path("c/include"));
    cw_minidocx_mod.addIncludePath(b.path("cpp/include/minidocx"));
    cw_minidocx_mod.linkLibrary(minidocx_lib);

    const cw_minidocx_lib = b.addLibrary(.{
        .name = "cw_minidocx",
        .linkage = linkage,
        .root_module = cw_minidocx_mod,
    });

    b.installArtifact(cw_minidocx_lib);
    targets.append(cw_minidocx_lib) catch @panic("OOM");

    // Zig Section
    const minidocx_h = b.addTranslateC(.{
        .root_source_file = b.path("c/include/c_wrap_minidocx.h"),
        .target = target,
        .optimize = optimize,
    });

    const minidocx_h_mod = minidocx_h.createModule();
    minidocx_h_mod.linkLibrary(cw_minidocx_lib);
    minidocx_h_mod.link_libc = true;

    const minidocx_mod = b.addModule("minidocx", .{
        .root_source_file = b.path("src/minidocx.zig"),
        .target = target,
        .optimize = optimize,
    });
    minidocx_mod.addImport("minidocx_c", minidocx_h_mod);

    // build and run C++ examples
    if (build_cpp_ex) {
        inline for (0..example_names.len) |i| {
            const exe = b.addExecutable(.{
                .name = "cpp_" ++ example_names[i],
                .target = target,
                .optimize = optimize,
            });
            exe.addCSourceFile(.{
                .file = b.path("cpp/examples/" ++ example_names[i] ++ ".cpp"),
                .flags = &.{"-std=c++20"},
            });
            exe.linkLibrary(minidocx_lib);
            exe.addIncludePath(b.path("cpp/include"));
            exe.addIncludePath(b.path("cpp/include/minidocx"));
            exe.addIncludePath(miniz_dep.path(".zig-cache/generated/miniz"));
            exe.addIncludePath(pugixml_dep.path("src"));
            b.installArtifact(exe);
            targets.append(exe) catch @panic("OOM");

            const run_cmd = b.addRunArtifact(exe);
            run_cmd.step.dependOn(b.getInstallStep());
            run_step.dependOn(&run_cmd.step);
        }
    }

    // build and run C examples
    if (build_c_ex) {
        inline for (0..example_names.len) |i| {
            const exe = b.addExecutable(.{
                .name = "c_" ++ example_names[i],
                .target = target,
                .optimize = optimize,
            });

            exe.addCSourceFile(.{
                .file = b.path("c/examples/" ++ example_names[i] ++ ".c"),
                // .file = b.path("c/examples/general.c"),
            });

            exe.linkLibrary(cw_minidocx_lib);
            exe.addIncludePath(b.path("c/include"));

            b.installArtifact(exe);
            targets.append(exe) catch @panic("OOM");

            const run_cmd = b.addRunArtifact(exe);
            run_cmd.step.dependOn(b.getInstallStep());
            run_step.dependOn(&run_cmd.step);
        }
    }

    // build and run Zig examples
    if (build_zig_ex) {
        inline for (0..example_names.len) |i| {
            const exe = b.addExecutable(.{
                .name = "zig_" ++ example_names[i],
                .root_source_file = b.path("examples/" ++ example_names[i] ++ ".zig"),
                .target = target,
                .optimize = optimize,
            });

            exe.root_module.addImport("minidocx", minidocx_mod);

            b.installArtifact(exe);

            const run_cmd = b.addRunArtifact(exe);
            run_cmd.step.dependOn(b.getInstallStep());
            run_step.dependOn(&run_cmd.step);
        }
    }

    const zcc_step = zcc.createStep(b, "cdb", targets.toOwnedSlice() catch @panic("OOM"));
    zcc_step.dependOn(&pugixml_dep.artifact("pugixml").step);
}
