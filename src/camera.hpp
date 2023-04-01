#ifndef CAMERA_H
#define CAMERA_H

#include "common.hpp"

class camera
{
    public: 
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;


    public:
    camera(point3 look_from, point3 look_at, vec3 v_up, double vertical_field_of_view, double aspect_ratio)
    {
        auto theta = degrees_to_radians(vertical_field_of_view);
        auto height = tan(theta / 2);
        auto view_port_height = 2.0 * height;
        auto view_port_width = aspect_ratio * view_port_height;
        
        auto w = unit_vector(look_from - look_at);
        auto u = unit_vector(cross(v_up, w));
        auto v = cross(w,u);

        origin = look_from;
        horizontal = view_port_width * u;
        vertical = view_port_height * v;
        lower_left_corner = origin - horizontal/2 - vertical/2 - w;
    }

    ray get_ray(double s, double t) const
    {
        return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
    }
};

#endif  // CAMERA_H