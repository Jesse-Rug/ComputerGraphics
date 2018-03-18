#include "mainview.h"

void MainView::genObj(){
    /*genCube();*/
    //genPyra();

    vaos.push_back(0);
    vbos.push_back(0);
    ibos.push_back(0);
    vertices.push_back(0);

    genObject(":/models/cat.obj", &vaos[0], &vbos[0], &ibos[0], &vertices[0]);


    vaos.push_back(1);
    vbos.push_back(1);
    ibos.push_back(1);
    vertices.push_back(1);
    genObject(":/models/cat.obj", &vaos[1], &vbos[1], &ibos[1], &vertices[1]);


    vaos.push_back(2);
    vbos.push_back(2);
    ibos.push_back(2);
    vertices.push_back(2);
    genObject(":/models/cube.obj", &vaos[2], &vbos[2], &ibos[2], &vertices[2]);

    vaos.push_back(3);
    vbos.push_back(3);
    ibos.push_back(3);
    vertices.push_back(3);
    genObject(":/models/cube.obj", &vaos[3], &vbos[3], &ibos[3], &vertices[3]);
}
