#include "mainview.h"

void MainView::genObj(){
    genCube();
    genPyra();
    genObject(":/models/sphere.obj");
}
