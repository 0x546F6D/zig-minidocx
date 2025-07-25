const TEXT1 = "In China, the spring festival marks the beginning of the new year. It falls on the first day of the first month of the Chinese calendar and involves a variety of social practices to usher in the new year, pray for good fortune, celebrate family reunions and promote community harmony. This process of celebration is known as ‘guonian’ (crossing the year).";
const TEXT2 = "In the days preceding the festival, people clean their homes, stock provisions and prepare food. On New Year’s Eve, families dine together and stay up late to welcome the new year. During the festival, people wear new clothes, make offerings to heaven, earth and ancestors, and extend greetings to elders, relatives, friends and neighbours. Public festivities are held by communities, cultural institutions, social groups and art troupes.";
const TEXT3 = "The spring festival promotes family values, social cohesion and peace while providing a sense of identity and continuity for the Chinese people.";

pub fn main() !void {
    const doc = try docz.initDocument();
    defer doc.deinit();

    const section = try doc.addSection();
    defer section.deinit();

    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    const richtext1 = try paragraph1.addRichText(TEXT1);
    defer richtext1.deinit();

    const pic1_id = try doc.addImagePath("cpp/examples/samples/17528.jpg");
    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();
    const pic1 = try paragraph2.addPicture(pic1_id);
    defer pic1.deinit();
    pic1.setSize(4725, 3173, 300, 20);

    const paragraph3 = try section.addParagraph();
    defer paragraph3.deinit();
    const richtext2 = try paragraph3.addRichText(TEXT2);
    defer richtext2.deinit();

    const pic2_id = try doc.addImagePath("cpp/examples/samples/17529.jpg");
    const paragraph4 = try section.addParagraph();
    defer paragraph4.deinit();
    const pic2 = try paragraph4.addPicture(pic2_id);
    defer pic2.deinit();
    pic2.setSize(4838, 3323, 300, 20);

    const paragraph5 = try section.addParagraph();
    defer paragraph5.deinit();
    const richtext3 = try paragraph5.addRichText(TEXT3);
    defer richtext3.deinit();

    try doc.saveAs("out/zig_picture.docx");
}

const std = @import("std");
const docz = @import("minidocx");
