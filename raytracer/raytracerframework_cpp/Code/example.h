#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include "shapes/triangle.h"

class Mesh
{
    std::vector<Triangle> triangles;
    public:
        Mesh(string const &filename);

        virtual Hit intersect(Ray const &ray);

        /* YOUR DATA MEMBERS HERE*/
};

#endif
