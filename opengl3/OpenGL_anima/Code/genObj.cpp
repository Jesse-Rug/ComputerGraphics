#include "mainview.h"

void MainView::genObj(){
    /*genCube();*/
    //genPyra();

    genObject(":/models/cat.obj", &sphVAO, &sphVBO, &sphIBO, &verticeNumber);
    //genObject(":/models/cube.obj", &cubIBO, &cubVBO, &cubIBO, &verticeNSphere);
}
