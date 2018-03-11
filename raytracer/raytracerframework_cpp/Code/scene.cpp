#include "scene.h"

#include "hit.h"
#include "image.h"
#include "material.h"
#include "ray.h"

#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

Color Scene::trace(Ray const &ray)
{
    // Find hit object and distance
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
    

    // No hit? Return background color.
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

    if (obj->material.hasNMap){
	Vector uvq = obj->getTextureCoord(hit);
        N = obj->material.getNormal(uvq.x, uvq.y, N);
    }

    //color = (N/2) + 0.5;
	




    /****************************************************
    * This is where you should insert the color
    * calculation (Phong model).
    *
    * Given: material, hit, N, V, lights[]
    * Sought: color
    *
    * Hints: (see triple.h)
    *        Triple.dot(Vector) dot product
    *        Vector + Vector    vector sum
    *        Vector - Vector    vector difference
    *        Point - Point      yields vector
    *        Vector.normalize() normalizes vector, returns length
    *        double * Color     scales each color component (r,g,b)
    *        Color * Color      dito
    *        pow(a,b)           a to the power of b
    ****************************************************/

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

    ambient += material.ks * reflectLight( Ray( Point(hit + 0.000001 * N), -N.reflect(V)), maxRef);    

    color = ambient;

    color.clamp(1.0);

    return color;
}

void Scene::render(Image &img)
{
    unsigned w = img.width();
    unsigned h = img.height();
    for (unsigned y = 0; y < h; ++y)
    {
        for (unsigned x = 0; x < w; ++x)
        {

	    //cerr << '\r' << x << ' ' << y ;
	    //progress meter

            Color col;
            Point pixel;
            for(int i=0; i<ss; i++){
                for(int j=0; j<ss; j++){
                    pixel = Point(x + ((2*i + 1)/ss), h - 1 - y + ((2*j + 1)/ss),0);
                    Ray ray(eye, (pixel - eye).normalized());
                    col += trace(ray);
                    
                }
            }
            col=col/pow(ss,2);
            col.clamp();
            img(x, y) = col;
        }
    }
    cerr << '\n';
}

// --- Misc functions ----------------------------------------------------------

void Scene::addObject(ObjectPtr obj)
{
    objects.push_back(obj);
}

void Scene::addLight(Light const &light)
{
    lights.push_back(LightPtr(new Light(light)));
}

void Scene::setEye(Triple const &position)
{
    eye = position;
}

void Scene::enableSS(int const &rays){
    ss = rays;
}

void Scene::set_maxRef(int m){
    maxRef = m;
}
unsigned Scene::getNumObject()
{
    return objects.size();
}
        
void Scene::setShadows(bool s){
    shadows = s;
}

unsigned Scene::getNumLights()
{
    return lights.size();
}


        
