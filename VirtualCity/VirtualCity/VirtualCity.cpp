// VirtualCity.cpp : �w�q�D���x���ε{�����i�J�I�C
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
void DrawVSValue(void);
void HintJudge(void);
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
WorldObject MyWorldObject;

ObjBox ObjA;
ObjBox ObjB;
ObjBox ObjC;
ObjBox ObjD;
ObjBox ObjH1;
ObjBox ObjH2;
ObjBox ObjH3;
ObjBox ObjH4;
ObjBox ObjTree_A;
ObjBox ObjTree_B;
ObjBox ObjTree_C;
ObjBox ObjTree_D;

ObjBox ObjRed_A;
ObjBox ObjRed_B;
ObjBox ObjRed_C;
ObjBox ObjGreen_A;
ObjBox ObjGreen_B;
ObjBox ObjBlue_A;
ObjBox ObjBlue_B;
ObjBox ObjLast;

ObjBox MyHouse;
ObjBox MyTree_A;
ObjBox MyTree_B;

float MoveX = 0.0;
float MoveY = 0.0;
float MoveZ = 0.0;
float v0[3], v1[3];
float mo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
float mo2[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
float ORGmo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };

char HintString[100];
char VitalityHintString[100];
char VitalityString[10];
char SleepHintString[100];
char SleepString[10];
int VitalityNum = 100;
int SleepNum = 200;

char TaskStringR[10];
int TaskRNum = 0;
int TaskRMax = 3;
char TaskStringG[10];
int TaskGNum = 0;
int TaskGMax = 2;
char TaskStringB[10];
int TaskBNum = 0;
int TaskBMax = 2;
char TaskFinish[20];

char string1[10] = "breath : ";
char string2[10];
char string3[10];

char string4[10];

int id_texture = 0;
int id_texture2 = 0;
int id_texture3 = 0;
int id_texture4 = 0;

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

float PosXUnit = 0.0;
float PosZUnit = 0.0;
//############################################ Boundary ############################################\\
float Px = 0.0;
float Pz = 0.0;
float Py = 0.0;
float Wx = 0.0;
float Wz = 0.0;
// Cube 1.0
float BoundPxU = -0.060;
float BoundPxD = -0.1132;
float BoundPzU = 0.46;
float BoundPzD = -1.25;

float BoundPyU = 0.95;
float BoundPyD = -0.95;
// House 1.0
float H_PyU = 1.14;   //m1
float H_PyD = -1.25;
float H_PxU = -0.04;  //m2
float H_PxD = -0.12;
float H_PzU = 0.4;    //m3
float H_PzD = -1.8;
// Cube 0.5
float BC05m0_U = 0.232; // a lot of ++
float BC05m0_D = -0.6;  // a lot of ++
float BC05m1_U = -0.06; 
float BC05m1_D = -0.9;
float BC05m2_U = 0.302;
float BC05m2_D = -1.0;
// House 1.0 2.0 1.0
float BH121m0_U = 0.991;
float BH121m0_D = -0.9;
float BH121m1_U = 0.5;
float BH121m1_D = 0.28;
float BH121m2_U = 0.7;
float BH121m2_D = -1.6;
// Tree 
float BTreem0_U = 0.6;
float BTreem0_D = -0.7;
float BTreem1_U = 0.95;
float BTreem1_D = 0.85;
float BTreem2_U = 0.5;
float BTreem2_D = -0.95;
ObjectBoundary Tree1_B;
ObjectBoundary House1_B;
ObjectBoundary House2_B;
ObjectBoundary Cube10_B;
ObjectBoundary Cube05_B;
//############################################ Boundary ############################################\\
float distant_x = 0.0;
float distant_y = 0.0;
float distant_z = 0.0;
float ObjA_w = 1.0; // z
float ObjA_h = 1.0; // y
float ObjA_l = 1.0; // x
bool BoundPy = false;
bool BoundPx = false;
bool BoundPz = false;
bool BoundObjBox1 = false;

