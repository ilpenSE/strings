#include <stdio.h>
#include "prettyp.h"

int main() {
  // TRIM
  String s1 = str_new("\t\n  hello!");
  String s2 = str_new(" hello! \r\t\n");
  String s3 = str_new("hello! \n");
  String s4 = str_new("");

  str_trim(&s1);
  str_trim(&s2);
  str_trim(&s3);
  str_trim(&s4);
  
  pprint("\"%s\"", s1.data);
  pprint("\"%s\"", s2.data);
  pprint("\"%s\"", s3.data);
  pprint("\"%s\"", s4.data);
  return 0;
}
