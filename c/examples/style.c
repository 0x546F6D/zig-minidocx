#include "c_wrap_minidocx.h"

int main(int argc, char *argv[]) {
  CDocument d = document_create();

  CSection s = document_add_section(d);

  CParaStyle parastyle = parastyle_create();
  parastyle_set_name(parastyle, "My Heading 1");
  parastyle_set_align(parastyle, Centered);
  parastyle_set_outlinelevel(parastyle, OutlineLevel1);
  parastyle_set_fontsize(parastyle, 32);
  parastyle_set_color(parastyle, "FF0000");
  document_add_parastyle(d, parastyle);

  parastyle_set_name(parastyle, "My Heading 2");
  parastyle_set_outlinelevel(parastyle, OutlineLevel2);
  parastyle_set_fontsize(parastyle, 28);
  parastyle_set_color(parastyle, "0000FF");
  document_add_parastyle(d, parastyle);

  CParagraph p1 = section_add_paragraph(s);
  paragraph_set_style(p1, "My Heading 1");
  CRichText t1 = paragraph_add_richtext(p1, "Quick Start");

  CParagraph p2 = section_add_paragraph(s);
  paragraph_set_style(p2, "My Heading 2");
  CRichText t2 = paragraph_add_richtext(p2, "Download and Installation");

  document_saveas(d, "out/c_style.docx");

  // clean up
  parastyle_destroy(parastyle);
  richtext_destroy(t1);
  richtext_destroy(t2);
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  section_destroy(s);
  document_destroy(d);
}
