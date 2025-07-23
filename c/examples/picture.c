#include "c_wrap_minidocx.h"
#include <sys/stat.h>

#define TEXT1                                                                  \
  u8"\
In China, the spring festival marks the beginning of the new year. It falls on \
the first day of the first month of the Chinese calendar and involves a variety \
of social practices to usher in the new year, pray for good fortune, celebrate \
family reunions and promote community harmony. This process of celebration is \
known as ‘guonian’ (crossing the year)."

#define TEXT2                                                                  \
  u8"\
In the days preceding the festival, people clean their homes, stock provisions \
and prepare food. On New Year’s Eve, families dine together and stay up late to \
welcome the new year. During the festival, people wear new clothes, make \
offerings to heaven, earth and ancestors, and extend greetings to elders, \
relatives, friends and neighbours. Public festivities are held by communities, \
cultural institutions, social groups and art troupes."

#define TEXT3                                                                  \
  "\
The spring festival promotes family values, social cohesion and peace while \
providing a sense of identity and continuity for the Chinese people."

int main(int argc, char *argv[]) {
  // Document doc;
  CDocument d = document_create();

  // SectionPointer sect = doc.addSection();
  CSection s = document_add_section(d);

  // sect->addParagraph()->addRichText(TEXT1);
  CParagraph p1 = section_add_paragraph(s);
  CRichText t1 = paragraph_add_richtext(p1, TEXT1);

  // PicturePointer pict1 = sect->addParagraph()->addPicture(
  //     doc.addImage("cpp/examples/samples/17528.jpg"));
  // pict1->prop_.extent_.setSize(4725, 3173, 300, 20);
  RelationshipId pic1_id =
      document_add_image_path(d, "cpp/examples/samples/17528.jpg");
  CParagraph p2 = section_add_paragraph(s);
  CPicture pic1 = paragraph_add_picture(p2, pic1_id);
  picture_set_size(pic1, 4725, 3173, 300, 20);

  // sect->addParagraph()->addRichText(TEXT2);
  CParagraph p3 = section_add_paragraph(s);
  CRichText t2 = paragraph_add_richtext(p3, TEXT2);

  // PicturePointer pict2 = sect->addParagraph()->addPicture(
  //     doc.addImage("cpp/examples/samples/17529.jpg"));
  // pict2->prop_.extent_.setSize(4838, 3323, 300, 20);
  RelationshipId pic2_id =
      document_add_image_path(d, "cpp/examples/samples/17529.jpg");
  CParagraph p4 = section_add_paragraph(s);
  CPicture pic2 = paragraph_add_picture(p4, pic2_id);
  picture_set_size(pic2, 4838, 3323, 300, 20);

  // sect->addParagraph()->addRichText(TEXT3);
  CParagraph p5 = section_add_paragraph(s);
  CRichText t3 = paragraph_add_richtext(p5, TEXT3);

  // doc.saveAs("out/cpp_picture.docx");
  document_saveas(d, "out/c_picture.docx");

  // clean up
  richtext_destroy(t1);
  richtext_destroy(t2);
  richtext_destroy(t3);
  picture_destroy(pic1);
  picture_destroy(pic2);
  paragraph_destroy(p1);
  paragraph_destroy(p2);
  paragraph_destroy(p3);
  paragraph_destroy(p4);
  paragraph_destroy(p5);
  section_destroy(s);
  document_destroy(d);
}
