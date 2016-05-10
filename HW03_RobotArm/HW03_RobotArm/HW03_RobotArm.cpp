// HW03_RobotArm.cpp : 定義主控台應用程式的進入點。
//
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
void myKeyboard(unsigned char key, int x, int y);
void DrawRobotArm(void);
void DrawCube(float Length, float Height, float Width);

/* Menu Function */
void myMenuInit();
void X_DirectionMenuFunc(int id);
void Y_DirectionMenuFunc(int id);
void ArmRotationMenuFunc(int id);
void GripperHeightMenuFunc(int id);
void GripperControlMenuFunc(int id);
void myMenu(int id);
/* End of Menu Function */

void OpenGL_Init(int argc, char** argv);

void mySpin(void);
void DrawPosition(void);
bool IsClockwise = false;
int Cnt_Clockwise = 3;
int Cnt_Counterclockwise = -3;

typedef struct glOrtho_Parameter {
	float X1 = -5;
	float X2 = 5;
	float Y1 = -5;
	float Y2 = 5;
	float Z1 = -5;
	float Z2 = 5;
	float Value = 5;
};

typedef struct RobotParameter {
	float Base_X = 0;
	float Base_Y = 0;
	float BaseHeight = 0.4;
	float BaseWidth = 0.4;
	float BaseLength = 0.4;

	float Link1_Height = 0.6;
	float Link1_Width = 0.2;
	float Link1_Length = 0.2;
	float Link1_theta = 0;

	float Link2_Height = 0.2;
	float Link2_Width = 0.2;
	float Link2_Length = 1.0;

	float Cube1_Height = 0.2;
	float Cube1_Width = 0.2;
	float Cube1_Length = 0.2;

	float Link3_Height = 0.1;	// 可變動
	float Link3_Width = 0.1;
	float Link3_Length = 0.1;

	float Link4_Height = 0.1;
	float Link4_Width = 0.1;
	float Link4_Length = 0.6;

	float Link5_Height = 0.2;
	float Link5_Width = 0.1;
	float Link5_Length = 0.1;

	float Link6_Height = 0.2;
	float Link6_Width = 0.1;
	float Link6_Length = 0.1;

	float GripperWidth = 0.1;

};

typedef struct RobotArmPosition {
	float Link1_RP_Y1;
	float Link1_DP_Y2;
	float Link2_DP_X1;
	float Link2_DP_Y1;
	float Cube1_DP_X1;
	float Cube1_DP_Y1;
	float Link4_DP_Y1;

	float Base_DP_X1;
	float Base_DP_Y1;
	float Link3_DP_Y1;
	float Link5_DP_X1;
	float Link5_DP_Y1;
	float Link6_DP_X1;
	float Link6_DP_Y1;

};


RobotParameter Robot_Arm;
RobotParameter Robot_Initial;
glOrtho_Parameter My_Ortho;
RobotArmPosition Robot_Position;


