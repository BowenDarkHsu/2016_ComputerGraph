#ifndef __MYGL_INIT_H
#define __MYGL_INIT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
#define DisplayMode 0
#define OpenTexture 0
#define ShowDirValue 1
	void initParticle(void);
	void parDisplay(void);
	float forces(int i, int j);
	void collision(int i);
	void parIdle(void);
void myMouse(int button, int state, int x, int y);
void myKeyboard(unsigned char key, int x, int y);
void myMenuInit();
void myMenu(int id);
void OpenGL_Init(int argc, char** argv);
void myInit();
void myTexture();
void LookAt_X_MenuFunc(int id);
void LookAt_Y_MenuFunc(int id);
void LookAt_Z_MenuFunc(int id);
void InitObjBoundary(void);

extern void myDisplay();
extern int tempX1;
extern int tempX2;
extern float Rotated_theta;
extern float Rotated_X;
extern float Rotated_Y;
extern float Rotated_Z;
extern int id_texture2;
extern int id_texture3;
extern int id_texture4;
extern float Fixed_Z;
extern float Z1;
extern float X1;
extern bool BackFalg;
extern bool ForwardFalg;
extern bool RightFalg;
extern bool LeftFalg;
extern float RotateAngle;
extern int RoatateCnt;
extern float MoveValeZ;

extern float Py;
extern float Px;
extern float Pz;
extern float Wx;
extern float Wz;
extern float BoundPxU;
extern float BoundPxD;
extern float BoundPzU;
extern float BoundPzD;
extern float BoundWxU;
extern float BoundWxD;
extern float BoundWzU;
extern float BoundWzD;
extern bool BoundPx;
extern bool BoundPz;
extern bool BoundWx;
extern bool BoundWz;
extern float ObjA_w; // z
extern float ObjA_h; // y
extern float ObjA_l; // x
extern float objBox1[16];
extern float BoundPyU;
extern float BoundPyD;
extern bool BoundPy;
extern bool BoundObjBox1;
extern float H_PxU;  //m2
extern float H_PxD;
extern float H_PzU;    //m3
extern float H_PzD;
extern float H_PyU;   //m1
extern float H_PyD;
extern float BC05m0_U;
extern float BC05m0_D;
extern float BC05m1_U;
extern float BC05m1_D;
extern float BC05m2_U;
extern float BC05m2_D;
//
extern float BH121m0_U;
extern float BH121m0_D;
extern float BH121m1_U;
extern float BH121m1_D;
extern float BH121m2_U;
extern float BH121m2_D;
//
extern float BTreem0_U;
extern float BTreem0_D;
extern float BTreem1_U;
extern float BTreem1_D;
extern float BTreem2_U;
extern float BTreem2_D;
extern bool WorldCollFalg;
#ifdef __cplusplus
}
#endif
#endif