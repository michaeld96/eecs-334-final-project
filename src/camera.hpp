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
    vec3 u, v, w;
    double lens_radius;


    public:
    camera(
        point3 look_from, 
        point3 look_at, 
        vec3 v_up, 
        double vertical_field_of_view,
        double aspect_ratio,
        double aperture,
        double focus_distance
        )
    {
        auto theta = degrees_to_radians(vertical_field_of_view);
        auto height = tan(theta / 2);
        auto view_port_height = 2.0 * height;
        auto view_port_width = aspect_ratio * view_port_height;
        
        w = unit_vector(look_from - look_at);
        u = unit_vector(cross(v_up, w));
        v = cross(w,u);

        origin = look_from;
        horizontal = focus_distance * view_port_width * u;
        vertical = focus_distance * view_port_height * v;
        lower_left_corner = origin - horizontal/2 - vertical/2 - focus_distance * w;

        lens_radius = aperture / 2;
    }

    ray get_ray(double s, double t) const
    {            
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = u * rd.x() + v * rd.y();

        return ray( origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset);
    }
};

#endif  // CAMERA_H