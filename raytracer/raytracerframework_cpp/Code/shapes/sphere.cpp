#include "sphere.h"

#include <cmath>

using namespace std;

Hit Sphere::intersect(Ray const &ray)
{
    /****************************************************
    * RT1.1: INTERSECTION CALCULATION
    *
    * Given: ray, position, r
    * Sought: intersects? if true: *t
    *
    * Insert calculation of ray/sphere intersection here.
    *
    * You have the sphere's center (C) and radius (r) as well as
    * the ray's origin (ray.O) and direction (ray.D).
    *
    * If the ray does not intersect the sphere, return false.
    * Otherwise, return true and place the distance of the
    * intersection point from the ray origin in *t (see example).
    ****************************************************/

    // place holder for actual intersection calculation

    Vector relative = position - ray.O;  // place (and direction) of sphere relative to the ray origin
    double outerOrtho = relative.dot(ray.D);

    //if (outerOrtho < 0)
      //return Hit::NO_HIT();

    double centerDist2 = relative.length_2() - (outerOrtho * outerOrtho);

    if (centerDist2 > (r * r) || relative.length() < r)
      return Hit::NO_HIT();

    double centerOrtho = sqrt((r * r) - (centerDist2));

    double t = outerOrtho - centerOrtho; // only the closest hit matters

    
    /****************************************************
    * RT1.2: NORMAL CALCULATION
    *
    * Given: t, C, r
    * Sought: N
    *
    * Insert calculation of the sphere's normal at the intersection point.
    ****************************************************/

    Vector N  = (position - ray.at(t)).normalized();

    return Hit(t,N);
}

Sphere::Sphere(Point const &pos, double radius)
:
    position(pos),
    r(radius)
{}
