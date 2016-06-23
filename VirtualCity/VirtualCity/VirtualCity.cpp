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
void CALLBACK AttackTimeCallBack(HWND hwnd, UINT message, UINT timerID, DWORD time);
glLight_Parameter mySource_1;
glMaterial_Parameter myMaterial_1;
RobotParameter Robot_Arm;
RobotParameter Robot_Initial;
glOrtho_Parameter My_Ortho;
RobotArmPosition Robot_Position;
glLookAt_Parameter My_LookAt;
glLookAt_Parameter Initial_LookAt;
HumanObject MajorRole ;
FixObject NonMovingObject;
WorldObject MyWorldObject;

float MoveX = 0.0;
float MoveY = 0.0;
float MoveZ = 0.0;
float v0[3], v1[3];
float mo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
float ORGmo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
int VitalityNum = 100.0;
char string1[10] = "breath : ";
char string2[10];
int id_texture = 0;
int id_texture2 = 0;
int num_texture = -1;

float Rotated_theta = 0.0;
float Rotated_X = 0.0;
float Rotated_Y = 0.0;
float Rotated_Z = 0.0;

int tempX1 = 0;
int tempX2 = 0;

float MoveX1 = 0.0;
float MoveY1 = 0.0;
float MoveZ1 = 0.0;

float Fixed_Z = 3.5;
float Z1 ;
float X1 ;
bool BackFalg = false;
bool ForwardFalg = false;
bool RightFalg = false;
bool LeftFalg = false;
AvoidObject NPC_Flag;
bool DrawHint = false;

float RotateAngle = 180;
//float RotateAngle = 0;
int RoatateCnt = 0;
float MoveValeZ = 0;


#if DisplayMode == 2
GLfloat colors[8][3] = { {0,0,0},{1,0,0},{0,1,0},{0,0,1},{0,1,1},{1,0,1},{1,1,0},{1,1,1} };
typedef struct Particle {
	int color;
	float mass;
	float position[3];
	float velocity[3];
}Particle;
Particle particles[10];

void initParticle(void) {
	for (int i = 0; i < 10; i++) {
		particles[i].mass = 1.0;
		particles[i].color = i%8;
		for (int j = 0; j < 3; j++) {
			particles[i].position[j] = 2.0*((float)rand() / 1) - 1.0;
			particles[i].velocity[j] = 2.0*((float)rand() / 1) - 1.0;
		}
	}	
}

void parDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POINT);
		for (int i = 0; i < 10; i++) {
			glColor3fv(colors[particles[i].color]);
			
			glutSolidCube(particles[i].color);
		}
	glEnd();
	glFlush();
}
float forces(int i , int j) {
	bool gravity = false;
	if (!gravity)
		return 0.0;
	else {
		if (j == 1)
			return -1.0;
		else
			return 0.0;
	}
}
void collision(int i) {
	float coef = 0.5;
	for (int j = 0; j < 3; j++) {
		if (particles[i].position[j] >= 1.0) {
			particles[i].position[j] = 1.0 - coef * (particles[i].position[j]-1.0);
			particles[i].velocity[j] *= -1.0 *coef;
		}
		if (particles[i].position[j] <= -1.0) {
			particles[i].position[j] = -1.0 - coef * (particles[i].position[j] + 1.0);
			particles[i].velocity[j] *= -1.0 *coef;
		}
	}
}
void parIdle(void) {
	float dt = 0.0001;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			particles[i].position[j] += dt*particles[i].velocity[j];
			particles[i].velocity[j] += dt*forces(i,j)/particles[i].mass;
		}
		collision(i);
	}
	glutPostRedisplay();
}
#endif

void CALLBACK VitalityTimeCallBack(HWND hwnd, UINT message, UINT timerID, DWORD time) {
	VitalityNum = VitalityNum - 1;
	sprintf(string2, " %d ", VitalityNum);
	printf("%s\n", string2);
	glutPostRedisplay();
}
void CALLBACK AttackTimeCallBack(HWND hwnd, UINT message, UINT timerID, DWORD time) {
	MoveZ1 = MoveZ1 - 0.1;
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
		//gluPerspective(100, double(viewport[2]) / viewport[3], 0.1, 100.0);
		gluPerspective(60, double(viewport[2]) / viewport[3], 0.1, 100.0);
		//printf("viewport[2] = %d , viewport[3] = %d , 2/3 = %f \r\n", viewport[2], viewport[3], double(viewport[2]) / viewport[3]);

		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		
		
		DrawFixPlane();
		//glutSolidTeapot(1);
		glLoadIdentity();

		glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			/*glGetFloatv(GL_MODELVIEW_MATRIX, ORGmo);
			for (int i = 0; i < 16; i += 4) {
				for (int j = 0; j < 4; j++)
					printf(" ORGmo[%d] = %f ,", i + j, ORGmo[i + j]);
				printf("\r\n");
			}
			printf(" =========== \r\n");*/

			gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
			//glMultMatrixf(mo);
			//MovePosition(10, 0, 0);
			/*for (int i = 0; i < 16; i += 4) {
				for (int j = 0; j < 4; j++)
					printf(" mo[%d] = %f ,", i + j, mo[i + j]);
				printf("\r\n");
			}
			printf("\r\n");*/
			DrawCubeI(0.4, 0.4, 0.4);
		glPopMatrix();
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);

			gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
			
			MovePosition(0, 0, 140);

			DrawCubeI(0.4, 0.4, 0.4);
		glPopMatrix();
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);

			gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
			
			MovePosition(100, 0, -50);

			DrawCubeI(1, 1, 1);
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
		//PreorderTravesal(&MyWorldObject.Fix.Plane);
		PreorderTravesal(&MajorRole.Torso);
		
		glLoadIdentity();
		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			
			gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);

			DrawCubeI(3.2, 1, 1);
		glPopMatrix();

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
	
	//補助線
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

	//glPushMatrix();
	//	glColor3f(1.0f, 1.0f, 0.0f);		
	//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	//	MovePosition(-150, 100, 0);
	//	glBindTexture(GL_TEXTURE_2D, id_texture2);
	//	glBegin(GL_QUADS);
	//		glTexCoord2f(0.0, 0.0);glVertex3f(0, 0, 0); //--
	//		glTexCoord2f(1.0, 0.0);glVertex3f(0.8, 0, 0); //+-
	//		glTexCoord2f(1.0, 1.0);glVertex3f(0.8, 0.8, 0); //++ 
	//		glTexCoord2f(0.0, 1.0);glVertex3f(0, 0.8, 0); //-+ 
	//	glEnd();
	//glPopMatrix();

	// OpenGL -  ensures that the drawing command are actually executed.
	DrawVitality();
	// heart
	//if (DrawHint) {
	//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	//	glPushMatrix();
	//	glColor3f(1.0f, 0.0f, 1.0f);
	//	//glRasterPos3f(-10, 7, 0);
	//	glRasterPos3f(-6.5, 5.5, 0);
	//	drawString(string1);
	//	glPopMatrix();
	//}

	if (DrawHint) {
		gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
		glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		//glRasterPos3f(-10, 7, 0);
		glRasterPos3f(-5, 5, 0);
		drawString(" hello my name is NPC 1");
		glPopMatrix();
	}
	

	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */
