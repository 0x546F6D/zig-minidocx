const Cell = @This();

cell_c: CCell,

// pub extern fn cell_destroy(self: CCell) void;
pub inline fn deinit(self: Cell) void {
    c.cell_destroy(self.cell_c);
}

// pub extern fn cell_add_paragraph(self: CCell) CParagraph;
pub inline fn addParagraph(self: Cell) !Paragraph {
    const paragraph_c: c.CParagraph = c.cell_add_paragraph(self.cell_c);
    try check(c.paragraph_has_error(paragraph_c));
    return Paragraph{
        .paragraph_c = paragraph_c,
    };
}

// pub extern fn cell_has_error(self: CCell) c_int;
// pub extern fn cell_get_error(self: CCell) [*c]const u8;
pub inline fn getStrError(self: Cell) ?[*:0]const u8 {
    return c.cell_get_error(self.cell_c);
}

// pub extern fn cell_clear_error(self: CCell) void;
pub inline fn clearError(self: Cell) void {
    return c.cell_clear_error(self.cell_c);
}

const std = @import("std");
const c = @import("minidocx_c");
pub const CCell = c.CCell;
const Paragraph = @import("Paragraph.zig");
const check = @import("errors.zig").checkResult;
