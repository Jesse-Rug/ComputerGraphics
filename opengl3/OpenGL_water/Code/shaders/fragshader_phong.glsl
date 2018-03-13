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

uniform vec3 lights;
uniform vec3 material;
uniform mat4 u_project;
uniform sampler2D sampler;

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;


void main()
{
    vec3 lightvec = normalize(lights - vertCoord);
    vec3 reflect =  reflect( lightvec, vertNormal);
    vec4 vieuwvec = u_project * vec4(vertCoord,1.0);
    vec3 incomL = normalize(-1 * vieuwvec.xyz);

    float ambient = material.x;

    float diffuse = max(dot(lightvec, vertNormal), 0.0);
    diffuse = diffuse * material.y;

    float specular = dot(reflect, incomL);
    specular = max(specular * material.z , 0);
    specular = pow(specular, 20);

    float gouraund = ambient + diffuse;

    vec4 textureColor = texture2D(sampler, vertTex);
    fColor = gouraund * textureColor;
}
