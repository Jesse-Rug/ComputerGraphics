#include "mainview.h"

void MainView::createShaders()
{
    createShaderPhong();
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
    sampler = shaderProgram.uniformLocation("sampler");



}

