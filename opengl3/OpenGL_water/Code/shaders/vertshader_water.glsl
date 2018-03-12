#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertColor_in;
layout (location = 2) in vec2 vertTex_inl

// Specify the Uniforms of the vertex shader
   uniform mat4 u_model;
   uniform mat4 u_vieuw;
   uniform mat4 u_project;


// Specify the output of the vertex stage
out vec3 vertColor;
out vec2 vertTex;

void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    // Currently without any transformation
    vec4 current = u_model * vec4(vertCoordinates_in, 1.0);
    current = u_vieuw * current;
    current = u_project * current;
    gl_Position = current;
    //gl_Position = vec4(vertCoordinates_in, 1.0);


    vertColor = vertColor_in;
    vertTex = vertTex_in;

}
