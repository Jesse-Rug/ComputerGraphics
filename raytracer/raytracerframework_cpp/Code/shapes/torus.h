#ifndef TORUS_H_
#define TORUS_H_

#include "../object.h"

class Torus: public Object
{
    public:
        Torus(/* YOUR DATA MEMBERS HERE*/);

        virtual Hit intersect(Ray const &ray);
	virtual Vector getTextureCoord(Point point);

        /* YOUR DATA MEMBERS HERE*/
};

#endif
