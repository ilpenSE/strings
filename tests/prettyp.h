#ifndef PRETTY_PRINT_H
#define PRETTY_PRINT_H

#include <stdio.h>
#include "../str.h"
#include "../vector.h"

#define COLOR_RED     "\033[0;31m"
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[0;33m"
#define COLOR_BLUE    "\033[0;36m"
#define COLOR_RESET   "\033[0;0m"

#define pprint(fmt, ...) do {                             \
    printf(COLOR_BLUE "%s:%d: " COLOR_RESET               \
           fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);  \
  } while (0)

#define pperror(fmt, ...) do {                                          \
    fprintf(stderr, COLOR_RED "[ERROR]" COLOR_BLUE "%s:%d: " COLOR_RESET \
            fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__);               \
  } while (0)

#define print_str(s) do {                       \
    pprint("data: \"%s\"", (s)->data);          \
    pprint("count: %zu", (s)->len);             \
    pprint("capacity: %zu", (s)->cap);          \
    printf("==================\n");             \
  } while(0)

#define print_sv(sv) do {                       \
    pprint("[SV] data: \"" sv_fmt "\"", sv_arg(sv));    \
    pprint("[SV] count: %zu", (sv)->len);       \
    printf("==================\n");             \
  } while(0)

void print_vector(Vector* v) {
  size_t len = v->len;
  pprint("Vector items = [");
  if (v->items) {
    for (size_t i = 0; i < len; i++) {
      StringView sv = vec_get_as(v, i, StringView);
      pprint("\"" sv_fmt "\"%s", sv_arg(&sv), (i == len - 1 ? "" : ", "));
    }
  }
  pprint("]");
  pprint("Vector capacity: %zu", v->cap);
  pprint("Vector length: %zu", v->len);
}

#endif // PRETTY_PRINT_H
