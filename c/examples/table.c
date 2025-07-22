#include "c_wrap_minidocx.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);
  //
  // sect->addParagraph()->addRichText("Example:");
  CParagraph p1 = section_add_paragraph(s);
  //
  // TablePointer tbl = sect->addTable(5, 7);
  // tbl->prop_.width_.type_ = TableProperties::WidthType::Percent;
  //
  // tbl->cellAt(0, 0)->addParagraph()->addRichText("AAA");
  CParagraph p2 = section_add_paragraph(s);
  //
  // tbl->merge(1, 1, 2, 3);
  // tbl->cellAt(1, 1)->addParagraph()->addRichText("BBB");
  CParagraph p3 = section_add_paragraph(s);
  //
  // tbl->merge(2, 4, 2, 2);
  // tbl->cellAt(2, 4)->addParagraph()->addRichText("CCC");
  CParagraph p4 = section_add_paragraph(s);
  //
  // tbl->merge(3, 2, 2, 2);
  // tbl->cellAt(3, 2)->addParagraph()->addRichText("DDD");
  CParagraph p5 = section_add_paragraph(s);
  //
  // tbl->merge(0, 6, 5, 1);
  // tbl->cellAt(0, 6)->addParagraph()->addRichText("EEE");
  CParagraph p6 = section_add_paragraph(s);
  //
  // /*tbl->dumpStructure();*/
  //
  // doc.saveAs("out/cpp_table.docx");
  document_saveas(d, "out/c_table.docx");

  // clean up
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  paragraph_destroy(p3);
  paragraph_destroy(p4);
  paragraph_destroy(p5);
  paragraph_destroy(p6);
  section_destroy(s);
  document_destroy(d);
}
