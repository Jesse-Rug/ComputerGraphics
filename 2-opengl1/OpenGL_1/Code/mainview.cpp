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
    glDeleteBuffers(1, &cubVBO);
    glDeleteBuffers(1, &cubIBO);
    glDeleteBuffers(1, &pyrVBO);
    glDeleteBuffers(1, &pyrIBO);
    glDeleteBuffers(1, &sphVBO);
    glDeleteBuffers(1, &sphIBO);
    glDeleteVertexArrays(1, &cubVAO);
    glDeleteVertexArrays(1, &pyrVAO);
    glDeleteVertexArrays(1, &sphVAO);
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

    // Set the color of the screen to be black on clear (new frame)
    glClearColor(0.2f, 0.5f, 0.7f, 0.0f);


    genObj();

    prepset();

    createShaderPhong();

}

void MainView::createShaderProgram()
{
    // Create shader program
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_normal.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_normal.glsl");
    shaderProgram.link();

    if (!shaderProgram.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgram.uniformLocation("u_model");
    u_project= shaderProgram.uniformLocation("u_project");
    normals = shaderProgram.uniformLocation("normals");
}


void MainView::createShaderPhong(){
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_phong.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_phong.glsl");
    shaderProgram.link();

    if (!shaderProgram.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgram.uniformLocation("u_model");
    u_project= shaderProgram.uniformLocation("u_project");
    normals = shaderProgram.uniformLocation("normals");
    lights = shaderProgram.uniformLocation("ligths");
    material = shaderProgram.uniformLocation("material");



}

void MainView::createShaderGouraund(){
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_gouraud.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_gouraund.glsl");
    shaderProgram.link();

    if (!shaderProgram.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgram.uniformLocation("u_model");
    u_project= shaderProgram.uniformLocation("u_project");
    normals = shaderProgram.uniformLocation("normals");
    lights = shaderProgram.uniformLocation("ligths");
    material = shaderProgram.uniformLocation("material");



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

    shaderProgram.bind();


    glUniformMatrix4fv(u_project, 1, GL_FALSE, projectM.data());

    // Draw here

    QMatrix4x4 iden = transform(modelC);
    QMatrix3x3 normalIden(iden.normalMatrix());
    QMatrix4x4 lightMat;
    QVector3D light;
    lightMat.setToIdentity();
    transform(lightMat);
    light.setX(lightMat(0,0));
    light.setY(lightMat(1,1));
    light.setZ(lightMat(2,2));

    QVector3D  mat(0.5f, 0.8f, 0.3f);

    shaderProgram.setUniformValue("lights", light);
    shaderProgram.setUniformValue("material", mat);

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

    glUniformMatrix4fv(u_model, 1, GL_FALSE, iden.data());
    glUniformMatrix3fv(normals, 1, GL_FALSE, normalIden.data());
    glBindVertexArray(sphVAO);
    glBindBuffer(GL_ARRAY_BUFFER, sphVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphIBO);
    glDrawElements(GL_TRIANGLES, verticeNumber, GL_UNSIGNED_INT, (GLvoid*)0);

    shaderProgram.release();
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

