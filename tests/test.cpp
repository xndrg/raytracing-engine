#include <iostream>
#include "vec.h"

void test_vec2()
{
        vec2 a = vec2(1, 2);
        vec2 b = vec2(3, 4);

        vec2 add = a + b;
        assert(add.x == 4 && add.y == 6);
        UNUSED(add);
        
        vec2 sub = a - b;
        assert(sub.x == -2 && sub.y == -2);
        UNUSED(sub);
        
        vec2 mul = a * b;
        assert(mul.x == 3 && mul.y == 8);
        UNUSED(mul);
        
        vec2 div = a / b;
        assert((div.x == 1.0/3) && (div.y == 2.0/4));
        UNUSED(div);

        vec2 neg = -a;
        assert(neg.x == -1 && neg.y == -2);
        UNUSED(neg);

        vec2 divs = a / 2;
        assert(divs.x == 1.0/2 && divs.y == 1.0);
        UNUSED(divs);

        vec2 scale1 = a * 3;
        assert(scale1.x == 3 && scale1.y == 6);
        UNUSED(scale1);

        vec2 scale2 = 3 * a;
        assert(scale2.x == 3 && scale2.y == 6);
        UNUSED(scale2);

        double dot_product = dot(a, b);
        assert(dot_product == 11.0);
        UNUSED(dot_product);
        
        std::cout << ("Testing vector a(1, 2):") << std::endl;
        std::cout << "a" << a << std::endl;
}

void test_vec3()
{
        vec3 a = vec3(1, 2, 3);
        vec3 b = vec3(4, 5, 6);

        vec3 add = a + b;
        assert(add.x == 5 && add.y == 7 && add.z == 9);
        UNUSED(add);
        
        vec3 sub = a - b;
        assert(sub.x == -3 && sub.y == -3 && sub.z == -3);
        UNUSED(sub);
        
        vec3 mul = a * b;
        assert(mul.x == 4 && mul.y == 10 && mul.z == 18);
        UNUSED(mul);
        
        vec3 div = a / b;
        assert((div.x == 1.0/4) && (div.y == 2.0/5) && (div.z == 3.0/6));
        UNUSED(div);

        vec3 neg = -a;
        assert(neg.x == -1 && neg.y == -2 && neg.z == -3);
        UNUSED(neg);

        vec3 divs = a / 2;
        assert(divs.x == 1.0/2 && divs.y == 1.0 && divs.z == 1.5);
        UNUSED(divs);

        vec3 scale1 = a * 3;
        assert(scale1.x == 3 && scale1.y == 6 && scale1.z == 9);
        UNUSED(scale1);

        vec3 scale2 = 3 * a;
        assert(scale1.x == 3 && scale1.y == 6 && scale1.z == 9);
        UNUSED(scale2);

        double dot_product = dot(a, b);
        assert(dot_product == 32.0);
        UNUSED(dot_product);

        vec3 cross_product = cross(a, b);
        assert(cross_product.x == -3 && cross_product.y == 6 && cross_product.z == -3);
        
        std::cout << ("Testing vector a(1, 2, 3):") << std::endl;
        std::cout << "a" << a << std::endl;
}
