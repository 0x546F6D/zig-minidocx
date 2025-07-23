#pragma once
#ifndef C_WRAP_CELL_H
#define C_WRAP_CELL_H

#include "c_wrap_paragraph.h"

#ifdef __cplusplus
#include "c_wrap_error.h"
#include "minidocx.hpp"
using namespace md;

// Cell Wrapper
struct CWrapCell {
  std::shared_ptr<Cell> p;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus
typedef struct CWrapCell *CCell;

// table functions
void cell_destroy(CCell self);

CParagraph cell_add_paragraph(CCell self);

int cell_has_error(CCell self);
const char *cell_get_error(CCell self);
void cell_clear_error(CCell self);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_CELL
