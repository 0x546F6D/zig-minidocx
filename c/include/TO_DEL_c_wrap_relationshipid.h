#pragma once
#ifndef C_WRAP_RELATIONSHIPID_H
#define C_WRAP_RELATIONSHIPID_H

#include "c_wrap_error.h"

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

// RelationshipId Wrapper
struct CWrapRelationshipId {
  RelationshipId id;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus

typedef struct CWrapRelationshipId *CRelationshipId;

void relationshipid_destroy(CRelationshipId self);

int relationshipid_has_error(CRelationshipId self);
const char *relationshipid_get_error(CRelationshipId self);
void relationshipid_clear_error(CRelationshipId self);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_RELATIONSHIPID_H
