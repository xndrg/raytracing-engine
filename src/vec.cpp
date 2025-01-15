#include "vec.h"
#include "math.h"

vec2::vec2()
{
        x = 0.0;
        y = 0.0;
}

vec2::vec2(double x, double y)
{
        this->x = x;
        this->y = y;
}

vec2 vec2::operator-() const
{
        return vec2(-x, -y);
}

double vec2::length() const
{
        return sqrt(x*x + y*y);
}

vec2 operator+(const vec2& a, const vec2& b)
{
        return vec2(a.x + b.x, a.y + b.y);
}

vec2 operator-(const vec2& a, const vec2& b)
{
        return vec2(a.x - b.x, a.y - b.y);
}

vec2 operator*(const vec2& a, const vec2& b)
{
        return vec2(a.x*b.x, a.y*b.y);
}

vec2 operator*(const vec2& a, double s)
{
        return vec2(s*a.x, s*a.y);
}

vec2 operator*(double s, const vec2& a)
{
        return a*s;
}

vec2 operator/(const vec2& a, const vec2& b)
{
        return vec2(a.x/b.x, a.y/b.y);
}

vec2 operator/(const vec2& a, double s)
{
        return vec2(a.x/s, a.y/s);
}

std::ostream& operator<<(std::ostream& out, const vec2& a)
{
        out << "(" << a.x << ", " << a.y << ")\n";
        return out;
}

double dot(vec2 const& a, vec2 const& b)
{
        return a.x*b.x + a.y*b.y;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

vec3::vec3()
{
        x = 0.0;
        y = 0.0;
        z = 0.0;
}

vec3::vec3(double x, double y, double z)
{
        this->x = x;
        this->y = y;
        this->z = z;
}

vec3 vec3::operator-() const
{
        return vec3(-x, -y, -z);
}

double vec3::length() const
{
        return sqrt(x*x + y*y + z*z);
}

vec3 operator+(const vec3& a, const vec3& b)
{
        return vec3(a.x + b.x, a.y + b.y, a.z + b.z);
}

vec3 operator-(const vec3& a, const vec3& b)
{
        return vec3(a.x - b.x, a.y - b.y, a.z - b.z);
}

vec3 operator*(const vec3& a, const vec3& b)
{
        return vec3(a.x*b.x, a.y*b.y, a.z*b.z);
}

vec3 operator*(const vec3& a, double s)
{
        return vec3(s*a.x, s*a.y, s*a.z);
}

vec3 operator*(double s, const vec3& a)
{
        return a*s;
}

vec3 operator/(const vec3& a, const vec3& b)
{
        return vec3(a.x/b.x, a.y/b.y, a.z/b.z);
}

vec3 operator/(const vec3& a, double s)
{
        return vec3(a.x/s, a.y/s, a.z/s);
}

std::ostream& operator<<(std::ostream& out, const vec3& a)
{
        out << "(" << a.x << ", " << a.y << ", " << a.z << ")\n";
        return out;
}

double dot(vec3 const& a, vec3 const& b)
{
        return a.x*b.x + a.y*b.y + a.z*b.z;
}

vec3 cross(vec3 const& a, vec3 const& b)
{
        return vec3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}
