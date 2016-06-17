#ifndef __MYGL_INIT_H
#define __MYGL_INIT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
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

#ifdef __cplusplus
}
#endif
#endif