bool WorldCollFalg = false;

float objBox1[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };

GLfloat D[8][3];

float ObjPosMapping[16][3] = {	{ 0,0,0 },{ -40,0,0 },{ 40,0,0 },
								{ 40,0,-40 },{ 120,0,-40 },{ -40,0,-40 },{ -120,0,-40 },
								{ 130,0,0 },{ 0,0,-40 },{ 100,0,0 },{ -100,0,0 }, // 11
								{ 100,0,100 },{ -100,0,100 },{ -70,0,50 },{ -50,0,50 },// 15
								{ 50,0,50 } // 16
							 };float ObjTaskPosMapping[7][3] = {	{ 10,0,50 },{ 50,0,50 },{ 100,0,50 },	// R  1  1  1
									{ -10,0,50 },{ -80,0,50 },				// G 05 05
									{ 30,0,100 },{ -30,0,100 }					// B  1 05
								};
#if DisplayInfoAdjWhite == 1
	float TempMoveX = -308.0;
	float TempMoveY = 121.0;
#else
	 float TempMoveX = -15;
	 float TempMoveY = 5;
#endif


int LevelCnt = 0;

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
	if (MyHouse.Counter >= 5) {
		if (VitalityNum == 100)
			VitalityNum = 100;
		else
			VitalityNum = VitalityNum + 1;
		MyHouse.Counter--;
		sprintf(VitalityHintString, "This is my house. You can get 1 blood. Time: %d Sec", MyHouse.Counter-4);
		printf("%s\r\n", VitalityHintString);
	}
	else {
		if (VitalityNum == 0)
			exit(0);
		else
			VitalityNum = VitalityNum - 1;
		MyHouse.Counter = 0;
		sprintf(VitalityHintString, "");
		printf("%s\r\n", VitalityHintString);
	}
	sprintf(VitalityString, " %d ", VitalityNum);
	printf("%s\n", VitalityString);
	glutPostRedisplay();
}
void CALLBACK SleepTimeCallBack(HWND hwnd, UINT message, UINT timerID, DWORD time) {
	if ((MyTree_A.Counter >= 5)|| (MyTree_B.Counter >= 5)){
		if (SleepNum == 200)
			SleepNum = 200;
		else
			SleepNum = SleepNum + 1;
		if (MyTree_A.Counter >= 5) {
			MyTree_A.Counter--;
			sprintf(SleepHintString, "This is my Tree. You can get 1 Sleep. Time: %d Sec", MyTree_A.Counter - 4);
			printf("%s\r\n", SleepHintString);
		}
		else if (MyTree_B.Counter >= 5) {
			MyTree_B.Counter--;
			sprintf(SleepHintString, "This is my Tree. You can get 1 Sleep. Time: %d Sec", MyTree_B.Counter - 4);
			printf("%s\r\n", SleepHintString);
		}
	}
	else {
		if (SleepNum == 0)
			exit(0);
		else
			SleepNum = SleepNum - 1;		
		MyTree_A.Counter = 0;
		MyTree_B.Counter = 0;
		sprintf(SleepHintString, "");
		printf("%s\r\n", SleepHintString);
	}
	sprintf(SleepString, " %d ", SleepNum);
	printf("%s\n", SleepString);
	glutPostRedisplay();
}

