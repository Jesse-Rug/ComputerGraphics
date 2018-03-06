#ifndef PLANE_H_
#define PLANE_H_

#include "../object.h"

class Plane: public Object
{
        
    
    public:
        Plane(Point loc0, Vector normal);
        Plane(Point point0, Point point1, Point point2);

        virtual Hit intersect(Ray const &ray);

        Point const d_loc0;
        Vector  d_normal;
};

#endif
