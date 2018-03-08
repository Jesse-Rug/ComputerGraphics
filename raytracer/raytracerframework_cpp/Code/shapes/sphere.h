#ifndef SPHERE_H_
#define SPHERE_H_

#include "../object.h"

class Sphere: public Object
{
    public:
        Sphere(Point const &pos, double radius);
        Sphere(Point const &pos, double radius, Vector const &rotation, double angle);


        virtual Hit intersect(Ray const &ray);
	virtual Vector getTextureCoord(Point point);

        Point const position;
        double const r;
	Vector const axis;
	double const angle;
        Vector rotMatrix[3];
	
};

#endif
