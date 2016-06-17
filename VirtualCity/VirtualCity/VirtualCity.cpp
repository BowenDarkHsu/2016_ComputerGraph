// VirtualCity.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <time.h>
/* OpenGL library */
#include "glut.h"
/* my library */
#include "Robot_Arm.h"
#include "myGL_Init.h"
#include "myLight.h"
#include "myDataStruct.h"
#include "DrawFunctions.h"
#include "glFunctions.h"

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
HumanObject MajorRole ;
float MoveX = 0.0;
float MoveY = 0.0;
float MoveZ = 0.0;
float v0[3], v1[3];
float mo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
int VitalityNum = 100.0;
char string1[10] = "breath : ";
char string2[10];
int id_texture = 0;
int num_texture = -1;

int tempX1 = 0;
int tempX2 = 0;


void CALLBACK VitalityTimeCallBack(HWND hwnd, UINT message, UINT timerID, DWORD time) {
	VitalityNum = VitalityNum - 1;
	sprintf(string2, " %d ", VitalityNum);
	printf("%s\n", string2);
	glutPostRedisplay();
}
int main(int argc, char** argv) {	
	// set Vitality Call Back Fun Timer : 3 sec
	//SetTimer(NULL, 0, 3000, VitalityTimeCallBack);
	
	//KillTimer(NULL, 1);
	DrawPosition();
	OpenGL_Init(argc, argv);
	return 0;
}

void BuildNormalCity(void) {
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		glColor3f(0.0, 1.0, 0.0);
		DrawHouse(1.4, 1.4, 1, 0.6, 0.5, 0.7, 0.7);
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

	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(8, 0, 0);
		glColor3f(1.0, 0.0, 1.0);
		DrawHouse(1, 2, 1, 0.4, 0.3, 0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(-8, 0, 0);
		glColor3f(0.0, 1.0, 1.0);
		DrawHouse(2, 1.5, 2, 0.6, 0.8, 0.7, 0.7);
	glPopMatrix();

	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(MoveX, MoveY, MoveZ);
		MovePosition(-8, 0, 10);
		glColor3f(1.0, 1.0, 0.0);
		DrawHouse(2, 1.5, 2, 0.6, 0.8, 0.7, 0.7);
	glPopMatrix();
}

void myDisplay() {
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	/* clear the display */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.0, 3.0, 7.0);
	glutWireCube(2);
	glutWireCube(1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	glutWireCube(0.7);
	glutWireCube(0.5);*/
		// Draw Horizontal
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(100.0, double(viewport[2]) / viewport[3], 0.1, 100.0);
		printf("viewport[2] = %d , viewport[3] = %d , 2/3 = %f \r\n", viewport[2], viewport[3], double(viewport[2]) / viewport[3]);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		
		
		DrawFixPlane();
		//glutSolidTeapot(1);
		glLoadIdentity();
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 1.0f);
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		gluLookAt(0, 1.5, 3.5, 0, 0, 0, 0, 1, 0);
		DrawCubeI(0.4, 0.4, 0.4);
		glPopMatrix();
		
		//BuildNormalCity();
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

		CreateNode();
		PreorderTravesal(&MajorRole.Torso);

	//DrawTorso();
	/*glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		glColor3f(0.0, 0.0, 1.0);

		MovePosition(2, 0, 0);
		DrawCubeF(1, 1, 0.5);
		MovePosition(0, 0.5, 0);
		DrawRoof(1, 1, 1);
		MovePosition(0, 0, -15);
		glColor3f(1.0, 1.0, 0.0);
		DrawCubeF(2, 2, 1.5);
		MovePosition(0, 0, 30);
		glColor3f(1.0, 0.0, 0.0);
		DrawCubeF(4, 4, 1.5);
	glPopMatrix();*/



	printf("In Display \r\n");

	//LightSource();
	//LightSource2();
	//LightSource3();
	//
	
	
	glLoadIdentity();
	glPushMatrix();

		glColor3f(1.0f, 0.0f, 1.0f);
		gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
		// h
		glBegin(GL_LINE_LOOP);
			glVertex3f(-7, 1.5, 1); //--
			glVertex3f(7, 1.5, 1); //--
		glEnd();
		glColor3f(1.0f, 1.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
			glVertex3f(-7, -2.5, 1); //--
			glVertex3f(7, -2.5, 1); //--
		glEnd();
		// v
		glBegin(GL_LINE_LOOP);
			glVertex3f(1.5, 7, 1); //--
			glVertex3f(1.5, -7, 1); //--
		glEnd();
		glColor3f(1.0f, 1.0f, 0.0f);
		glBegin(GL_LINE_LOOP);
			glVertex3f(-1, -7, 1); //--
			glVertex3f(-1, 7, 1); //--
		glEnd();
	glPopMatrix();
	// OpenGL -  ensures that the drawing command are actually executed.
	DrawVitality();
	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */
