#include "torus.h"

#include <cmath>

Hit Torus::intersect(Ray const &ray)
{
    /* 
	//torus

	a1 = outer
	a2 = inner

 	x = cos(a1) * (r1 + (cos(a2) * r2))
	y = sin(a2) * r2
	z = sin(a1) * (r1 + (cos(a2) * r2))

	y = sin(a2) * r2 -> arcsin(y/r2) = a2 =>

 	x = cos(a1) * (r1 + (cos(arcsin(y/r2)) * r2)) 
 	z = sin(a1) * (r1 + (cos(arcsin(y/r2)) * r2)) 

	sin(a1) = z/(r1 + (cos(arcsin(y/r2)) * r2)) 
	a1 = arccos(x/(r1 + (cos(arcsin(y/r2)) * r2)))
	
	z = sin(arccos(x/(r1 + (cos(arcsin(y/r2)) * r2)))) *
		(r1 + (cos(arcsin(y/r2)) * r2)) ;
	z is f(x,y,r2,r1) (r1 and r2 are known)
	
	
	//line

	x = O.x + t * D.x
	y = O.y + t * D.y
	z = O.z + t * D.z

	x - O.x = t * D.x
	t = (x - O.x)/D.x
	z = O.z + ((x - O.x)/D.x) * D.z

	// intersect 
	sin(arccos(x / (r1 + (cos(arcsin(y/r2)) * r2)))) *
		(r1 + (cos(arcsin(y/r2)) * r2))  = O.z + ((x - O.x)/D.x) * D.z
	
	r1 + (cos(arcsin(y/r2)) * r2) = (O.z + ((x - O.x)/D.x) * D.z) /
		 (sin(arccos(x / (r1 + (cos(arcsin(y/r2)) * r2)))))

	reisolate y...

	y = (sin(arccos((((O.z + ((x - O.x)/D.x) * D.z) / (sin(arccos(x / (r1 + (cos(arcsin(y/r2)) * r2)))))) - r1) / r2))) * r2

	fill into t = (y - O.y)/D.y and you have t. not solvable though.


    */

    double t = 0 /* = ... */;
    Vector N /* = ... */;

    return Hit(t, N);
}

Torus::Torus(/* YOUR DATAMEMBERS HERE */)
//:
// See sphere.cpp how to initialize your data members
{}

Vector Torus::getTextureCoord(Point hit)
{
    return Vector(0, 0, 0);
}