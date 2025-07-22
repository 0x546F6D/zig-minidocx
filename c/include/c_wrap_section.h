#pragma once
#ifndef C_WRAP_SECTION_H
#define C_WRAP_SECTION_H

#include "c_wrap_paragraph.h"

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

// Section Wrapper
struct CWrapSection {
  std::shared_ptr<Section> p;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus

typedef struct CWrapSection *CSection;
// section functions
void section_destroy(CSection self);
void section_set_landscape(CSection self, int landscape);
CParagraph section_add_paragraph(CSection self);

int section_has_error(CSection self);
const char *section_get_error(CSection self);
void section_clear_error(CSection self);
#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_SECTION_H
