pub const ErrorTypes = enum(c_int) {
    no_error = c.NoError,
    unsupported_feature = c.UnsupportedFeatureError,
    invalid_parameter = c.InvalidParameterError,
    invalid_operation = c.InvalidOperationError,
    io = c.IoError,
    runtime = c.RunTimeError,
    _,
};

pub const DocxError = error{
    UnsupportedFeature,
    InvalidParameter,
    InvalidOperation,
    Io,
    RunTime,
    Unknown,
};

pub inline fn checkResult(error_code: c_int) DocxError!void {
    const result: ErrorTypes = @enumFromInt(error_code);
    if (result == .no_error) return;
    return switch (result) {
        .unsupported_feature => DocxError.UnsupportedFeature,
        .invalid_parameter => DocxError.InvalidParameter,
        .invalid_operation => DocxError.InvalidOperation,
        .io => DocxError.Io,
        .runtime => DocxError.RunTime,
        else => DocxError.Unknown,
    };
}

const c = @import("minidocx_c");
//   CellPointer Table::cellAt(const size_t row, const size_t col) const
//   CellPointer Table::merge(const Rect expected)
//
//   void Package::readContentTypes()
//   void Package::readRelationships(const PartName& name, Relationships& rels)
//
//   RelationshipId Document::addImage(const FileName& filename)
//
//   void readFile(Buffer& buf, const FileName& filename)
//   void writeFile(const Buffer& buf, const FileName& filename)
//
// void Zip::open(const std::string &filename, const OpenMode openMode) {
// bool Zip::isZip64() const {
// void Zip::deleteFiles(const std::vector<fs::path> &names) {
// size_t Zip::countEntries() const {
// std::vector<fs::path> Zip::listEntries() {
// bool Zip::hasEntry(const fs::path &name) {
// size_t Zip::entrySize(const fs::path &name) {
// Zip::extractFileToStream(const fs::path &name, std::ostream &dst) {
// void Zip::extractFileToDisk(const fs::path &name, const fs::path &dst) {
// void Zip::addFileFromMem(
// void Zip::addFileFromStream(
// void Zip::addFileFromDisk(const fs::path &name, const fs::path &src) {
// void Zip::addFileFromString(const fs::path &name, const std::string &data) {
