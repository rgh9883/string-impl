#include <stdio.h>

#include "string.h"


int main() {
  String* str = string_create();
  char_append(str, "Hello World");
  printf("%s\n", str->data);
  
  String* str2 = string_create();
  char_append(str2, "!");
  string_append(str, str2);
  printf("%s\n", str->data);
  
  char_insert(str, "NOT", 0);
  printf("%s\n", str->data);

  string_insert(str, str2, 3);
  printf("%s\n", str->data);

  string_free(str);
  string_free(str2);
  return 1;
}
