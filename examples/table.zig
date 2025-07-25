pub fn main() !void {
    defer _ = dbga.deinit();
    // defer alloc.free(xlsx_path);

    // CDocument d = document_create();
    const doc = try docz.initDocument();
    defer doc.deinit();

    // CSection s = document_add_section(d);
    const section = try doc.addSection();
    defer section.deinit();

    // CParagraph p1 = section_add_paragraph(s);
    // CRichText t1 = paragraph_add_richtext(p1, "Example:");
    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    const richtext1 = try paragraph1.addRichText("Example:");
    defer richtext1.deinit();

    // CTable tbl = section_add_table(s, 5, 7);
    // table_set_widthtype(tbl, TableWidthPercent);
    const table = try section.addTable(5, 7);

    defer table.deinit();
    table.setWidthType(.percent);

    // CCell cell1 = table_cellat(tbl, 0, 0);
    // CParagraph p2 = cell_add_paragraph(cell1);
    // CRichText t2 = paragraph_add_richtext(p2, "AAA");
    const cell1 = try table.cellAt(0, 0);
    const paragraph2 = try cell1.addParagraph();
    defer paragraph2.deinit();
    const richtext2 = try paragraph2.addRichText("AAA");
    defer richtext2.deinit();

    // CCell cell2 = table_merge(tbl, 1, 1, 2, 3);
    // CParagraph p3 = cell_add_paragraph(cell2);
    // CRichText t3 = paragraph_add_richtext(p3, "BBB");
    const cell2 = try table.merge(1, 1, 2, 3);
    const paragraph3 = try cell2.addParagraph();
    defer paragraph3.deinit();
    const richtext3 = try paragraph3.addRichText("BBB");
    defer richtext3.deinit();

    // CCell cell3 = table_merge(tbl, 2, 4, 2, 2);
    // CParagraph p4 = cell_add_paragraph(cell3);
    // CRichText t4 = paragraph_add_richtext(p4, "CCC");
    const cell3 = try table.merge(2, 4, 2, 2);
    const paragraph4 = try cell3.addParagraph();
    defer paragraph4.deinit();
    const richtext4 = try paragraph4.addRichText("CCC");
    defer richtext4.deinit();

    // CCell cell4 = table_merge(tbl, 3, 2, 2, 2);
    // CParagraph p5 = cell_add_paragraph(cell4);
    // CRichText t5 = paragraph_add_richtext(p5, "DDD");
    const cell4 = try table.merge(3, 2, 2, 2);
    const paragraph5 = try cell4.addParagraph();
    defer paragraph5.deinit();
    const richtext5 = try paragraph5.addRichText("DDD");
    defer richtext5.deinit();

    // CCell cell5 = table_merge(tbl, 0, 6, 5, 1);
    // CParagraph p6 = cell_add_paragraph(cell5);
    // CRichText t6 = paragraph_add_richtext(p6, "EEE");
    const cell5 = try table.merge(0, 6, 5, 1);
    const paragraph6 = try cell5.addParagraph();
    defer paragraph6.deinit();
    const richtext6 = try paragraph6.addRichText("EEE");
    defer richtext6.deinit();

    // document_saveas(d, "out/c_table.docx");
    try doc.saveAs("out/zig_table.docx");
}

const std = @import("std");
var dbga: @import("std").heap.DebugAllocator(.{}) = .init;
const alloc = dbga.allocator();
const docz = @import("minidocx");
