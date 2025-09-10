#ifndef ENTSERVICES_ERRORCODES_H
#define ENTSERVICES_ERRORCODES_H
#pragma once
#include <stdio.h>

// 1. The single source of truth: a list of all errors.
#define ERROR_LIST \
    X(ERROR_FILE_IO, "File Read or Write error") \
    X(ERROR_INVALID_PARAMETER, "Invalid Parameter") \
    X(ERROR_INVALID_DEVICENAME, "Invalid device name") \
    X(ERROR_INVALID_MOUNTPOINT, "Invalid mount path") \
    X(ERROR_FIRMWAREUPDATE_INPROGRESS, "Firmware update already in progress") \
    X(ERROR_FIRMWAREUPDATE_UPTODATE, "Firmware is already upto date") \

/******** PLEASE DO NOT MODIFY ANYTHING BELOW THIS **********/
// 2. Define the 'X' macro to generate the enum.
#define X(name, string) name,
enum ErrorCodeEnum{
    // Start the first error code at 1000
    ERROR_BASE = 1000,
    ERROR_LIST
    MAX_ERROR_CODE
};
// Undefine 'X' to avoid conflicts.
#undef X

// 3. Define the 'X' macro to generate the string array.
#define X(name, string) string,
const char* const error_strings[] = {
    "Error base",
    ERROR_LIST
    "Unknown error code"
};

//4.Check if Error code is within the entservices error code range.
#define IS_ENTSERVICES_ERRORCODE(errorcode) \
    ((errorcode) >= ERROR_BASE && \
     (errorcode) <  MAX_ERROR_CODE)


//5.Fetch Error strings
#define ERROR_MESSAGE(errorcode) (error_strings[(errorcode) - ERROR_BASE])

#endif //ENTSERVICES_ERRORCODES_H
