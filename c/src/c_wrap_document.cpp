#include "c_wrap_document.h"

// Document functions
CDocument document_create() {
  try {
    return new CWrapDocument{.p = new Document(), .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapDocument{.err = _init_cerror_from_exception(ex)};
  }
}

void document_destroy(CDocument self) {
  delete self->p;
  delete self->err;
  delete self;
}

void document_saveas(CDocument self, const char *filename) {
  if (self->err->type)
    return;

  try {
    reinterpret_cast<Document *>(self->p)->saveAs(filename);
  } catch (const Exception &ex) {
    _check_exception(self->err, ex);
  }
}

void document_set_properties(CDocument self, const CPackageProperties *prop) {
  Document *doc = reinterpret_cast<Document *>(self->p);
  if (prop->author)
    doc->prop_.author_ = prop->author;
  if (prop->company)
    doc->prop_.company_ = prop->company;
  if (prop->lastModifiedBy)
    doc->prop_.lastModifiedBy_ = prop->lastModifiedBy;
  if (prop->subject)
    doc->prop_.subject_ = prop->subject;
  if (prop->title)
    doc->prop_.title_ = prop->title;
}

CSection document_add_section(CDocument self) {
  if (self->err->type)
    return new CWrapSection{.err = _pass_down_cerror(self->err)};

  try {
    return new CWrapSection{.p = self->p->addSection(), .err = _init_cerror()};
  } catch (const Exception &ex) {
    return new CWrapSection{.err = _init_cerror_from_exception(ex)};
  }
}

RelationshipId document_add_image_path(CDocument self, const char *filename) {
  if (self->err->type)
    return SIZE_MAX;

  try {
    return self->p->addImage(filename);
  } catch (const Exception &ex) {
    _check_exception(self->err, ex);
    return SIZE_MAX;
  }
}

NumberingId document_add_bulleted_list_definition(CDocument self) {
  if (self->err->type)
    return SIZE_MAX;

  try {
    return self->p->addBulletedListDefinition();
  } catch (const Exception &ex) {
    _check_exception(self->err, ex);
    return SIZE_MAX;
  }
}

NumberingId document_add_numbered_list_definition(CDocument self) {
  if (self->err->type)
    return SIZE_MAX;

  try {
    return self->p->addNumberedListDefinition();
  } catch (const Exception &ex) {
    _check_exception(self->err, ex);
    return SIZE_MAX;
  }
}

void document_add_parastyle(CDocument self, CParaStyle style) {
  if (self->err->type)
    return;

  try {
    self->p->addParagraphStyle(style->p);
  } catch (const Exception &ex) {
    _check_exception(self->err, ex);
  }
}
int document_has_error(CDocument self) { return self->err->type; }
const char *document_get_error(CDocument self) { return self->err->message; }
void document_clear_error(CDocument self) { _clear_error(self->err); }
