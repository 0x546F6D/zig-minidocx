pub fn main() !void {
    defer _ = dbga.deinit();
    // defer alloc.free(xlsx_path);

    // CDocument d = document_create();
    const doc = try docz.initDocument();
    defer doc.deinit();

    // CSection s = document_add_section(d);
    const section = try doc.addSection();
    defer section.deinit();

    // CParaStyle parastyle = parastyle_create();
    const parastyle = docz.initParagraphStyle();
    defer parastyle.deinit();

    // parastyle_set_name(parastyle, "My Heading 1");
    // parastyle_set_align(parastyle, Centered);
    // parastyle_set_outlinelevel(parastyle, OutlineLevel1);
    // parastyle_set_fontsize(parastyle, 32);
    // parastyle_set_color(parastyle, "FF0000");
    // document_add_parastyle(d, parastyle);
    parastyle.setName("My Heading 1");
    parastyle.setAlign(.centered);
    parastyle.setOutlineLevel(.level1);
    parastyle.setFontSize(32);
    parastyle.setColor("FF0000");
    try doc.addParagraphStyle(parastyle);

    // parastyle_set_name(parastyle, "My Heading 2");
    // parastyle_set_outlinelevel(parastyle, OutlineLevel2);
    // parastyle_set_fontsize(parastyle, 28);
    // parastyle_set_color(parastyle, "0000FF");
    // document_add_parastyle(d, parastyle);
    parastyle.setName("My Heading 2");
    parastyle.setOutlineLevel(.level2);
    parastyle.setFontSize(28);
    parastyle.setColor("0000FF");
    try doc.addParagraphStyle(parastyle);

    // CParagraph p1 = section_add_paragraph(s);
    // paragraph_set_style(p1, "My Heading 1");
    // CRichText t1 = paragraph_add_richtext(p1, "Quick Start");
    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    paragraph1.setStyle("My Heading 1");
    const richtext1 = try paragraph1.addRichText("Quick Start");
    defer richtext1.deinit();

    // CParagraph p2 = section_add_paragraph(s);
    // paragraph_set_style(p2, "My Heading 2");
    // CRichText t2 = paragraph_add_richtext(p2, "Download and Installation");
    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();
    paragraph2.setStyle("My Heading 2");
    const richtext2 = try paragraph2.addRichText("Download and Installation");
    defer richtext2.deinit();

    // document_saveas(d, "out/c_style.docx");
    try doc.saveAs("out/zig_style.docx");
}

const std = @import("std");
var dbga: @import("std").heap.DebugAllocator(.{}) = .init;
const alloc = dbga.allocator();
const docz = @import("minidocx");
