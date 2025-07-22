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
#endif // #ifdef __cplusplus

typedef struct CWrapRelationshipId *CRelationshipId;

int relationshipid_has_error(CRelationshipId self);
const char *relationshipid_get_error(CRelationshipId self);
void relationshipid_clear_error(CRelationshipId self);
#endif // C_WRAP_RELATIONSHIPID_H
