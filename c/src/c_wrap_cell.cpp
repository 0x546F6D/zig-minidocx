#include "c_wrap_cell.h"

// Cell functions
void cell_destroy(CCell self) {
  delete self->err;
  delete self;
}

CParagraph cell_add_paragraph(CCell self) {
  if (self->err->type)
    return new CWrapParagraph{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapParagraph{.p = self->p->addParagraph(),
                              .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapParagraph{.err = _init_cerror_from_exception(ex)};
  }
}

int cell_has_error(CCell self) { return self->err->type; }
const char *cell_get_error(CCell self) { return self->err->message; }
void cell_clear_error(CCell self) { _clear_error(self->err); }
