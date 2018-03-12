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
  d_normal = u.cross(v);
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