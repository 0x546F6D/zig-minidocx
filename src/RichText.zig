const RichText = @This();

text_c: c.CRichText,

// pub extern fn richtext_destroy(self: CRichText) void;
pub inline fn deinit(self: RichText) void {
    c.richtext_destroy(self.text_c);
}

// pub extern fn richtext_set_font_size(self: CRichText, size: c_int) void;
pub inline fn setFontSize(self: RichText, size: c_uint) void {
    c.richtext_set_fontsize(self.text_c, size);
}

// pub extern fn richtext_set_color(self: CRichText, color: [*c]const u8) void;
pub inline fn setColor(self: RichText, color: [*:0]const u8) void {
    c.richtext_set_color(self.text_c, color);
}

// pub extern fn richtext_get_error(self: CRichText) [*c]const u8;
pub inline fn getStrError(self: RichText) ?[*:0]const u8 {
    return c.richtext_get_error(self.text_c);
}

const std = @import("std");
const c = @import("minidocx_c");
const check = @import("errors.zig").checkResult;
