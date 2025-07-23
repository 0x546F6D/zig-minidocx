#pragma once
#ifndef C_WRAP_TABLE_H
#define C_WRAP_TABLE_H

#include "c_wrap_cell.h"

typedef enum TableWidthType {
  TableWidthAuto,    // Specifies that width is determined by the table layout
  TableWidthPercent, // 50 = 1%
  TableWidthAbsolute // 1440 = 1 Inch = 72 points
} TableWidthType;

typedef enum TableLayout {
  TableLayoutAuto,
  TableLayoutFixed,
} TableLayout;

typedef enum TableAlignment {
  TableAlignLeft,   // Align To Leading Edge 左对齐
  TableAlignRight,  // Align to Trailing Edge 右对齐
  TableAlignCenter, // Align Center 居中对齐
} TableAlignment;

typedef enum TableBorder {
  TableBorderTop,
  TableBorderBottom,
  TableBorderLeft,
  TableBorderRight,
  TableBorderInsideHorizontal,
  TableBorderInsideVertical,
} TableBorder;

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

// Table Wrapper
struct CWrapTable {
  std::shared_ptr<Table> p;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus
typedef struct CWrapTable *CTable;

// table functions
void table_destroy(CTable self);

void table_set_layout(CTable self, TableLayout layout);
void table_set_widthtype(CTable self, TableWidthType type);
void table_set_widthsize(CTable self, size_t size);
void table_set_align(CTable self, TableAlignment align);
void table_set_border(CTable self, TableBorder border, CBorderProperties prop);

CCell table_cellat(CTable self, const size_t row, const size_t col);
CCell table_merge(CTable self, const size_t row, const size_t col,
                  const size_t rows, const size_t cols);

int table_has_error(CTable self);
const char *table_get_error(CTable self);
void table_clear_error(CTable self);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_TABLE_H
