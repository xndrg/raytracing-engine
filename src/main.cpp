#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "vec.h"
#include "ansi.h"

#define Q(x) #x
#define STR(x) Q(x)
#define UNUSED(x) (void)x

static const char *file_path = "image.ppm";
#define IMAGE_WIDTH  1000
#define IMAGE_HEIGHT 1000

int main()
{
        FILE *f = fopen(file_path, "wb");
        if (!f)
        {
                fprintf(stderr, "ERROR: Could not open %s:%s\n", file_path, strerror(errno));
                return -1;
        }
        
        // Header
        fprintf(f, "P3\n" STR(IMAGE_WIDTH) " " STR(IMAGE_HEIGHT) "\n255\n");

        for (int y = 0; y < IMAGE_HEIGHT; y++)
        {
                fprintf(stdout, "\rScanlines remaining: %d ", IMAGE_HEIGHT - y);
                fflush(stdout);
                for (int x = 0; x < IMAGE_WIDTH; x++)
                {
                        double r = (double) x / (IMAGE_WIDTH-1);
                        double g = (double) y / (IMAGE_HEIGHT-1);
                        double b = 0.0;

                        int ir = (int) 255.999 * r;
                        int ig = (int) 255.999 * g;
                        int ib = (int) 255.999 * b;

                        fprintf(f, "%d %d %d\n", ir, ig, ib);
                }
        }
        
        fprintf(stdout, "\r" GREEN "Done.                  \n" RESET);
}
