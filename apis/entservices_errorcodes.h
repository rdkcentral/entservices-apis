#include <stdio.h>

// 1. The single source of truth: a list of all errors.
#define ERROR_LIST \
    X(ERROR_FILE_IO, "File Read or Write error") \
    X(ERROR_PERMISSION_DENIED, "Permission denied") \

/******** PLEASE DO NOT MODIFY ANYTHING BELOW THIS **********/
// 2. Define the 'X' macro to generate the enum.
#define X(name, string) name,
typedef enum {
    // Start the first error code at 1000
    ERROR_BASE = 1000,
    ERROR_LIST
    MAX_ERROR_CODE
} ErrorCode;
// Undefine 'X' to avoid conflicts.
#undef X

// 3. Define the 'X' macro to generate the string array.
#define X(name, string) string,
const char *error_strings[] = {
    "Error base",
    ERROR_LIST
    "Unknown error code"
};

//4.Fetch Error strings
#define ERROR_MESSAGE(errorcode) \
    ({ \
        const char *msg = \
            (((errorcode) >= ERROR_BASE && \
              (errorcode) < ERROR_BASE + (sizeof(error_strings)/sizeof(error_strings[0]))) \
                ? error_strings[(errorcode) - ERROR_BASE] \
                : Core::ErrorToString(errorcode)); \
        printf("[DEBUG] ErrorCode=%d -> %s\n", errorcode, msg); \
        msg; \
    })

