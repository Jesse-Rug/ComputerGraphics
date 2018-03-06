//
//  triangle.cpp
//  
//
//  Created by Paola Del Hierro on 2/24/18.
//


#include "triangle.h"
#include <cmath>
//#include <stdio.h>

using namespace std;

/*Hit Triangle::intersect(Ray const &ray){
   
    double t = 0;
    
    
    Vector N, l1, l2, l3;
    l1 = pos2 - pos1;
    l2 = pos3 - pos1;
    l3 = pos3 - pos1;

    //Normal
    N = l1.cross(l2);
    
    if(N.dot(ray.D)==0.0){
        return Hit::NO_HIT();
    }
    
    
    //double distance = -N.dot(ray.O - pos1);
    
    t= (N.dot(ray.O - pos1))/N.dot(ray.D);
    
    if((int)t==0.0){
        return Hit::NO_HIT();
    }
    
    
    
    Vector P = ray.O + (ray.D)*t;
    
  
   
    double d11, d12, d22, dwu, dwv, D;
    d11 = l1.dot(l1);
    d12 = l1.dot(l2);
    d22 = l2.dot(l2);
    Vector lw = P - pos1;
    dwu = lw.dot(l1);
    dwv = lw.dot(l2);
    D = (d12*d12) - (d11*d12);
    
    double r, s;
    s = ((d12* dwv)-(d22*dwu))/D;
    r = ((d12*dwu)-(d11*dwv)/D);
    
    if(s< 0.0 || s>1.0)
        return Hit::NO_HIT();
    
    if(r<0.0 || (s+r) >1.0)
        return Hit::NO_HIT();
    
    
    N.normalize();
    return Hit(t, N);

    
} */

Hit Triangle::intersect(Ray const &ray)
{
    // compute plane's normal
    Vector pos1pos2 = pos2 - pos1;
    Vector pos1pos3 = pos3 - pos1;
    // no need to normalize
    Vector N = pos1pos2.cross(pos1pos3); // N

    // Step 1: finding P
    
    // check if ray and plane are parallel ?
    float NdotRayDirection = N.dot(ray.D);
    if (fabs(NdotRayDirection) < 0.0001) // almost 0
    return Hit::NO_HIT(); // they are parallel so they don't intersect !

    // compute d parameter using equation 2
    float d = N.dot(pos1);

    // compute t (equation 3)
    double t = (N.dot(ray.O) + d) / NdotRayDirection;
    // check if the triangle is in behind the ray
    if (t < 0) return Hit::NO_HIT(); // the triangle is behind

    // compute the intersection point using equation 1
    Vector P = ray.O + t * ray.D;

    // Step 2: inside-outside test
    Vector C; // vector perpendicular to triangle's plane
    
    // edge 0
    Vector edge0 = pos2 - pos1;
    Vector vp0 = P - pos1;
    C = edge0.cross(vp0);
    if (N.dot(C) < 0) return Hit::NO_HIT(); // P is on the right side

    // edge 1
    Vector edge1 = pos3 - pos2;
    Vector vp1 = P - pos2;
    C = edge1.cross(vp1);
    if (N.dot(C) < 0) return Hit::NO_HIT(); // P is on the right side

    // edge 2
    Vector edge2 = pos1 - pos3;
    Vector vp2 = P - pos3;
    C = edge2.cross(vp2);
    if (N.dot(C) < 0) return Hit::NO_HIT(); // P is on the right side;

    return Hit(t,N); // this ray hits the triangle
} 


Triangle::Triangle(Point const &p1, Point const &p2, Point const &p3):

    pos1(p1),
    pos2(p2),
    pos3(p3)
{}

Triangle &Triangle::operator=(Triangle &&t1)
{
	swap(pos1, t1.pos1);
	swap(pos2, t1.pos2);
	swap(pos3, t1.pos3);
	return *this;
}

