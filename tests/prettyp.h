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

void print_sv_vector(Vector(StringView)* v) {
  size_t len = vec_len(v);
  printf("{items: [");
  if (v->items) {
    vec_foreach(v, it) {
      bool is_last = sv_equals(it, &vec_last(v));
      printf("\"" sv_fmt "\"%s", sv_arg(it), (is_last ? "" : ", "));
    }
  }
  printf("], ");
  printf("length: %zu}\n", len);
}

#endif // PRETTY_PRINT_H
