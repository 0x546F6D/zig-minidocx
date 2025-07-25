#include "c_wrap_minidocx.h"

int main(int argc, char *argv[]) {
  CDocument d = document_create();
  const NumberingId numId1 = document_add_bulleted_list_definition(d);
  const NumberingId numId2 = document_add_numbered_list_definition(d);

  CSection s = document_add_section(d);

  CParagraph p0 = section_add_paragraph(s);
  CRichText t0 = paragraph_add_richtext(p0, "Example 1:");

  CParagraph p1 = section_add_paragraph(s);
  CRichText t1 = paragraph_add_richtext(p1, "Level one");
  paragraph_set_numid(p1, numId1);

  CParagraph p2 = section_add_paragraph(s);
  CRichText t2 = paragraph_add_richtext(p2, "Level two");
  paragraph_set_numid(p2, numId1);
  paragraph_set_level(p2, NumLevel2);

  CParagraph p3 = section_add_paragraph(s);
  CRichText t3 = paragraph_add_richtext(p3, "Level three");
  paragraph_set_numid(p3, numId1);
  paragraph_set_level(p3, NumLevel3);

  CParagraph p00 = section_add_paragraph(s);
  CRichText t00 = paragraph_add_richtext(p00, "Example 2:");

  CParagraph p4 = section_add_paragraph(s);
  CRichText t4 = paragraph_add_richtext(p4, "Level one");
  paragraph_set_numid(p4, numId2);

  CParagraph p5 = section_add_paragraph(s);
  CRichText t5 = paragraph_add_richtext(p5, "Level two");
  paragraph_set_numid(p5, numId1);
  paragraph_set_level(p5, NumLevel2);

  CParagraph p6 = section_add_paragraph(s);
  CRichText t6 = paragraph_add_richtext(p6, "Level three");
  paragraph_set_numid(p6, numId1);
  paragraph_set_level(p6, NumLevel3);

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
