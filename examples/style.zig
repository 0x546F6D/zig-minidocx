pub fn main() !void {
    const doc = try docz.initDocument();
    defer doc.deinit();

    const section = try doc.addSection();
    defer section.deinit();

    const parastyle = docz.initParagraphStyle();
    defer parastyle.deinit();

    parastyle.setName("My Heading 1");
    parastyle.setAlign(.centered);
    parastyle.setOutlineLevel(.level1);
    parastyle.setFontSize(32);
    parastyle.setColor("FF0000");
    try doc.addParagraphStyle(parastyle);

    parastyle.setName("My Heading 2");
    parastyle.setOutlineLevel(.level2);
    parastyle.setFontSize(28);
    parastyle.setColor("0000FF");
    try doc.addParagraphStyle(parastyle);

    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    paragraph1.setStyle("My Heading 1");
    const richtext1 = try paragraph1.addRichText("Quick Start");
    defer richtext1.deinit();

    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();
    paragraph2.setStyle("My Heading 2");
    const richtext2 = try paragraph2.addRichText("Download and Installation");
    defer richtext2.deinit();

    try doc.saveAs("out/zig_style.docx");
}

const std = @import("std");
const docz = @import("minidocx");
