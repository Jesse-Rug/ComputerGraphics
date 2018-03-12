#include "mainview.h"

void MainView::prepset(){
    magni = 1.0;

    modelM.setToIdentity();
    projectM.setToIdentity();

    modelM.translate( 2.0, 0.0, -7.0);


    projectM.perspective(60.0 , 1.0, .1, 100.0);
}
