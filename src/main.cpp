#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "typedefs.h"
#include "vec.h"
#include "color.h"
#include "ansi.h"

#define IMAGE_WIDTH  512
#define IMAGE_HEIGHT 512
static const char *file_path = "image.ppm";

FILE *read_entire_file(const char *file_path)
{
        FILE *f = fopen(file_path, "wb");
        if (!f)
        {
                fprintf(stderr, "ERROR: Could not open `%s`:%s\n", file_path, strerror(errno));
                exit(-1);
        }

        return f;
}

int main()
{
        FILE *f = read_entire_file(file_path);
        
        // Header
        fprintf(f, "P3\n" STR(IMAGE_WIDTH) " " STR(IMAGE_HEIGHT) "\n255\n");

        for (int y = 0; y < IMAGE_HEIGHT; y++)
        {
                fprintf(stdout, "\rScanlines remaining: %d ", IMAGE_HEIGHT - y);
                fflush(stdout);
                for (int x = 0; x < IMAGE_WIDTH; x++)
                {
                        double r = (double) x / (IMAGE_WIDTH-1);
                        double g = 0.0;
                        double b = (double) y / (IMAGE_HEIGHT-1);
                        color pixel_color = color(r, g, b);

                        write_color(f, pixel_color);
                }
        }

        fprintf(stdout, "\r" GREEN "Done.                  \n" RESET);
        fclose(f);
        return 0;
}
