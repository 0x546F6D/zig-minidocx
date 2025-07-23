#pragma once
#ifndef C_WRAP_COMMON_H
#define C_WRAP_COMMON_H

#include "c_wrap_error.h"
#include <stddef.h>

typedef size_t RelationshipId;
typedef size_t NumberingId;

typedef enum CNumberingLevel : unsigned int {
  NumLevel1,
  NumLevel2,
  NumLevel3,
  NumLevel4,
  NumLevel5,
  NumLevel6,
  NumLevel7,
  NumLevel8,
  NumLevel9,
} CNumberingLevel;

typedef enum COutlineLevel {
  OutlineLevel1,
  OutlineLevel2,
  OutlineLevel3,
  OutlineLevel4,
  OutlineLevel5,
  OutlineLevel6,
  OutlineLevel7,
  OutlineLevel8,
  OutlineLevel9,
  BodyText,
} COutlineLevel;

typedef struct CPackageProperties {
  const char *title;
  const char *subject;
  const char *author;
  const char *company;
  const char *lastModifiedBy;
} CPackageProperties;

typedef enum CAlignment {
  Left,
  Centered,
  Right,
  Justified,
  Distributed,
} CAlignment;

typedef enum CBorderStyle {
  BorderSingle,
  BorderDouble,
  BorderTriple,
  BorderDotted,
  BorderDashed,
  BorderDotDash,
  BorderWave,
  BorderDoubleWave,
} CBorderStyle;

typedef struct CBorderProperties {
  CBorderStyle style_;
  size_t width_;      // 8 = 1 pt
  const char *color_; // "auto" or "RRGGBB"
} CBorderProperties;
// CBorderProperties CBorderProp = {
//     .style_ = BorderSingle,
//     .width_ = 4,
//     .color_ = "auto",
// };
#endif // C_WRAP_COMMON_H
