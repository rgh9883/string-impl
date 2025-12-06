#include <stdlib.h>
#include <stdio.h>

#include "string.h"


String* string_create() {
  String* new_str = (String*) malloc(sizeof(String));
  new_str->data = (char*) malloc(sizeof(char));
  new_str->data[0] = '\0';
  new_str->len = 0;

  return new_str;
}

void char_append(String* str, char* add_char) {
  size_t add_len = 0;
  while(add_char[add_len] != '\0') {
    add_len++;
  }

  size_t len = str->len;
  str->data = (char*) realloc(str->data, (len + add_len + 1) * sizeof(char));
  for(int i = 0; i <= add_len; i++) {
    str->data[len+i] = add_char[i];
  }

  str->len = len + add_len;
}

void string_free(String* str) {
  free(str->data);
  free(str);
}
