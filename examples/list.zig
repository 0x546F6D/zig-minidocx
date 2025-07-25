pub fn main() !void {
    defer _ = dbga.deinit();
    // defer alloc.free(xlsx_path);

    // CDocument d = document_create();
    const doc = try docz.initDocument();
    defer doc.deinit();

    // const NumberingId numId1 = document_add_bulleted_list_definition(d);
    // const NumberingId numId2 = document_add_numbered_list_definition(d);
    const numId1 = try doc.addBulletedListDefinition();
    const numId2 = try doc.addNumberedListDefinition();

    // CSection s = document_add_section(d);
    const section = try doc.addSection();
    defer section.deinit();

    // CParagraph p0 = section_add_paragraph(s);
    // CRichText t0 = paragraph_add_richtext(p0, "Example 1:");
    const paragraph0 = try section.addParagraph();
    defer paragraph0.deinit();
    const richtext0 = try paragraph0.addRichText("Example 1:");
    defer richtext0.deinit();

    // CParagraph p1 = section_add_paragraph(s);
    // paragraph_set_numid(p1, numId1);
    // CRichText t1 = paragraph_add_richtext(p1, "Level one");
    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    paragraph1.setNumid(numId1);
    const richtext1 = try paragraph1.addRichText("Level one");
    defer richtext1.deinit();

    // CParagraph p2 = section_add_paragraph(s);
    // paragraph_set_numid(p2, numId1);
    // paragraph_set_level(p2, NumLevel2);
    // CRichText t2 = paragraph_add_richtext(p2, "Level two");
    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();
    paragraph2.setNumid(numId1);
    paragraph2.setLevel(.level2);
    const richtext2 = try paragraph2.addRichText("Level two");
    defer richtext2.deinit();

    // CParagraph p3 = section_add_paragraph(s);
    // CRichText t3 = paragraph_add_richtext(p3, "Level three");
    // paragraph_set_numid(p3, numId1);
    // paragraph_set_level(p3, NumLevel3);
    const paragraph3 = try section.addParagraph();
    defer paragraph3.deinit();
    paragraph3.setNumid(numId1);
    paragraph3.setLevel(.level3);
    const richtext3 = try paragraph3.addRichText("Level three");
    defer richtext3.deinit();

    // CParagraph p00 = section_add_paragraph(s);
    // CRichText t00 = paragraph_add_richtext(p00, "Example 2:");
    const paragraph00 = try section.addParagraph();
    defer paragraph00.deinit();
    const richtext00 = try paragraph00.addRichText("Example 2:");
    defer richtext00.deinit();

    // CParagraph p4 = section_add_paragraph(s);
    // CRichText t4 = paragraph_add_richtext(p4, "Level one");
    // paragraph_set_numid(p4, numId2);
    const paragraph4 = try section.addParagraph();
    defer paragraph4.deinit();
    paragraph4.setNumid(numId2);
    const richtext4 = try paragraph4.addRichText("Level one");
    defer richtext4.deinit();

    // CParagraph p5 = section_add_paragraph(s);
    // CRichText t5 = paragraph_add_richtext(p5, "Level two");
    // paragraph_set_numid(p5, numId1);
    // paragraph_set_level(p5, NumLevel2);
    const paragraph5 = try section.addParagraph();
    defer paragraph5.deinit();
    paragraph5.setNumid(numId2);
    paragraph5.setLevel(.level2);
    const richtext5 = try paragraph5.addRichText("Level two");
    defer richtext5.deinit();

    // CParagraph p6 = section_add_paragraph(s);
    // CRichText t6 = paragraph_add_richtext(p6, "Level three");
    // paragraph_set_numid(p6, numId1);
    // paragraph_set_level(p6, NumLevel3);
    const paragraph6 = try section.addParagraph();
    defer paragraph6.deinit();
    paragraph6.setNumid(numId2);
    paragraph6.setLevel(.level3);
    const richtext6 = try paragraph6.addRichText("Level three");
    defer richtext6.deinit();

    // document_saveas(d, "out/c_list.docx");
    try doc.saveAs("out/zig_list.docx");
}

const std = @import("std");
var dbga: @import("std").heap.DebugAllocator(.{}) = .init;
const alloc = dbga.allocator();
const docz = @import("minidocx");
