# Minidocx packaged for the Zig build system

This is a fork of [minidocx](https://github.com/totravel/minidocx), packaged for Zig. Unnecessary files have been deleted, and the build system has been replaced with build.zig.

## Documentation

- [User Guide](./guide.md)

## Example

Sample code from general.zig to generate Word document.

```zig
pub fn main() !void {
    const doc = try docz.initDocument();
    defer doc.deinit();

    const section = try doc.addSection();
    defer section.deinit();
    section.setLandscape(true);

    const paragraph1 = try section.addParagraph();
    defer paragraph1.deinit();
    paragraph1.setAlign(.centered);

    const richtext1 = try paragraph1.addRichText("Happy Chinese New Year!");
    defer richtext1.deinit();
    richtext1.setFontSize(32);
    richtext1.setColor("FF0000");

    const paragraph2 = try section.addParagraph();
    defer paragraph2.deinit();

    const richtext2 = try paragraph2.addRichText("Spring Festival, known as the Chinese New Year, is the most important festival celebrated by the Chinese people. UNESCO inscribed Spring Festival on the Representative List of the Intangible Cultural Heritage of Humanity in 2024.");
    defer richtext2.deinit();

    const paragraph3 = try section.addParagraph();
    defer paragraph3.deinit();
    paragraph3.setAlign(.centered);

    const pic_id = try doc.addImagePath("cpp/examples/samples/17533.jpg");
    const picture = try paragraph3.addPicture(pic_id);
    defer picture.deinit();
    picture.setSize(4643, 6199, 300, 20);

    const prop = docz.PackageProperties{
        .title = "Chinese New Year",
        .author = "Quinn",
        .lastModifiedBy = "John",
    };
    doc.setProperties(prop);

    try doc.saveAs("document.docx");
}

const std = @import("std");
const docz = @import("minidocx");
```
