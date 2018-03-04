#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertNormals_in;

// Specify the Uniforms of the vertex shader
   uniform mat4 u_model;
   uniform mat4 u_project;
   uniform mat3 normals;
   uniform vec3 lights;
   uniform vec3 material;
   uniform vec4 pos;


// Specify the output of the vertex stage
out vec3 vertColor;


void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    // Currently without any transformation


    vec4 model = u_model * vec4(vertCoordinates_in, 1.0);
    gl_Position = u_project * model;
    //gl_Position = vec4(vertCoordinates_in, 1.0);
<<<<<<< HEAD
     vec3 L = lights - gl_Position.xyz;
    vec3 H = (L + gl_Position.xyz)/length(L * gl_Position.xyz);
    vec3  N = normals * gl_Position.xyz;
=======
>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173

    vec3  lightvec = normalize(lights - vec3(model));
    // "normals" is the normal ADJUSTMENT matrix.
    vec3  adjust = normals * vertNormals_in;
    vec3  norm = adjust * gl_Position.xyz;
    vec3 reflect = reflect(-lightvec, adjust);
    vec3 incomL = normalize( gl_Position.xyz );

<<<<<<< HEAD
    float l = dot(L, N);
    l = l>0 ? (l*material.y) : 0;

    float s = dot(N, H);
    s = s>0 ? (s*material.z) : 0;
    s = pow(s, 20);
=======
    float ambient = material.x;

    float diffuse = max(dot(lightvec, adjust), 0.0);
    diffuse = diffuse * material.y;
>>>>>>> 1640ec216327627e59d523fe06197fddba3fb173


    float specular = dot(reflect, incomL);
    specular = max(specular * material.z , 0);
    specular = pow(specular, 20);

    //float gouraund = ambient + defuse + specular;
    float gouraund = specular;
    vec3 col = vec3(0.5, 0.5, 0.5);

    vertColor = col * gouraund;
}

/*


in vec3 VertexPosition;
in vec3 VertexNormal;


struct LightInfo
{
        vec3 Position;	//Light Position in eye-coords
        vec3 La;		//Ambient light intensity
        vec3 Ld;		//Diffuse light intensity
        vec3 Ls;		//Specular light intensity
};

struct MaterialInfo
{
        vec3 Ka;			//Ambient reflectivity
        vec3 Kd;			//Diffuse reflectivity
        vec3 Ks;			//Specular reflectivity
        float Shininess;	//Specular shininess factor
};

uniform LightInfo Light[LIGHTCOUNT];
uniform MaterialInfo Material;

uniform mat4 u_model;
uniform mat3 NormalMatrix;
uniform mat4 MVP;


void getEyeSpace( out vec3 norm, out vec3 position )
{
        norm = normalize( NormalMatrix * VertexNormal );
        position = vec3( u_model * vec4( VertexPosition, 1 ) );
}

vec3 light( int lightIndex, vec3 position, vec3 norm )
{
        vec3 s = normalize( vec3( lightPos - position ) );
        vec3 v = normalize( -position.xyz );
        vec3 r = reflect( -s, norm );

        vec3 ambient = 0.1 * Material.Ka;

        float sDotN = max( dot( s, norm ), 0.0 );
        vec3 diffuse = 1 * Material.Kd * sDotN;

        vec3 spec = vec3( 0.0 );
        if ( sDotN > 0.0 )
                spec =1 * Material.Ks * pow( max( dot(r,v) , 0.0 ), Material.Shininess );

        return ambient + diffuse + spec;
}

void main()
{
        vec3 norm = normalize( NormalMatrix * VertexNormal );
        vec3 position = vec3( u_model * vec4( VertexPosition, 1 ) );
        getEyeSpace( eyeNorm, position );

        data.FrontColor = vec3(0);

        vec3 lightvec = normalize( vec3( lightPos - position ) );
        vec3 incomL = normalize( -position.xyz );
        vec3 optimR = reflect( -lightvec, norm );

        vec3 ambient = 0.1 * material.x;

        float sDotN = max( dot( lightvec, norm ), 0.0 );
        vec3 diffuse = 1 * material.y * sDotN;

        vec3 spec = vec3( 0.0 );
        if ( sDotN > 0.0 )
                spec = 1 * material.z * pow( max( dot(optimR, incomL) , 0.0 ), Material.Shininess );

        return ambient + diffuse + spec;

        //data.TexCoord = VertexTex;
        gl_Position = MVP * vec4( VertexPosition, 1 );
}

// ambient = mat.x 
// defuse = mat.y
// specular = mat.z
  */
