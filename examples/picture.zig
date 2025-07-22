pub fn main() !void {
    defer _ = dbga.deinit();
    // defer alloc.free(xlsx_path);

    const doc = try docz.initDocument();
    defer doc.deinit();

    try doc.saveAs("out/zig_picture.docx");
}

const std = @import("std");
var dbga: @import("std").heap.DebugAllocator(.{}) = .init;
const alloc = dbga.allocator();
const docz = @import("minidocx");
