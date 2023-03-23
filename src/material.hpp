#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "common.hpp"
// #include "hittable.hpp"
// #include "ray.hpp"

struct hit_record;

class material
{
    public: 
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const = 0;

    virtual ~material() = default;
};

class lambertian : public material 
{
    public:
    color albedo;


    public:
    lambertian(const color& a) : albedo(a) {}
    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override
    {
        auto scatter_direction = rec.normal + random_unit_vector();
        // catch degenrate scatter direction.
        if (scatter_direction.near_zero())
        {
            scatter_direction = rec.normal;
        }

        scattered = ray(rec.p, scatter_direction);
        attenuation = albedo;
        return true;
    }
};

class metal : public material
{
    public:
    color albedo;
    public:
    metal(const color& a) : albedo(a) {}

    virtual bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const override
    {
        vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
        scattered = ray(rec.p, reflected);
        attenuation = albedo;
        return (dot(scattered.direction(), rec.normal) > 0);
    }

};

#endif 