#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertColor;
<<<<<<< HEAD
in vec4 H, N, V, L;
=======
in vec3 H;
in vec3 N;

>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173
// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example

uniform mat3 normals;
uniform vec3 lights;
uniform vec3 material;
<<<<<<< HEAD

=======
//uniform vec3 H, N;
>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;


void main()
{

    normalize(H);
    normalize(N);
    normalize(V);
    normalize(L);


    float a = material.x;

<<<<<<< HEAD
    float l = dot(L, N);
    l = l>0 ? (l*material.y) : 0;

    float s = dot(N, H);
    s = s>0 ? (s*material.z) : 0;
    s = pow(s, 80);
=======
    float l = dot(lights, N);
    l = l > 0 ? (l * material.y) : 0;

    float s = dot(lights, H);
    s = s > 0 ? (s*material.z) : 0;
    s = pow(s, 20);
>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173

    float gouraund = a + l + s;



    fColor = vec4((gouraund*vertColor), 1.0)/3;
}
