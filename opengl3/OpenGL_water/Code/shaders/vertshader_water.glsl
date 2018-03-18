#version 330 core

// Define constants
#define M_PI 3.141593
#define NWAVES 2

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
   uniform float u_time;


// Specify the output of the vertex stage
out vec3 vertCoord;
out vec3 vertNormal;
out vec2 vertTex;
out float ratio;

float waveHeight(int waveIdx, float location)
{
    float amp = u_amplitude[waveIdx];
    float freq = u_frequency[waveIdx];
    float phase = u_phase[waveIdx];
    return amp * sin(2 * M_PI * (freq * location + phase + u_time));
}

float waveDelta(int waveIdx, float location)
{
    float amp = u_amplitude[waveIdx];
    float freq = u_frequency[waveIdx];
    float phase = u_phase[waveIdx];
    return amp * freq * cos(2 * M_PI * (freq * location + phase + u_time));
}

vec3 tangentNormal(vec3 normal, vec3 adapt)
{
    //work smart not hard
    if(normal.x == 0 && normal.y == 0)
        return adapt;

    vec3 tang = (normal.z == 0) ? vec3(0, 0, 1) :
                vec3(-normal.xy, (-normal.x - normal.y)/-normal.z);
    tang = normalize(tang);
    vec3 bitan = cross(normal, tang);
    bitan = normalize(tang);
    if (normal.z < 0)
        bitan *= -1;

    mat3 tangentSpace;
    tangentSpace[0] = vec3(tang.x, bitan.x, normal.x);
    tangentSpace[0] = vec3(tang.y, bitan.y, normal.y);
    tangentSpace[0] = vec3(tang.z, bitan.z, normal.z);

    //return normalize(tangentSpace * adapt);
    return (tangentSpace * adapt);
}

void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    float height = 0;
    float norm = 0;
    float maxAmp = 0;

    for(int index = 0; index != NWAVES; index++){
        height += waveHeight(index, vertTex_in.x);
        norm += waveDelta(index, vertTex_in.x);
        maxAmp += abs(u_amplitude[index]);
    }

    vec4 current = vec4(vertCoordinates_in + vertNormal_in * 0 * height, 1.0);
    current = u_model * current;
    current = u_vieuw * current;
    gl_Position = u_project * current;
    //gl_Position = vec4(vertCoordinates_in, 1.0);


    //bring to tangent space for sphere.
    vec3 normal =  tangentNormal(vertNormal_in ,normalize(vec3(0.0 , -norm, 1)));

    /// normalM in vertex of frag shader
    vertCoord = vec3(current);
    vertNormal = u_normalM * normal;
    vertTex = vertTex_in;
    ratio = smoothstep(-maxAmp, maxAmp, height);

}
