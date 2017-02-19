#include <stdio.h>
#include <stdlib.h>
#include <emscripten.h>
#include <string.h>

EMSCRIPTEN_KEEPALIVE
void print_array(char *ptr, int length) {
  for(int i = 0; i < length; i++) {
    printf("%c", *ptr);
    ptr++;
  }
}