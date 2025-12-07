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

void string_append(String* str, String* add_str) {
  size_t add_len = add_str->len;

  size_t len = str->len;
  str->data = (char*) realloc(str->data, (len + add_len + 1) * sizeof(char));
  for(int i = 0; i <= add_len; i++) {
    str->data[len+i] = add_str->data[i];
  }

  str->len = len + add_len;
}

void char_insert(String* str, char* ins_char, size_t index) {
  size_t ins_len = 0;
  while(ins_char[ins_len] != '\0') {
    ins_len++;
  }

  size_t len = str->len;
  str->data = (char*) realloc(str->data, (len + ins_len + 1) * sizeof(char));

  size_t i = len;
  while(i >= index) {
    str->data[i+ins_len] = str->data[i];
    if(i == 0) break; // size_t unsigned so 0-1 -> inf
    i--;
  }
  
  for(int j = 0; j < ins_len; j++) {
    str->data[j+index] = ins_char[j];
  }

  str->len = len + ins_len;
}

void string_free(String* str) {
  free(str->data);
  free(str);
}
