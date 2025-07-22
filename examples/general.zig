pub fn main() !void {
    defer _ = dbga.deinit();
    // defer alloc.free(xlsx_path);

    // CDocument d = document_create();
    const doc = try docz.initDocument();
    // document_destroy(d);
    defer doc.deinit();

    // CSection s = document_add_section(d);
    // section_set_landscape(s, 1);
    const section = try doc.addSection();
    defer section.deinit();
    section.setLandscape(true);

    // CParagraph p1 = section_add_paragraph(s);
    // paragraph_set_align(p1, Centered);
    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    paragraph1.setAlign(.centered);

    // CRichText t1 = paragraph_add_richtext(p1, "Happy Chinese New Year!");
    // richtext_set_font_size(t1, 32);
    // richtext_set_color(t1, "ff0000");
    const richtext1 = try paragraph1.addRichText("Happy Chinese New Year!");
    defer richtext1.deinit();
    richtext1.setFontSize(32);
    richtext1.setColor("FF0000");

    // CParagraph p2 = section_add_paragraph(s);
    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();

    // CRichText t2 = paragraph_add_richtext(
    //     p2, "Spring Festival, known as the Chinese New Year, "
    //         "is the most important festival celebrated by the Chinese people. "
    //         "UNESCO inscribed Spring Festival on the Representative List of "
    //         "the Intangible Cultural Heritage of Humanity in 2024.");
    const richtext2 = try paragraph2.addRichText("Spring Festival, known as the Chinese New Year, is the most important festival celebrated by the Chinese people. UNESCO inscribed Spring Festival on the Representative List of the Intangible Cultural Heritage of Humanity in 2024.");
    defer richtext2.deinit();

    // CParagraph p3 = section_add_paragraph(s);
    // paragraph_set_align(p3, Centered);
    const paragraph3 = try section.addParagraph();
    defer paragraph3.deinit();
    paragraph3.setAlign(.centered);

    // CRelationshipId pic_id =
    //     document_add_image_path(d, "cpp/examples/samples/17533.jpg");
    // CPicture pic = paragraph_add_picture(p3, pic_id);
    // picture_set_size(pic, 4643, 6199, 300, 20);
    const id = try doc.addImagePath("cpp/examples/samples/17533.jpg");
    defer id.deinit();
    const picture = try paragraph3.addPicture(id);
    defer picture.deinit();
    picture.setSize(4643, 6199, 300, 20);

    // CPackageProperties prop = {
    //     .title = "Chinese New Year",
    //     .author = "Quinn",
    //     .lastModifiedBy = "John",
    // };
    // document_set_properties(d, &prop);
    const prop = docz.PackageProperties{
        .title = "Chinese New Year",
        .author = "Quinn",
        .lastModifiedBy = "John",
    };
    doc.setProperties(prop);

    // document_saveas(d, "out/c_general.docx");
    // // document_saveas(d, "dir_that_does_not_exit/c_general.docx");
    // if (document_has_error(d)) {
    //   const char *err = document_get_error(d);
    //   printf("error code %d: %s\n", document_has_error(d), err);
    // }
    try doc.saveAs("out/zig_general.docx");
    // doc.saveAs("qweqwe/zig_general.docx") catch {
    //     std.debug.print("doc error: {s}", .{doc.getStrError().?});
    // };
}

const std = @import("std");
var dbga: @import("std").heap.DebugAllocator(.{}) = .init;
const alloc = dbga.allocator();
const docz = @import("minidocx");
