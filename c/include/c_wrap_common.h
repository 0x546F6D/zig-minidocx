#pragma once
#ifndef C_WRAP_COMMON_H
#define C_WRAP_COMMON_H

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

typedef struct CPackageProperties {
  char *title;
  char *subject;
  char *author;
  char *company;
  char *lastModifiedBy;
} CPackageProperties;
#endif // C_WRAP_MINIDOCX_H
