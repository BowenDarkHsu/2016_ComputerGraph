// HW04_Lighting.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <windows.h>
/* OpenGL library */
#include "glut.h"
/* Robot_Arm library */
#include "Robot_Arm.h"


void myInit();
void myDisplay();
void myMouse(int button, int state, int x, int y);
void myKeyboard(unsigned char key, int x, int y);
void myMenuInit();
void myMenu(int id);
void OpenGL_Init(int argc, char** argv);
RobotParameter Robot_Arm;
RobotParameter Robot_Initial;
glOrtho_Parameter My_Ortho;
RobotArmPosition Robot_Position;
int main(int argc, char** argv){
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
	glutCreateWindow(" Homework -3- RobotArm ");

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
	int X_Direction_menu = glutCreateMenu(X_DirectionMenuFunc);
	glutAddMenuEntry("Increase X (快捷鍵 D)", 1);
	glutAddMenuEntry("Decrease X (快捷鍵 A)", 2);

	int Y_Direction_menu = glutCreateMenu(Y_DirectionMenuFunc);
	glutAddMenuEntry("Increase Y (快捷鍵 W)", 1);
	glutAddMenuEntry("Decrease Y (快捷鍵 S)", 2);

	int ArmRotation_menu = glutCreateMenu(ArmRotationMenuFunc);
	glutAddMenuEntry("Clockwise (快捷鍵 1)", 1);
	glutAddMenuEntry("CounterClockwise (快捷鍵 2)", 2);

	int GripperHeight_menu = glutCreateMenu(GripperHeightMenuFunc);
	glutAddMenuEntry("Up (快捷鍵 4)", 1);
	glutAddMenuEntry("Down (快捷鍵 5)", 2);

	int GripperControl_menu = glutCreateMenu(GripperControlMenuFunc);
	glutAddMenuEntry("Open (快捷鍵 7)", 1);
	glutAddMenuEntry("Close (快捷鍵 8)", 2);


	glutCreateMenu(myMenu);
	glutAddSubMenu("X Direction", X_Direction_menu);
	glutAddSubMenu("Y Direction", Y_Direction_menu);
	glutAddSubMenu("Arm-Rotation", ArmRotation_menu);
	glutAddSubMenu("Gripper Height", GripperHeight_menu);
	glutAddSubMenu("Gripper Control", GripperControl_menu);
	glutAddMenuEntry("Home", 1);
	glutAddMenuEntry("Quit", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myMenu(int id) {
	switch (id) {
	case 1:
		Robot_Arm = Robot_Initial;
		DrawPosition();
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
	case 'w':
		Y_DirectionMenuFunc(1);
		break;
	case 's':
		Y_DirectionMenuFunc(2);
		break;
	case 'a':
		X_DirectionMenuFunc(2);
		break;
	case 'd':
		X_DirectionMenuFunc(1);
		break;
	case '1':
		ArmRotationMenuFunc(1);
		break;
	case '2':
		ArmRotationMenuFunc(2);
		break;
	case '4':
		GripperHeightMenuFunc(1);
		break;
	case '5':
		GripperHeightMenuFunc(2);
		break;
	case '7':
		GripperControlMenuFunc(1);
		break;
	case '8':
		GripperControlMenuFunc(2);
		break;
	}

}

void myDisplay() {

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw Horizontal
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(0, -(Robot_Arm.BaseHeight / My_Ortho.Value), 0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(My_Ortho.X1, 0, 0);
	glVertex3f(My_Ortho.X2, 0, 0);
	glEnd();
	// Draw Robot - Arm
	DrawRobotArm();


	// OpenGL -  ensures that the drawing command are actually executed.
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */
