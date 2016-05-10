// HW02_Ellipse_Manipulation.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <windows.h>
/* OpenGL library */
#include "glut.h"


/*
pi = 3.1415926
1 degree = 2*pi/360 = 0.017445 radian
*/
#define degree 0.017445

/*
Function Define
*/
void myInit();
void myDisplay();
void myMouse(int button, int state, int x, int y);
void myMenuInit();
void myRotationMenuFunc(int id);
void myDirectionMenuFunc(int id);
void myTranslationMenuFunc(int id);
void myMenu(int id);
void OpenGL_Init(int argc, char** argv);

void mySpin(void);
void RotationTest(double theatar);


void RotationMatrix(double *h, double *k, double theataFunc);
void DrawOval(double h, double a, double k, double b, double theataFunc);
double OvalCal_X(double h, double a, double t);
double OvalCal_Y(double k, double b, double t);
double VOval_X = 0.0;
double VOval_Y = 0.0;
double VOval_Xa = 2.0;
double VOval_Yb = 1.0;

double HOval_X = 512.0;
double HOval_Y = 384.0;
double HOval_Xa = 2.0;
double HOval_Yb = 1.0;
double theta = 0.0;

bool IsClockwise = false;
int Cnt_Clockwise = 3;
int Cnt_Counterclockwise = -3;

/*
Program Start
*/
int main(int argc, char** argv) {

	OpenGL_Init(argc, argv);

	return 0;
}

void OpenGL_Init(int argc, char** argv) {

	// OpenGL - initializes GLUT and should be called before any other GLUT routine.
	glutInit(&argc, (char **)argv);

	// OpenGL - specifies the color model (RGB or color-index color model)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// OpenGL - specifies the size, in pixels, of your window.
	glutInitWindowSize(1024, 768);

	// OpenGL - specifies the screen location for the upper - left corner
	glutInitWindowPosition(500, 0);

	// OpenGL - creates a window with an OpenGL context.
	glutCreateWindow(" Homework -2- Ellipse_Manipulation ");

	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);

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
	
	gluOrtho2D(0.0, 1024.0, 768.0, 0.0);
	myMenuInit();

}/* End of myInit */

void myMenuInit(){
	int Rotation_menu = glutCreateMenu(myRotationMenuFunc);
	glutAddMenuEntry("Start", 1);
	glutAddMenuEntry("Abort", 2);

	int Direction_menu = glutCreateMenu(myDirectionMenuFunc);
	glutAddMenuEntry("Clockwise", 3);
	glutAddMenuEntry("Counterclockwise", 4);

	int Translation_menu = glutCreateMenu(myTranslationMenuFunc);
	glutAddMenuEntry("Increase x", 5);
	glutAddMenuEntry("Decrease x", 6);
	glutAddMenuEntry("Increase y", 7);
	glutAddMenuEntry("Decrease y", 8);

	glutCreateMenu(myMenu);
	glutAddSubMenu("Rotation", Rotation_menu);
	glutAddSubMenu("Direction", Direction_menu);
	glutAddSubMenu("Translation", Translation_menu);
	glutAddMenuEntry("Quit", 9);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void myRotationMenuFunc(int id) {
	switch (id) {
	case 1:		// Start 
		glutIdleFunc(mySpin);
		break;
	case 2:		// Abort
		glutIdleFunc(NULL);
		break;
	}/* End of swtich*/
}
void myDirectionMenuFunc(int id) {
	switch (id) {
	case 3:		// Clockwise 		
		IsClockwise = true;
		break;
	case 4:		// Counterclockwise
		IsClockwise = false;
		break;
	}/* End of swtich*/
}
void myTranslationMenuFunc(int id) {
	switch (id) {
	case 5:		// Increase X		
		HOval_X += 100;
		break;
	case 6:		// Decrease X
		HOval_X -= 100;
		break;
	case 7:		// Increase Y		
		HOval_Y += 100;
		break;
	case 8:		// Decrease Y
		HOval_Y -= 100;
		break;
	}/* End of swtich*/
	glutPostRedisplay();
}
void myMenu(int id) {
	switch (id) {
		case 9: exit(0);
	}/* End of switch */
}


void myMouse(int button , int state , int x , int y){
	if( (button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)){
		printf(" x = %d  y = %d  \r\n" , x,y);
		HOval_X = x;
		HOval_Y = y;
		glutPostRedisplay();
	}/* End of if*/
}

void myDisplay() {

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT);

	/*
	// use Red draw vertial oval
	glColor3f(1.0, 0.0, 0.0);
	DrawVertialOval(VOval_X, VOval_Xa, VOval_Y, VOval_Yb);
	*/

	double theatar = theta *3.14159 / (180);

	// use Green draw horizontal oval
	glColor3f(0.0, 1.0, 0.0);
	
	DrawOval(HOval_X, HOval_Xa*50, HOval_Y, HOval_Yb*50, theatar);
	//RotationTest(theatar);
	printf(" HOval_X = %f  HOval_Y = %f  \r\n", HOval_X, HOval_Y);

	// OpenGL -  ensures that the drawing command are actually executed.
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */

void mySpin(void) {
	if (IsClockwise)
		theta += Cnt_Clockwise;
	else
		theta += Cnt_Counterclockwise;
	if (abs(theta) >= 360.0) theta = 0.0;
	
	//Sleep(100);
	glutPostRedisplay();
}


void DrawOval(double h, double a, double k, double b ,double theataFunc) {
	/* define variable X , Y */
	double X = 0.0;
	double Y = 0.0;
	double RotationX = 0.0;
	double RotationY = 0.0;

	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		X = OvalCal_X(0, a, i);
		Y = OvalCal_Y(0, b, i);
		RotationX = X * cos(theataFunc) - Y * sin(theataFunc);
		RotationY = X * sin(theataFunc) + Y * cos(theataFunc);
		X = RotationX + HOval_X;
		Y = RotationY + HOval_Y;
		glVertex2f(X, Y);
	}
	glEnd();
}/* End of DrawVertialOval */


double OvalCal_X(double h, double a, double t) {
	double x = 0.0;
	x = h + a * cos(t);
	return x;
}/* End of OvalCal_X */
double OvalCal_Y(double k, double b, double t) {
	double y = 0.0;
	y = k + b * sin(t);
	return y;
}/* End of OvalCal_Y */