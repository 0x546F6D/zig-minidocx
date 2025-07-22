#include "c_wrap_relationshipid.h"

int relationshipid_has_error(CRelationshipId self) {
  return self->err->type;
}
const char *relationshipid_get_error(CRelationshipId self) {
  return self->err->message;
}
void relationshipid_clear_error(CRelationshipId self) {
  _clear_error(self->err);
}
