const Paragraph = @This();

paragraph_c: c.CParagraph,

// pub extern fn paragraph_destroy(self: CParagraph) void;
pub inline fn deinit(self: Paragraph) void {
    c.paragraph_destroy(self.paragraph_c);
}

// pub extern fn paragraph_set_align(self: CParagraph, @"align": CAlignment) void;
pub inline fn setAlign(self: Paragraph, alignment: Alignment) void {
    c.paragraph_set_align(self.paragraph_c, @intFromEnum(alignment));
}

// pub extern fn paragraph_add_richtext(self: CParagraph, text: [*c]const u8) CRichText;
pub inline fn addRichText(self: Paragraph, text: ?[*:0]const u8) !RichText {
    const text_c: c.CRichText = c.paragraph_add_richtext(self.paragraph_c, text);
    try check(c.richtext_has_error(text_c));
    return RichText{
        .text_c = text_c,
    };
}

// pub extern fn paragraph_add_picture(self: CParagraph, relationship_id: CRelationshipId) CPicture;
pub inline fn addPicture(self: Paragraph, id: RelationshipId) !Picture {
    const picture_c: c.CPicture = c.paragraph_add_picture(self.paragraph_c, id);
    try check(c.picture_has_error(picture_c));
    return Picture{
        .picture_c = picture_c,
    };
}

// pub extern fn paragraph_get_error(self: CParagraph) [*c]const u8;
pub inline fn getStrError(self: Paragraph) ?[*:0]const u8 {
    return c.paragraph_get_error(self.paragraph_c);
}

const std = @import("std");
const c = @import("minidocx_c");
const common = @import("common.zig");
const Alignment = common.Alignment;
const RelationshipId = common.RelationshipId;
const RichText = @import("RichText.zig");
const Picture = @import("Picture.zig");
const check = @import("errors.zig").checkResult;
