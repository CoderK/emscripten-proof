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

// 1 pixel is rgba 4 bytes
EMSCRIPTEN_KEEPALIVE
void SepiaFilter(
    unsigned char *image_data,
    int image_width,
    int image_height)
{
    unsigned int *px = (unsigned int *) image_data;
    unsigned int *end = px + (image_width * image_height);

    for (; px < end; ++px) {
        unsigned int ir = (*px & 0x00FF0000) >> 16;
        unsigned int ig = (*px & 0x0000FF00) >> 8;
        unsigned int ib = (*px & 0x000000FF);

        unsigned int or = (ir * 402 + ig * 787 + ib * 194) >> 10;
        unsigned int og = (ir * 357 + ig * 702 + ib * 172) >> 10;
        unsigned int ob = (ir * 279 + ig * 547 + ib * 134) >> 10;

        or = or > 255 ? 255 : or;
        og = og > 255 ? 255 : og;
        ob = ob > 255 ? 255 : ob;

        *px = 0xFF000000 | (unsigned int) or << 16 | (unsigned int) og << 8 | (unsigned int) ob;
    }
}