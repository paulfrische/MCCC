#include "filesystem.h"
#include "base.h"
#include "logging.h"
#include "memory.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

// read entire file
String filesystem_read_file(Arena* arena, String path)
{
    Arena* scratch = arena_init_sized(path.len);
    char* cpath = str_to_c_str(scratch, path);
    FILE* file = fopen(cpath, "r");
    if (file == NULL) {
        ERROR("file %s doesn't exits/could'd be opened", cpath);
    }

    // get length of file
    fseek(file, 0, SEEK_END);
    u64 length = ftell(file);
    fseek(file, 0, SEEK_SET);

    String content = str_alloc(arena, length);
    fread(content.str, sizeof(char), length, file);

    fclose(file);
    arena_free(scratch);

    return content;
}

// write content to file
void filesystem_write_file(String path, String content)
{
    Arena* scratch = arena_init_sized(path.len + content.len);
    FILE* file = fopen(str_to_c_str(scratch, path), "w");

    fprintf(file, "%s", str_to_c_str(scratch, content));

    fclose(file);
    arena_free(scratch);
}

// append content to file
void filesystem_append_file(String path, String content)
{
    Arena* scratch = arena_init_sized(path.len + content.len);
    FILE* file = fopen(str_to_c_str(scratch, path), "a");

    fprintf(file, "%s", str_to_c_str(scratch, content));

    fclose(file);
    arena_free(scratch);
}
