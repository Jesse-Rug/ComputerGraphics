#include "mainview.h"

void MainView::prepset(){
    magni = 1.0;
    time = 0.0;

    modelM.setToIdentity();
    projectM.setToIdentity();
    vieuwM.setToIdentity();

    modelM.translate( 0.0, 0.0, -7.0);
    vieuwM.lookAt( QVector3D(0, 0, 0), QVector3D(0, 0, -1), QVector3D(0, 1, 0));
    projectM.perspective(60.0 , 1.0, .1, 100.0);

    numWaves = 2;
    frequencies.push_back(5);
    amplitudes.push_back(0.1);
    phases.push_back(0.0);

    frequencies.push_back(7);
    amplitudes.push_back(0.12);
    phases.push_back(0.1);


}
