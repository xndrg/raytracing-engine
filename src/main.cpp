#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "typedefs.h"
#include "vec.h"
#include "color.h"
#include "ansi.h"

namespace global {
        static const char *file_path = "image.ppm";
        
        constexpr double aspect_ratio = 16.0 / 9.0;
        constexpr int image_width = 1280;
        constexpr int image_height = image_width / aspect_ratio;

        constexpr double viewport_height = 2.0;
        constexpr double viewport_width = viewport_height * aspect_ratio;
}

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
        FILE *f = read_entire_file(global::file_path);

        // Header
        fprintf(f, "P3\n%d %d\n255\n", global::image_width, global::image_height);

        for (int y = 0; y < global::image_height; y++)
        {
                fprintf(stdout, "\rScanlines remaining: %d ", global::image_height - y);
                fflush(stdout);
                for (int x = 0; x < global::image_width; x++)
                {
                        double r = (double) x / (global::image_width-1);
                        double g = 0.0;
                        double b = (double) y / (global::image_height-1);
                        color pixel_color = color(r, g, b);

                        write_color(f, pixel_color);
                }
        }

        fprintf(stdout, "\r" GREEN "Done.                  \n" RESET);
        fclose(f);
        return 0;
}
