#include "c_wrap_richtext.h"

// RichText functions
void richtext_destroy(CRichText self) {
  delete self->err;
  delete self;
}

void richtext_set_font_size(CRichText self, int size) {
  self->p->prop_.fontSize_ = size;
}
void richtext_set_color(CRichText self, const char *color) {
  self->p->prop_.color_ = color;
}

int richtext_has_error(CRichText self) { return self->err->type; }
const char *richtext_get_error(CRichText self) { return self->err->message; }
void richtext_clear_error(CRichText self) { _clear_error(self->err); }
