#ifndef __DRAWFUNCTIONS_H
#define __DRAWFUNCTIONS_H	
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
#include "myDataStruct.h"
void MovePosition(float x, float y, float z);
void DrawCubeF(float Length, float Height, float Width);
void DrawRoof(float Length, float Height, float Width);
void DrawDoor(float Length, float Height, float Width, float door_L, float door_H);
#ifdef __cplusplus
}
#endif
#endif