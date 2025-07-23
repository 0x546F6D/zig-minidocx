#include "c_wrap_minidocx.h"
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  // sect->prop_.landscape_ = true;
  CSection s = document_add_section(d);
  section_set_landscape(s, 1);

  // ParagraphPointer para = sect->addParagraph();
  // para->prop_.align_ = Alignment::Centered;
  CParagraph p1 = section_add_paragraph(s);
  paragraph_set_align(p1, Centered);

  // RichTextPointer rich = para->addRichText("Happy Chinese New Year!");
  // rich->prop_.fontSize_ = 32;
  // rich->prop_.color_ = "FF0000";
  CRichText t1 = paragraph_add_richtext(p1, "Happy Chinese New Year!");
  richtext_set_font_size(t1, 32);
  richtext_set_color(t1, "FF0000");

  // sect->addParagraph()->addRichText(
  //   "Spring Festival, known as the Chinese New Year, "
  //   "is the most important festival celebrated by the Chinese people. "
  //   "UNESCO inscribed Spring Festival on the Representative List of "
  //   "the Intangible Cultural Heritage of Humanity in 2024.");
  CParagraph p2 = section_add_paragraph(s);
  CRichText t2 = paragraph_add_richtext(
      p2, "Spring Festival, known as the Chinese New Year, "
          "is the most important festival celebrated by the Chinese people. "
          "UNESCO inscribed Spring Festival on the Representative List of "
          "the Intangible Cultural Heritage of Humanity in 2024.");

  // PicturePointer pict =
  //   sect->addParagraph({.align_ = Alignment::Centered})
  //   ->addPicture(doc.addImage("cpp/examples/samples/17533.jpg"));
  // pict->prop_.extent_.setSize(4643, 6199, 300, 20);
  CParagraph p3 = section_add_paragraph(s);
  paragraph_set_align(p3, Centered);
  RelationshipId pic_id =
      document_add_image_path(d, "cpp/examples/samples/17533.jpg");
  CPicture pic = paragraph_add_picture(p3, pic_id);
  picture_set_size(pic, 4643, 6199, 300, 20);

  // doc.prop_.title_ = "Chinese New Year";
  // doc.prop_.author_ = "Quinn";
  // doc.prop_.lastModifiedBy_ = "John";
  CPackageProperties prop = {
      .title = "Chinese New Year",
      .author = "Quinn",
      .lastModifiedBy = "John",
  };
  document_set_properties(d, &prop);

  // doc.saveAs("out/example.docx");
  document_saveas(d, "out/c_general.docx");
  // document_saveas(d, "dir_that_does_not_exit/c_general.docx");
  if (document_has_error(d)) {
    const char *err = document_get_error(d);
    printf("error code %d: %s\n", document_has_error(d), err);
  }

  // clean up
  richtext_destroy(t1);
  richtext_destroy(t2);
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  paragraph_destroy(p3);
  picture_destroy(pic);
  section_destroy(s);
  document_destroy(d);

  return 0;
}
