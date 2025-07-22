const Document = @This();

doc_c: c.CDocument,

// pub extern fn document_Create(...) CDoc;
pub inline fn init() !Document {
    const doc_c: c.CDocument = c.document_create();
    try check(c.document_has_error(doc_c));
    // if(c.document_has_error(doc_c)) {
    // }
    return Document{
        .doc_c = doc_c,
        // .doc_c = c.document_create(),
    };
}

// pub extern fn document_Destroy(d: CDoc) void;
pub inline fn deinit(self: Document) void {
    c.document_destroy(self.doc_c);
}

// pub extern fn document_SaveAs(d: CDoc, filename: [*c]const u8) void;
pub inline fn saveAs(self: Document, filename: ?[*:0]const u8) !void {
    c.document_saveas(self.doc_c, filename);
    try check(c.document_has_error(self.doc_c));
}

// pub extern fn document_SaveAs(d: CDoc, filename: [*c]const u8) void;
pub inline fn getStrError(self: Document) ?[*:0]const u8 {
    return c.document_get_error(self.doc_c);
}

const std = @import("std");
const c = @import("minidocx_c");
const check = @import("errors.zig").checkResult;
