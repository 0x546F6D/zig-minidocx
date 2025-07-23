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
  CRichText t1 = paragraph_add_richtext(p1, "Example:");
  //
  // TablePointer tbl = sect->addTable(5, 7);
  // tbl->prop_.width_.type_ = TableProperties::WidthType::Percent;
  CTable tbl = section_add_table(s, 5, 7);
  table_set_widthtype(tbl, TableWidthPercent);

  // tbl->cellAt(0, 0)->addParagraph()->addRichText("AAA");
  CCell cell1 = table_cellat(tbl, 0, 0);
  CParagraph p2 = cell_add_paragraph(cell1);
  CRichText t2 = paragraph_add_richtext(p2, "AAA");

  // tbl->merge(1, 1, 2, 3);
  // tbl->cellAt(1, 1)->addParagraph()->addRichText("BBB");
  CCell cell2 = table_merge(tbl, 1, 1, 2, 3);
  CParagraph p3 = cell_add_paragraph(cell2);
  CRichText t3 = paragraph_add_richtext(p3, "BBB");

  // tbl->merge(2, 4, 2, 2);
  // tbl->cellAt(2, 4)->addParagraph()->addRichText("CCC");
  CCell cell3 = table_merge(tbl, 2, 4, 2, 2);
  CParagraph p4 = cell_add_paragraph(cell3);
  CRichText t4 = paragraph_add_richtext(p4, "CCC");

  // tbl->merge(3, 2, 2, 2);
  // tbl->cellAt(3, 2)->addParagraph()->addRichText("DDD");
  CCell cell4 = table_merge(tbl, 3, 2, 2, 2);
  CParagraph p5 = cell_add_paragraph(cell4);
  CRichText t5 = paragraph_add_richtext(p5, "DDD");

  // tbl->merge(0, 6, 5, 1);
  // tbl->cellAt(0, 6)->addParagraph()->addRichText("EEE");
  CCell cell5 = table_merge(tbl, 0, 6, 5, 1);
  CParagraph p6 = cell_add_paragraph(cell5);
  CRichText t6 = paragraph_add_richtext(p6, "EEE");

  // /*tbl->dumpStructure();*/

  // doc.saveAs("out/cpp_table.docx");
  document_saveas(d, "out/c_table.docx");

  // clean up
  richtext_destroy(t1);
  richtext_destroy(t2);
  richtext_destroy(t3);
  richtext_destroy(t4);
  richtext_destroy(t5);
  richtext_destroy(t6);
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  paragraph_destroy(p3);
  paragraph_destroy(p4);
  paragraph_destroy(p5);
  paragraph_destroy(p6);
  cell_destroy(cell1);
  cell_destroy(cell2);
  cell_destroy(cell3);
  cell_destroy(cell4);
  cell_destroy(cell5);
  table_destroy(tbl);
  section_destroy(s);
  document_destroy(d);
}
