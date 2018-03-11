#ifndef SCENE_H_
#define SCENE_H_

#include "light.h"
#include "object.h"
#include "triple.h"

#include <vector>
#include <tuple>
#include <utility>

// Forward declerations
class Ray;
class Image;

class Scene
{
    std::vector<ObjectPtr> objects;
    std::vector<LightPtr> lights;   // no ptr needed, but kept for consistency
    Point eye;
    int ss;
    bool shadows;
    int maxRef;

    public:

        // trace a ray into the scene and return the color
        Color trace(Ray const &ray);

        // render the scene to the given image
        void render(Image &img);


        void addObject(ObjectPtr obj);
        void addLight(Light const &light);
        void setEye(Triple const &position);
        void enableSS(int const &rays);
        void setShadows(bool s);
        void set_maxRef(int m);
        std::pair<Hit, ObjectPtr> lightInt(Ray ray);
    

        unsigned getNumObject();
        unsigned getNumLights();
};

#endif
