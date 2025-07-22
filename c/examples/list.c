#include "c_wrap_minidocx.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);
  // const NumberingId numId1 = doc.addBulletedListDefinition();
  // const NumberingId numId2 = doc.addNumberedListDefinition();
  //
  // sect->addParagraph()->addRichText("Example 1:");
  CParagraph p0 = section_add_paragraph(s);
  //
  // ParagraphPointer para1 = sect->addParagraph();
  CParagraph p1 = section_add_paragraph(s);
  // para1->addRichText("Level one");
  // para1->numId_ = numId1;
  //
  // ParagraphPointer para2 = sect->addParagraph();
  CParagraph p2 = section_add_paragraph(s);
  // para2->addRichText("Level two");
  // para2->numId_ = numId1;
  // para2->level_ = NumberingLevel::Level2;
  //
  // ParagraphPointer para3 = sect->addParagraph();
  CParagraph p3 = section_add_paragraph(s);
  // para3->addRichText("Level three");
  // para3->numId_ = numId1;
  // para3->level_ = NumberingLevel::Level3;
  //
  // sect->addParagraph()->addRichText("Example 2:");
  CParagraph p00 = section_add_paragraph(s);
  //
  // ParagraphPointer para4 = sect->addParagraph();
  CParagraph p4 = section_add_paragraph(s);
  // para4->addRichText("Level one");
  // para4->numId_ = numId2;
  //
  // ParagraphPointer para5 = sect->addParagraph();
  CParagraph p5 = section_add_paragraph(s);
  // para5->addRichText("Level two");
  // para5->numId_ = numId2;
  // para5->level_ = NumberingLevel::Level2;
  //
  // ParagraphPointer para6 = sect->addParagraph();
  CParagraph p6 = section_add_paragraph(s);
  // para6->addRichText("Level three");
  // para6->numId_ = numId2;
  // para6->level_ = NumberingLevel::Level3;
  //
  // doc.saveAs("out/cpp_list.docx");
  document_saveas(d, "out/c_list.docx");

  // clean up
  paragraph_destroy(p0);
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  paragraph_destroy(p3);
  paragraph_destroy(p00);
  paragraph_destroy(p4);
  paragraph_destroy(p5);
  paragraph_destroy(p6);
  section_destroy(s);
  document_destroy(d);
}
