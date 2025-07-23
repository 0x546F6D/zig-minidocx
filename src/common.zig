pub const RelationshipId = c.RelationshipId;
pub const NumberingId = c.NumberingId;

pub const PackageProperties = struct {
    title: ?[*:0]const u8 = null,
    subject: ?[*:0]const u8 = null,
    author: ?[*:0]const u8 = null,
    company: ?[*:0]const u8 = null,
    lastModifiedBy: ?[*:0]const u8 = null,

    pub inline fn toC(self: PackageProperties) c.CPackageProperties {
        return c.CPackageProperties{
            .title = self.title,
            .subject = self.subject,
            .author = self.author,
            .company = self.company,
            .lastModifiedBy = self.lastModifiedBy,
        };
    }
};

pub const Alignment = enum(c_int) {
    left = c.Left,
    centered = c.Centered,
    right = c.Right,
    justified = c.Justified,
    distributed = c.Distributed,
};

pub const BorderStyle = enum(c_int) {
    single = c.Single,
    double = c.Double,
    triple = c.Triple,
    dotted = c.Dotted,
    dashed = c.Dashed,
    dotDash = c.DotDash,
    wave = c.Wave,
    doublewave = c.DoubleWave,
};

// c.CPackageProperties;
// typedef struct CPackageProperties {
//   char *title;
//   char *subject;
//   char *author;
//   char *company;
//   char *lastModifiedBy;
// } CPackageProperties;
//
// c.CAlignment;
// typedef enum CAlignment {
//   Left,
//   Centered,
//   Right,
//   Justified,
//   Distributed,
// } CAlignment;
//
// c.CBorderStyle;
// typedef enum CBorderStyle {
//   Single,
//   Double,
//   Triple,
//   Dotted,
//   Dashed,
//   DotDash,
//   Wave,
//   DoubleWave,
// } CBorderStyle;

const c = @import("minidocx_c");
