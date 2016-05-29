#ifndef __MYLIGHT_H
#define __MYLIGHT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
#include "myDataStruct.h"

#define Init_Light_Ambient_Red 3.0
#define Init_Light_Ambient_Green 1.0
#define Init_Light_Ambient_Blue -9.0
#define Init_Light_Position_X -3.5
#define Init_Light_Position_Y -3.5
#define Init_Light_Position_Z -10.0


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