#include "mesh.h"
#include "../objloader.h"

#include <cmath>
#include <limits>

Hit Mesh::intersect(Ray const &ray)
{
    /* Your intersect calculation goes here */

    Hit min_hit(std::numeric_limits<double>::infinity(), Vector());
    ObjectPtr obj = nullptr;
    for (unsigned idx = 0; idx != triangles.size(); ++idx)
    {
        Hit hit(triangles[idx].intersect(ray));
        if (hit.t < min_hit.t)
            min_hit = hit;
    }

    if (!obj) 
	return Hit::NO_HIT();

    return Hit(min_hit.t, min_hit.N); //flat shading untill barycentric interpolation is implemented
}

Mesh::Mesh(std::string const &filename)
:
    triangles()
{
    OBJLoader loader(filename);
    std::vector<Vertex> data;
    for (size_t index = 0; index != loader.numTriangles(); ++index){
	Point p1(data[3 * index].x, data[3 * index].y, data[3 * index].z);
	Point p2(data[(3 * index + 1)].x, data[(3 * index + 1)].y, data[(3 * index + 1)].z);
	Point p3(data[(3 * index + 2)].x, data[(3 * index + 2)].y, data[(3 * index + 2)].z);
	triangles.at(index) = Triangle(p1, p2, p3);
    }
}

Vector Mesh::getTextureCoord(Point hit)
{
    return Vector(0, 0, 0);
}
