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
    GLuint watVAO, watVBO, watIBO;
  //  GLuint textureHandle, samplerHandle;
    GLuint u_model, u_project, u_vieuw;
    GLuint u_normalM, u_light, u_material;
    int numWaves;
    GLuint u_amplitude, u_frequency, u_phase;
    QMatrix4x4 modelM;
    QMatrix4x4 projectM;
    QMatrix4x4 vieuwM;
    float angleX, angleY, angleZ, magni;
    QVector<float> amplitudes, frequencies, phases;
    QOpenGLShaderProgram  shaderProgram;

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
    void createShaderPhong();
    void createShaderWater();
    QVector<quint8> imageToBytes(QImage image);

    void genObj();
    void genObject(QString name);
    void prepset();
    void loadTexture(QString const texname, GLuint *textureHandle);
    QMatrix4x4 transform(QMatrix4x4 shape, QMatrix3x3 *normal);

};

#endif // MAINVIEW_H
