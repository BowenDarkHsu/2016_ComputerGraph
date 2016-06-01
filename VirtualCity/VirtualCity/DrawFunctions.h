#ifndef __DRAWFUNCTIONS_H
#define __DRAWFUNCTIONS_H	
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
#include "myDataStruct.h"
void MovePosition(float x, float y, float z);
/* Modeling Function */
void CreateNode(void);
void PreorderTravesal(TreeNode *root);
void DrawTorso(void);
void DrawHead(void);
void DrawLUA(void);
/* End of Modeling Function */
void DrawCubeF(float Length, float Height, float Width);
void DrawRoof(float Length, float Height, float Width);
void DrawDoor(float Length, float Height, float Width, float door_L, float door_H);
void DrawWindows(float Length, float Height, float Width, float door_L, float door_H, float W_L, float W_H);
void DrawHouse(float Length, float Height, float Width, float door_L, float door_H, float Windows_L, float Windows_H);
void DrawFixWindows(void);
void DrawFixPlane(void);
void DrawVitality(void);
extern char string1[10];
extern char string2[10];
#ifdef __cplusplus
}
#endif
#endif