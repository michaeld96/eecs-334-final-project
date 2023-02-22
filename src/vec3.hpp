#ifndef VEC3_HPP
#define VEC_HPP

#include <cmath>
#include <iostream>

class vec3
{
    public:
    // Constructors.
    vec3() : e{0,0,0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // Returning specific coords.
    // Const says we wont modify the state of the object.
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    // Negates all the coordinates of the vector.
    // ex: vec3 v1(1,2,3);
    //     auto v2 = -v1; -> v2 (-1,-2,-3)
    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
    // ex: v1[1] -> 2
    double operator[](int i) const { return e[i]; }
    double& operator[](int i) {return e[i]; }

    // Vector addition.
    vec3& operator+=(const vec3 &v)
    {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    }

    // Scalar mult.
    vec3& operator*=(const double t)
    {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    }

    // Scalar division.
    vec3& operator/=(const double t)
    {
        return *this *= 1/t;
    }
    
    double length() const
    {   
        return sqrt(length_squared());
    }

    double length_squared() const
    {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    }

    public:
    double e[3];
};

// Type aliases for vec3.
// ex: point3 v1(1,2,3) -> makes a vector
// just using a different name.
using point3 = vec3;    // 3D point.
using color = vec3;     // RGB color.

#endif // VEC3_HPP