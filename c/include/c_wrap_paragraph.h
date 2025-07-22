#pragma once
#ifndef C_WRAP_PARAGRAPH_H
#define C_WRAP_PARAGRAPH_H

#include "c_wrap_common.h"
#include "c_wrap_picture.h"
#include "c_wrap_relationshipid.h"
#include "c_wrap_richtext.h"

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

// Paragraph Wrapper
struct CWrapParagraph {
  std::shared_ptr<Paragraph> p;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus

typedef struct CWrapParagraph *CParagraph;

// paragraph functions
void paragraph_destroy(CParagraph self);
void paragraph_set_align(CParagraph self, CAlignment align);
CRichText paragraph_add_richtext(CParagraph self, const char *text);
CPicture paragraph_add_picture(CParagraph self,
                               const CRelationshipId relationship_id);

int paragraph_has_error(CParagraph self);
const char *paragraph_get_error(CParagraph self);
void paragraph_clear_error(CParagraph self);
#ifdef __cplusplus
} // extern "C"
#endif

#endif // C_WRAP_PARAGRAPH_H
