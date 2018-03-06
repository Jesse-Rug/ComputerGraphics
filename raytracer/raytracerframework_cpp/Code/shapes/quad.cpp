#include "quad.h"

#include <cmath>
#include <algorithm>

Hit Quad::intersect(Ray const &ray)
{
    return t1.intersect(ray).t < t2.intersect(ray).t ? t1.intersect(ray) : t2.intersect(ray) ;
}

Quad::Quad(Point p1, Point p2, Point p3, Point p4)
:
    t1(p1, p2, p4),
    t2(p1, p3, p4)
{
    std::vector<Point> s ({p1, p2, p3, p4});
    std::sort(s.begin(), s.end(), [](Point a, Point b) {
        return a.x < b.x;   
    });
    t1 = Triangle(s[0], s[1], s[3]);
    t2 = Triangle(s[0], s[2], s[3]);
}
