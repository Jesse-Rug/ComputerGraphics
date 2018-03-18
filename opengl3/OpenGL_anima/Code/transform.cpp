#include "mainview.h"

QMatrix4x4 MainView::transform(QMatrix4x4 shape, QMatrix3x3 *normal, size_t index){
    QVector3D movement(moveDir.at(index));
    float amp = AFPs.at(index).x();
    float freq = AFPs.at(index).y();
    float phase = AFPs.at(index).z();
    movement *= amp * std::sin(freq * 0.1 * time + phase);
    shape.translate(movement);

    shape.rotate(angleX , 1.0, 0.0, 0.0);   // x
    shape.rotate(angleY , 0.0, 1.0, 0.0);   // y
    shape.rotate(angleZ , 0.0, 0.0, 1.0);   //z
    shape.rotate(rspeed.at(index) * 0.1 * time, axi.at(index));
    //shape.rotate(0.0, 0.0, 1.0, 0.0);

    *normal = shape.normalMatrix();

    shape.scale(magni);
    //shape.scale(1.0);

    return shape;
}
