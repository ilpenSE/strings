#include <stdio.h>
#include <string.h>
#include "prettyp.h"

int main() {
  String s = str_new("selamlamb");
  const char delim = 'a';

  Vector vec = str_split(&s, delim);
  print_vector(&vec);
  printf("Delimiter char: '%c'\n", delim);
  printf("Original: %s\n", s.data);
  return 0;
}
