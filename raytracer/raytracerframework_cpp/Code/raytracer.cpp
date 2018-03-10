#include "raytracer.h"

#include "image.h"
#include "light.h"
#include "material.h"
#include "triple.h"

// =============================================================================
// -- Include all your shapes here ---------------------------------------------
// =============================================================================

#include "shapes/sphere.h"
#include "shapes/cylinder.hpp"
#include "shapes/triangle.h"
#include "shapes/plane.h"
#include "shapes/quad.h"

// =============================================================================
// -- End of shape includes ----------------------------------------------------
// =============================================================================

#include "json/json.h"

#include <exception>
#include <fstream>
#include <iostream>

using namespace std;        // no std:: required
using json = nlohmann::json;

bool Raytracer::parseObjectNode(json const &node)
{
    ObjectPtr obj = nullptr;

// =============================================================================
// -- Determine type and parse object parametrers ------------------------------
// =============================================================================

    if (node["type"] == "sphere")
    {
        if (node.size() == 7){
	    // regular have 5
            Point pos(node["position"]);
            double radius = node["radius"];
            Vector axis(node["rotation"]);
	    double angle = node["angle"];
            obj = ObjectPtr(new Sphere(pos, radius, axis, angle));
        } else {
            Point pos(node["position"]);
            double radius = node["radius"];
            obj = ObjectPtr(new Sphere(pos, radius));
        }
    } 
    else if (node["type"] == "triangle")
    {
        Point p1(node["pos1"]);
        Point p2(node["pos2"]);
        Point p3(node["pos3"]);
        obj = ObjectPtr(new Triangle(p1,p2,p3));
    } 
    else if (node["type"] == "quad")
    {
        Point p1(node["pos1"]);
        Point p2(node["pos2"]);
        Point p3(node["pos3"]);
	Point p4(node["pos4"]);
        obj = ObjectPtr(new Quad(p1,p2,p3,p4));
    } 
    else if (node["type"] == "plane")
    {
        Point p1(node["pos1"]);
        Point p2(node["pos2"]);
        Point p3(node["pos3"]);
        obj = ObjectPtr(new Plane(p1,p2,p3));
    } 
    else if (node["type"] == "cylinder")
    {
        Point p1(node["pos1"]);
        Point p2(node["pos2"]);
	double radius = node["radius"];
        obj = ObjectPtr(new Cylinder(p1, p2, (p1-p2).length(), radius));
    } 
 /*   else if (node["type"] == "plane")
    {
        Point p1(node["pos1"]);
        Vector p2(node["pos2"]);
        obj = ObjectPtr(new Plane(p1,p2));
    } */
    else
    {
        cerr << "Unknown object type: " << node["type"] << ".\n";
    }

// =============================================================================
// -- End of object reading ----------------------------------------------------
// =============================================================================

    if (!obj)
        return false;

    //this prevents a std::bad_alloc. somehow
    cerr << " parsed \n";


    // Parse material and add object to the scene
    obj->material = parseMaterialNode(node["material"]);
    scene.addObject(obj);
    return true;
}

Light Raytracer::parseLightNode(json const &node) const
{
    Point pos(node["position"]);
    Color col(node["color"]);
    return Light(pos, col);
}

Material Raytracer::parseMaterialNode(json const &node) const
{
    double ka = node["ka"];
    double kd = node["kd"];
    double ks = node["ks"];
    double n  = node["n"];

    if(node["color"].is_string()){
        Image texture(node["color"]);
        try{
            Image bump(node.at("bumpmap"));
	    return Material(texture, bump, ka, kd, ks, n);
	} catch (...) {
            return Material(texture, ka, kd, ks, n);
        }
    } else {
        Color color(node["color"]);
        try{
            Image bump(node.at("bumpmap"));
	    return Material(color, bump, ka, kd, ks, n);
	} catch (...) {
            return Material(color, ka, kd, ks, n);
        }
    } 
}

bool Raytracer::readScene(string const &ifname)
try
{
    // Read and parse input json file
    ifstream infile(ifname);
    if (!infile) throw runtime_error("Could not open input file for reading.");
    json jsonscene;
    infile >> jsonscene;

// =============================================================================
// -- Read your scene data in this section -------------------------------------
// =============================================================================

    Point eye(jsonscene["Eye"]);
    scene.setEye(eye);
    
    if(!jsonscene["SuperSamplingFactor"].is_null())
        scene.enableSS(jsonscene["SuperSamplingFactor"]);
    else
        scene.enableSS(1);

    // TODO: add your other configuration settings here

    for (auto const &lightNode : jsonscene["Lights"])
        scene.addLight(parseLightNode(lightNode));

    unsigned objCount = 0;
    for (auto const &objectNode : jsonscene["Objects"])
        if (parseObjectNode(objectNode))
            ++objCount;

    cout << "Parsed " << objCount << " objects.\n";

// =============================================================================
// -- End of scene data reading ------------------------------------------------
// =============================================================================

    return true;
}
catch (exception const &ex)
{
    cerr << ex.what() << '\n';
    return false;
}

void Raytracer::renderToFile(string const &ofname)
{
    // TODO: the size may be a settings in your file
    Image img(400, 400);
    cout << "Tracing...\n";
    scene.render(img);
    cout << "Writing image to " << ofname << "...\n";
    img.write_png(ofname);
    cout << "Done.\n";
}
