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
    //glDeleteTextures(1, &textureHandle);
    glDeleteBuffers(1, &watVBO);
    glDeleteBuffers(1, &watIBO);
    glDeleteVertexArrays(1, &watVAO);

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
    //glEnable(GL_CULL_FACE);

    // Default is GL_LESS
    glDepthFunc(GL_LEQUAL);

    //loadTexture(":/textures/cat_diff", &textureHandle);
    //glEnable(GL_TEXTURE_2D);

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

    shaderProgram.bind();


 //   glUniformMatrix4fv(u_vieuw, 1, GL_FALSE, vieuwM.data());

    // Draw here

    QVector<float> light( {5.0f, 5.0f, -10.0f});

    QVector<float>  material({0.5f, 0.4f, 0.3f});

    QMatrix3x3 normalM;
    QMatrix4x4 iden = transform(modelM, &normalM);

    glUniformMatrix4fv(u_project, 1, GL_FALSE, projectM.data());
    glUniformMatrix4fv(u_vieuw, 1, GL_FALSE, vieuwM.data());
    glUniform3fv(u_light, 1, light.data());
    glUniform3fv(u_material, 1, material.data());

    //glUniform1i(u_numWaves, numWaves);
    glUniform1fv(u_frequency, numWaves, frequencies.data());
    glUniform1fv(u_amplitude, numWaves, amplitudes.data());
    glUniform1fv(u_phase, numWaves, phases.data());

    glUniformMatrix4fv(u_model, 1, GL_FALSE, iden.data());
    glUniformMatrix3fv(u_normalM, 1, GL_FALSE, normalM.data());

    /*glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureHandle);
    glUniform1i(sampler, 0); */
    glBindVertexArray(watVAO);
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

    //magni = static_cast<float>(scale) / 100;
    magni = static_cast<float>(100 - ((100 - scale) * 4)) / 100;

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

