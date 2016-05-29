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

void DrawCube2(float scaleX, float scaleY, float scaleZ);

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
glLookAt_Parameter My_LookAt;
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

	// Draw Horizontal
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	
	glColor3f(0.0, 1.0, 1.0);
	glTranslated(0, -(Robot_Arm.BaseHeight / My_Ortho.Value), 0);

	glBegin(GL_LINE_LOOP);
		glVertex3f(My_Ortho.X1, 0, 0);
		glVertex3f(My_Ortho.X2, 0, 0);
	glEnd();
	// Draw Robot - Arm
	/*glColor3f(1.0, 0.0, 0.0);
	DrawCube_Lib(0.4,0.4,0.4);
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(0.1, 0.5, 0);
	DrawCube_Lib(0.2, 0.6, 0.2);
	glTranslated(0.5, 0.2, 0);
	DrawCube_Lib(0.2, 1, 0.2);*/
	DrawRobotArm();
	//glTranslatef(1000, 100, -5);	
	
	printf("In Display \r\n");
	
	//
	//glPushMatrix();
	//	//glLoadIdentity();
	//	//DrawCube2(1, -2, 1);
	//	/*glMatrixMode(GL_PROJECTION);
	//	glLoadIdentity();
	//	*///glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);
	//	/*glFrustum(1024,1024,1024,1024,1024,1024);
	//	gluPerspective(180.0, 5.0, 10, 300.0);*/
	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();
	//	
	//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	//glPopMatrix();

	
	// OpenGL -  ensures that the drawing command are actually executed.
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */



