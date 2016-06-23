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
void DrawLLA(void);

void DrawRUA(void);
void DrawLUL(void);
void DrawRUL(void);
/* End of Modeling Function */
void DrawCubeI(float L, float H, float W);
void DrawCubeF(float Length, float Height, float Width);
void DrawRoof(float Length, float Height, float Width);
void DrawDoor(float Length, float Height, float Width, float door_L, float door_H);
void DrawWindows(float Length, float Height, float Width, float door_L, float door_H, float W_L, float W_H);
void DrawHouse(float Length, float Height, float Width, float door_L, float door_H, float Windows_L, float Windows_H);
void DrawFixWindows(void);
void DrawFixPlane(void);
void DrawVitality(void);
void DrawHouse_0(void);
void DrawTree_0(void);
void DrawSide_0(void);
void CalculateARC(float theta);
extern char string1[10];
extern char string2[10];
extern float Rotated_theta;
extern int id_texture;
extern int id_texture2;
extern float Rotated_X;
extern float Rotated_Y;
extern float Rotated_Z;

#ifdef __cplusplus
}
#endif
#endif