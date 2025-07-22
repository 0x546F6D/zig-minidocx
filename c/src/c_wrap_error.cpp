#include "c_wrap_error.h"

// CError functions
CErrorProperties *_init_cerror() {
  return new CErrorProperties{
      .type = NoError,
      .message = nullptr,
  };
}

CErrorProperties *_pass_down_cerror(CErrorProperties *parent_err) {
  return new CErrorProperties{
      .type = parent_err->type,
      .message = "Error inherited from parent object",
  };
}

void _check_exception(CErrorProperties *err, Exception ex) {
  err->message = ex.what();

  if (typeid(ex) == typeid(unsupported_feature)) {
    err->type = UnsupportedFeatureError;
  } else if (typeid(ex) == typeid(invalid_parameter)) {
    err->type = InvalidParameterError;
  } else if (typeid(ex) == typeid(invalid_operation)) {
    err->type = InvalidOperationError;
  } else if (typeid(ex) == typeid(io_error)) {
    err->type = IoError;
  } else {
    err->type = RunTimeError;
  }
}

CErrorProperties *_init_cerror_from_exception(Exception ex) {
  CErrorProperties *err = new CErrorProperties{};
  _check_exception(err, ex);
  return err;
}

void _clear_error(CErrorProperties *self) {
  self->type = NoError;
  self->message = nullptr;
}
