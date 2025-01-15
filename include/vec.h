#ifndef VEC_H_
#define VEC_H_

#include <iostream>

struct vec2
{
        double x;
        double y;

        vec2();
        vec2(double x, double y);
        vec2 operator-() const;
        double length() const;
};

vec2 operator+(const vec2& a, const vec2& b);
vec2 operator-(const vec2& a, const vec2& b);
vec2 operator*(const vec2& a, const vec2& b);
vec2 operator*(const vec2& a, double s);
vec2 operator*(double s, const vec2& a);
vec2 operator/(const vec2& a, const vec2& b);
vec2 operator/(const vec2& a, double s);
std::ostream& operator<<(std::ostream& out, const vec2& a);

double dot(vec2 const& a, vec2 const& b);

struct vec3
{
        double x;
        double y;
        double z;

        vec3();
        vec3(double x, double y, double z);
        vec3 operator-() const;
        double length() const;
};

vec3 operator+(const vec3& a, const vec3& b);
vec3 operator-(const vec3& a, const vec3& b);
vec3 operator*(const vec3& a, const vec3& b);
vec3 operator*(const vec3& a, double s);
vec3 operator*(double s, const vec3& a);
vec3 operator/(const vec3& a, const vec3& b);
vec3 operator/(const vec3& a, double s);
std::ostream& operator<<(std::ostream& out, const vec3& a);

double dot(vec3 const& a, vec3 const& b);
vec3 cross(vec3 const& a, vec3 const& b);

#endif // VEC_H_
