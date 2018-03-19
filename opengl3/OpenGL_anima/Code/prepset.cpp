#include "mainview.h"

void MainView::prepset(){
    arcX = arcY = 0;
    arcspeedX = arcspeedY = 0;
    arcSize = 20;
    magni = 1.0;
    projectM.setToIdentity();
    vieuwM.setToIdentity();

    projectM.perspective(60.0 , 1.0, .1, 100.0);
    vieuwM.lookAt(QVector3D(0, 0, 0), QVector3D(0, 0, -1), QVector3D(0, 1, 0));

    QMatrix4x4 next;

    next.translate( -5.0, 0.0, -10.0);
    models.push_back(next);
    moveDir.push_back(QVector3D(1, 0, 1));
    axi.push_back(QVector3D(0, 0, 0));
    AFPs.push_back(QVector3D(.5, 2, 0.5));
    rspeed.push_back(0.0);

    next.setToIdentity();
    next.translate(5.0, 1.0,-10.0);
    models.push_back(next);
    moveDir.push_back(QVector3D(0, 1, 1));
    axi.push_back(QVector3D(0, 0, 0));
    AFPs.push_back(QVector3D(1, 0.5, 0));
    rspeed.push_back(0.0);

    next.setToIdentity();
    next.translate(6.0, 3.0, -15.0);
    models.push_back(next);
    moveDir.push_back(QVector3D(0, 1, 1));
    axi.push_back(QVector3D(0, 1, .5));
    AFPs.push_back(QVector3D(0, 0, 0));
    rspeed.push_back(4.5);

    next.setToIdentity();
    next.translate(-6.0, -3.0, -15.0);
    models.push_back(next);
    moveDir.push_back(QVector3D(0, 1, 1));
    axi.push_back(QVector3D(1, 0, 1));
    AFPs.push_back(QVector3D(1, 1.2, 0));
    rspeed.push_back(2);

}
