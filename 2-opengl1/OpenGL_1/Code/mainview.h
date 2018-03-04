#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "model.h"
#include "utils.h"

#include <QKeyEvent>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLDebugLogger>
#include <QOpenGLShaderProgram>
#include <QTimer>
#include <QVector3D>
#include <memory>

class MainView : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

    QOpenGLDebugLogger *debugLogger;
    QTimer timer; // timer used for animation

    size_t verticeNumber;
    GLuint cubVAO, cubVBO, cubIBO;
    GLuint pyrVAO, pyrVBO, pyrIBO;
    GLuint sphVAO, sphVBO, sphIBO;
    GLuint textureHandle;
    GLuint u_model, u_project, normals, lights, material;
    QMatrix4x4 modelC, modelP, modelS;
    QMatrix4x4 projectM;
    float angleX, angleY, angleZ, magni;
    QOpenGLShaderProgram shaderProgram;

public:
    enum ShadingMode : GLuint
    {
        PHONG = 0, NORMAL, GOURAUD
    };

    MainView(QWidget *parent = 0);
    ~MainView();

    // Functions for widget input events
    void setRotation(int rotateX, int rotateY, int rotateZ);
    void setScale(int scale);
    void setShadingMode(ShadingMode shading);

protected:
    void initializeGL();
    void resizeGL(int newWidth, int newHeight);
    void paintGL();

    // Functions for keyboard input events
    void keyPressEvent(QKeyEvent *ev);
    void keyReleaseEvent(QKeyEvent *ev);

    // Function for mouse input events
    void mouseDoubleClickEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void wheelEvent(QWheelEvent *ev);


    void genCube();
    void genPyra();
    void genObj();
    void genObject(QString name);
    void prepset();
    QMatrix4x4 transform(QMatrix4x4 shape);

private slots:
    void onMessageLogged( QOpenGLDebugMessage Message );

private:
    void createShaderProgram();
    void createShaderGouraund();
    void createShaderPhong();

};

#endif // MAINVIEW_H
