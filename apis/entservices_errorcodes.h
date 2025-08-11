#include <stdio.h>

// 1. The single source of truth: a list of all errors.
#define ERROR_LIST \
    X(FILE_IO, "File Read or Write error") \
    X(PERMISSION_DENIED, "Permission denied") \

// 2. Define the 'X' macro to generate the enum.
#define X(name, string) ERROR_##name,
typedef enum {
    // Start the first error code at 1000
    ERROR_BASE = 1000,
    ERROR_LIST,
    MAX_ERROR_CODE
} ErrorCode;
// Undefine 'X' to avoid conflicts.
#undef X

// 3. Define the 'X' macro to generate the string array.
#define X(name, string) string,
const char *error_strings[] = {
    "Error base",
    ERROR_LIST,
    "Unknown error code"
};
