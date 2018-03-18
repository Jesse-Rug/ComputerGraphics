#include "mainview.h"

void MainView::prepset(){
    magni = 1.0;
    projectM.setToIdentity();

    QMatrix4x4 next;

    next.translate( 0.0, 0.0, -10.0);
    models.push_back(next);
    next.setToIdentity();

    projectM.perspective(60.0 , 1.0, .1, 100.0);
}
