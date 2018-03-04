#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertNormal_in;

// Specify the Uniforms of the vertex shader
   uniform mat4 u_model;
   uniform mat4 u_project;
   uniform mat3 normals;
   uniform vec3 lights;
<<<<<<< HEAD


// Specify the output of the vertex stage
out vec3 vertColor;
out vec4 H, N, V, L;
=======
   uniform vec3 material;
   //uniform vec4 fragNormals;
   //hands off off uniforms, they don't change
   //uniform vec3 H, N;

// Specify the output of the vertex stage
out vec3 vertNormal;
out vec3 ;
//^^
>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173

void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    // Currently without any transformation

    vec4 model = u_model * vec4(vertCoordinates_in, 1.0);
    gl_Position = u_project * model;


    L = vec4(lights, 0) - gl_Position;
    V = gl_Position;
    H = (L + V)/length(L * V);
    N = vec4(normals * gl_Position.xyz,0);


    //gl_Position = vec4(vertCoordinates_in, 1.0);

    vec3 color = vec3(1,0,0);

<<<<<<< HEAD
    vertColor =  color;
=======
    vertNormal =  vertNormal_in * normals;
>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173

}
