// 1. Endianness
#include <stdio.h>
#include <assert.h>

int main() {
  short sh;
  char *ch;
  assert (2 == sizeof(short));
  sh = 0x4321;
  ch = (char *)&sh;
  if (0x43 == *ch) {
    printf("This is a Big-endian processor.\n");
  } else if (0x21 == *ch) {
    printf("This is a Little-endian processor.\n");
  } else {
    printf("This should never be printed.\n");
  }
  return 0;
}
