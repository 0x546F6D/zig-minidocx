#pragma once
#ifndef C_WRAP_DOCUMENT_H
#define C_WRAP_DOCUMENT_H

#include "c_wrap_section.h"

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

// Document Wrapper
struct CWrapDocument {
  Document *p;
  CErrorProperties *err;
};

extern "C" {
#endif // #ifdef __cplusplus
typedef struct CWrapDocument *CDocument;

// document functions
CDocument document_create();
void document_destroy(CDocument self);

void document_saveas(CDocument self, const char *filename);
void document_set_properties(CDocument self, const CPackageProperties *prop);
CSection document_add_section(CDocument self);
RelationshipId document_add_image_path(CDocument self, const char *filename);
NumberingId document_add_bulleted_list_definition(CDocument self);
NumberingId document_add_numbered_list_definition(CDocument self);

int document_has_error(CDocument self);
const char *document_get_error(CDocument self);
void document_clear_error(CDocument self);
#ifdef __cplusplus
} // extern "C"
#endif
#endif // C_WRAP_DOCUMENT_H
