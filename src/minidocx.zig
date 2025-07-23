pub const c = @import("minidocx_c");

pub const Document = @import("Document.zig");
pub const initDocument = Document.init;

pub const Paragraph = @import("Paragraph.zig");
pub const Picture = @import("Picture.zig");
pub const RichText = @import("RichText.zig");
pub const Section = @import("Section.zig");
pub const Table = @import("Table.zig");

pub const common = @import("common.zig");
pub const PackageProperties = common.PackageProperties;
pub const Alignment = common.Alignment;
pub const BorderStyle = common.BorderStyle;
pub const RelationshipId = common.RelationshipId;
pub const NumberingId = common.NumberingId;
