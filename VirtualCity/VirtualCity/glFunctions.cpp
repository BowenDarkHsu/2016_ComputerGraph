#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "glut.h"
#include "glFunctions.h"
// ASCII字符總共只有0到127，一共128種字符
#define MAX_CHAR        128

void drawString(const char* str) {
	static int isFirstCall = 1;
	static GLuint lists;

	if (isFirstCall) { // 如果是第一次調用，執行初始化
					   // 为每一個ASCII字符產生一個顯示列表
		isFirstCall = 0;

		// 申請MAX_CHAR個連續的顯示列表編號
		lists = glGenLists(MAX_CHAR);

		// 把每個字符的繪制命令都裝到對應的顯示列表中
		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
	}
	// 調用每個字符對應的顯示列表，繪制每個字符
	for (; *str != '\0'; ++str)
		glCallList(lists + *str);
}

void display()
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100, double(viewport[2]) / viewport[3], 0.1, 10);
	printf("viewport[2] = %d , viewport[3] = %d , 2/3 = %f \r\n", viewport[2], viewport[3], double(viewport[2]) / viewport[3]);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 3, 0, 0, 0, 0, 1, 0);
	glMultMatrixf(mo);

	glutSolidTeapot(1);
	glPushMatrix();
	glColor3f(1.0f, 1.0f, 0.0f);
	glRasterPos3f(1.0f, 1.0f, 1.0f);
	drawString("Hello, World!");
	glPopMatrix();
	glutSwapBuffers();
}

void mousebutton(int button, int state, int x, int y)
{
	vassign(v0, 2.0*x / 512 - 1, -2.0*y / 512 + 1, 1);
	normalize(v0);
}

void mousemove(int x, int y)
{
	float axis[3], angle;

	vassign(v1, 2.0*x / 512 - 1, -2.0*y / 512 + 1, 1);
	normalize(v1);
	if (dot(v0, v1)>.999)
		return;
	cross(axis, v0, v1);
	normalize(axis);
	angle = acosf(clamp(dot(v0, v1), -1, 1));
	vassign(v0, v1);

	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle * 180 / PI, axis[0], axis[1], axis[2]);
	glMultMatrixf(mo);
	glGetFloatv(GL_MODELVIEW_MATRIX, mo);
	glPopMatrix();
	glutPostRedisplay();
}


float clamp(float x, float a, float b) { return x<a ? a : (x<b ? x : b); }
float dot(const float *a, const float *b) { return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]; }
float norm(const float *a) { return sqrtf(dot(a, a)); }
void vassign(float *a, float x, float y, float z) { a[0] = x; a[1] = y; a[2] = z; }
void vassign(float *a, const float *b) { a[0] = b[0]; a[1] = b[1]; a[2] = b[2]; }

void cross(float *a, const float *b, const float *c)
{
	a[0] = b[1] * c[2] - c[1] * b[2];
	a[1] = -b[0] * c[2] + c[0] * b[2];
	a[2] = b[0] * c[1] - c[0] * b[1];
}

void normalize(float *a)
{
	float l = norm(a);
	a[0] /= l; a[1] /= l; a[2] /= l;
}