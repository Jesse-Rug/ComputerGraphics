#include "mainview.h"

void MainView::genObj(){
    /*genCube();*/
    //genPyra();

    vaos.push_back(0);
    vbos.push_back(0);
    ibos.push_back(0);
    vertices.push_back(0);

    genObject(":/models/cat.obj", &vaos[0], &vbos[0], &ibos[0], &vertices[0]);
    //genObject(":/models/cube.obj", &cubIBO, &cubVBO, &cubIBO, &verticeNSphere);
}
