#ifndef UTILS_H
#define UTILS_H

#include "model.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLDebugLogger>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QVector3D>
#include <memory>

void genCube(GLuint VAO, GLuint VBO, GLuint IBO);
void genPyra(GLuint VAO, GLuint VBO, GLuint IBO);

#endif // UTILS_H
