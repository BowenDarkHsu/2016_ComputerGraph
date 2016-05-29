#include "stdafx.h"
#include "Robot_Arm.h"


/*
pi = 3.1415926
1 degree = 2*pi/360 = 0.017445 radian
#define degree 0.017445
*/

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

void DrawRobotArm(void) {
	// glTranslated 、 glRotatef ..等，每呼叫一次函式 都會累加
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	
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
	//glBegin(GL_LINE_LOOP);
	GLfloat DrawRange[16][3] = { 
		{ Length,Height,Width },{ Length,Height,-Width },{ -Length,Height,-Width },
		{ -Length,Height,Width },{ Length,Height,Width },{ Length,-Height,Width },
		{ Length,-Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },
		{ Length,-Height,Width },{ Length,-Height,-Width },{ Length,Height,-Width },
		{ -Length,Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },{ -Length,Height,Width } };
	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };	
	glBegin(GL_POLYGON);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 3; j++) {
				DrawPoint[j] = DrawRange[i][j];
			}			
			glNormal3fv(DrawPoint);
			glVertex3fv(DrawPoint);
		}
	glEnd();	
	// glBegin(GL_POLYGON);
		// glVertex3f(Length, Height, Width);
		// glVertex3f(Length, Height, -Width);
		// glVertex3f(-Length, Height, -Width);
		
		// glVertex3f(-Length, Height, Width);
		// glVertex3f(Length, Height, Width);
		// glVertex3f(Length, -Height, Width);
		
		// glVertex3f(Length, -Height, -Width);
		// glVertex3f(-Length, -Height, -Width);
		// glVertex3f(-Length, -Height, Width);
		
		// glVertex3f(Length, -Height, Width);
		// glVertex3f(Length, -Height, -Width);
		// glVertex3f(Length, Height, -Width);
		
		// glVertex3f(-Length, Height, -Width);
		// glVertex3f(-Length, -Height, -Width);
		// glVertex3f(-Length, -Height, Width);
		
		// glVertex3f(-Length, Height, Width);
	// glEnd();
	
}

void DrawCube_Lib(float scaleX, float scaleY, float scaleZ) {
	glPushMatrix();
	glScalef(scaleX, scaleY, scaleZ);
	glutWireCube(1.0);
	glPopMatrix();
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




