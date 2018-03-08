#include "plane.h"

#include <cmath>

Hit Plane::intersect(Ray const &ray)
{
    /* Your intersect calculation goes here */

    double denum = std::abs(d_normal.dot(ray.D));
    double t = (d_loc0 - ray.O).dot(d_normal);

    if (denum < 0.0001 || t < 0) // something something floating point inaccuracy
        return Hit::NO_HIT();
    else 
        t /= denum;
    

    Vector N = d_normal;

    return Hit(t, N);
}

Plane::Plane(Point point0, Point point1, Point point2)
:
    d_loc0(point0)
{
  Vector v = point1 - point0;
  Vector u = point2 - point0;
  d_normal.x = (v.y * u.z) - (v.z * u.y);
  d_normal.y = (v.z * u.x) - (v.x * u.z);
  d_normal.x = (v.x * u.y) - (v.y * u.x);
}

Plane::Plane(Point point0, Vector normal)
:
    d_loc0(point0),
    d_normal(normal)
{}

Vector Plane::getTextureCoord(Point hit)
{
    return Vector(0, 0, 0);
}