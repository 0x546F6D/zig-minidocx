const Table = @This();

table_c: CTable,

pub const WidthType = enum(c_int) {
    auto = c.TableWidthAuto,
    percent = c.TableWidthPercent,
    absolute = c.TableWidthAbsolute,
};

pub const Layout = enum(c_int) {
    auto = c.TableLayoutAuto,
    fixed = c.TableLayoutFixed,
};

pub const Alignment = enum(c_int) {
    left = c.TableAlignLeft,
    right = c.TableAlignRight,
    center = c.TableAlignCenter,
};

pub const Border = enum(c_int) {
    top = c.TableBorderTop,
    bottom = c.TableBorderBottom,
    left = c.TableBorderLeft,
    right = c.TableBorderRight,
    inside_horizontal = c.TableBorderInsideHorizontal,
    inside_vertical = c.TableBorderInsideVertical,
};

pub const BorderProperties = struct {
    style: BorderStyle = .single,
    width: usize = 4,
    color: ?[*:0]const u8 = null,

    pub inline fn toC(self: BorderProperties) c.CBorderProperties {
        return c.CBorderProperties{
            .style_ = @intFromEnum(self.style),
            .width_ = self.size,
            .color_ = self.color,
        };
    }
};

// pub extern fn table_destroy(self: CTable) void;
pub inline fn deinit(self: Table) void {
    c.table_destroy(self.table_c);
}

// pub extern fn table_set_layout(self: CTable, layout: TableLayout) void;
pub inline fn setLayout(self: Table, layout: Layout) void {
    c.table_set_layout(self.table_c, @intFromEnum(layout));
}
// pub extern fn table_set_widthtype(self: CTable, @"type": TableWidthType) void;
pub inline fn setWidthType(self: Table, width_type: WidthType) void {
    c.table_set_widthtype(self.table_c, @intFromEnum(width_type));
}

// pub extern fn table_set_widthsize(self: CTable, size: usize) void;
pub inline fn setWidthSize(self: Table, size: usize) void {
    c.table_set_widthsize(self.table_c, size);
}

// pub extern fn table_set_align(self: CTable, @"align": TableAlignment) void;
pub inline fn setAlign(self: Table, alignment: Alignment) void {
    c.table_set_align(self.table_c, @intFromEnum(alignment));
}

// pub extern fn table_set_border(self: CTable, border: TableBorder, prop: CBorderProperties) void;
pub inline fn setBorder(self: Table, border: Border, prop: BorderProperties) void {
    c.table_set_border(
        self.table_c,
        @intFromEnum(border),
        &prop.toC(),
    );
}

// pub extern fn table_cellat(self: CTable, row: usize, col: usize) CCell;
pub inline fn cellAt(self: Table, row: usize, col: usize) !Cell {
    const cell_c: CCell = c.table_cellat(self.table_c, row, col);
    try check(c.cell_has_error(cell_c));
    return Cell{
        .cell_c = cell_c,
    };
}

// pub extern fn table_merge(self: CTable, row: usize, col: usize, rows: usize, cols: usize) CCell;
pub inline fn merge(self: Table, row: usize, col: usize, rows: usize, cols: usize) !Cell {
    const cell_c: CCell = c.table_merge(self.table_c, row, col, rows, cols);
    try check(c.cell_has_error(cell_c));
    return Cell{
        .cell_c = cell_c,
    };
}

// pub extern fn table_has_error(self: CTable) c_int;
// pub extern fn table_get_error(self: CTable) [*c]const u8;
pub inline fn getStrError(self: Table) ?[*:0]const u8 {
    return c.table_get_error(self.table_c);
}

// pub extern fn table_clear_error(self: CTable) void;
pub inline fn clearError(self: Table) void {
    return c.table_clear_error(self.table_c);
}

const std = @import("std");
const c = @import("minidocx_c");
pub const CTable = c.CTable;
const Cell = @import("Cell.zig");
const CCell = Cell.CCell;
const common = @import("common.zig");
const BorderStyle = common.BorderStyle;
const check = @import("errors.zig").checkResult;
