#include "mainview.h"

void MainView::genObject(QString name, GLuint *vao, GLuint *vbo, GLuint *ibo, size_t *verticeN){
    //Model object(":/models/sphere.obj");
    Model object(name);
    object.unitize();

    //QVector<QVector3D> vertices =  object.getVertices();

    QVector<unsigned int> indices = object.getIndices();
    QVector<float> buffer = object.getVNTInterleaved_indexed();
    //buffer.reserve(2*sizeof(vertices));//im adding 3 colour to the 3 location bytes



    glGenVertexArrays(1, vao);
    glGenBuffers(1, vbo);
    glGenBuffers(1, ibo);

    glBindVertexArray(*vao);

    glBindBuffer(GL_ARRAY_BUFFER, *vbo);
    glBufferData(GL_ARRAY_BUFFER, buffer.size() * sizeof(float) , &(buffer.at(0)), GL_STATIC_DRAW);
    // &(buffer.at(0) works since the elements are strictly in sequence in memory

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * 4 , indices.data(), GL_STATIC_DRAW);

    *verticeN = (4 * indices.size());
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
