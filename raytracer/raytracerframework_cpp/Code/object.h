#ifndef OBJECT_H_
#define OBJECT_H_

#include "material.h"
#include "image.h"

// not really needed here, but deriving classes may need them
#include "hit.h"
#include "ray.h"
#include "triple.h"

#include <memory>
class Object;
typedef std::shared_ptr<Object> ObjectPtr;

class Object
{
    public:
        Material material;

        virtual ~Object() = default;

        virtual Hit intersect(Ray const &ray) = 0;  // must be implemented
                                                    // in derived class
	virtual Vector getTextureCoord(Point point) = 0;
};

#endif
