#include "c_wrap_minidocx.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);

  // ParagraphStyle paraStyle;
  // paraStyle.name_ = "My Heading 1";
  // paraStyle.align_ = Alignment::Centered;
  // paraStyle.outlineLevel_ = ParagraphProperties::OutlineLevel::Level1;
  // paraStyle.fontSize_ = 32;
  // paraStyle.color_ = "FF0000";
  // doc.addParagraphStyle(paraStyle);
  CParaStyle parastyle = parastyle_create();
  parastyle_set_name(parastyle, "My Heading 1");
  parastyle_set_align(parastyle, Centered);
  parastyle_set_outlinelevel(parastyle, OutlineLevel1);
  parastyle_set_fontsize(parastyle, 32);
  parastyle_set_color(parastyle, "FF0000");
  document_add_parastyle(d, parastyle);

  // paraStyle.name_ = "My Heading 2";
  // paraStyle.outlineLevel_ = ParagraphProperties::OutlineLevel::Level2;
  // paraStyle.fontSize_ = 28;
  // paraStyle.color_ = "0000FF";
  // doc.addParagraphStyle(paraStyle);
  parastyle_set_name(parastyle, "My Heading 2");
  parastyle_set_outlinelevel(parastyle, OutlineLevel2);
  parastyle_set_fontsize(parastyle, 28);
  parastyle_set_color(parastyle, "0000FF");
  document_add_parastyle(d, parastyle);

  // ParagraphPointer para = sect->addParagraph();
  // para->prop_.style_ = "My Heading 1";
  // para->addRichText("Quick Start");
  CParagraph p1 = section_add_paragraph(s);
  paragraph_set_style(p1, "My Heading 1");
  CRichText t1 = paragraph_add_richtext(p1, "Quick Start");

  // ParagraphPointer para2 = sect->addParagraph();
  // para2->prop_.style_ = "My Heading 2";
  // para2->addRichText("Download and Installation");
  CParagraph p2 = section_add_paragraph(s);
  paragraph_set_style(p2, "My Heading 2");
  CRichText t2 = paragraph_add_richtext(p2, "Download and Installation");

  // doc.saveAs("out/cpp_style.docx");
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
