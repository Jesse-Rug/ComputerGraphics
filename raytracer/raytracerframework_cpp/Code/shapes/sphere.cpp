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
    r(radius),
    axis( Vector(0, 1, 0)),
    angle(0.0)
{}

Sphere::Sphere(Point const &pos, double radius, Vector const &rotation, double angle)
:
    position(pos),
    r(radius),
    axis(rotation),
    angle(angle)
{
    Vector rAxis = rotation.normalized().cross(Vector(0, 1, 0));
    double cos = rotation.normalized().dot(Vector(0, 1, 0));
    double theta = std::acos(cos);

    Vector S0(0, -rAxis.z, rAxis.y);
    Vector S1(rAxis.z, 0, -rAxis.x);
    Vector S2(-rAxis.y, rAxis.x, 0);

    Vector ST0(S0.x, S1.x, S2.x);
    Vector ST1(S0.y, S1.y, S2.y);
    Vector ST2(S0.z, S1.z, S2.z);

    Vector Ssq0(S0.dot(ST0), S0.dot(ST1), S0.dot(ST2));
    Vector Ssq1(S1.dot(ST0), S1.dot(ST1), S1.dot(ST2));
    Vector Ssq2(S2.dot(ST0), S2.dot(ST1), S2.dot(ST2));

    rotMatrix[0] = Vector(1, 0, 0) + (S0 * theta) + (Ssq0 * (1 - cos));
    rotMatrix[1] = Vector(0, 1, 0) + (S1 * theta) + (Ssq1 * (1 - cos));
    rotMatrix[2] = Vector(0, 0, 1) + (S2 * theta) + (Ssq2 * (1 - cos));


}

//https://www.gamedev.net/forums/topic/61727-aligning-two-vectors/

Vector Sphere::getTextureCoord(Point hit)
{
   Point point(hit - position);
   double pi = 3.14159265359;
   point /= r;
   Point normal;
   normal.x = point.dot(rotMatrix[0]);
   normal.y = point.dot(rotMatrix[1]);
   normal.z = point.dot(rotMatrix[2]);
   //normal is now a point on a unit sphere, pointing up, centered around the origin

   double u = atan2(normal.x, normal.z) / (2 * pi) + 0.5;
   double v = normal.y;  
   // std::atan2 returns on the range of [-PI, PI], dividing by 2PI mapping to [-.5, .5] and finally to [0,1] 
   return Vector(u, v, 0);
}
