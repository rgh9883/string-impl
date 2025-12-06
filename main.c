#include <stdio.h>

#include "string.h"


int main() {
  String* str = string_create();
  char_append(str, "Hello World");

  printf("%s", str->data);

  string_free(str);

  return 1;
}
