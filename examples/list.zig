pub fn main() !void {
    const doc = try docz.initDocument();
    defer doc.deinit();

    const numId1 = try doc.addBulletedListDefinition();
    const numId2 = try doc.addNumberedListDefinition();

    const section = try doc.addSection();
    defer section.deinit();

    const paragraph0 = try section.addParagraph();
    defer paragraph0.deinit();
    const richtext0 = try paragraph0.addRichText("Example 1:");
    defer richtext0.deinit();

    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    paragraph1.setNumid(numId1);
    const richtext1 = try paragraph1.addRichText("Level one");
    defer richtext1.deinit();

    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();
    paragraph2.setNumid(numId1);
    paragraph2.setLevel(.level2);
    const richtext2 = try paragraph2.addRichText("Level two");
    defer richtext2.deinit();

    const paragraph3 = try section.addParagraph();
    defer paragraph3.deinit();
    paragraph3.setNumid(numId1);
    paragraph3.setLevel(.level3);
    const richtext3 = try paragraph3.addRichText("Level three");
    defer richtext3.deinit();

    const paragraph00 = try section.addParagraph();
    defer paragraph00.deinit();
    const richtext00 = try paragraph00.addRichText("Example 2:");
    defer richtext00.deinit();

    const paragraph4 = try section.addParagraph();
    defer paragraph4.deinit();
    paragraph4.setNumid(numId2);
    const richtext4 = try paragraph4.addRichText("Level one");
    defer richtext4.deinit();

    const paragraph5 = try section.addParagraph();
    defer paragraph5.deinit();
    paragraph5.setNumid(numId2);
    paragraph5.setLevel(.level2);
    const richtext5 = try paragraph5.addRichText("Level two");
    defer richtext5.deinit();

    const paragraph6 = try section.addParagraph();
    defer paragraph6.deinit();
    paragraph6.setNumid(numId2);
    paragraph6.setLevel(.level3);
    const richtext6 = try paragraph6.addRichText("Level three");
    defer richtext6.deinit();

    try doc.saveAs("out/zig_list.docx");
}

const std = @import("std");
const docz = @import("minidocx");
