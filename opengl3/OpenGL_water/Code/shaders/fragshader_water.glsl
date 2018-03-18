#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertCoord;
in vec3 vertNormal;
in vec2 vertTex;
in float ratio;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example

uniform mat4 u_project;
uniform vec3 u_light;
uniform vec3 u_material;

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;


void main()
{
    vec3 color = mix(vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 1.0), ratio);

    vec3 normal;
    if (gl_FrontFacing)
        normal = normalize(vertNormal);
    else
        normal = normalize(-vertNormal);

    vec3 lightVec = normalize(u_light - vertCoord);
    vec3 reflectVec = reflect(-lightVec , normal);
    vec3 sightVec = normalize(-vertCoord);

    float ambient = u_material.x;

    float diffuse = max(dot(normal, lightVec), 0.0);
    diffuse = diffuse * u_material.y;

    float specular = dot(reflectVec, sightVec);
    specular = max(specular, 0);
    specular = pow(specular, 25);
//    specular *= u_material.z;

    float illum = ambient + diffuse;
    //float illum = specular;

    color *= illum;
    color += specular * vec3(1.0, 1.0, 1.0);
    color = clamp(color, 0.0, 1.0);

    fColor = vec4(color, 1.0);
    //normal = normalize((normal / 2) + 0.5);
    //fColor = vec4(normal, 1.0);
    //fColor = vec4(vertTex ,0.0 , 1.0);
}
