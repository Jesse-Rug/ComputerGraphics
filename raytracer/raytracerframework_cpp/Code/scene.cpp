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
    return reflectLight(ray, maxRef + 1);
}

void Scene::render(Image &img)
{
    unsigned w = img.width();
    unsigned h = img.height();
    for (unsigned y = 0; y < h; ++y)
    {
        for (unsigned x = 0; x < w; ++x)
        {

	    cerr << '\r' << x << ' ' << y ;
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


        
