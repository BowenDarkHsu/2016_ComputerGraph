#ifndef __MYLIGHT_H
#define __MYLIGHT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"

typedef struct Ambient_Parameter{
	GLfloat Red = 0.0;
	GLfloat Green = 0.0;
	GLfloat Blue = 0.0;
	GLfloat IsPoint(bool p);
};

typedef struct Diffuse_Parameter{
	GLfloat Red = 1.0;
	GLfloat Green = 1.0;
	GLfloat Blue = 1.0;
	GLfloat IsPoint(bool p);
};
typedef struct Specular_Parameter{
	GLfloat Red = 1.0;
	GLfloat Green = 1.0;
	GLfloat Blue = 1.0;
	GLfloat IsPoint(bool p);
};
typedef struct Position_Parameter{
	GLfloat X = 0.0;
	GLfloat Y = 0.0;
	GLfloat Z = 0.0;
	GLfloat IsPoint(bool p);
};

typedef struct glLight_Parameter{
	Ambient_Parameter Ambient;
	Diffuse_Parameter Diffuse;
	Specular_Parameter Specular;
	Position_Parameter Position;
};
typedef struct glMaterial_Parameter{
	Ambient_Parameter Ambient;
	Diffuse_Parameter Diffuse;
	Specular_Parameter Specular;
	GLfloat Shininess;
};
#define Init_Light_Ambient_Red 3.0
#define Init_Light_Ambient_Green 1.0
#define Init_Light_Ambient_Blue -9.0
#define Init_Light_Position_X -3.5
#define Init_Light_Position_Y -3.5
#define Init_Light_Position_Z -10.0

extern glLight_Parameter mySource_1;
extern glMaterial_Parameter myMaterial_1;
void LightSource(void);
void LightSource2(void);
void LightSource3(void);
GLfloat IsPoint(bool p);
void SetupLight_Parameter(int source, glLight_Parameter Svalue,bool IsPoint);
void InitLight_Ambient(glLight_Parameter Svalue);
#ifdef __cplusplus
}
#endif
#endif