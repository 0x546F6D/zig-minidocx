#include "c_wrap_minidocx.h"
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);
  //
  // sect->addParagraph()->addRichText(TEXT1);
  CParagraph p1 = section_add_paragraph(s);
  //
  // PicturePointer pict1 = sect->addParagraph()->addPicture(
  //     doc.addImage("cpp/examples/samples/17528.jpg"));
  // pict1->prop_.extent_.setSize(4725, 3173, 300, 20);
  //
  // sect->addParagraph()->addRichText(TEXT2);
  CParagraph p2 = section_add_paragraph(s);
  //
  // PicturePointer pict2 = sect->addParagraph()->addPicture(
  //     doc.addImage("cpp/examples/samples/17529.jpg"));
  // pict2->prop_.extent_.setSize(4838, 3323, 300, 20);
  //
  // sect->addParagraph()->addRichText(TEXT3);
  CParagraph p3 = section_add_paragraph(s);
  //
  // doc.saveAs("out/cpp_picture.docx");
  document_saveas(d, "out/c_picture.docx");

  // clean up
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  paragraph_destroy(p3);
  section_destroy(s);
  document_destroy(d);
}
