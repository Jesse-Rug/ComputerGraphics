#ifndef MATERIAL_H_
#define MATERIAL_H_

#include "triple.h"

class Material
{
    Color color;        // base color
    Image texture;

    public:
        bool hasTexture;
        double ka;          // ambient intensity
        double kd;          // diffuse intensity
        double ks;          // specular intensity
        double n;           // exponent for specular highlight size

        Material() = default;

	Color color(u, v){
            if (!hasTexture)
		return (color);
	    return texture.colorAt(u, v);
	}

        Material(Color const &color, double ka, double kd, double ks, double n)
        :
            color(color),
	    hasTexture(false),
            ka(ka),
            kd(kd),
            ks(ks),
            n(n)
        {}

        Material(Image const &texture, double ka, double kd, double ks, double n)
        :
            texture(texture),
	    hasTexture(true),
            ka(ka),
            kd(kd),
            ks(ks),
            n(n)
        {}
};

#endif
