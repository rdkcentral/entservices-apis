#include "entservices_errorcodes.h"

#define X(name, string) string,
const char *error_strings[] = {
    "Error base",
    ERROR_LIST
    "Unknown error code"
};
