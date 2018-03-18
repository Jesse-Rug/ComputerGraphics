#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertColor;
in vec2 vertTex;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example

uniform sampler2D sampler;

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;


void main()
{
    vec4 textureColor = texture(sampler, vertTex);
    fColor = vec4(vertColor, 1.0) * textureColor;
}
