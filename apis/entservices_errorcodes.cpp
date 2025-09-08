#include "entservices_errorcodes.h"

#define X(name, string) string,
const char* const error_strings[] = {
    "Error base",
    ERROR_LIST
    "Unknown error code"
};
