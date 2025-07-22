#pragma once
#ifndef C_WRAP_ERROR_H
#define C_WRAP_ERROR_H

typedef enum CError {
  NoError,
  UnsupportedFeatureError,
  InvalidParameterError,
  InvalidOperationError,
  IoError,
  RunTimeError,
  UnknownError,
} CError;

typedef struct CErrorProperties {
  CError type;
  const char *message;
} CErrorProperties;

#ifdef __cplusplus
#include "minidocx.hpp"
using namespace md;

CErrorProperties *_init_cerror();
CErrorProperties *_pass_down_cerror(CErrorProperties *parent_err);
void _check_exception(CErrorProperties *err, Exception ex);
CErrorProperties *_init_cerror_from_exception(Exception ex);
void _clear_error(CErrorProperties *self);
#endif // #ifdef __cplusplus

#endif // C_WRAP_ERROR_H
