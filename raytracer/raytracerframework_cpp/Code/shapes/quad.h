#ifndef QUAD_H_
#define QUAD_H_

#include "../object.h"
#include "triangle.h"

class Quad: public Object
{
    public:
        Quad(Point p1, Point p2, Point p3, Point p4);

        virtual Hit intersect(Ray const &ray);
	virtual Vector getTextureCoord(Point point);

        Triangle t1, t2;
};

#endif
