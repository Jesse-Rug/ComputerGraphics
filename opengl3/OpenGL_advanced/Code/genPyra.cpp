#include "mainview.h"

void MainView::genPyra() {
    glGenBuffers(1, &pyrVBO);
    glGenBuffers(1, &pyrIBO);
    glGenVertexArrays(1, &pyrVAO);

    float pyramid[]{
        //x, y ,z
        // r, g, b

        //from front
        //peak
        0,  1,  0,
        1,  1,  1,

        //front left
        -1, -1,  1,
         1,  0,  0,


        // front right
         1, -1,  1,
         0,  1,  0,


        //back left
        -1, -1, -1,
         0,  0,  1,


        // back right
         1, -1, -1,
         1,  1,  0,

    };

    GLubyte order2[]{
        //order
      //top, right, left

        //vertice order; fl, fr, bl, br

        //front face
        0, 1, 2,

        //right face
        0, 2, 4,

        //back face
        0, 4, 3,

        //left face
        0, 3, 1,

        // bottom face
        4, 2, 1,
        4, 1, 3

    };

    glBindVertexArray(pyrVAO);

    glBindBuffer(GL_ARRAY_BUFFER, pyrVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(pyramid), &pyramid, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pyrIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(order2), &order2, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), ((GLvoid*) (3 * sizeof(GLfloat))));

}

