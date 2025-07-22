#include "c_wrap_paragraph.h"

// Paragraph functions
void paragraph_destroy(CParagraph self) {
  delete self->err;
  delete self;
}

void paragraph_set_align(CParagraph self, CAlignment align) {
  self->p->prop_.align_ = static_cast<Alignment>(align);
}

CRichText paragraph_add_richtext(CParagraph self, const char *text) {
  if (self->err->type)
    return new CWrapRichText{.err = _pass_down_cerror(self->err)};

  return new CWrapRichText{.p = self->p->addRichText(text),
                           .err = _init_cerror()};
}

CPicture paragraph_add_picture(CParagraph self,
                               const CRelationshipId relationship_id) {
  if (self->err->type)
    return new CWrapPicture{.err = _pass_down_cerror(self->err)};

  return new CWrapPicture{.p = self->p->addPicture(relationship_id->id),
                          .err = _init_cerror()};
}

int paragraph_has_error(CParagraph self) { return self->err->type; }
const char *paragraph_get_error(CParagraph self) { return self->err->message; }
void paragraph_clear_error(CParagraph self) { _clear_error(self->err); }
