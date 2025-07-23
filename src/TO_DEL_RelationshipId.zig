const RelationshipId = @This();

id_c: c.CRelationshipId,

// pub extern fn relationshipid_destroy(self: CRelationshipId) void;
pub inline fn deinit(self: RelationshipId) void {
    c.relationshipid_destroy(self.id_c);
}

// pub extern fn relationshipid_get_error(self: CRelationshipId) [*c]const u8;
pub inline fn getStrError(self: RelationshipId) ?[*:0]const u8 {
    return c.relationshipid_get_error(self.id_c);
}

const std = @import("std");
const c = @import("minidocx_c");
const check = @import("errors.zig").checkResult;
