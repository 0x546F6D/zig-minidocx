pub fn main() !void {
    const doc = try docz.initDocument();
    defer doc.deinit();

    const section = try doc.addSection();
    defer section.deinit();

    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    const richtext1 = try paragraph1.addRichText("Example:");
    defer richtext1.deinit();

    const table = try section.addTable(5, 7);
    defer table.deinit();
    table.setWidthType(.percent);

    const cell1 = try table.cellAt(0, 0);
    const paragraph2 = try cell1.addParagraph();
    defer paragraph2.deinit();
    const richtext2 = try paragraph2.addRichText("AAA");
    defer richtext2.deinit();

    const cell2 = try table.merge(1, 1, 2, 3);
    const paragraph3 = try cell2.addParagraph();
    defer paragraph3.deinit();
    const richtext3 = try paragraph3.addRichText("BBB");
    defer richtext3.deinit();

    const cell3 = try table.merge(2, 4, 2, 2);
    const paragraph4 = try cell3.addParagraph();
    defer paragraph4.deinit();
    const richtext4 = try paragraph4.addRichText("CCC");
    defer richtext4.deinit();

    const cell4 = try table.merge(3, 2, 2, 2);
    const paragraph5 = try cell4.addParagraph();
    defer paragraph5.deinit();
    const richtext5 = try paragraph5.addRichText("DDD");
    defer richtext5.deinit();

    const cell5 = try table.merge(0, 6, 5, 1);
    const paragraph6 = try cell5.addParagraph();
    defer paragraph6.deinit();
    const richtext6 = try paragraph6.addRichText("EEE");
    defer richtext6.deinit();

    try doc.saveAs("out/zig_table.docx");
}

const std = @import("std");
const docz = @import("minidocx");
