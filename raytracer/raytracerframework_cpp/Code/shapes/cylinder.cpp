//
//  cylinder.cpp
//  
//
//  Created by Paola Del Hierro on 2/25/18.
//

#include "cylinder.hpp"
#include <cmath>


Hit Cylinder::intersect(Ray const&ray){
    double t;
    Vector N;
    
    Point center (ray.O - position);
    
    double a = pow(ray.D.x, 2) + pow(ray.D.z, 2);
    double b = ray.D.x*center.x + ray.D.z*center.z;
    double c = pow(center.x, 2) + pow(center.z,2) - pow(rad,2);
    
    double dif = pow(b,2) - a*c;
    
    if((int)dif ==0) // Check if an intersection exists
        return Hit::NO_HIT();
    
    t= (-b -sqrt(dif))/a; //closest intersection
    
    if((int)t <= 0) //Check if intersection is valid
        return Hit::NO_HIT();
    
    double y = center.y + t*ray.D.y;
    
    if((int)y > h || (int)y<0){
        if(position.y  == position.y + h || positionT.y == position.y +h )
            N = Vector(0,1,0);
        if(position.y == position.y || positionT.y == position.y)
            N = Vector(0,-1,0);
        
        double db, dt, dis;
        a = N.x;
        b = N.y;
        c = N.z;
        dt = -(a*(positionT.x - position.x)) + b*(positionT.y-position.y) + c*(positionT.z-position.z);
        db = a*ray.D.x + b*ray.D.y + c*ray.D.z;
        
        if(db == 0)
            return Hit::NO_HIT();
        
        dis = -(a*center.x + b*center.y + c*center.z)/db;
        
        if((int)dis==0)
            dis = -(a*center.x + b*center.y + c*center.z + dt)/db;
        if((int)dis == 0)
            return Hit::NO_HIT();
        
        Point f;
        f.x = center.x + dis*ray.D.x;
        f.y = center.y + dis*ray.D.y;
        f.z = center.z + dis*ray.D.z;
        
        double isIn = (pow(f.x, 2) + pow(f.z, 2)) - pow(rad, 2);
        if(isIn>0)
            return Hit::NO_HIT();
        t = dis;
    }else{
        Vector P = ray.O + t*ray.D;
        Point n = Point (position.x, P.y,  position.z);
        N = P - n;
        
    }
    N.normalize();
    
    return Hit(t, N);
    
    
}

Cylinder::Cylinder(Point const &pos, Point const &pos2, double height, double radius):
    position(pos), //center of base
    positionT(pos2), //center of top
    rad(radius),
    h(height)
{}

Vector Cylinder::getTextureCoord(Point hit)
{
   Point point((hit - position).normalized());
   double pi = 3.14159265359;
   Point normal;
   normal.x = point.dot(rotMatrix[0]);
   normal.y = point.dot(rotMatrix[1]);
   normal.z = point.dot(rotMatrix[2]); 
   normal.normalize();
   //normal is now a point on a unit sphere that points up(ish), centered around the origin

   double u = atan2(normal.x , normal.z) /  (2* pi) + 0.5; // + (angle * pi / 180);
   for(; u > 1.0; u -= 1.0 );  //while (u > 1.0) u -= 1.0;  
   double v = (-normal.y / 2) + 0.5; 
// std::atan2 returns on the range of [-PI, PI], dividing by 2 PI mapping to [-.5, .5] and finally to [0,1]
//the final part adds the angle disposition 
// minus normal.y to make coordinate systems line up.
   return Vector(u, v, 0);
}