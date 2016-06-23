// MouseAxis.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"

/////////////////////////
// glutTest13.cpp
//
// Created by Gary Ho, ma_hty@hotmail.com, 2007
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "glut.h"

#define PI 3.14159265358979323846f

float v0[3], v1[3];
float mo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };

float clamp(float x, float a, float b);
float dot(const float *a, const float *b);
float norm(const float *a);
void vassign(float *a, float x, float y, float z);
void vassign(float *a, const float *b);
void cross(float *a, const float *b, const float *c);
void normalize(float *a);

void display();
void mousebutton(int button, int state, int x, int y);
void mousemove(int x, int y);
void mousefreemove(int x, int y);

int Gx, Gy = 0;
bool EvenMouse = false;

void main(int argc, char **argv)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);

	glutCreateWindow("test09");
	glutDisplayFunc(display);
	glutPassiveMotionFunc(mousefreemove);
	glutMouseFunc(mousebutton);
	glutMotionFunc(mousemove);

	glutMainLoop();
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
	gluPerspective(100, double(viewport[2]) / viewport[3], 0.1, 100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 1, 5, 0, 0, 0, 0, 1, 0);
	glMultMatrixf(mo);

	glutSolidTeapot(1);
	if (EvenMouse) {
		glBegin(GL_POINTS);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // RGBA
		glVertex2f(Gx, Gy);
		glEnd();
		//printf("Gx = %d Gy = %d \r\n", Gx, Gy);
		EvenMouse = false;
	}
	

	glutSwapBuffers();
}

void mousebutton(int button, int state, int x, int y)
{
	vassign(v0, 2.0*x / 1024 - 1, -2.0*y / 768 + 1, 1);
	//printf("Vassign a[0] = %f , a[1] = %f , a[2] = %f , a[3] = %f \r\n", v0[0], v0[1], v0[2], v0[3]);
	normalize(v0);
	//printf("Normalize a[0] = %f , a[1] = %f , a[2] = %f , a[3] = %f \r\n", v0[0], v0[1], v0[2], v0[3]);
}
void mousefreemove(int x, int y)
{
	Gx = x;
	Gy = y;
	EvenMouse = true;
	
	glutPostRedisplay();
}
void mousemove(int x, int y)
{
	float axis[3], angle;

	vassign(v1, 2.0*x / 1024 - 1, -2.0*y / 768 + 1, 1);
	normalize(v1);
	if (dot(v0, v1)>.999)
		return;
	cross(axis, v0, v1);
	normalize(axis);
	angle = acosf(clamp(dot(v0, v1), -1, 1));
	vassign(v0, v1);

	glPushMatrix();
	glLoadIdentity();
	glRotatef(angle * 180 / PI, 0, axis[1],0);
	printf("glRotatef a[0] = %f , a[1] = %f , a[2] = %f \r\n", axis[0], axis[1], axis[2]);
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
