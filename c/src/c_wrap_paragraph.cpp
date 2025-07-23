#include "c_wrap_paragraph.h"

// Paragraph functions
void paragraph_destroy(CParagraph self) {
  delete self->err;
  delete self;
}

void paragraph_set_align(CParagraph self, CAlignment align) {
  self->p->prop_.align_ = static_cast<Alignment>(align);
}

void paragraph_set_numid(CParagraph self, NumberingId id) {
  self->p->numId_ = id;
}

void paragraph_set_level(CParagraph self, CNumberingLevel level) {
  self->p->level_ = static_cast<NumberingLevel>(level);
}

CRichText paragraph_add_richtext(CParagraph self, const char *text) {
  if (self->err->type)
    return new CWrapRichText{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapRichText{.p = self->p->addRichText(text),
                             .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapRichText{.err = _init_cerror_from_exception(ex)};
  }
}

CPicture paragraph_add_picture(CParagraph self, const RelationshipId id) {
  if (self->err->type)
    return new CWrapPicture{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapPicture{.p = self->p->addPicture(id),
                            .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapPicture{.err = _init_cerror_from_exception(ex)};
  }
}

int paragraph_has_error(CParagraph self) { return self->err->type; }
const char *paragraph_get_error(CParagraph self) { return self->err->message; }
void paragraph_clear_error(CParagraph self) { _clear_error(self->err); }
