#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "typedefs.h"
#include "vec.h"
#include "color.h"
#include "ansi.h"
#include "ray.h"

namespace global {
        static const char *file_path = "image.ppm";

        constexpr double aspect_ratio = 16.0 / 9.0;
        constexpr int image_width = 1280;
        constexpr int image_height = image_width / aspect_ratio;

        constexpr double viewport_height = 2.0;
        constexpr double viewport_width = viewport_height * ((double) image_width / image_width);
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

color ray_color(const Ray& r)
{
        vec3 dir = r.direction().norm();

        double a = 0.5*(dir.y + 1.0);

        // Basic lerp
        color result = (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);

        return result;
}

void render(FILE *f)
{
        double focal_length = 1.0;
        vec3 camera_center = vec3(0.0, 0.0, 0.0);

        vec3 viewport_u = vec3(global::viewport_width, 0, 0);
        vec3 viewport_v = vec3(0, -global::viewport_height, 0);
        vec3 pixel_delta_u = viewport_u / global::image_width;
        vec3 pixel_delta_v = viewport_v / global::image_height;

        vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
        vec3 pixel_00 = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

        // Header
        fprintf(f, "P3\n%d %d\n255\n", global::image_width, global::image_height);

        for (int y = 0; y < global::image_height; y++)
        {
                fprintf(stdout, "\rScanlines remaining: %d ", global::image_height - y);
                fflush(stdout);
                for (int x = 0; x < global::image_width; x++)
                {
                        vec3 pixel_center = pixel_00 + (x*pixel_delta_u) + (y*pixel_delta_v);
                        vec3 ray_direction = pixel_center - camera_center;
                        Ray ray(camera_center, ray_direction);

                        color pixel_color = ray_color(ray);
                        write_color(f, pixel_color);
                }
        }
        fprintf(stdout, "\r" GREEN "Done.                  \n" RESET);
}

int main()
{
        FILE *f = read_entire_file(global::file_path);

        render(f);

        fclose(f);
        return 0;
}
