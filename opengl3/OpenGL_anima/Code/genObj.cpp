#include "mainview.h"

void MainView::genObj(){
    /*genCube();*/
    //genPyra();

    vaos.resize(objCount);
    vbos.resize(objCount);
    ibos.resize(objCount);
    vertices.resize(objCount);

    QVector<QString> objects({
                                ":/models/cat.obj",
                                ":/models/cat.obj",
                                ":/models/cube.obj",
                                ":/models/cube.obj"
                             });

    for (size_t idx = 0; idx != objCount; idx++){
        genObject(objects[idx], &vaos[idx], &vbos[idx], &ibos[idx], &vertices[idx]);
    }
}
