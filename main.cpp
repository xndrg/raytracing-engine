#include <cstdio>

#define Q(X) #X
#define STR(X) Q(X)

#define IMAGE_WIDTH  256
#define IMAGE_HEIGHT 256

int main()
{
        printf("P3\n" STR(IMAGE_WIDTH) " " STR(IMAGE_HEIGHT) "\n255\n");

        for (int y = 0; y < IMAGE_HEIGHT; y++)
        {
                for (int x = 0; x < IMAGE_WIDTH; x++)
                {
                        auto r = (double) x / (IMAGE_WIDTH-1);
                        auto g = (double) y / (IMAGE_HEIGHT-1);
                        auto b = 0.0;

                        int ir = (int) 255.999 * r;
                        int ig = (int) 255.999 * g;
                        int ib = (int) 255.999 * b;

                        printf("%d %d %d\n", ir, ig, ib);
                }
        }
}
