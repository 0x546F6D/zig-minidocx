#include "c_wrap_minidocx.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);
  //
  // ParagraphStyle paraStyle;
  // paraStyle.name_ = "My Heading 1";
  // paraStyle.align_ = Alignment::Centered;
  // paraStyle.outlineLevel_ = ParagraphProperties::OutlineLevel::Level1;
  // paraStyle.fontSize_ = 32;
  // paraStyle.color_ = "FF0000";
  // doc.addParagraphStyle(paraStyle);
  //
  // paraStyle.name_ = "My Heading 2";
  // paraStyle.outlineLevel_ = ParagraphProperties::OutlineLevel::Level2;
  // paraStyle.fontSize_ = 28;
  // paraStyle.color_ = "0000FF";
  // doc.addParagraphStyle(paraStyle);
  //
  // ParagraphPointer para = sect->addParagraph();
  CParagraph p1 = section_add_paragraph(s);
  // para->addRichText("Quick Start");
  // para->prop_.style_ = "My Heading 1";
  //
  // ParagraphPointer para2 = sect->addParagraph();
  CParagraph p2 = section_add_paragraph(s);
  // para2->addRichText("Download and Installation");
  // para2->prop_.style_ = "My Heading 2";
  //
  // doc.saveAs("out/cpp_style.docx");
  document_saveas(d, "out/c_style.docx");

  // clean up
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  section_destroy(s);
  document_destroy(d);
}
