#include "mainview.h"

void MainView::genObject(QString name){
    //Model object(":/models/sphere.obj");
    Model object(name);
    object.unitize();

    //QVector<QVector3D> vertices =  object.getVertices();
    QVector<QVector3D> vertices =  object.getVertices_indexed();
    QVector<QVector3D> normals  =  object.getNormals_indexed();
    QVector<QVector2D> textures =  object.getTextureCoords_indexed();
    QVector<unsigned int> indices = object.getIndices();
    std::vector<float> buffer;
    //buffer.reserve(2*sizeof(vertices));//im adding 3 colour to the 3 location bytes

   for (int index = 0; index < vertices.size(); index ++){
        buffer.push_back(vertices.at(index).x());
        buffer.push_back(vertices.at(index).y());
        buffer.push_back(vertices.at(index).z());

        /*random  r,g,b values from [0-1]
        buffer.push_back((float)(rand() % 100) / 100);
        buffer.push_back((float)(rand() % 100) / 100);
        buffer.push_back((float)(rand() % 100) / 100);
        */

        buffer.push_back(normals.at(index).x());
        buffer.push_back(normals.at(index).y());
        buffer.push_back(normals.at(index).z());

        buffer.push_back((textures.at(index).x()));
        buffer.push_back((textures.at(index).y()));

    }

    glGenVertexArrays(1, &sphVAO);
    glGenBuffers(1, &sphVBO);
    glGenBuffers(1, &sphIBO);

    glBindVertexArray(sphVAO);

    glBindBuffer(GL_ARRAY_BUFFER, sphVBO);
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float) , &(buffer.at(0)), GL_STATIC_DRAW);
    // &(buffer.at(0) works since the elements are strictly in sequence in memory

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * 4 , indices.data(), GL_STATIC_DRAW);

    verticeNumber = 4 * indices.size();
    /* i can feel the angel losing it's wings at this magic number "4" but
    just indices.size() gave me half the triangles on a half object.
    I have no idea why.
    */

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), ((GLvoid*) (3 * sizeof(GLfloat))));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), ((GLvoid*) (6 * sizeof(GLfloat))));


}
