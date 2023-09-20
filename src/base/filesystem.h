#ifndef BASE_FILESYSTEM_H
#define BASE_FILESYSTEM_H

#include "base.h"
#include "memory.h"
#include "string.h"

// read entire file
String filesystem_read_file(Arena* arena, String path);

// write content to file
void filesystem_write_file(String path, String content);

// append content to file
void filesystem_append_file(String path, String content);

#endif // !BASE_FILESYSTEM_H
