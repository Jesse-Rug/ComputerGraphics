#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertCoord;
in vec3 vertNormal;
in vec2 vertTex;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example

//uniform mat3 normals;
uniform vec3 u_light;
uniform vec3 u_material;

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;


void main()
{
    //fColor = vec4(vertTex ,0.0 , 1.0);
    vec3 normal = normalize((vertNormal/2) + 0.5);
    fColor = vec4(normal, 1.0);
}
