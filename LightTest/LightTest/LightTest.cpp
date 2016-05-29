// LightTest.cpp : 定義主控台應用程式的進入點。
//
// HW04_Lighting.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <windows.h>
/* OpenGL library */
#include "glut.h"
#include "myDataStruct.h"

void DrawCube(float Length, float Height, float Width);
void myInit();
void myDisplay();
void myMouse(int button, int state, int x, int y);
void myKeyboard(unsigned char key, int x, int y);
void myMenuInit();
void myMenu(int id);
void OpenGL_Init(int argc, char** argv);
void DrawPosition(void);
RobotParameter Robot_Arm;
RobotParameter Robot_Initial;
glOrtho_Parameter My_Ortho;
RobotArmPosition Robot_Position;
glLookAt_Parameter My_LookAt;
int main(int argc, char** argv) {
	DrawPosition();
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
	glutCreateWindow(" Homework -4- RobotArm Light ");

	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	myInit();

	glutMainLoop();
}/* End of OpenGL_Init */

void myInit() {
	/* set color */
	// OpenGL -  establishes what color the window will be cleared to.
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// OpenGL -  establishes what color to use for drawing objects.
	glColor3f(1.0, 1.0, 1.0);

	myMenuInit();
	glOrtho(My_Ortho.X1, My_Ortho.X2, My_Ortho.Y1, My_Ortho.Y2, My_Ortho.Z1, My_Ortho.Z2);

	myDisplay();
}/* End of myInit */

void myMenuInit() {
	
}

void myMenu(int id) {
	switch (id) {
	case 1:

		glutPostRedisplay();
		break;
	case 2: exit(0);
	}/* End of switch */
}


void myMouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		glutPostRedisplay();
	}/* End of if*/
}

void myKeyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'z':
		My_LookAt.X = My_LookAt.X + 0.1;
		printf(" My_LookAt.X = %f  \r\n", My_LookAt.X);
		glutPostRedisplay();
		break;
	case 'x':
		My_LookAt.X = My_LookAt.X - 0.1;
		printf(" My_LookAt.X = %f  \r\n", My_LookAt.X);
		glutPostRedisplay();
		break;
	case 'c':
		My_LookAt.Y = My_LookAt.Y + 0.1;
		printf(" My_LookAt.Y = %f  \r\n", My_LookAt.Y);
		glutPostRedisplay();
		break;
	case 'v':
		My_LookAt.Y = My_LookAt.Y - 0.1;
		printf(" My_LookAt.Y = %f  \r\n", My_LookAt.Y);
		glutPostRedisplay();
		break;
	case 'b':
		My_LookAt.Z = My_LookAt.Z + 0.1;
		printf(" My_LookAt.Z = %f  \r\n", My_LookAt.Z);
		glutPostRedisplay();
		break;
	case 'n':
		My_LookAt.Z = My_LookAt.Z - 0.1;
		printf(" My_LookAt.Z = %f  \r\n", My_LookAt.Z);
		glutPostRedisplay();
		break;
	case 'f':
		My_LookAt.Forward_X = My_LookAt.Forward_X + 0.1;
		printf(" My_LookAt.Forward_X = %f  \r\n", My_LookAt.Forward_X);
		glutPostRedisplay();
		break;
	case 'g':
		My_LookAt.Forward_X = My_LookAt.Forward_X - 0.1;
		printf(" My_LookAt.Forward_X = %f  \r\n", My_LookAt.Forward_X);
		glutPostRedisplay();
		break;
	case 'h':
		My_LookAt.Forward_Y = My_LookAt.Forward_Y + 0.1;
		printf(" My_LookAt.Forward_Y = %f  \r\n", My_LookAt.Forward_Y);
		glutPostRedisplay();
		break;
	case 'j':
		My_LookAt.Forward_Y = My_LookAt.Forward_Y - 0.1;
		printf(" My_LookAt.Forward_Y = %f  \r\n", My_LookAt.Forward_Y);
		glutPostRedisplay();
		break;
	case 'k':
		My_LookAt.Forward_Z = My_LookAt.Forward_Z + 0.1;
		printf(" My_LookAt.Forward_Z = %f  \r\n", My_LookAt.Forward_Z);
		glutPostRedisplay();
		break;
	case 'l':
		My_LookAt.Forward_Z = My_LookAt.Forward_Z - 0.1;
		printf(" My_LookAt.Forward_Z = %f  \r\n", My_LookAt.Forward_Z);
		glutPostRedisplay();
		break;

	default:
		break;
	}

}

