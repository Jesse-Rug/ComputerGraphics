#include "mainview.h"

QMatrix4x4 MainView::transform(QMatrix4x4 shape){
    shape.rotate(angleX , 1.0, 0.0, 0.0);   // x
    shape.rotate(angleY , 0.0, 1.0, 0.0);   // y
    shape.rotate(angleZ , 0.0, 0.0, 1.0);   //z
    //shape.rotate(0.0, 0.0, 1.0, 0.0);

    shape.scale(magni);
    //shape.scale(1.0);

    return shape;
}