void CALLBACK AttackTimeCallBack(HWND hwnd, UINT message, UINT timerID, DWORD time) {
	MoveZ1 = MoveZ1 - 0.1;
	printf("%s\n", string2);
	glutPostRedisplay();
}
int main(int argc, char** argv) {	
	// set Vitality Call Back Fun Timer : 3 sec
		SetTimer(NULL, 0, 1000, VitalityTimeCallBack);
		SetTimer(NULL, 0, 1000, SleepTimeCallBack);
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

		// Draw Horizontal

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//gluPerspective(100, double(viewport[2]) / viewport[3], 0.1, 100.0);
		gluPerspective(60, double(viewport[2]) / viewport[3], 0.1, 100.0);
		//printf("viewport[2] = %d , viewport[3] = %d , 2/3 = %f \r\n", viewport[2], viewport[3], double(viewport[2]) / viewport[3]);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		DrawFixPlane();


		// �T�w���󪺫إ�
		//DrawFixObj();

		
		

		DrawObjFlow(&MyHouse);

		
		



		/*glColor3f(0.0f, 1.0f, 0.0f);
		ObjA.DrawObj(&ObjA,80,0,0,id_texture4);

		glColor3f(0.8f, 0.5f, 0.0f);
		ObjB.DrawObj(&ObjB, 30, 0, -20, id_texture4);

		glColor3f(0.8f, 0.5f, 1.0f);
		ObjC.DrawObj(&ObjC, 130, 0, -20, id_texture4);

		glColor3f(0.8f, 0.5f, 0.0f);
		ObjTree_A.DrawObj(&ObjTree_A,0,0,10, id_texture4);

		glColor3f(0.8f, 1.0f, 1.0f);
		ObjD.DrawObj(&ObjD, 0, 0, 0, id_texture4);

		glColor3f(1.0f, 0.0f, 0.0f);
		ObjRed_A.DrawObj(&ObjRed_A,-10,0,0,id_texture4);*/

		/*glColor3f(1.0f, 1.0f, 1.0f);
		ObjH1.DrawObj(&ObjH1, -10, 0, -50, id_texture4);

		glColor3f(0.85f, 0.56f, 0.72f);
		ObjH2.DrawObj(&ObjH2, -100, 0, -50, id_texture4);
*/
		

		//// �e�Фl 1
		//glPushMatrix();
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	glColor3f(1.0, 0.0, 0.0);
		//	MovePosition(80, 0, -100);
		//	glGetFloatv(GL_MODELVIEW_MATRIX, ObjH1.org_m);
		//	ObjH1.m[0] = ObjH1.org_m[12];
		//	ObjH1.m[1] = ObjH1.org_m[13];
		//	ObjH1.m[2] = ObjH1.org_m[14];
		//	//printf(" m1[0] = %f , m1[1] = %f , m1[2] = %f \r\n", ObjH1.m[0], ObjH1.m[1], ObjH1.m[2]);			
		//	DrawCubeTexture(1.0, 1.0, 1.0, id_texture3);
		//	MovePosition(0, 10, 0);
		//	DrawRoof(0.5, 0.5, 0.5);
		//	MovePosition(0, -10, 0);
		//	DrawDoor(0.5, 0.5, 0.5, 0.2, 0.3);
		//	MovePosition(0, -5, 0);
		//	DrawWindows(0.5, 0.5, 0.5, 0.2, 0.3, 0.3, 0.3);
		//glPopMatrix();


		//// Tree Object
		//glPushMatrix();
		//	glColor3f(0.8f, 0.5f, 0.0f);
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	MovePosition(0, 20, 0);
		//	glGetFloatv(GL_MODELVIEW_MATRIX, ObjTree_A.org_m);
		//	ObjTree_A.m[0] = ObjTree_A.org_m[12];
		//	ObjTree_A.m[1] = ObjTree_A.org_m[13];
		//	ObjTree_A.m[2] = ObjTree_A.org_m[14];
		//	//printf(" m[0] = %f , m[1] = %f , m[2] = %f \r\n", ObjTree_A.m[0], ObjTree_A.m[1], ObjTree_A.m[2]);
		//	DrawCubeTexture(0.5,2.5,0.5,id_texture3);
		//	MovePosition(0, 10, 0);
		//	DrawTriangleTexture(2,3,2, id_texture3);
		//glPopMatrix();

		// Red Object
		//glPushMatrix();
		//	glColor3f(1.0f, 0.0f, 0.0f);
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	MovePosition(-50, 0, 0);
		//	glGetFloatv(GL_MODELVIEW_MATRIX, ObjRed_A.org_m);
		//	ObjRed_A.m[0] = ObjRed_A.org_m[12];
		//	ObjRed_A.m[1] = ObjRed_A.org_m[13];
		//	ObjRed_A.m[2] = ObjRed_A.org_m[14];
		//	//printf(" m[0] = %f , m[1] = %f , m[2] = %f \r\n", ObjRed_A.m[0], ObjRed_A.m[1], ObjRed_A.m[2]);
		//	DrawCubeTexture(0.5,0.5,0.5,id_texture3);
		//glPopMatrix();
		
		//// �e�Фl 2
		//glPushMatrix();
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	glColor3f(0.0, 0.0, 1.0);
		//	MovePosition(-20, 10, 0);
		//	glGetFloatv(GL_MODELVIEW_MATRIX, ObjH2.org_m);
		//	ObjH2.m[0] = ObjH2.org_m[12];
		//	ObjH2.m[1] = ObjH2.org_m[13];
		//	ObjH2.m[2] = ObjH2.org_m[14];
		//	//printf(" m1[0] = %f , m1[1] = %f , m1[2] = %f \r\n", ObjH2.m[0], ObjH2.m[1], ObjH2.m[2]);			
		//	DrawCubeTexture(1.0, 2.0, 1.0, id_texture3);
		//	MovePosition(0, 20, 0);
		//	DrawRoof(0.5, 0.5, 0.5);
		//	MovePosition(0, -30, 0);
		//	DrawDoor(0.5, 0.5, 0.5, 0.2, 0.3);
		//	MovePosition(0, -5, 0);
		//	DrawWindows(0.5, 0.5, 0.5, 0.2, 0.3, 0.3, 0.3);
		//glPopMatrix();

		


		//-------------------------------------------------
		//CreateNode();
		////PreorderTravesal(&MyWorldObject.Fix.Plane);
		//PreorderTravesal(&MajorRole.Torso);
		//
		//glLoadIdentity();
		//glPushMatrix();
		//	glColor3f(0.0f, 0.0f, 1.0f);
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	DrawCubeI(3.2, 1, 1);
		//glPopMatrix();
		//-------------------------------------------------

	



	printf("In Display \r\n");

	//LightSource();
	//LightSource2();
	//LightSource3();
	
	DrawVitality();

	glDisable(GL_TEXTURE_2D);

	DrawCenterLine();	// �ɧU�u
	DrawVSValue();		// ���O���
	HintJudge();		// �n�����Ʊ�

	/*if (DrawHint) {
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos3f(-14, 7, 0);
		drawString(" hello my name is NPC 1");
		glPopMatrix();
		DrawHint = false;
	}*/
	glEnable(GL_TEXTURE_2D);

	glFlush();
	glutSwapBuffers();
}/* End of myDisplay */

