const Picture = @This();

picture_c: c.CPicture,

// pub extern fn picture_destroy(self: CPicture) void;
pub inline fn deinit(self: Picture) void {
    c.picture_destroy(self.picture_c);
}

// pub extern fn picture_set_size(self: CPicture, cols: usize, rows: usize, dpi: usize, scale: usize) void;
pub inline fn setSize(self: Picture, cols: usize, rows: usize, dpi: usize, scale: usize) void {
    c.picture_set_size(self.picture_c, cols, rows, dpi, scale);
}

// pub extern fn picture_get_error(self: CPicture) [*c]const u8;
pub inline fn getStrError(self: Picture) ?[*:0]const u8 {
    return c.picture_get_error(self.picture_c);
}

const std = @import("std");
const c = @import("minidocx_c");
const check = @import("errors.zig").checkResult;
