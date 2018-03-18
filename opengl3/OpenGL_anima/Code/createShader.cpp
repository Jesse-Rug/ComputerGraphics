#include "mainview.h"

void MainView::createShaders()
{
    createShaderGouraund();
    createShaderNormal();
    createShaderPhong();
    shaderProgram = &shaderProgramP;
}

void MainView::createShaderNormal()
{
    // Create shader program
    shaderProgramN.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_normal.glsl");
    shaderProgramN.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_normal.glsl");
    shaderProgramN.link();

    if (!shaderProgramN.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgramN.uniformLocation("u_model");
    u_vieuw = shaderProgramN.uniformLocation("u_vieuw");
    u_project = shaderProgramN.uniformLocation("u_project");
    normals = shaderProgramN.uniformLocation("normals");
}


void MainView::createShaderPhong(){
    shaderProgramP.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_phong.glsl");
    shaderProgramP.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_phong.glsl");
    shaderProgramP.link();

    if (!shaderProgramP.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgramP.uniformLocation("u_model");
    u_vieuw = shaderProgramP.uniformLocation("u_vieuw");
    u_project= shaderProgramP.uniformLocation("u_project");
    normals = shaderProgramP.uniformLocation("normals");
    lights = shaderProgramP.uniformLocation("ligths");
    material = shaderProgramP.uniformLocation("material");
    sampler = shaderProgramP.uniformLocation("sampler");



}

void MainView::createShaderGouraund(){
    shaderProgramG.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_gouraud.glsl");
    shaderProgramG.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_gouraund.glsl");
    shaderProgramG.link();

    if (!shaderProgramG.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgramG.uniformLocation("u_model");
    u_vieuw = shaderProgramG.uniformLocation("u_vieuw");
    u_project= shaderProgramG.uniformLocation("u_project");
    normals = shaderProgramG.uniformLocation("normals");
    lights = shaderProgramG.uniformLocation("ligths");
    material = shaderProgramG.uniformLocation("material");
    sampler = shaderProgramG.uniformLocation("sampler");


}