void DrawVSValue(void) {
	// �ͩR ���թ��� string2
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		//MovePosition(TempMoveX, TempMoveY, 0);
		MovePosition(-258, -231, 0);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0); //--
			glVertex3f(2.5, 0, 0); //+-
			glVertex3f(2.5, 2.5, 0); //++ 
			glVertex3f(0, 2.5, 0); //-+ 
		glEnd();
	glPopMatrix();
	// �ͩR �� string2
	glPushMatrix();
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos3f(-12, -10.5, 0);
		//glRasterPos3f(TempMoveX, TempMoveY, 0);
		//drawString("12");
		drawString(VitalityString);
	glPopMatrix();

	// Sleep ���թ��� string3
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		//MovePosition(TempMoveX, TempMoveY, 0);
		MovePosition(-158, -231, 0);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0); //--
			glVertex3f(2.5, 0, 0); //+-
			glVertex3f(2.5, 2.5, 0); //++ 
			glVertex3f(0, 2.5, 0); //-+ 
		glEnd();
	glPopMatrix();
	// Sleep �� string3
	glPushMatrix();
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos3f(-7, -10.5, 0);
		//glRasterPos3f(TempMoveX, TempMoveY, 0);
		drawString(SleepString);
		//drawString("34");
	glPopMatrix();
	// ���ܦr ���թ���
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		MovePosition(-90, -231, 0);
		//MovePosition(TempMoveX, TempMoveY, 0);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0); //--
			glVertex3f(12, 0, 0); //+-
			glVertex3f(12, 3, 0); //++ 
			glVertex3f(0, 3, 0); //-+ 
		glEnd();
	glPopMatrix();
	// ���ܦr ����r�T��
	glPushMatrix();
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos3f(-4.1, -9.6, 0);
		drawString(" Hint Font : ");
		//glRasterPos3f(-3.7, -10.6, 0);
		glRasterPos3f(-4.1 + 0.4, -9.6 - 1, 0);
		//glRasterPos3f(TempMoveX, TempMoveY, 0);
		//drawString(" hello my name is NPC 1");
		drawString(HintString);
		drawString(SleepHintString);
		drawString(VitalityHintString);
	glPopMatrix();

	// ���Ȧr ���թ���
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 1.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		MovePosition(-308, 111, 0);
		//MovePosition(TempMoveX, TempMoveY, 0);
		glBegin(GL_QUADS);
			glVertex3f(0, 0, 0); //--
			glVertex3f(8, 0, 0); //+-
			glVertex3f(8, 6, 0); //++ 
			glVertex3f(0, 6, 0); //-+ 
		glEnd();
	glPopMatrix();

	// ���Ȧr 
	glPushMatrix();
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		glColor3f(0.0f, 0.0f, 0.0f);
		glRasterPos3f(-15.2, 11, 0);		
		drawString(" Task : ");
			glRasterPos3f(-15.2 + 0.5, 11 - 0.7, 0);
			drawString(" Red Object : ");
				glRasterPos3f(-15.2 + 4, 11 - 0.7, 0);
				drawString(TaskStringR);
			glRasterPos3f(-15.2 + 0.5, 11 - 0.7*2, 0);
			drawString(" Green Object : ");
				glRasterPos3f(-15.2 + 4, 11 - 0.7*2, 0);
				drawString(TaskStringG);
			glRasterPos3f(-15.2 + 0.5, 11 - 0.7 * 3, 0);
			drawString(" Blue Object : ");
				glRasterPos3f(-15.2 + 4, 11 - 0.7 * 3, 0);
				drawString(TaskStringB);
			glRasterPos3f(-15.2 + 0.5, 11 - 0.7 * 4, 0);
				drawString(TaskFinish);
	glPopMatrix();

}

