// VirtualCity.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <windows.h>
/* OpenGL library */
#include "glut.h"
/* my library */
#include "Robot_Arm.h"
#include "myGL_Init.h"
#include "myLight.h"
#include "myDataStruct.h"
#include "DrawFunctions.h"
void myDisplay();
void LightSource(void);
void LightSource2(void);
glLight_Parameter mySource_1;
glMaterial_Parameter myMaterial_1;
RobotParameter Robot_Arm;
RobotParameter Robot_Initial;
glOrtho_Parameter My_Ortho;
RobotArmPosition Robot_Position;
glLookAt_Parameter My_LookAt;
glLookAt_Parameter Initial_LookAt;
int main(int argc, char** argv) {
	DrawPosition();
	OpenGL_Init(argc, argv);
	return 0;
}

void myDisplay() {

	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Draw Horizontal
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);

		glColor3f(0.0, 1.0, 1.0);
		glTranslated(0, -(Robot_Arm.BaseHeight / My_Ortho.Value), 0);

		glBegin(GL_LINE_LOOP);
		glVertex3f(My_Ortho.X1, 0, 0);
		glVertex3f(My_Ortho.X2, 0, 0);
		glEnd();
	glPopMatrix();
	/*glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
		glVertex3f(My_Ortho.X1, 0, My_Ortho.Z1);
		glVertex3f(-My_Ortho.X1, 0, My_Ortho.Z1);
		glVertex3f(-My_Ortho.X1, 0, -My_Ortho.Z1);
		glVertex3f(My_Ortho.X1, 0, -My_Ortho.Z1);
		glVertex3f(My_Ortho.X1, 0, My_Ortho.Z1);
	glEnd();
	glPopMatrix();*/
	// Draw Robot - Arm
	/*glColor3f(1.0, 0.0, 0.0);
	DrawCube_Lib(0.4,0.4,0.4);
	glColor3f(0.0, 1.0, 0.0);
	glTranslated(0.1, 0.5, 0);
	DrawCube_Lib(0.2, 0.6, 0.2);
	glTranslated(0.5, 0.2, 0);
	DrawCube_Lib(0.2, 1, 0.2);*/
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();*/
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		glColor3f(0.0, 1.0, 0.0);
		DrawHouse(1.4,1.4,1,0.6,0.5,0.7,0.7);

	glPopMatrix();

	glPushMatrix();
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(4, 0, 0);
		glColor3f(1.0, 0.0, 0.0);
		DrawHouse(1, 1, 1, 0.4, 0.3, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(-4, 0, 0);
		glColor3f(0.0, 0.0, 1.0);
		DrawHouse(1, 1, 1, 0.4, 0.3, 0.5, 0.5);
	glPopMatrix();

	/*glPushMatrix();
		MovePosition(-10, -10, 0);
		glColor3f(0.0, 0.0, 1.0);
		DrawHouse(1, 1, 1, 0.4, 0.3, 0.5, 0.5);
	glPopMatrix();*/
	glPushMatrix();
		DrawFixWindows();		
	glPopMatrix();

	
	
	/*glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		glColor3f(0.0, 0.0, 1.0);

		MovePosition(2, 0, 0);
		DrawCubeF(1, 1, 0.5);
		MovePosition(0, 0.5, 0);
		DrawRoof(1, 1, 1);
	glPopMatrix();*/



	printf("In Display \r\n");

	//LightSource();
	//LightSource2();
	//LightSource3();

	// OpenGL -  ensures that the drawing command are actually executed.
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */
