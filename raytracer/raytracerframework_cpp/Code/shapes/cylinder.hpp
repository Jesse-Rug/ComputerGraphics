//
//  cylinder.hpp
//  
//
//  Created by Paola Del Hierro on 2/25/18.
//

#ifndef cylinder_hpp
#define cylinder_hpp

#include "../object.h"
#include <stdio.h>

class Cylinder: public Object{
    
public:
    Cylinder(Point const &pos, Point const &pos2, double height, double radius);
    
    virtual Hit intersect(Ray const &ray);
    virtual Vector getTextureCoord(Point point);
    
    Point const position, positionT;
    double const rad, h;
    Vector rotMatrix[3];
    
};

#endif /* cylinder_hpp */
