#include "mainview.h"

void MainView::prepset(){
    magni = 1.0;

    modelC.setToIdentity();
    modelP.setToIdentity();
    modelS.setToIdentity();
    projectM.setToIdentity();

    modelC.translate( 2.0, 0.0, -7.0);
    modelP.translate(-2.0, 0.0, -7.0);
    modelS.translate( 0.0, 0.0, -10.0);


    projectM.perspective(60.0 , 1.0, .1, 100.0);
}
