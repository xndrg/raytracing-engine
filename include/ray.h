#ifndef RAY_H_
#define RAY_H_

#include "vec.h"

class Ray
{
private:
        vec3 m_origin;
        vec3 m_direction;

public:
        Ray(const vec3& origin, const vec3& direction);

        const vec3& origin() const;
        const vec3& direction() const;
        vec3 at(double t) const;
};

#endif // RAY_H_
