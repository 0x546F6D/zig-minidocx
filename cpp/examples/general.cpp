#include "minidocx/minidocx.hpp"
#include "utils/exceptions.hpp"
#include <iostream>

int main() {
  using namespace md;
  try {
    if (!std::filesystem::exists("out")) {
      std::error_code err;
      if (!std::filesystem::create_directories("out", err)) {
        std::cout << "CreateDirectoryFAILED, err: " << err.message()
                  << std::endl;
        return 0;
      }
    }

    Document doc;
    SectionPointer sect = doc.addSection();
    sect->prop_.landscape_ = true;

    ParagraphPointer para = sect->addParagraph();
    para->prop_.align_ = Alignment::Centered;

    RichTextPointer rich = para->addRichText("Happy Chinese New Year!");
    rich->prop_.fontSize_ = 32;
    rich->prop_.color_ = "FF0000";

    sect->addParagraph()->addRichText(
        "Spring Festival, known as the Chinese New Year, "
        "is the most important festival celebrated by the Chinese people. "
        "UNESCO inscribed Spring Festival on the Representative List of "
        "the Intangible Cultural Heritage of Humanity in 2024.");

    PicturePointer pict =
        sect->addParagraph({.align_ = Alignment::Centered})
            ->addPicture(doc.addImage("cpp/examples/samples/17533.jpg"));
    pict->prop_.extent_.setSize(4643, 6199, 300, 20);

    doc.prop_.title_ = "Chinese New Year";
    doc.prop_.author_ = "Quinn";
    doc.prop_.lastModifiedBy_ = "John";

    doc.saveAs("out/cpp_general.docx");

  } catch (const Exception &e) {
    if (typeid(e) == typeid(invalid_parameter)) {
      std::cerr << "INVALID PARAMETER!" << std::endl;
      // Handle invalid_parameter
    } else if (typeid(e) == typeid(io_error)) {
      std::cerr << "IO ERROR!" << std::endl;
      // Handle unsupported_feature
    } else {
      // Handle generic Exception
    }
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
