#include "c_wrap_parastyle.h"

// Document functions
CParaStyle parastyle_create() {
  return new CWrapParaStyle{.p = ParagraphStyle{}};
}

void parastyle_destroy(CParaStyle self) { delete self; }

void parastyle_set_name(CParaStyle self, const char *name) {
  self->p.name_ = name;
}
void parastyle_set_align(CParaStyle self, CAlignment align) {
  self->p.align_ = static_cast<Alignment>(align);
}
void parastyle_set_outlinelevel(CParaStyle self, COutlineLevel level) {
  self->p.outlineLevel_ = static_cast<ParagraphStyle::OutlineLevel>(level);
}
void parastyle_set_fontsize(CParaStyle self, int size) {
  self->p.fontSize_ = size;
}
void parastyle_set_color(CParaStyle self, const char *color) {
  self->p.color_ = color;
}
