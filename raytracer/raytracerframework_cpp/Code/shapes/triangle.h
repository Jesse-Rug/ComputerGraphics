//
//  triangle.h
//  
//
//  Created by Paola Del Hierro on 2/24/18.
//

#ifndef triangle_h
#define triangle_h

#include "../object.h"
class Triangle: public Object{
    
public:
    Triangle (Point const &p1, Point const &p2, Point const &p3);
    
    virtual Hit intersect(Ray const &ray);
    virtual Vector getTextureCoord(Point point);
    
    Point pos1, pos2, pos3;

    Triangle &operator=(Triangle &&t1);

};


#endif /* triangle_h */
