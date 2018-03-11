#include "sphere.h"
#include "solvers.h"

#include <cmath>

using namespace std;

Hit Sphere::intersect(Ray const &ray)
{
    // Sphere formula: ||x - position||^2 = r^2
    // Line formula:   x = ray.O + t * ray.D

    Vector L = ray.O - position;
    double a = ray.D.dot(ray.D);
    double b = 2 * ray.D.dot(L);
    double c = L.dot(L) - r * r;

    double t0;
    double t1;
    if (not Solvers::quadratic(a, b, c, t0, t1))
        return Hit::NO_HIT();

    // t0 is closest hit
    if (t0 < 0)  // check if it is not behind the camera
    {
        t0 = t1;    // try t1
        if (t0 < 0) // both behind the camera
            return Hit::NO_HIT();
    }

    // calculate normal
    Point hit = ray.at(t0);
    Vector N = (hit - position).normalized();

    // determine orientation of the normal
    if (N.dot(ray.D) > 0)
        N = -N;

    return Hit(t0, N);
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
   Point point((hit - position).normalized());
   double pi = 3.14159265359;
   Point normal;
   normal.x = point.dot(rotMatrix[0]);
   normal.y = point.dot(rotMatrix[1]);
   normal.z = point.dot(rotMatrix[2]); 
   normal.normalize();
   //normal is now a point on a unit sphere that points up(ish), centered around the origin

   double u = atan2(normal.x , normal.z) /  (2* pi) + 0.5 + (angle / 360);
   for(; u > 1.0; u -= 1.0 );  // or while (u > 1.0) u -= 1.0;  
   double v = 0.5 - (asin(normal.y) / pi);
   // std::atan2 returns on the range of [-PI, PI], dividing by 2 PI mapping to [-.5, .5] and finally to [0,1]
   // the final part adds the angle disposition 
   // https://en.wikipedia.org/wiki/UV_mapping
   return Vector(u, v, 0);
}


