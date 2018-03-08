#include "scene.h"

#include "hit.h"
#include "image.h"
#include "material.h"
#include "ray.h"

#include <cmath>
#include <limits>

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

    Material material = obj->material;          //the hit objects material
    Point hit = ray.at(min_hit.t);                 //the hit point

    Color color;
    if (material.hasTexture){
        Vector uvq = obj->getTextureCoord(hit);
	color = material.getColor(uvq.x, uvq.y);
    } else 
	color = material.getColor(0, 0);

    Vector N = min_hit.N.normalized;                          //the normal at hit point
    Vector V = -ray.D;                             //the view vector
    Vector L = lights[0]->position-hit;
    L.normalize();
    Vector R = 2*(N.dot(L))*N - L;

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
    

   if (lightInt( Ray( Point(hit - 0.000001 * L), (-1)*L)))
        return ambient;
    
    double  lamb = N.dot(L);
    lamb = (lamb<0) ? lamb:0;
    Color lambert =  -1 * lamb * color * material.kd;
    R.normalize();
    double reflection = V.dot(R);
    reflection = (reflection<0) ? 0: reflection;
    reflection = material.ks * pow(reflection, material.n);
    Color ref = reflection * lights[0]->color;
    //lambert = lambert* lights[0]->color;

    color = ambient + lambert + ref;
    //Color color = material.color;                  // place holder
    /*Color color;
    color.set(N.dot(ray.D)); */

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
            Color col(0,0,0);
            Point pixel[4]; //(x + 0.5, h - 1 - y + 0.5, 0);
            pixel[0] = Point(x + .25, h - 1 - y + 0.25 ,0);
            pixel[1] = Point(x + .25, h - 1 - y + 0.75 ,0);
            pixel[2] = Point(x + .75, h - 1 - y + 0.25 ,0);
            pixel[3] = Point(x + .75, h - 1 - y + 0.75 ,0);
            for(int i=0; i<4; i++){
                Ray ray(eye, (pixel[i] - eye).normalized());
                col += trace(ray);
            }
            col /= 4;
            col.clamp();
            img(x, y) = col;
        }
    }
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

unsigned Scene::getNumObject()
{
    return objects.size();
}

unsigned Scene::getNumLights()
{
    return lights.size();
}
