const TEXT1 = "In China, the spring festival marks the beginning of the new year. It falls on the first day of the first month of the Chinese calendar and involves a variety of social practices to usher in the new year, pray for good fortune, celebrate family reunions and promote community harmony. This process of celebration is known as ‘guonian’ (crossing the year).";

const TEXT2 = "In the days preceding the festival, people clean their homes, stock provisions and prepare food. On New Year’s Eve, families dine together and stay up late to welcome the new year. During the festival, people wear new clothes, make offerings to heaven, earth and ancestors, and extend greetings to elders, relatives, friends and neighbours. Public festivities are held by communities, cultural institutions, social groups and art troupes.";

const TEXT3 = "The spring festival promotes family values, social cohesion and peace while providing a sense of identity and continuity for the Chinese people.";

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
    // CRichText t1 = paragraph_add_richtext(p1, TEXT1);
    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    const richtext1 = try paragraph1.addRichText(TEXT1);
    defer richtext1.deinit();

    // RelationshipId pic1_id =
    //     document_add_image_path(d, "cpp/examples/samples/17528.jpg");
    // CParagraph p2 = section_add_paragraph(s);
    // CPicture pic1 = paragraph_add_picture(p2, pic1_id);
    // picture_set_size(pic1, 4725, 3173, 300, 20);
    const pic1_id = try doc.addImagePath("cpp/examples/samples/17528.jpg");
    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();
    const pic1 = try paragraph2.addPicture(pic1_id);
    defer pic1.deinit();
    pic1.setSize(4725, 3173, 300, 20);

    // CParagraph p3 = section_add_paragraph(s);
    // CRichText t2 = paragraph_add_richtext(p3, TEXT2);
    const paragraph3 = try section.addParagraph();
    defer paragraph3.deinit();
    const richtext2 = try paragraph3.addRichText(TEXT2);
    defer richtext2.deinit();

    // RelationshipId pic2_id =
    //     document_add_image_path(d, "cpp/examples/samples/17529.jpg");
    // CParagraph p4 = section_add_paragraph(s);
    // CPicture pic2 = paragraph_add_picture(p4, pic2_id);
    // picture_set_size(pic2, 4838, 3323, 300, 20);
    const pic2_id = try doc.addImagePath("cpp/examples/samples/17529.jpg");
    const paragraph4 = try section.addParagraph();
    defer paragraph4.deinit();
    const pic2 = try paragraph4.addPicture(pic2_id);
    defer pic2.deinit();
    pic2.setSize(4838, 3323, 300, 20);

    // CParagraph p5 = section_add_paragraph(s);
    // CRichText t3 = paragraph_add_richtext(p5, TEXT3);
    const paragraph5 = try section.addParagraph();
    defer paragraph5.deinit();
    const richtext3 = try paragraph5.addRichText(TEXT3);
    defer richtext3.deinit();

    // document_saveas(d, "out/c_picture.docx");
    try doc.saveAs("out/zig_picture.docx");
}

const std = @import("std");
var dbga: @import("std").heap.DebugAllocator(.{}) = .init;
const alloc = dbga.allocator();
const docz = @import("minidocx");
