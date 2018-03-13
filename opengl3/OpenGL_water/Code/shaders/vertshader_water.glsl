#version 330 core

// Define constants
#define M_PI 3.141593
#define NWAVES 1

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertNormal_in;
layout (location = 2) in vec2 vertTex_in;

// Specify the Uniforms of the vertex shader
   uniform mat4 u_model;
   uniform mat4 u_vieuw;
   uniform mat4 u_project;
   uniform mat3 u_normalM;

   uniform float u_amplitude[NWAVES];
   uniform float u_frequency[NWAVES];
   uniform float u_phase[NWAVES];


// Specify the output of the vertex stage
out vec3 vertCoord;
out vec3 vertNormal;
out vec2 vertTex;

float waveHeight(int waveIdx, float location)
{
    float amp = u_amplitude[waveIdx];
    float freq = u_frequency[waveIdx];
    float phase = u_phase[waveIdx];
    return amp * sin(2 * M_PI * (freq * location + phase));
}

float waveDelta(int waveIdx, float location)
{
    float amp = u_amplitude[waveIdx];
    float freq = u_frequency[waveIdx];
    float phase = u_phase[waveIdx];
    return amp * freq * cos(2 * M_PI * (freq * location + phase));
}

void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    float z = 0;
    float norm = 0;

    for(int index = 0; index != NWAVES; index++){
        z += waveHeight(index, vertTex_in.x);
        norm += waveDelta(index, vertTex_in.x);
    }

    vec4 current = vec4(vertCoordinates_in.x, vertCoordinates_in.y, z, 1.0);
    current = u_model * current;
    current = u_vieuw * current;
    current = u_project * current;
    gl_Position = current;
    //gl_Position = vec4(vertCoordinates_in, 1.0);


    //bring to tangent space for sphere.
    vec3 normal =  normalize(vec3(0.0 , -norm, 1.0));

    /// normalM in vertex of frag shader
    vertCoord = vec3(current);
    vertNormal = normal * u_normalM;
    vertTex = vertTex_in;

}
