#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertNormals_in;
layout (location = 2) in vec2 vertTex_in;

// Specify the Uniforms of the vertex shader
   uniform mat4 u_model;
   uniform mat4 u_project;
   uniform mat3 normals;
   uniform vec3 lights;
   uniform vec3 material;


// Specify the output of the vertex stage
out vec3 vertColor;
out vec2 vertTex;


void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    // Currently without any transformation


    vec4 model = u_model * vec4(vertCoordinates_in, 1.0);
    gl_Position = u_project * model;
    //gl_Position = vec4(vertCoordinates_in, 1.0);

    vec3  lightvec = normalize(lights - vec3(model));
    // "normals" is the normal ADJUSTMENT matrix.
    vec3  adjust = normals * vertNormals_in;
    vec3 reflect =  reflect( lightvec, adjust);
    vec3 incomL = normalize( -gl_Position.xyz );

    float ambient = material.x;

    float diffuse = max(dot(lightvec, adjust), 0.0);
    diffuse = diffuse * material.y;

    float specular = dot(reflect, incomL);
    specular = max(specular * material.z , 0);
    specular = pow(specular, 20);

    float gouraund = ambient + diffuse + specular;
    //float gouraund = s;
    vec3 col = vec3(0.5, 0.5, 0.5);

    vertColor = vec3(gouraund);
    vertTex = vertTex_in;
}

/*

// ambient = mat.x 
// defuse = mat.y
// specular = mat.z
  */