void HintJudge(void) {
	if (MyHouse.hint) {
		MyHouse.Counter = 10 + 5;
		sprintf(VitalityHintString,"This is my house. You can get 1 blood.");
		printf("%s\r\n", VitalityHintString);
		printf(" MyHouse.hint = %d \r\n", MyHouse.hint);
		MyHouse.hint = false;	
		glutPostRedisplay();
	}
	else if (MyTree_A.hint) {
		MyTree_A.Counter = 10 + 5;
		sprintf(SleepHintString, "This is my Tree. You can get 1 Sleep.");
		printf("%s\r\n", SleepHintString);
		printf(" MyTree_A.hint = %d \r\n", MyTree_A.hint);
		MyTree_A.hint = false;
		glutPostRedisplay();
	}
	else if (MyTree_B.hint) {
		MyTree_B.Counter = 10 + 5;
		sprintf(SleepHintString, "This is my Tree. You can get 1 Sleep.");
		printf("%s\r\n", SleepHintString);
		printf(" MyTree_B.hint = %d \r\n", MyTree_B.hint);
		MyTree_B.hint = false;
		glutPostRedisplay();
	}
	else if (ObjRed_A.hint) {
		DeleteNode(&ObjRed_A);
		// Object ++
		TaskRNum = TaskRNum + 1;
		sprintf(TaskStringR, " %d / %d ", TaskRNum, TaskRMax);
		printf("%s\n", TaskStringR);

		sprintf(HintString, " You get a Red Object ");
		printf("%s\n", HintString);

		glutPostRedisplay();
	}
	else if (ObjRed_B.hint) {
		DeleteNode(&ObjRed_B);
		// Object ++
		TaskRNum = TaskRNum + 1;
		sprintf(TaskStringR, " %d / %d ", TaskRNum, TaskRMax);
		printf("%s\n", TaskStringR);
		sprintf(HintString, " You get a Red Object ");
		printf("%s\n", HintString);
		glutPostRedisplay();
	}
	else if (ObjRed_C.hint) {
		DeleteNode(&ObjRed_C);
		//printf(" ObjRed_C.hint = %d \r\n", ObjRed_C.hint);
		// Object ++
		TaskRNum = TaskRNum + 1;
		sprintf(TaskStringR, " %d / %d ", TaskRNum, TaskRMax);
		printf("%s\n", TaskStringR);
		sprintf(HintString, " You get a Red Object ");
		printf("%s\n", HintString);
		glutPostRedisplay();
	}
	else if (ObjGreen_A.hint) {
		DeleteNode(&ObjGreen_A);
		//printf(" ObjGreen_A.hint = %d \r\n", ObjGreen_A.hint);
		// Object ++
		TaskGNum = TaskGNum + 1;
		sprintf(TaskStringG, " %d / %d ", TaskGNum, TaskGMax);
		printf("%s\n", TaskStringG);
		sprintf(HintString, " You get a Green Object ");
		printf("%s\n", HintString);
		glutPostRedisplay();
	}
	else if (ObjGreen_B.hint) {
		DeleteNode(&ObjGreen_B);
		printf(" ObjGreen_B.hint = %d \r\n", ObjGreen_B.hint);
		TaskGNum = TaskGNum + 1;
		sprintf(TaskStringG, " %d / %d ", TaskGNum, TaskGMax);
		printf("%s\n", TaskStringG);
		sprintf(HintString, " You get a Green Object ");
		printf("%s\n", HintString);
		glutPostRedisplay();
	}
	else if (ObjBlue_A.hint) {
		DeleteNode(&ObjBlue_A);
		printf(" ObjBlue_A.hint = %d \r\n", ObjBlue_A.hint);
		TaskBNum = TaskBNum + 1;
		sprintf(TaskStringB, " %d / %d ", TaskBNum, TaskBMax);
		printf("%s\n", TaskStringB);
		sprintf(HintString, " You get a Blue Object ");
		printf("%s\n", HintString);
		glutPostRedisplay();
	}
	else if (ObjBlue_B.hint) {
		DeleteNode(&ObjBlue_B);
		printf(" ObjBlue_B.hint = %d \r\n", ObjBlue_B.hint);
		TaskBNum = TaskBNum + 1;
		sprintf(TaskStringB, " %d / %d ", TaskBNum, TaskBMax);
		printf("%s\n", TaskStringB);
		sprintf(HintString, " You get a Blue Object ");
		printf("%s\n", HintString);
		glutPostRedisplay();
	}
	else {
		sprintf(HintString, "");
		printf("%s\n", HintString);
		printf(" others \r\n");
	}
	if ((TaskRNum == TaskRMax) && (TaskGNum == TaskGMax) && (TaskBNum == TaskBMax)) {
		TaskRNum = TaskGNum = TaskBNum = 0;
		sprintf(TaskFinish, "you can start building house !");
		printf("%s\n", TaskFinish);
		glutPostRedisplay();
	}
}

/*
"�������A���w���~�A�i�H�}�l�سy�Фl�A���|�ݭn30��"
After finish collecting indicative items, 
you can start building house, which will take 30 seconds
*/