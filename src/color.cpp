#include <stdio.h>
#include <string.h>

#include "typedefs.h"
#include "color.h"

void write_color(FILE *f, const color& pixel)
{
        double r = pixel.x;
        double g = pixel.y;
        double b = pixel.z;

        u8 rbyte = (u8) 255.999*r;
        u8 gbyte = (u8) 255.999*g;
        u8 bbyte = (u8) 255.999*b;

        char buffer[12] = {0};
        sprintf(buffer, "%d %d %d\n", rbyte, gbyte, bbyte);
        fwrite(buffer, 1, strlen(buffer), f);
}
