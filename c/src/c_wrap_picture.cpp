#include "c_wrap_picture.h"

// Pictures functions
void picture_destroy(CPicture self) {
  delete self->err;
  delete self;
}

void picture_set_size(CPicture self, const size_t cols, const size_t rows,
                      const size_t dpi, const size_t scale = 100) {
  self->p->prop_.extent_.setSize(cols, rows, dpi, scale);
}

int picture_has_error(CPicture self) { return self->err->type; }
const char *picture_get_error(CPicture self) { return self->err->message; }
void picture_clear_error(CPicture self) { _clear_error(self->err); }
