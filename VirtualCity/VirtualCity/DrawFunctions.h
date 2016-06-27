#ifndef __DRAWFUNCTIONS_H
#define __DRAWFUNCTIONS_H	
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
#include "myDataStruct.h"
#define DebugMode 0
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
float f_abs(float x, float y);
void CameraForward(void);
void CameraBackward(void);
void CameraLeftward(void);
void CameraRightward(void);

void DrawTriangleTexture(float L, float H, float W, int texture);

void DrawObjHouse2(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture);
void DrawObjHouse1(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture);
void DrawObjCube05(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture);
void DrawObjCube10(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture);
void DrawObjTree(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture);
ObjBox* FindLastNode(ObjBox *obj);
void DeleteNode(ObjBox *obj);
bool CheckObjTouchFlow(ObjBox *obj);
void CheckTouch(ObjBox *obj, ObjectBoundary *obj_B);
void CheckObjFlagFlow(ObjBox *obj);
void DrawObjFlow(ObjBox *obj);
void DrawCenterLine(void);

void checkTouch3(ObjBox *obj, float m0U, float m0D, float m1U, float m1D, float m2U, float m2D);
void checkTouch2(ObjBox *obj, float xU, float yU, float zU, float xD, float yD, float zD);
void checkTouch(ObjBox *obj);
void DrawFixObj(void);
void DrawCubeTexture(float L, float H, float W, int texture);
extern char string1[10];
extern char string2[10];
extern float Rotated_theta;
extern int id_texture;
extern int id_texture2;
extern int id_texture3;
extern float Rotated_X;
extern float Rotated_Y;
extern float Rotated_Z;
extern float PosXUnit;
extern float PosZUnit;
extern int id_texture4;
extern bool WorldCollFalg;
extern GLfloat D[8][3];
#ifdef __cplusplus
}
#endif
#endif