const Section = @This();

section_c: c.CSection,

// pub extern fn section_destroy(self: CSection) void;
pub inline fn deinit(self: Section) void {
    c.section_destroy(self.section_c);
}

// pub extern fn section_set_landscape(self: CSection, landscape: c_int) void;
pub inline fn setLandscape(self: Section, landscape: bool) void {
    c.section_set_landscape(self.section_c, @intFromBool(landscape));
}

// pub extern fn section_add_paragraph(self: CSection) CParagraph;
pub inline fn addParagraph(self: Section) !Paragraph {
    const paragraph_c: c.CParagraph = c.section_add_paragraph(self.section_c);
    try check(c.paragraph_has_error(paragraph_c));
    return Paragraph{
        .paragraph_c = paragraph_c,
    };
}

// pub extern fn section_get_error(self: CSection) [*c]const u8;
pub inline fn getStrError(self: Section) ?[*:0]const u8 {
    return c.section_get_error(self.section_c);
}

const std = @import("std");
const c = @import("minidocx_c");
const Paragraph = @import("Paragraph.zig");
const check = @import("errors.zig").checkResult;
