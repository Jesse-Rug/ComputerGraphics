#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "triple.h"
#include "image.h"
#include <iostream>

class Material
{
    Color color;        // base color
    Image texture;
    Image bumpmap;

    public:
        bool hasTexture;
	bool hasNMap;
        double ka;          // ambient intensity
        double kd;          // diffuse intensity
        double ks;          // specular intensity
        double n;           // exponent for specular highlight size

        Material() = default;

	Color getColor(float u, float v)
        {
    	    if (!hasTexture)
	        return (color);
            return texture.colorAt(u, v);
	     //return Color(u, v, 0);
        }

	Vector getNormal(float u, float v, Vector N)
        {
	    Vector tangent = (N.z == 0) ? Vector(0, 0, 1) :
		 Vector(-N.x, -N.y, (-N.x + -N.y)/-N.z);
	    Vector bitangent = N.cross(tangent);

	    Vector tangentSpaceMat[3]{
		Vector(tangent.x, bitangent.x, N.x),
		Vector(tangent.y, bitangent.y, N.y),
		Vector(tangent.z, bitangent.z, N.z)
	    };
	    // matrix to go from tangent space (in which the map normals are) to model space

	    //Vector extract(0, 0, 1);
            Vector extract(bumpmap.colorAt(u, v));
	    extract = (extract - 0.5) * 2;
	    // get the map normal and convert it from color range [0,1] to normal range [-1, 1]

	    Vector normal;
   	    normal.x = extract.dot(tangentSpaceMat[0]);
   	    normal.y = extract.dot(tangentSpaceMat[1]);
   	    normal.z = extract.dot(tangentSpaceMat[2]); 
   	    normal.normalize();
	    return normal;
	     
        }

        Material(Color const &color, double ka, double kd, double ks, double n)
        :
            color(color),
	    hasTexture(false),
	    hasNMap(false),
            ka(ka),
            kd(kd),
            ks(ks),
            n(n)
        {}

        Material(Image const &texture, double ka, double kd, double ks, double n)
        :
            texture(texture),
	    hasTexture(true),
	    hasNMap(false),
            ka(ka),
            kd(kd),
            ks(ks),
            n(n)
        {}

        Material(Color const &color, Image const &bump, double ka, double kd, double ks, double n)
        :
            color(color),
            bumpmap(bump),
	    hasTexture(false),
	    hasNMap(true),
            ka(ka),
            kd(kd),
            ks(ks),
            n(n)
        {}

        Material(Image const &texture, Image const &bump, double ka, double kd, double ks, double n)
        :
            texture(texture),
            bumpmap(bump),
	    hasTexture(true),
	    hasNMap(true),
            ka(ka),
            kd(kd),
            ks(ks),
            n(n)
        {}
};

#endif
