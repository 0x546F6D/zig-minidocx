#include "c_wrap_table.h"

// Table functions
void table_destroy(CTable self) {
  delete self->err;
  delete self;
}

void table_set_layout(CTable self, TableLayout layout) {
  self->p->prop_.layout_ = static_cast<TableProperties::Layout>(layout);
}

void table_set_widthtype(CTable self, TableWidthType type) {
  self->p->prop_.width_.type_ = static_cast<TableProperties::WidthType>(type);
}

void table_set_widthsize(CTable self, size_t size) {
  self->p->prop_.width_.value_ = size;
}

void table_set_align(CTable self, TableAlignment align) {
  self->p->prop_.align_ = static_cast<TableProperties::Alignment>(align);
}
void table_set_border(CTable self, TableBorder border,
                      CBorderProperties cprop) {
  BorderProperties prop = {
      .style_ = static_cast<BorderStyle>(cprop.style_),
      .width_ = cprop.width_,
      .color_ = cprop.color_,
  };

  switch (border) {
  case TableBorderTop:
    self->p->prop_.borders_.top_ = prop;
    break;
  case TableBorderBottom:
    self->p->prop_.borders_.bottom_ = prop;
    break;
  case TableBorderLeft:
    self->p->prop_.borders_.left_ = prop;
    break;
  case TableBorderRight:
    self->p->prop_.borders_.right_ = prop;
    break;
  case TableBorderInsideHorizontal:
    self->p->prop_.borders_.insideHorizontal_ = prop;
    break;
  case TableBorderInsideVertical:
    self->p->prop_.borders_.insideVertical_ = prop;
    break;
  }
}

CCell table_cellat(CTable self, const size_t row, const size_t col) {
  if (self->err->type)
    return new CWrapCell{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapCell{.p = self->p->cellAt(row, col), .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapCell{.err = _init_cerror_from_exception(ex)};
  }
}

CCell table_merge(CTable self, const size_t row, const size_t col,
                  const size_t rows, const size_t cols){
  if (self->err->type)
    return new CWrapCell{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapCell{
      .p = self->p->merge(row, col, rows, cols),
      .err = _init_cerror(),
    };
  } catch (const Exception &ex) {
    return new CWrapCell{.err = _init_cerror_from_exception(ex)};
  }
}

int table_has_error(CTable self) { return self->err->type; }
const char *table_get_error(CTable self) { return self->err->message; }
void table_clear_error(CTable self) { _clear_error(self->err); }
