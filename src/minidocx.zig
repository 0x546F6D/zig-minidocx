pub const c = @import("minidocx_c");

pub const Document = @import("Document.zig");
pub const Paragraph = @import("Paragraph.zig");
pub const Picture = @import("Picture.zig");
pub const RichText = @import("RichText.zig");
pub const Section = @import("Section.zig");
pub const Table = @import("Table.zig");

pub const initDocument = Document.init;
