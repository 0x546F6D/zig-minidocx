#pragma once
#ifndef C_WRAP_COMMON_H
#define C_WRAP_COMMON_H

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
  Single,
  Double,
  Triple,
  Dotted,
  Dashed,
  DotDash,
  Wave,
  DoubleWave,
} CBorderStyle;

#endif // C_WRAP_MINIDOCX_H
