// FirstCG.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

/* OpenGL library */
#include "glut.h"

/*	
	pi = 3.1415926 
	1 degree = 2*pi/360 = 0.017445 radian
*/
//#define degree 0.017445

/*
	Function Define 
*/
void myInit();
void myDisplay();
void OpenGL_Init(int argc, char** argv);
void DrawVertialOval();
void DrawHorizontalOval();
double OvalCal_X(double h, double a, float t);
double OvalCal_Y(double k, double b, float t);

/*
	Program Start
*/
int main(int argc, char** argv) {

	OpenGL_Init(argc, argv);

	return 0;
}

void OpenGL_Init(int argc, char** argv){

	// OpenGL - initializes GLUT and should be called before any other GLUT routine.
	glutInit(&argc, (char **)argv);

	// OpenGL - specifies the color model (RGB or color-index color model)
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// OpenGL - specifies the size, in pixels, of your window.
	glutInitWindowSize(500, 500);

	// OpenGL - specifies the screen location for the upper - left corner
	glutInitWindowPosition(500, 500);

	// OpenGL - creates a window with an OpenGL context.
	glutCreateWindow(" Homework -1- Draw Oval ");

	glutDisplayFunc(myDisplay);

	myInit();

	glutMainLoop();
}/* End of OpenGL_Init */

void myInit() {
	/* set color */
	// OpenGL -  establishes what color the window will be cleared to.
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// OpenGL -  establishes what color to use for drawing objects.
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0,5.0 ,-5.0,5.0 ,-1.0,1.0);

}/* End of myInit */

void myDisplay() {

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT);

	// use Red draw vertial oval
	glColor3f(1.0, 0.0, 0.0);	
	DrawVertialOval();

	// use Green draw horizontal oval
	glColor3f(0.0, 1.0, 0.0);	
	DrawHorizontalOval();
	

	// OpenGL -  ensures that the drawing command are actually executed.
	glFlush();
}/* End of myDisplay */

void DrawVertialOval() {
	/* define variable X , Y */
	double X = 0.0;
	double Y = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		X = OvalCal_X(0, 2, i);
		Y = OvalCal_Y(0, 1, i);
		glVertex3f(X, Y, 0.0);
		printf("X = %f , Y = %f \r\n",X,Y);
	}
	glEnd();
}/* End of DrawVertialOval */

void DrawHorizontalOval() {
	/* define variable X , Y */
	double X = 0.0;
	double Y = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		X = OvalCal_X(0, 1, i);
		Y = OvalCal_Y(0, 2, i);
		glVertex3f(X, Y, 0.0);
	}
	glEnd();
}/* End of DrawHorizontalOval */

double OvalCal_X(double h, double a, float t){
	double x = 0.0;
	x = h + a * cos(t);
	return x;
}/* End of OvalCal_X */
double OvalCal_Y(double k, double b, float t) {
	double y = 0.0;
	y = k + b * sin(t);
	return y;
}/* End of OvalCal_Y */