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

    size_t objCount = 4;
    QVector<size_t> vertices;
    QVector<GLuint> vaos, vbos, ibos, textures, samplers;
    QVector<QMatrix4x4> models;
    QVector<QVector3D> axi, moveDir, AFPs;
    QVector<float> rspeed;
    size_t time = 0;
    GLuint u_model, u_project, u_vieuw, normals, lights, material, sampler;
    QMatrix4x4 vieuwM, projectM;
    float angleX, angleY, angleZ, magni, walk, rotate;
    QOpenGLShaderProgram  shaderProgramG, shaderProgramP, shaderProgramN;
    QOpenGLShaderProgram *shaderProgram;

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



private slots:
    void onMessageLogged( QOpenGLDebugMessage Message );

private:
    void createShaders();
    void createShaderNormal();
    void createShaderGouraund();
    void createShaderPhong();
    QVector<quint8> imageToBytes(QImage image);
    void loadTexture(QString const texname, GLuint *textureHandle);

    void genCube();
    void genPyra();
    void genObj();
    void genObject(QString name, GLuint *vao, GLuint *vbo, GLuint *ibo, size_t *verticeN);
    void prepset();
    QMatrix4x4 transform(QMatrix4x4 shape, QMatrix3x3 *normal, size_t index);

};

#endif // MAINVIEW_H
