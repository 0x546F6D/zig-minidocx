#include "c_wrap_section.h"

// Section functions
void section_destroy(CSection self) {
  delete self->err;
  delete self;
}

void section_set_landscape(CSection self, int landscape) {
  self->p->prop_.landscape_ = landscape;
}

CParagraph section_add_paragraph(CSection self) {
  if (self->err->type)
    return new CWrapParagraph{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapParagraph{.p = self->p->addParagraph(),
                              .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapParagraph{.err = _init_cerror_from_exception(ex)};
  }
}

int section_has_error(CSection self) { return self->err->type; }
const char *section_get_error(CSection self) { return self->err->message; }
void section_clear_error(CSection self) { _clear_error(self->err); }
