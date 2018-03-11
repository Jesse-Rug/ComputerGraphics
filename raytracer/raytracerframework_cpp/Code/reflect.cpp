#include "scene.h"
#include <limits>
#include <cmath>

using namespace std;

Color Scene::reflectLight(Ray const &ray, int factor)
{
    if (factor == 0)
        return Color(0, 0, 0);

    Hit min_hit(numeric_limits<double>::infinity(), Vector());
    ObjectPtr obj = nullptr;
    for (unsigned idx = 0; idx != objects.size(); ++idx)
    {
        Hit hit(objects[idx]->intersect(ray));
        if (hit.t < min_hit.t)
        {
            min_hit = hit;
            obj = objects[idx];
        }
    }
    
    if (!obj) return Color(0.0, 0.0, 0.0);

    Point hit = ray.at(min_hit.t);                 //the hit point
    Vector N = min_hit.N.normalized();              //the normal at hit point
    Vector V = -ray.D;                             //the view vector
    Vector L = lights[0]->position-hit;
    L.normalize();
    Vector R = 2*(N.dot(L))*N - L;
    R.normalize();
    
    Material material;                  //the hit objects material without the texture/color
    material.ka = obj->material.ka; 
    material.kd = obj->material.kd;
    material.ks = obj->material.ks;
    material.n  = obj->material.n;

    Color color;
    if (obj->material.hasTexture){
        Vector uvq = obj->getTextureCoord(hit);
	color = obj->material.getColor(uvq.x, uvq.y);
    
    } else
        color = obj->material.getColor(0,0);


    Color ambient = color * material.ka;
    //Color phong;
    int numLights = getNumLights();
    
    
    for(int i=0; i < numLights; i++){
        L = lights[i]->position-hit;
        L.normalize();
        std::pair<Hit, ObjectPtr>objInt(lightInt(Ray( Point(hit + 0.000001 * L), L)));
        if(objInt.second == nullptr || !shadows){
            double  lamb = N.dot(L);
            lamb = (lamb>0) ? lamb:0;
            Color lambert =   lamb * color * material.kd;
            R = 2*(N.dot(L))*N - L;
            R.normalize();
            double reflection = V.dot(R);
            reflection = (reflection<0) ? 0: reflection;
            reflection = material.ks * pow(reflection, material.n);
            Color ref = reflection * lights[i]->color;
            ambient += (lambert + ref);
        }
    }

    ambient += material.ks * reflectLight( Ray( Point(hit + 0.000001 * L), N.reflect(V)), factor - 1);
    
    color = ambient;

    color.clamp(1.0);

    return color;

}
