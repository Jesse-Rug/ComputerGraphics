//
//  intersectLight.cpp
//  
//
//  Created by Paola Del Hierro on 3/6/18.
//

#include "scene.h"
#include <limits>
#include <cmath>

bool Scene::lightInt(Ray ray){
    Hit light_hit(std::numeric_limits<double>::infinity(), Vector());
    ObjectPtr obj = nullptr;
    for (unsigned idx = 0; idx != objects.size(); ++idx)
    {
        Hit hit(objects[idx]->intersect(ray));
        if (hit.t < light_hit.t)
        {
            light_hit = hit;
            obj = objects[idx];
        }
    }
    
    return obj ? true : false;
}

