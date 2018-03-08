#ifndef EXAMPLE_H_
#define EXAMPLE_H_

#include "triangle.h"

class Mesh
{
    public:
        Mesh(std::string const &filename);

        virtual Hit intersect(Ray const &ray);
	virtual Vector getTextureCoord(Point point);

        std::vector<Triangle> triangles;
};

#endif
