#pragma once
#ifndef C_WRAP_PICTURE_H
#define C_WRAP_PICTURE_H


#ifdef __cplusplus
#include "c_wrap_error.h"
#include "minidocx.hpp"
using namespace md;

// Picture Wrapper
struct CWrapPicture {
  std::shared_ptr<Picture> p;
  CErrorProperties *err;
};

extern "C" {
#else
#include <stddef.h>
#endif // #ifdef __cplusplus
typedef struct CWrapPicture *CPicture;

// picture functions
void picture_destroy(CPicture self);
void picture_set_size(CPicture self, const size_t cols, const size_t rows,
                      const size_t dpi, const size_t scale);

int picture_has_error(CPicture self);
const char *picture_get_error(CPicture self);
void picture_clear_error(CPicture self);
#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_PICTURE_H
