
#include "minidocx/minidocx.hpp"
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

    sect->addParagraph()->addRichText("Example:");

    TablePointer tbl = sect->addTable(5, 7);
    tbl->prop_.width_.type_ = TableProperties::WidthType::Percent;

    tbl->cellAt(0, 0)->addParagraph()->addRichText("AAA");

    tbl->merge(1, 1, 2, 3);
    tbl->cellAt(1, 1)->addParagraph()->addRichText("BBB");

    tbl->merge(2, 4, 2, 2);
    tbl->cellAt(2, 4)->addParagraph()->addRichText("CCC");

    tbl->merge(3, 2, 2, 2);
    tbl->cellAt(3, 2)->addParagraph()->addRichText("DDD");

    tbl->merge(0, 6, 5, 1);
    tbl->cellAt(0, 6)->addParagraph()->addRichText("EEE");

    /*tbl->dumpStructure();*/

    doc.saveAs("out/cpp_table.docx");
  } catch (const Exception &ex) {
    std::cerr << ex.what() << std::endl;
  }
  return 0;
}
