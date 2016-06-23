#ifndef __MYGL_INIT_H
#define __MYGL_INIT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
#define DisplayMode 0
#define OpenTexture 0

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
extern void myDisplay();
extern int tempX1;
extern int tempX2;
extern float Rotated_theta;
extern float Rotated_X;
extern float Rotated_Y;
extern float Rotated_Z;
extern int id_texture2;
extern float Fixed_Z;
extern float Z1;
extern float X1;
extern bool BackFalg;
extern bool ForwardFalg;
extern bool RightFalg;
extern bool LeftFalg;
extern float RotateAngle;


#ifdef __cplusplus
}
#endif
#endif