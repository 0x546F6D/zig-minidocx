const Paragraph = @This();

paragraph_c: CParagraph,

pub const NumberingLevel = enum(usize) {
    level1 = c.NumLevel1,
    level2 = c.NumLevel2,
    level3 = c.NumLevel3,
    level4 = c.NumLevel4,
    level5 = c.NumLevel5,
    level6 = c.NumLevel6,
    level7 = c.NumLevel7,
    level8 = c.NumLevel8,
    level9 = c.NumLevel9,
};

pub const OutlineLevel = enum(c_int) {
    level1 = c.OutlineLevel1,
    level2 = c.OutlineLevel2,
    level3 = c.OutlineLevel3,
    level4 = c.OutlineLevel4,
    level5 = c.OutlineLevel5,
    level6 = c.OutlineLevel6,
    level7 = c.OutlineLevel7,
    level8 = c.OutlineLevel8,
    level9 = c.OutlineLevel9,
    body_text = c.BodyText,
};

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
    const text_c: CRichText = c.paragraph_add_richtext(self.paragraph_c, text);
    try check(c.richtext_has_error(text_c));
    return RichText{
        .text_c = text_c,
    };
}

// pub extern fn parastyle_set_color(self: CParaStyle, color: [*c]const u8) void;
pub inline fn setStyle(self: Paragraph, style: ?[*:0]const u8) void {
    c.paragraph_set_style(self.paragraph_c, style);
}

// pub extern fn paragraph_set_numid(self: CParagraph, id: NumberingId) void;
pub inline fn setNumid(self: Paragraph, id: NumberingId) void {
    c.paragraph_set_numid(self.paragraph_c, id);
}

// pub extern fn paragraph_set_level(self: CParagraph, level: CNumberingLevel) void;
pub inline fn setLevel(self: Paragraph, level: NumberingLevel) void {
    c.paragraph_set_level(self.paragraph_c, @intFromEnum(level));
}

// pub extern fn paragraph_add_picture(self: CParagraph, relationship_id: CRelationshipId) CPicture;
pub inline fn addPicture(self: Paragraph, id: RelationshipId) !Picture {
    const picture_c: CPicture = c.paragraph_add_picture(self.paragraph_c, id);
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
pub const CParagraph = c.CParagraph;
const common = @import("common.zig");
const Alignment = common.Alignment;
const RelationshipId = common.RelationshipId;
const NumberingId = common.NumberingId;
const RichText = @import("RichText.zig");
const CRichText = RichText.CRichText;
const Picture = @import("Picture.zig");
const CPicture = Picture.CPicture;
const check = @import("errors.zig").checkResult;
