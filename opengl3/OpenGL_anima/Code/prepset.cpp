#include "mainview.h"

void MainView::prepset(){
    magni = 1.0;
    projectM.setToIdentity();

    QMatrix4x4 next;

    next.translate( -5.0, 0.0, -10.0);
    models.push_back(next);
    next.setToIdentity();

    next.translate(5.0, 1.0,-10.0);
    models.push_back(next);

    next.setToIdentity();
    next.translate(6.0, 3.0, -15.0);
    models.push_back(next);

    next.setToIdentity();
    next.translate(-6.0, -3.0, -15.0);
    models.push_back(next);

    projectM.perspective(60.0 , 1.0, .1, 100.0);
}
