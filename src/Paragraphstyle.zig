const ParagraphStyle = @This();

style_c: CParaStyle,

// pub extern fn parastyle_create(...) CParaStyle;
pub inline fn init() ParagraphStyle {
    return ParagraphStyle{
        .style_c = c.parastyle_create(),
    };
}

// pub extern fn parastyle_destroy(self: CParaStyle) void;
pub inline fn deinit(self: ParagraphStyle) void {
    c.parastyle_destroy(self.style_c);
}

// pub extern fn parastyle_set_name(self: CParaStyle, name: [*c]const u8) void;
pub inline fn setName(self: ParagraphStyle, name: ?[*:0]const u8) void {
    c.parastyle_set_name(self.style_c, name);
}

// pub extern fn parastyle_set_align(self: CParaStyle, @"align": CAlignment) void;
pub inline fn setAlign(self: ParagraphStyle, alignment: Alignment) void {
    c.parastyle_set_align(self.style_c, @intFromEnum(alignment));
}

// pub extern fn parastyle_set_outlinelevel(self: CParaStyle, level: COutlineLevel) void;
pub inline fn setOutlineLevel(self: ParagraphStyle, level: OutlineLevel) void {
    c.parastyle_set_outlinelevel(self.style_c, @intFromEnum(level));
}

// pub extern fn parastyle_set_fontsize(self: CParaStyle, size: c_int) void;
pub inline fn setFontSize(self: ParagraphStyle, size: usize) void {
    c.parastyle_set_fontsize(self.style_c, size);
}

// pub extern fn parastyle_set_color(self: CParaStyle, color: [*c]const u8) void;
pub inline fn setColor(self: ParagraphStyle, color: ?[*:0]const u8) void {
    c.parastyle_set_color(self.style_c, color);
}

const std = @import("std");
const c = @import("minidocx_c");
pub const CParaStyle = c.CParaStyle;
const common = @import("common.zig");
const Alignment = common.Alignment;
const Paragraph = @import("Paragraph.zig");
const OutlineLevel = Paragraph.OutlineLevel;
