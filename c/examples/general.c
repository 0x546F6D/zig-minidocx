#include "c_wrap_minidocx.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  CDocument d = document_create();

  CSection s = document_add_section(d);
  section_set_landscape(s, 1);

  CParagraph p1 = section_add_paragraph(s);
  paragraph_set_align(p1, Centered);

  CRichText t1 = paragraph_add_richtext(p1, "Happy Chinese New Year!");
  richtext_set_fontsize(t1, 32);
  richtext_set_color(t1, "FF0000");

  CParagraph p2 = section_add_paragraph(s);
  CRichText t2 = paragraph_add_richtext(
      p2, "Spring Festival, known as the Chinese New Year, "
          "is the most important festival celebrated by the Chinese people. "
          "UNESCO inscribed Spring Festival on the Representative List of "
          "the Intangible Cultural Heritage of Humanity in 2024.");

  CParagraph p3 = section_add_paragraph(s);
  paragraph_set_align(p3, Centered);
  RelationshipId pic_id =
      document_add_image_path(d, "cpp/examples/samples/17533.jpg");
  CPicture pic = paragraph_add_picture(p3, pic_id);
  picture_set_size(pic, 4643, 6199, 300, 20);

  CPackageProperties prop = {
      .title = "Chinese New Year",
      .author = "Quinn",
      .lastModifiedBy = "John",
  };
  document_set_properties(d, &prop);

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
