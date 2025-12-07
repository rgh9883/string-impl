#ifndef STRING_H
#define STRING_H


#include <stddef.h>


typedef struct {
  char* data;
  size_t len;
} String;

String* string_create();
void char_append(String* str, const char* add_char);
void string_append(String* str, String* add_str);
void char_insert(String* str, const char* ins_char, size_t index);
void string_insert(String* str, String* ins_str, size_t index);
void string_delete(String* str, size_t index);
void string_free(String* str);

#endif
