#include <stdio.h>

#include <librock/librock.h>

int main(int argc, const char *argv[]) {
  fprintf(stdout, "foo\n");
  fprintf(stderr, "bar\n");
  return 0;
}
