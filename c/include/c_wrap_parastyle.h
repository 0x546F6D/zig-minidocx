#pragma once
#ifndef C_WRAP_PARASTYLE_H
#define C_WRAP_PARASTYLE_H

#include "c_wrap_common.h"

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

struct CWrapParaStyle {
  ParagraphStyle p;
};

extern "C" {
#endif // #ifdef __cplusplus
typedef struct CWrapParaStyle *CParaStyle;

// document functions
CParaStyle parastyle_create();
void parastyle_destroy(CParaStyle self);
void parastyle_set_name(CParaStyle self, const char *name);
void parastyle_set_align(CParaStyle self, CAlignment align);
void parastyle_set_outlinelevel(CParaStyle self, COutlineLevel level);
void parastyle_set_fontsize(CParaStyle self, int size);
void parastyle_set_color(CParaStyle self, const char *color);
#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_PARASTYLE_H
