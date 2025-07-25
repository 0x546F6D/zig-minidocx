#pragma once
#ifndef C_WRAP_RICHTEXT_H
#define C_WRAP_RICHTEXT_H

#ifdef __cplusplus
#include "c_wrap_error.h"
#include "minidocx.hpp"

using namespace md;

// RichText Wrapper
struct CWrapRichText {
  std::shared_ptr<RichText> p;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus

typedef struct CWrapRichText *CRichText;

// richtext functions
void richtext_destroy(CRichText self);
void richtext_set_fontsize(CRichText self, size_t size);
void richtext_set_color(CRichText self, const char *color);

int richtext_has_error(CRichText self);
const char *richtext_get_error(CRichText self);
void richtext_clear_error(CRichText self);
#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_RICHTEXT_H
