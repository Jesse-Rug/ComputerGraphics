#include "mainview.h"

void MainView::createShaders()
{
    createShaderWater();
}

/*
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

} */

void MainView::createShaderWater(){
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex,
                                           ":/shaders/vertshader_water.glsl");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment,
                                           ":/shaders/fragshader_water.glsl");
    shaderProgram.link();

    if (!shaderProgram.link()){
        exit(EXIT_FAILURE);
    }

    u_model = shaderProgram.uniformLocation("u_model");
    u_vieuw = shaderProgram.uniformLocation("u_vieuw");
    u_project = shaderProgram.uniformLocation("u_project");

    u_normalM = shaderProgram.uniformLocation("u_normalM");
    u_light = shaderProgram.uniformLocation("u_light");
    u_material = shaderProgram.uniformLocation("u_material");

    u_amplitude = shaderProgram.uniformLocation("u_amplitude");
    u_frequency = shaderProgram.uniformLocation("u_frequency");
    u_phase = shaderProgram.uniformLocation("u_phase");
    u_time = shaderProgram.uniformLocation("u_time");


}