/*
Program Start
*/
int main(int argc, char** argv) {

	DrawPosition();
	OpenGL_Init(argc, argv);

	return 0;
}

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
void X_DirectionMenuFunc(int id) {
	switch (id) {
	case 1:		// Increase 
		Robot_Arm.Base_X += 0.1;
		break;
	case 2:		// Decrease
		Robot_Arm.Base_X -= 0.1;
		break;
	}/* End of swtich*/
	Robot_Position.Base_DP_X1 = Robot_Arm.Base_X / My_Ortho.Value;
	printf(" Robot_Arm.Base_X = %f  \r\n", Robot_Arm.Base_X);
	glutPostRedisplay();
}
void Y_DirectionMenuFunc(int id) {
	switch (id) {
	case 1:		// Increase 
		Robot_Arm.Base_Y += 0.1;
		break;
	case 2:		// Decrease
		Robot_Arm.Base_Y -= 0.1;		
		break;
	}/* End of swtich*/
	Robot_Position.Base_DP_Y1 = Robot_Arm.Base_Y / My_Ortho.Value;
	printf(" Robot_Arm.Base_Y = %f  \r\n", Robot_Arm.Base_Y);
	glutPostRedisplay();
}
void ArmRotationMenuFunc(int id) {
	switch (id) {
	case 1:		// Clockwise 
		Robot_Arm.Link1_theta+=5;		
		break;
	case 2:		// CounterClockwise
		Robot_Arm.Link1_theta-=5;
		break;
	}/* End of swtich*/
	printf(" Robot_Arm.Link1_theta = %f  \r\n", Robot_Arm.Link1_theta);
	glutPostRedisplay();
}
void GripperHeightMenuFunc(int id) {
	switch (id) {
	case 1:		// Up 
		if (Robot_Arm.Link3_Height > 0.1)
			Robot_Arm.Link3_Height -= 0.1;
		else
			Robot_Arm.Link3_Height = 0.0;
		break;
	case 2:		// Down
		if (Robot_Arm.Link3_Height < 0.2)
			Robot_Arm.Link3_Height += 0.1;
		else
			Robot_Arm.Link3_Height = 0.2;
		break;
	}/* End of swtich*/
	Robot_Position.Link3_DP_Y1 = -(Robot_Arm.Cube1_Height / My_Ortho.Value) - (Robot_Arm.Link3_Height / My_Ortho.Value);
	Robot_Position.Link4_DP_Y1 = -(Robot_Arm.Link3_Height / My_Ortho.Value) - (Robot_Arm.Link4_Height / My_Ortho.Value);
	printf(" Robot_Arm.Link3_Height = %f  \r\n", Robot_Arm.Link3_Height);
	glutPostRedisplay();
}
void GripperControlMenuFunc(int id) {
	switch (id) {
	case 1:		// Open 
		if (Robot_Arm.GripperWidth < 0.2)
			Robot_Arm.GripperWidth += 0.1;
		else
			Robot_Arm.GripperWidth = 0.2;
		break;
	case 2:		// Close
		if (Robot_Arm.GripperWidth > 0.1)
			Robot_Arm.GripperWidth -= 0.1;
		else
			Robot_Arm.GripperWidth = 0;
		break;
	}/* End of swtich*/
	Robot_Position.Link5_DP_X1 = -(Robot_Arm.GripperWidth / My_Ortho.Value) - (Robot_Arm.Link5_Length / My_Ortho.Value);
	Robot_Position.Link6_DP_X1 = -2 * Robot_Position.Link5_DP_X1;
	printf(" Robot_Arm.GripperWidth = %f  \r\n", Robot_Arm.GripperWidth);
	glutPostRedisplay();
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
		glVertex3f(My_Ortho.X1 , 0, 0);
		glVertex3f(My_Ortho.X2 , 0, 0);
	glEnd();
	// Draw Robot - Arm
	DrawRobotArm();


	// OpenGL -  ensures that the drawing command are actually executed.
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */


void DrawRobotArm(void) {
	// glTranslated 、 glRotatef ..等，每呼叫一次函式 都會累加
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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

}
void DrawCube(float Length, float Height, float Width) {

	glBegin(GL_LINE_LOOP);
		glVertex3f(Length, Height, Width);
		glVertex3f(Length, Height, -Width);
		glVertex3f(-Length, Height, -Width);
		glVertex3f(-Length, Height, Width);
		glVertex3f(Length, Height, Width);
		glVertex3f(Length, -Height, Width);
		glVertex3f(Length, -Height, -Width);
		glVertex3f(-Length, -Height, -Width);
		glVertex3f(-Length, -Height, Width);
		glVertex3f(Length, -Height, Width);
		glVertex3f(Length, -Height, -Width);
		glVertex3f(Length, Height, -Width);
		glVertex3f(-Length, Height, -Width);
		glVertex3f(-Length, -Height, -Width);
		glVertex3f(-Length, -Height, Width);
		glVertex3f(-Length, Height, Width);
	glEnd();
	
}

