const Document = @This();

doc_c: c.CDocument,

// pub extern fn document_create(...) CDocument;
pub inline fn init() !Document {
    const doc_c: c.CDocument = c.document_create();
    try check(c.document_has_error(doc_c));
    return Document{
        .doc_c = doc_c,
    };
}

// pub extern fn document_destroy(self: CDocument) void;
pub inline fn deinit(self: Document) void {
    c.document_destroy(self.doc_c);
}

// pub extern fn document_set_properties(self: CDocument, prop: [*c]const CPackageProperties) void;
pub inline fn setProperties(self: Document, properties: Properties) void {
    return c.document_set_properties(self.doc_c, &properties.toC());
}

// pub extern fn document_saveas(self: CDocument, filename: [*c]const u8) void;
pub inline fn saveAs(self: Document, filename: ?[*:0]const u8) !void {
    c.document_saveas(self.doc_c, filename);
    try check(c.document_has_error(self.doc_c));
}

// pub extern fn document_get_error(self: CDocument) [*c]const u8;
pub inline fn getStrError(self: Document) ?[*:0]const u8 {
    return c.document_get_error(self.doc_c);
}

// pub extern fn document_add_section(self: CDocument) CSection;
pub inline fn addSection(self: Document) !Section {
    const section_c: c.CSection = c.document_add_section(self.doc_c);
    try check(c.section_has_error(section_c));
    return Section{
        .section_c = section_c,
    };
}

// pub extern fn document_add_image_path(d: CDocument, filename: [*c]const u8) CRelationshipId;
pub inline fn addImagePath(self: Document, filename: ?[*:0]const u8) !RelationshipId {
    const id_c: c.CRelationshipId = c.document_add_image_path(self.doc_c, filename);
    try check(c.relationshipid_has_error(id_c));
    return RelationshipId{
        .id_c = id_c,
    };
}

const std = @import("std");
const c = @import("minidocx_c");
const Properties = @import("common.zig").PackageProperties;
const Section = @import("Section.zig");
const RelationshipId = @import("RelationshipId.zig");
const check = @import("errors.zig").checkResult;