void myDisplay() {
	
	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// Draw Horizontal
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	/* preprocesing define variable */
	GLfloat mat_spec[] = { 1,1,1,1.0 };
	GLfloat mat_shine[] = { 10.0 };
	GLfloat light_ambient[] = { 1.0,1.0,1.0,1.0 };
	GLfloat light_diffuse[] = { 1,1,1,1.0 };
	GLfloat light_specular[] = { 1,1,1.0,1.0 };
	GLfloat light_position[] = { -2.0,2.0,-2.0,0.0 };

	/* Step1 Create Normal Vector and Object */
	///////////////////////////////////////////////////////////////////////////////
	// Draw Base G
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(Robot_Position.Base_DP_X1, Robot_Position.Base_DP_Y1, 0);
	DrawCube(Robot_Arm.BaseLength, Robot_Arm.BaseHeight, Robot_Arm.BaseWidth);
	// Draw Link1 R
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(0, Robot_Position.Link1_RP_Y1, 0);
	glRotated(Robot_Arm.Link1_theta, 0.0, 1.0, 0.0);

	glTranslated(0, Robot_Position.Link1_DP_Y2, 0);
	DrawCube(Robot_Arm.Link1_Length, Robot_Arm.Link1_Height, Robot_Arm.Link1_Width);

	// Draw Link2 G
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(Robot_Position.Link2_DP_X1, Robot_Position.Link2_DP_Y1, 0);
	DrawCube(Robot_Arm.Link2_Length, Robot_Arm.Link2_Height, Robot_Arm.Link2_Width);
	// Draw Cube1 G
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(Robot_Position.Cube1_DP_X1, Robot_Position.Cube1_DP_Y1, 0);
	DrawCube(Robot_Arm.Cube1_Length, Robot_Arm.Cube1_Height, Robot_Arm.Cube1_Width);
	// Draw Link3 R
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(0, Robot_Position.Link3_DP_Y1, 0);
	DrawCube(Robot_Arm.Link3_Length, Robot_Arm.Link3_Height, Robot_Arm.Link3_Width);
	// Draw Link4 G
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(0, Robot_Position.Link4_DP_Y1, 0);
	DrawCube(Robot_Arm.Link4_Length, Robot_Arm.Link4_Height, Robot_Arm.Link4_Width);
	// Draw Link5 R
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(Robot_Position.Link5_DP_X1, Robot_Position.Link5_DP_Y1, 0);
	DrawCube(Robot_Arm.Link5_Length, Robot_Arm.Link5_Height, Robot_Arm.Link5_Width);
	// Draw Link6 R
	glColor3f(1.0, 0.0, 0.0);
	glTranslated(Robot_Position.Link6_DP_X1, Robot_Position.Link6_DP_Y1, 0);
	DrawCube(Robot_Arm.Link6_Length, Robot_Arm.Link6_Height, Robot_Arm.Link6_Width);

	///////////////////////////////////////////////////////////////////////////////



	/* Step2 Create Light Source , Select model , decide position */
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,light_diffuse );
	glLightfv(GL_LIGHT0,GL_SPECULAR,light_specular );
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);
	

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */
void DrawPosition(void) {
	Robot_Position.Base_DP_X1 = Robot_Arm.Base_X / My_Ortho.Value;
	Robot_Position.Base_DP_Y1 = Robot_Arm.Base_Y / My_Ortho.Value;

	Robot_Position.Link1_RP_Y1 = Robot_Arm.BaseHeight / My_Ortho.Value;
	Robot_Position.Link1_DP_Y2 = Robot_Arm.Link1_Height / My_Ortho.Value;
	Robot_Position.Link2_DP_X1 = (Robot_Arm.Link1_Length / My_Ortho.Value) + (Robot_Arm.Link2_Length / My_Ortho.Value);
	Robot_Position.Link2_DP_Y1 = (Robot_Arm.Link1_Height / My_Ortho.Value) - (Robot_Arm.Link2_Height / My_Ortho.Value);
	Robot_Position.Cube1_DP_X1 = (Robot_Arm.Link2_Length / My_Ortho.Value) - (Robot_Arm.Cube1_Length / My_Ortho.Value);
	Robot_Position.Cube1_DP_Y1 = -(Robot_Arm.Link2_Height / My_Ortho.Value) - (Robot_Arm.Cube1_Height / My_Ortho.Value);
	Robot_Position.Link3_DP_Y1 = -(Robot_Arm.Cube1_Height / My_Ortho.Value) - (Robot_Arm.Link3_Height / My_Ortho.Value);
	Robot_Position.Link4_DP_Y1 = -(Robot_Arm.Link3_Height / My_Ortho.Value) - (Robot_Arm.Link4_Height / My_Ortho.Value);

	Robot_Position.Link5_DP_Y1 = -(Robot_Arm.Link4_Height / My_Ortho.Value) - (Robot_Arm.Link5_Height / My_Ortho.Value);
	Robot_Position.Link6_DP_Y1 = 0; // the same Link5 DP Y1
	Robot_Position.Link5_DP_X1 = -(Robot_Arm.GripperWidth / My_Ortho.Value) - (Robot_Arm.Link5_Length / My_Ortho.Value);
	Robot_Position.Link6_DP_X1 = -2 * Robot_Position.Link5_DP_X1; // Link5 的對稱位置
}
void DrawCube(float Length, float Height, float Width) {

	GLfloat BaseCubeV[15][3] = { {0,0,0},{ 0,4,0 },{ 4,4,0 },{ 4,0,0 },{ 0,0,0 },{ 0,0,4 },{ 0,4,4 },{ 0,4,0 },{ 4,4,0 },{ 4,4,4 },{ 0,4,4 },{ 0,0,4 },{ 4,0,4 },{ 4,4,4 },{ 0,4,4 } };
	GLfloat BaseCubeV2[15][3] = { 
		{ Length,Height,Width },{ Length,Height,-Width },{ -Length,Height,-Width },
		{ -Length,Height,Width },{ Length,Height,Width },{ Length,-Height,Width },
		{ Length,-Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },
		{ Length,-Height,Width },{ Length,-Height,-Width },{ Length,Height,-Width },
		{ -Length,Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width } };
	/*
	GLfloat BaseCubeV2[15][3] = { 
		{ Length,Height,Width },{ Length,Height,Width },{ Length,Height,Width },
		{ Length,Height,Width },{ Length,Height,Width },{ Length,Height,Width },
		{ Length,Height,Width },{ Length,Height,Width },{ Length,Height,Width },
		{ Length,Height,Width },{ Length,Height,Width },{ Length,Height,Width },
		{ Length,Height,Width },{ Length,Height,Width },{ Length,Height,Width }};
	*/
	GLfloat BaseCubeP[3] = { 0.0,0.0,0.0 };

	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glColor3f(0.0, 1.0, 1.0);
	
	glBegin(GL_POLYGON);
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 3; j++) {
				BaseCubeP[j] = BaseCubeV2[i][j];
			}			
			glNormal3fv(BaseCubeP);
			glVertex3fv(BaseCubeP);
		}
	glEnd();
	/*glTranslated(0, Robot_Position.Link1_RP_Y1, 0);
	glRotated(Robot_Arm.Link1_theta, 0.0, 1.0, 0.0);

	glTranslated(0, Robot_Position.Link1_DP_Y2, 0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 3; j++) {
			BaseCubeP[j] = BaseCubeV2[i][j];
		}
		glNormal3fv(BaseCubeP);
		glVertex3fv(BaseCubeP);
	}
	glEnd();*/
	//glutSolidSphere(1.0,100,100);
	
	glFlush();
}

