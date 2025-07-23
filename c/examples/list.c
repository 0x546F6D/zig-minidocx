#include "c_wrap_minidocx.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);
  // const NumberingId numId1 = doc.addBulletedListDefinition();
  // const NumberingId numId2 = doc.addNumberedListDefinition();
  const NumberingId numId1 = document_add_bulleted_list_definition(d);
  const NumberingId numId2 = document_add_numbered_list_definition(d);

  // sect->addParagraph()->addRichText("Example 1:");
  CParagraph p0 = section_add_paragraph(s);
  CRichText t0 = paragraph_add_richtext(p0, "Example 1:");

  // ParagraphPointer para1 = sect->addParagraph();
  // para1->addRichText("Level one");
  // para1->numId_ = numId1;
  CParagraph p1 = section_add_paragraph(s);
  CRichText t1 = paragraph_add_richtext(p1, "Level one");
  paragraph_set_numid(p1, numId1);

  // ParagraphPointer para2 = sect->addParagraph();
  // para2->addRichText("Level two");
  // para2->numId_ = numId1;
  // para2->level_ = NumberingLevel::Level2;
  CParagraph p2 = section_add_paragraph(s);
  CRichText t2 = paragraph_add_richtext(p2, "Level two");
  paragraph_set_numid(p2, numId1);
  paragraph_set_level(p2, NumLevel2);

  // ParagraphPointer para3 = sect->addParagraph();
  // para3->addRichText("Level three");
  // para3->numId_ = numId1;
  // para3->level_ = NumberingLevel::Level3;
  CParagraph p3 = section_add_paragraph(s);
  CRichText t3 = paragraph_add_richtext(p3, "Level three");
  paragraph_set_numid(p3, numId1);
  paragraph_set_level(p3, NumLevel3);

  // sect->addParagraph()->addRichText("Example 2:");
  CParagraph p00 = section_add_paragraph(s);
  CRichText t00 = paragraph_add_richtext(p00, "Example 2:");

  // ParagraphPointer para4 = sect->addParagraph();
  // para4->addRichText("Level one");
  // para4->numId_ = numId2;
  CParagraph p4 = section_add_paragraph(s);
  CRichText t4 = paragraph_add_richtext(p4, "Level one");
  paragraph_set_numid(p4, numId2);

  // ParagraphPointer para5 = sect->addParagraph();
  // para5->addRichText("Level two");
  // para5->numId_ = numId2;
  // para5->level_ = NumberingLevel::Level2;
  CParagraph p5 = section_add_paragraph(s);
  CRichText t5 = paragraph_add_richtext(p5, "Level two");
  paragraph_set_numid(p5, numId1);
  paragraph_set_level(p5, NumLevel2);

  // ParagraphPointer para6 = sect->addParagraph();
  // para6->addRichText("Level three");
  // para6->numId_ = numId2;
  // para6->level_ = NumberingLevel::Level3;
  CParagraph p6 = section_add_paragraph(s);
  CRichText t6 = paragraph_add_richtext(p6, "Level three");
  paragraph_set_numid(p6, numId1);
  paragraph_set_level(p6, NumLevel3);

  // doc.saveAs("out/cpp_list.docx");
  document_saveas(d, "out/c_list.docx");

  // clean up
  richtext_destroy(t0);
  richtext_destroy(t1);
  richtext_destroy(t2);
  richtext_destroy(t3);
  richtext_destroy(t00);
  richtext_destroy(t4);
  richtext_destroy(t5);
  richtext_destroy(t6);
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
