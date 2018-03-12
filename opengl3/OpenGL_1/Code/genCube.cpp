#include "mainview.h"

void MainView::genCube() {

    glGenVertexArrays(1, &cubVAO);
    glGenBuffers(1, &cubVBO);
    glGenBuffers(1, &cubIBO);

    std::vector<float> cubus{
        //x, y ,z
        // r, g, b

        //from front

        //front left
        -1,  1,  1,
         1,  0,  0,

        -1, -1,  1,
         1,  0,  0,


        // front right
         1,  1,  1,
         0,  1,  0,

         1, -1,  1,
         0,  1,  0,


        //back left
        -1,  1, -1,
         0,  0,  1,

        -1, -1, -1,
         0,  0,  1,


        // back right
         1,  1, -1,
         1,  1,  0,

         1, -1, -1,
         1,  1,  0,

    };

    GLubyte order[]{
        //order
      //top left , top right , bottom right
      //top left , bottom right , bottom left

        //vertice order; fl, fr, bl, br

        //front face V
        0, 1, 3,
        0, 3, 2,

        //right face
        2, 3, 7,
        2, 7, 6,

        //back face V
        4, 7, 5,
        4, 6, 7,

        //left face
        4, 5, 1,
        4, 1, 0,

        //top face
        4, 0, 2,
        4, 2, 6,

        // bottom face
        7, 3, 1,
        7, 1, 5

    };

    glBindVertexArray(cubVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * cubus.size() , &(cubus.at(0)), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubIBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(order), &order, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), ((GLvoid*) (3 * sizeof(GLfloat))));

}
