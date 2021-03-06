#include "mainview.h"
#include "math.h"

#include <QDateTime>

/**
 * @brief MainView::MainView
 *
 * Constructor of MainView
 *
 * @param parent
 */
MainView::MainView(QWidget *parent) : QOpenGLWidget(parent) {
    qDebug() << "MainView constructor";

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
}

/**
 * @brief MainView::~MainView
 *
 * Destructor of MainView
 * This is the last function called, before exit of the program
 * Use this to clean up your variables, buffers etc.
 *
 */
MainView::~MainView() {
    glDeleteTextures(1, &textureHandle);
    glDeleteBuffers(1, &cubVBO);
    glDeleteBuffers(1, &cubIBO);
    glDeleteBuffers(1, &pyrVBO);
    glDeleteBuffers(1, &pyrIBO);
    glDeleteBuffers(1, &sphVBO);
    glDeleteBuffers(1, &sphIBO);
    glDeleteVertexArrays(1, &cubVAO);
    glDeleteVertexArrays(1, &pyrVAO);
    glDeleteVertexArrays(1, &sphVAO);

    glDeleteTextures(1, &textureHandle);
    debugLogger->stopLogging();

    qDebug() << "MainView destructor";
}

// --- OpenGL initialization

/**
 * @brief MainView::initializeGL
 *
 * Called upon OpenGL initialization
 * Attaches a debugger and calls other init functions
 */
void MainView::initializeGL() {
    qDebug() << ":: Initializing OpenGL";
    initializeOpenGLFunctions();

    debugLogger = new QOpenGLDebugLogger();
    connect( debugLogger, SIGNAL( messageLogged( QOpenGLDebugMessage ) ),
             this, SLOT( onMessageLogged( QOpenGLDebugMessage ) ), Qt::DirectConnection );

    if ( debugLogger->initialize() ) {
        qDebug() << ":: Logging initialized";
        debugLogger->startLogging( QOpenGLDebugLogger::SynchronousLogging );
        debugLogger->enableMessages();
    }

    QString glVersion;
    glVersion = reinterpret_cast<const char*>(glGetString(GL_VERSION));
    qDebug() << ":: Using OpenGL" << qPrintable(glVersion);

    // Enable depth buffer
    glEnable(GL_DEPTH_TEST);

    // Enable backface culling
    glEnable(GL_CULL_FACE);

    // Default is GL_LESS
    glDepthFunc(GL_LEQUAL);

    //loadtexture.cc
    QImage imageq(":/textures/cat_diff");
    QVector<quint8> imagev(imageToBytes(imageq));
    glGenTextures(1, &textureHandle);
    glBindTexture(GL_TEXTURE_2D, textureHandle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imageq.width(), imageq.height(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, imagev.data());
    glEnable(GL_TEXTURE_2D);

    // Set the color of the screen to be black on clear (new frame)
    glClearColor(0.2f, 0.5f, 0.7f, 0.0f);


    genObj();

    prepset();

    createShaders();

}



// --- OpenGL drawing

/**
 * @brief MainView::paintGL
 *
 * Actual function used for drawing to the screen
 *
 */
void MainView::paintGL() {
    // Clear the screen before rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shaderProgram->bind();


    glUniformMatrix4fv(u_project, 1, GL_FALSE, projectM.data());

    // Draw here

    QMatrix4x4 iden = transform(modelC);
    QMatrix3x3 normalIden(iden.normalMatrix());

    QVector3D light(5.0, 5.0, -10.0);

    QVector3D  mat(0.5f, 0.4f, 0.3f);

    shaderProgram->setUniformValue("lights", light);
    shaderProgram->setUniformValue("material", mat);

    glUniformMatrix4fv(u_model, 1, GL_FALSE, iden.data());
    glUniformMatrix3fv(normals, 1, GL_FALSE, normalIden.data());
    glBindVertexArray(cubVAO);
    glBindBuffer(GL_ARRAY_BUFFER, cubVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubIBO);
    //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, (GLvoid*)0);

    iden = transform(modelP);
    normalIden = iden.normalMatrix();

    glUniformMatrix4fv(u_model, 1, GL_FALSE, iden.data());
    glUniformMatrix3fv(normals, 1, GL_FALSE, normalIden.data());
    glBindVertexArray(pyrVAO);
    glBindBuffer(GL_ARRAY_BUFFER, pyrVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, pyrIBO);
    //glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_BYTE, (GLvoid*)0);

    iden = transform(modelS);
    normalIden = iden.normalMatrix();

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureHandle);
    glUniform1i(sampler, 0);
    glUniformMatrix4fv(u_model, 1, GL_FALSE, iden.data());
    glUniformMatrix3fv(normals, 1, GL_FALSE, normalIden.data());
    glBindVertexArray(sphVAO);
    glBindBuffer(GL_ARRAY_BUFFER, sphVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphIBO);
    glDrawElements(GL_TRIANGLES, verticeNumber, GL_UNSIGNED_INT, (GLvoid*)0);

    shaderProgram->release();
}

/**
 * @brief MainView::resizeGL
 *
 * Called upon resizing of the screen
 *
 * @param newWidth
 * @param newHeight
 */
void MainView::resizeGL(int newWidth, int newHeight) 
{
    // TODO: Update projection to fit the new aspect ratio
    Q_UNUSED(newWidth)
    Q_UNUSED(newHeight)
    projectM.setToIdentity();
    projectM.perspective(60.0 , (float) newWidth/newHeight, .1, 100.0);
    //projectM.perspective(60.0 , 1.0, .1, 100.0);
}

// --- Public interface

void MainView::setRotation(int rotateX, int rotateY, int rotateZ)
{
    qDebug() << "Rotation changed to (" << rotateX << "," << rotateY << "," << rotateZ << ")";

    angleX = rotateX;
    angleY = rotateY;
    angleZ = rotateZ;


    repaint();

}

void MainView::setScale(int scale)
{
    qDebug() << "Scale changed to " << scale;

    magni = static_cast<float>(scale) / 100;

    repaint();
}

void MainView::setShadingMode(ShadingMode shading)
{
    qDebug() << "Changed shading to" << shading;

    if (shading == ShadingMode::PHONG){
        u_model = shaderProgramP.uniformLocation("u_model");
        u_project= shaderProgramP.uniformLocation("u_project");
        normals = shaderProgramP.uniformLocation("normals");
        lights = shaderProgramP.uniformLocation("ligths");
        material = shaderProgramP.uniformLocation("material");
        sampler = shaderProgramP.uniformLocation("sampler");

        shaderProgram = &shaderProgramP;


    }

    if (shading == ShadingMode::NORMAL){
        u_model = shaderProgramN.uniformLocation("u_model");
        u_project= shaderProgramN.uniformLocation("u_project");
        normals = shaderProgramN.uniformLocation("normals");
        lights = 0;
        material = 0;
        sampler = 0;

        shaderProgram = &shaderProgramN;
    }

    if (shading == ShadingMode::GOURAUD){
        u_model = shaderProgramG.uniformLocation("u_model");
        u_project= shaderProgramG.uniformLocation("u_project");
        normals = shaderProgramG.uniformLocation("normals");
        lights = shaderProgramG.uniformLocation("ligths");
        material = shaderProgramG.uniformLocation("material");
        sampler = shaderProgramG.uniformLocation("sampler");


        shaderProgram = &shaderProgramG;
    }
}

// --- Private helpers

/**
 * @brief MainView::onMessageLogged
 *
 * OpenGL logging function, do not change
 *
 * @param Message
 */
void MainView::onMessageLogged( QOpenGLDebugMessage Message ) {
    qDebug() << " → Log:" << Message;
}

