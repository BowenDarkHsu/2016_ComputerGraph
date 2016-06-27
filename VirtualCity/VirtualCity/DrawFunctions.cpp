#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "DrawFunctions.h"
#include "glFunctions.h"
#include "texture.h"
#include "math.h"
void MovePosition(float x , float y , float z) {
	glTranslated((x / My_Ortho.X2), (y / My_Ortho.Y2), (z / My_Ortho.Z2));
}

/* Modeling Function */
void CreateNode(void) {
	//// MyWorldObject.Fix.Tree_0
	//// Right   : Tree
	//// Left	 : Show
	//glLoadIdentity();
	//glGetFloatv(GL_MODELVIEW_MATRIX, .m);
	//.f = DrawHouse_0;
	//.Sibling = &MajorRole.LeftUpperArm;
	//.Child = NULL;

	//// create plane
	//glLoadIdentity();
	//gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	//glGetFloatv(GL_MODELVIEW_MATRIX, MyWorldObject.Fix.Plane.m);
	//MyWorldObject.Fix.Plane.f = DrawFixPlane;
	//MyWorldObject.Fix.Plane.Sibling = &MyWorldObject.Fix.House_0;
	//MyWorldObject.Fix.Plane.Child = NULL;
	//	// MyWorldObject.Fix.House_0
	//	// Right : Tree
	//	// Left	 : Show -->null ====> Robot
	//	glLoadIdentity();
	//	//gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	//	MovePosition(-100, 0, -50);
	//	glGetFloatv(GL_MODELVIEW_MATRIX, MyWorldObject.Fix.House_0.m);
	//	MyWorldObject.Fix.House_0.f = DrawHouse_0;
	//	MyWorldObject.Fix.House_0.Sibling = &MajorRole.Torso;
	//	MyWorldObject.Fix.House_0.Child = &MyWorldObject.Fix.Tree_0;
	//	// MyWorldObject.Fix.Tree_0
	//	// Right : Tree
	//	// Left	 : Side
	//	glLoadIdentity();
	//	//gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	//	MovePosition(100, 0, -50);
	//	glGetFloatv(GL_MODELVIEW_MATRIX, MyWorldObject.Fix.Tree_0.m);
	//	MyWorldObject.Fix.Tree_0.f = DrawTree_0;
	//	MyWorldObject.Fix.Tree_0.Sibling = &MyWorldObject.Fix.Side_0;
	//	MyWorldObject.Fix.Tree_0.Child = NULL;
	//	// MyWorldObject.Fix.Side_0
	//	// Right   : NULL
	//	// Left	 : NULL
	//	glLoadIdentity();
	//	MovePosition(-120, 0, -50);
	//	//gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);		
	//	glGetFloatv(GL_MODELVIEW_MATRIX, MyWorldObject.Fix.Side_0.m);
	//	MyWorldObject.Fix.Side_0.f = DrawSide_0;
	//	MyWorldObject.Fix.Side_0.Sibling = NULL;
	//	MyWorldObject.Fix.Side_0.Child = NULL;

	// MajorRole.Torso
	glLoadIdentity();
	MovePosition(MoveX -100 , MoveY +55, MoveZ + 0);
	glRotated(Rotated_theta, Rotated_X, Rotated_Y, Rotated_Z);
	//MovePosition(0, 20, 0);
	
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);

	glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.Torso.m);
	MajorRole.Torso.f = DrawTorso;
	MajorRole.Torso.Sibling = NULL;
	MajorRole.Torso.Child = &MajorRole.Head;
		// Head
		glLoadIdentity();			
		MovePosition(0,26,0);
		glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.Head.m);
		MajorRole.Head.f = DrawHead;
		MajorRole.Head.Sibling = &MajorRole.LeftUpperArm;
		MajorRole.Head.Child = NULL;
		// Left Upper Arm
		glLoadIdentity();
		MovePosition(-14, 15, 0);
		glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.LeftUpperArm.m);
		MajorRole.LeftUpperArm.f = DrawLUA;
		MajorRole.LeftUpperArm.Sibling = &MajorRole.RightUpperArm;
		MajorRole.LeftUpperArm.Child = &MajorRole.LeftLowerArm;
			// Left Lower Arm
			glLoadIdentity();
			MovePosition(0, -15, 0);
			glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.LeftLowerArm.m);
			MajorRole.LeftLowerArm.f = DrawLLA;
			MajorRole.LeftLowerArm.Sibling = NULL;
			MajorRole.LeftLowerArm.Child = NULL;
		// Right Upper Arm 
		glLoadIdentity();
		MovePosition(14, 15, 0);
		glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.RightUpperArm.m);
		MajorRole.RightUpperArm.f = DrawLUA;
		MajorRole.RightUpperArm.Sibling = &MajorRole.LeftUpperLeg;
		MajorRole.RightUpperArm.Child = &MajorRole.RightLowerArm;
			// Right Lower Arm
			glLoadIdentity();
			MovePosition(0, -15, 0);
			glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.RightLowerArm.m);
			MajorRole.RightLowerArm.f = DrawLLA;
			MajorRole.RightLowerArm.Sibling = NULL;
			MajorRole.RightLowerArm.Child = NULL;
		// Left Upper Leg 
		glLoadIdentity();
		MovePosition(-4, -28, 0);
		glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.LeftUpperLeg.m);
		MajorRole.LeftUpperLeg.f = DrawLUL;
		MajorRole.LeftUpperLeg.Sibling = &MajorRole.RightUpperLeg;
		MajorRole.LeftUpperLeg.Child = NULL;

		// Right Upper Leg 
		glLoadIdentity();
		MovePosition(4, -28, 0);
		glGetFloatv(GL_MODELVIEW_MATRIX, MajorRole.RightUpperLeg.m);
		MajorRole.RightUpperLeg.f = DrawLUL;
		//MajorRole.LeftUpperLeg.Sibling = &MajorRole.RightUpperLeg;
		MajorRole.RightUpperLeg.Sibling = NULL;
		MajorRole.RightUpperLeg.Child = NULL;

	//MajorRole.RightUpperLeg.Sibling = NULL;
	//MajorRole.RightUpperLeg.Child = NULL;
}
void PreorderTravesal(TreeNode *root) {

	if (root == NULL) return;
	glPushMatrix();
		glMultMatrixf(root->m);
		root->f();
		if (root->Child != NULL)
			PreorderTravesal(root->Child);
	glPopMatrix();
	if (root->Sibling != NULL)
		PreorderTravesal(root->Sibling);
}
/* End of Modeling Function */


void DrawTorso() {	
	
	glColor3f(0.0f, 1.0f, 0.0f);
	
	DrawCubeI(1,2,0.5);
}
void DrawHead() {
	glColor3f(1.0f, 0.0f, 0.0f);	
	DrawCubeI(0.5, 0.6, 0.5);
}
void DrawLUA() {	
	glColor3f(0.0f, 0.0f, 1.0f);
	DrawCubeI(0.4, 0.8, 0.5);
}
void DrawLLA() {
	glColor3f(1.0f, 0.0f, 0.0f);
	DrawCubeI(0.2, 0.7, 0.5);
}
void DrawLUL() {	
	glColor3f(1.0f, 1.0f, 1.0f);
	DrawCubeI(0.3, 0.8, 0.5);
}

void DrawRUL() {
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	glColor3f(1.0f, 0.0f, 1.0f);
	DrawCubeI(0.3, 1.6, 0.5);
}
void DrawCubeI(float L, float H, float W) {
	//glBegin(GL_LINE_LOOP);
	GLfloat Length, Height, Width;
	Length = L / 2;
	Height = H / 2;
	Width = W / 2;
	GLfloat DrawRange[16][3] = {
		{ Length,Height,Width },{ Length,Height,-Width },{ -Length,Height,-Width },
		{ -Length,Height,Width },{ Length,Height,Width },{ Length,-Height,Width },
		{ Length,-Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },
		{ Length,-Height,Width },{ Length,-Height,-Width },{ Length,Height,-Width },
		{ -Length,Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },{ -Length,Height,Width } };
	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };	
	glBegin(GL_LINE_LOOP);
	//glBegin(GL_POLYGON);
	for (int i = 0; i < 16; i++) {
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}

void DrawCubeTexture(float L, float H, float W, int texture) {
	//glBegin(GL_LINE_LOOP);
	GLfloat L1, H1, W1;
	L1 = L / 2;
	H1 = H / 2;
	W1 = W / 2;
	GLfloat P[8][3] = { { L1,H1,W1 },{ L1,H1,-W1 },{ L1,-H1,W1 },{ L1,-H1,-W1 },
						{ -L1,H1,W1 },{ -L1,H1,-W1 },{ -L1,-H1,W1 },{ -L1,-H1,-W1 } };
	GLfloat P0[3] = { L1,H1,W1 };
	GLfloat P1[3] = { L1,H1,-W1 };
	GLfloat P2[3] = { L1,-H1,W1 };
	GLfloat P3[3] = { L1,-H1,-W1 };
	GLfloat P4[3] = { -L1,H1,W1 };
	GLfloat P5[3] = { -L1,H1,-W1 };
	GLfloat P6[3] = { -L1,-H1,W1 };
	GLfloat P7[3] = { -L1,-H1,W1 };
	GLfloat Draw_U[4][3] = { { L1,H1,W1 },{ -L1,H1,W1 },{ -L1,H1,-W1 },{ L1,H1,-W1 } };		// 0451
	GLfloat Draw_R[4][3] = { { L1,-H1,-W1 },{ L1,-H1,W1 },{ L1,H1,W1 },{ L1,H1,-W1 } };		// 3201
	GLfloat Draw_D[4][3] = { { L1,-H1,W1 },{ -L1,-H1,W1 },{ -L1,-H1,-W1 },{ L1,-H1,-W1 } }; // 2673
	GLfloat Draw_L[4][3] = { { -L1,-H1,W1 },{ -L1,-H1,-W1 },{ -L1,H1,-W1 },{ -L1,H1,W1 } }; // 6754
	GLfloat Draw_F[4][3] = { { L1,-H1,W1 },{ -L1,-H1,W1 },{ -L1,H1,W1 },{ L1,H1,W1 } };		// 2640
	GLfloat Draw_B[4][3] = { { L1,-H1,-W1 },{ -L1,-H1,-W1 },{ -L1,H1,-W1 },{ L1,H1,-W1 } }; // 3751
	GLfloat Testure2D[4][2] = { { 0,0 },{ 1,0 },{ 1,1 },{ 0,1 } };

	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	for (int i = 0; i < 4; i++) {
		glNormal3fv(Draw_U[i]);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(Draw_U[i]);
	}
	for (int i = 0; i < 4; i++) {
		glNormal3fv(Draw_R[i]);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(Draw_R[i]);
	}
	for (int i = 0; i < 4; i++) {
		glNormal3fv(Draw_D[i]);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(Draw_D[i]);
	}
	for (int i = 0; i < 4; i++) {
		glNormal3fv(Draw_L[i]);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(Draw_L[i]);
	}
	for (int i = 0; i < 4; i++) {
		glNormal3fv(Draw_F[i]);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(Draw_F[i]);
	}
	for (int i = 0; i < 4; i++) {
		glNormal3fv(Draw_B[i]);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(Draw_B[i]);
	}
	glEnd();
	/*for (int i = 0; i < 8; i++){
		for (int j = 0; j < 3; j++) {
			D[i][j] = P[i][j];
			printf(" D[%d][%d] = %f , ", i,j,D[i][j]);
		}
		printf(" \r\n");
	}*/
}

void DrawTriangleTexture(float L, float H, float W, int texture) {
	GLfloat Length, Height, Width;
	Length = L / 2;
	Height = H / 2;
	Width = W / 2;
	GLfloat Testure2D[4][2] = { { 0,0 },{ 1,0 },{ 1,1 },{ 0,1 } };

	GLfloat DrawRange[5][3] = {
		{ Length,0,Width },{ -Length,0,Width },{ -Length,0,-Width },{ Length,0,-Width },{ Length,0,Width }	// 5
	};

	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };

	GLfloat Draw_Triangle[12][3] = {
		{ Length , 0 , Width } ,{ -Length , 0 , Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // ABM
		{ Length , 0 , Width } ,{ Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // ADM
		{ -Length , 0 , Width } ,{ -Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // BCM
		{ -Length , 0 , -Width } ,{ Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // CDM
	};

	GLfloat Draw_A[3] = { Length , 0 , Width };
	GLfloat Draw_B[3] = { -Length , 0 , Width };
	GLfloat Draw_C[3] = { -Length , 0 , -Width };
	GLfloat Draw_D[3] = { Length , 0 , -Width };
	GLfloat Draw_M[3] = { ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) };

	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(DrawPoint);
	}
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);

	for (int j = 0 ; j < 12 ; j++) {
		for (int k = 0 ; k < 3 ; k++) {
			DrawPoint[k] = Draw_Triangle[j][k];
		}
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();

}

void DrawHouse(float Length, float Height, float Width, float door_L, float door_H, float Windows_L, float Windows_H) {
//	DrawCubeF(Length, Height, Width);
//
//	DrawDoor(Length, Height, Width, door_L, door_H);
//
//	DrawWindows(Length, Height, Width, door_L, door_H, Windows_L, Windows_H);
//
//	MovePosition(0, Height, 0);
////	DrawRoof(Length, Height, Width);
}
void DrawRoof (float Length, float Height, float Width , int texture) {
	//glBegin(GL_LINE_LOOP);
	GLfloat Testure2D[4][2] = { { 0,0 },{ 1,0 },{ 1,1 },{ 0,1 } };

	GLfloat DrawRange[5][3] = {
		{ Length,0,Width },{ -Length,0,Width },{ -Length,0,-Width },{ Length,0,-Width },{ Length,0,Width }	// 5
	};

	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };

	GLfloat Draw_Triangle[12][3] = {
		{ Length , 0 , Width } ,{ -Length , 0 , Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // ABM
		{ Length , 0 , Width } ,{ Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // ADM
		{ -Length , 0 , Width } ,{ -Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // BCM
		{ -Length , 0 , -Width } ,{ Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.X2) , Height , ((-Width) / 2 / My_Ortho.Z2) } , // CDM
	};

	GLfloat Draw_A[3] = { Length , 0 , Width };
	GLfloat Draw_B[3] = { -Length , 0 , Width };
	GLfloat Draw_C[3] = { -Length , 0 , -Width };
	GLfloat Draw_D[3] = { Length , 0 , -Width };
	GLfloat Draw_M[3] = { ((-Length)/4 / My_Ortho.X2) , Height , ((-Width)/2/ My_Ortho.Z2) };
		
	
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {	
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(DrawPoint);
	}
	glEnd();
	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

		/*for (int j = 0 ; j < 12 ; j++) {

			for (int k = 0 ; k < 3 ; k++) {
				DrawPoint[k] = Draw_Triangle[j][k];
			}		
			glNormal3fv(DrawPoint);
			glVertex3fv(DrawPoint);
		}*/
	glColor3f(1.0, 0.0, 0.0);
		for (int j = 0 ; j < 3 ; j++) {
			for (int k = 0 ; k < 3 ; k++) 
				DrawPoint[k] = Draw_Triangle[j][k];
			glNormal3fv(DrawPoint);
			glVertex3fv(DrawPoint);
		}
	glColor3f(1.0, 1.0, 0.0);
	for (int j = 3; j < 6; j++) {
		for (int k = 0; k < 3; k++)
			DrawPoint[k] = Draw_Triangle[j][k];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glColor3f(1.0, 0.0,1.0);
	for (int j = 6; j < 9; j++) {
		for (int k = 0; k < 3; k++)
			DrawPoint[k] = Draw_Triangle[j][k];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glColor3f(0.0, 1.0, 1.0);
	for (int j = 9; j < 12; j++) {
		for (int k = 0; k < 3; k++)
			DrawPoint[k] = Draw_Triangle[j][k];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}
void DrawCubeF(float Length, float Height, float Width) {
	//glBegin(GL_LINE_LOOP);
	GLfloat DrawRange[16][3] = {
		{ Length,Height,Width },{ Length,Height,-Width },{ -Length,Height,-Width },
		{ -Length,Height,Width },{ Length,Height,Width },{ Length,-Height,Width },
		{ Length,-Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },
		{ Length,-Height,Width },{ Length,-Height,-Width },{ Length,Height,-Width },
		{ -Length,Height,-Width },{ -Length,-Height,-Width },{ -Length,-Height,Width },{ -Length,Height,Width } };
	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 16; i++) {
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}
void DrawDoor(float Length, float Height, float Width, float door_L , float door_H , int texture) {
	//glBegin(GL_LINE_LOOP);
	//float Point_A[3] = { ((-Length) / My_Ortho.Value + door_L / My_Ortho.Value),0,Width };										// A
	//float Point_B[3] = { ((-Length) / My_Ortho.Value + door_L / My_Ortho.Value), ((-Height) / My_Ortho.Value + door_H / My_Ortho.Value) ,Width };		// B
	//float Point_C[3] = { ((-Length) / My_Ortho.Value - door_L / My_Ortho.Value), ((-Height) / My_Ortho.Value + door_H / My_Ortho.Value) ,Width };		// C
	//float Point_D[3] = { ((-Length) / My_Ortho.Value - door_L / My_Ortho.Value), ((-Height) / My_Ortho.Value - door_H / My_Ortho.Value) ,Width };		// D
	// Length 1 Width 1 Hight 1
	float Point_A[3] = { -Length+ (Length - door_L / 2),-Height ,Width };										// A
	float Point_B[3] = { -Length + (Length - door_L / 2),(-Height + Height) - door_H / 3  ,Width };		// B
	float Point_C[3] = { -Length + (Length + door_L / 2),(-Height + Height) - door_H / 3 ,Width };		// C
	float Point_D[3] = { -Length + (Length  + door_L / 2),-Height  ,Width };		// D
	GLfloat Testure2D[4][2] = { { 1,0 },{ 1,1 },{ 0,1 },{ 0,0 } };

	GLfloat DrawRange[5][3] = {
		{ Point_A[0],Point_A[1],Point_A[2] },										// A
			{ Point_B[0],Point_B[1],Point_B[2] },										// B
			{ Point_C[0],Point_C[1],Point_C[2] },										// C
			{ Point_D[0],Point_D[1],Point_D[2] },
			{ Point_A[0],Point_A[1],Point_A[2] },
	};
	/*GLfloat DrawRange[5][3] = {
		{ -0.2,-1,0 },
		{ -0.2,-0.1,0 },
		{ 0.2,-0.1,0 },
		{ 0.2,-1,0 },
		{ -0.2,-1,0 }		
	};*/
	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };
	/*printf(" LHW = %f %f %f \r\n ", Length, Height, Width);
	printf(" A = %f %f %f \r\n ", Point_A[0], Point_A[1], Point_A[2]);
	printf(" B = %f %f %f \r\n ", Point_B[0], Point_B[1], Point_B[2]);
	printf(" C = %f %f %f \r\n ", Point_C[0], Point_C[1], Point_C[2]);
	printf(" D = %f %f %f \r\n ", Point_D[0], Point_D[1], Point_D[2]);*/
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}
void DrawWindows(float Length, float Height, float Width, float door_L, float door_H , float W_L , float W_H, int texture) {

	float Point_A[3] = { -Length + (Length - door_L / 2),-Height ,Width };								// A
	float Point_B[3] = { -Length + (Length - door_L / 2),(-Height + Height) - door_H / 3  ,Width };		// B
	float Point_C[3] = { -Length + (Length + door_L / 2),(-Height + Height) - door_H / 3 ,Width };		// C
	float Point_D[3] = { -Length + (Length + door_L / 2),-Height  ,Width };								// D

	GLfloat DrawRange0[5][3] = {
		{ Point_C[0],Point_C[1] + door_H,Point_C[2] },										// Right Windows - Left-Down Corner  
		{ Point_C[0] + W_L,Point_C[1] + door_H,Point_C[2] },										
		{ Point_C[0] + W_L,Point_C[1] + door_H + W_H,Point_C[2] },										
		{ Point_C[0] ,Point_C[1] + door_H + W_H,Point_C[2] },										
		{ Point_C[0],Point_C[1] + door_H,Point_C[2] }										
	};
	GLfloat DrawRange1[5][3] = {		
		{ Point_B[0],Point_B[1] + door_H,Point_B[2] },										// Left Windows - Right-Down Corner 
		{ Point_B[0] - W_L ,Point_B[1] + door_H,Point_B[2] },										
		{ Point_B[0] - W_L ,Point_B[1] + door_H + W_H ,Point_B[2] },										
		{ Point_B[0]  ,Point_B[1] + door_H + W_H ,Point_B[2] },										
		{ Point_B[0],Point_B[1] + door_H,Point_B[2] }										
	};
	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };
	GLfloat Testure2D[4][2] = { { 0,0 },{ 1,0 },{ 1,1 },{ 0,1 } };
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		DrawPoint[0] = DrawRange0[i][0];
		DrawPoint[1] = DrawRange0[i][1];
		DrawPoint[2] = DrawRange0[i][2];
		glNormal3fv(DrawPoint);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(DrawPoint);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 4; i++) {
		DrawPoint[0] = DrawRange1[i][0];
		DrawPoint[1] = DrawRange1[i][1];
		DrawPoint[2] = DrawRange1[i][2];
		glNormal3fv(DrawPoint);
		glTexCoord2f(Testure2D[i % 4][0], Testure2D[i % 4][1]);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}
void DrawFixWindows(void) {
	GLfloat DrawRange[5][3] = {
		{ 0,0,0 },{ -20,0,0 },{ -20,20,0 },{ 0,20,0 },{ 0,0,0 }
	};

	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };
	MovePosition(10, 9, 0);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; i++) {
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}

void DrawFixPlane(void) {
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//glMultMatrixf(mo);
		glColor3f(0.4, 0.4, 0.4);
		
		//glBegin(GL_POLYGON);			
		glBindTexture(GL_TEXTURE_2D, TextureGround);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z1); //--
			glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X2, 0, My_Ortho.Z1); //+-
			glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X2, 0, My_Ortho.Z2); //++ 
			glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z2); //-+ 
		glEnd();
	glPopMatrix();
	// Back
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//glMultMatrixf(mo);
		glColor3f(0.3, 0.3, 0.4);
		//glBegin(GL_POLYGON);			
		glBindTexture(GL_TEXTURE_2D, TextureBack);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X2, 0,My_Ortho.Z2); // 右下
			glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z2); // 左下
			glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X1, My_Ortho.Y2, My_Ortho.Z2); //左上 
			glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X2, My_Ortho.Y2, My_Ortho.Z2); //右上
		glEnd();
	glPopMatrix();
	// Front 
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//glMultMatrixf(mo);
		glColor3f(0.5, 0.5, 0.4);
		//glBegin(GL_POLYGON);			
		glBindTexture(GL_TEXTURE_2D, TextureFront);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X2, 0,My_Ortho.Z1); // 右下
			glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z1); // 左下
			glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X1, My_Ortho.Y2, My_Ortho.Z1); //左上 
			glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X2, My_Ortho.Y2, My_Ortho.Z1); //右上 
		glEnd();
	glPopMatrix();
	// Left
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//glMultMatrixf(mo);
		glColor3f(0.5, 0.7, 0.4);
		//glBegin(GL_POLYGON);			
		glBindTexture(GL_TEXTURE_2D, TextureLeft);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X1, 0,My_Ortho.Z2); // 右下
			glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z1); // 左下
			glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X1, My_Ortho.Y2, My_Ortho.Z1); //左上 
			glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X1, My_Ortho.Y2, My_Ortho.Z2); //右上 
		glEnd();
	glPopMatrix();
	// Right
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//glMultMatrixf(mo);
		glColor3f(0.8, 0.7, 0.4);
		//glBegin(GL_POLYGON);			
		glBindTexture(GL_TEXTURE_2D, TextureRight);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X2, 0,My_Ortho.Z1); // 右下
			glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X2, 0, My_Ortho.Z2); // 左下
			glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X2, My_Ortho.Y2, My_Ortho.Z2); //左上 
			glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X2, My_Ortho.Y2, My_Ortho.Z1); //右上 
		glEnd();
	glPopMatrix();
}

void DrawVitality(void) {
	//glLoadIdentity();
	/*gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);
		glRasterPos3f(-7, 6, 0);
		drawString(string1);
	glPopMatrix();
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);
		glRasterPos3f(-4, 5, 0);
		drawString(string2);
	glPopMatrix();*/
	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		MovePosition(-308, -231, 0);
		glBindTexture(GL_TEXTURE_2D, id_texture2);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(0, 0, 0); //--
			glTexCoord2f(1.0, 0.0);glVertex3f(2.5, 0, 0); //+-
			glTexCoord2f(1.0, 1.0);glVertex3f(2.5, 2.5, 0); //++ 
			glTexCoord2f(0.0, 1.0);glVertex3f(0, 2.5, 0); //-+ 
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glColor3f(1.0f, 1.0f, 0.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		MovePosition(-208, -231, 0);
		glBindTexture(GL_TEXTURE_2D, id_texture4);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(0, 0, 0); //--
			glTexCoord2f(1.0, 0.0);glVertex3f(2.5, 0, 0); //+-
			glTexCoord2f(1.0, 1.0);glVertex3f(2.5, 2.5, 0); //++ 
			glTexCoord2f(0.0, 1.0);glVertex3f(0, 2.5, 0); //-+ 
		glEnd();
	glPopMatrix();


}



void DrawHouse_0(void) {
	glColor3f(1.0f, 1.0f, 1.0f);
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	DrawCubeI(4, 4, 4);
}
void DrawTree_0(void) {
	glColor3f(0.0f, 1.0f, 0.0f);
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	DrawCubeI(10, 15, 10);
}
void DrawSide_0(void) {
	glColor3f(1.0f, 0.0f, 1.0f);
	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
	DrawCubeI(1, 5, 1);
}

void DrawFixObj(void) {
		//glPushMatrix();
		//	glColor3f(0.0f, 1.0f, 0.0f);
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	MovePosition(0, 0, 0);
		//	glGetFloatv(GL_MODELVIEW_MATRIX, ObjA.org_m);
		//	ObjA.m[0] = ObjA.org_m[12];
		//	ObjA.m[1] = ObjA.org_m[13];
		//	ObjA.m[2] = ObjA.org_m[14];
		//	//printf(" m[0] = %f , m[1] = %f , m[2] = %f \r\n" , ObjA.m[0], ObjA.m[1], ObjA.m[2]);
		//	DrawCubeTexture(1,1,1,id_texture3);
		//glPopMatrix();

		//glPushMatrix();
		//	glColor3f(1.0f, 0.0f, 0.0f);
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	MovePosition(-100, 0, -50);
		//	glGetFloatv(GL_MODELVIEW_MATRIX, ObjB.org_m);
		//	ObjB.m[0] = ObjB.org_m[12];
		//	ObjB.m[1] = ObjB.org_m[13];
		//	ObjB.m[2] = ObjB.org_m[14];
		//	//printf(" m[0] = %f , m[1] = %f , m[2] = %f \r\n", ObjB.m[0], ObjB.m[1], ObjB.m[2]);
		//	DrawCubeTexture(1,1,1,id_texture3);
		//glPopMatrix();

		//// 畫房子 1
		//glPushMatrix();
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	glColor3f(1.0, 0.0, 0.0);
		//	MovePosition(80, 0, 0);
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
		//// 畫房子 2
		//glPushMatrix();
		//	gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//	glColor3f(0.0, 0.0, 1.0);
		//	MovePosition(120, 10, 0);
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
}

void DrawObjHouse1(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture) {
	// 畫房子 1
	glPushMatrix();
		//glColor3f(0.0f, 1.0f, 0.0f);
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
			MovePosition(MoveX, MoveY, MoveZ);
		glGetFloatv(GL_MODELVIEW_MATRIX, obj->org_m);
		//printf("H1 m[12] = %f , m[13] = %f , m[14] = %f \r\n" , obj->org_m[12], obj->org_m[13], obj->org_m[14]);			
		DrawCubeTexture(1.0, 1.0, 1.0, texture);
			MovePosition(0, MoveY + 10, 0);
			DrawRoof(0.5, 0.5, 0.5, TextureRoof);
				MovePosition(0, MoveY - 10, 0);
				DrawDoor(0.5, 0.5, 0.5, 0.2, 0.3, TextureDoor);
					MovePosition(0, MoveY - 5, 0);
					DrawWindows(0.5, 0.5, 0.5, 0.2, 0.3, 0.3, 0.3, TextureWindows);
	glPopMatrix();
}
void DrawObjHouse2(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture) {
	// 畫房子 2
	glPushMatrix();
		//glColor3f(0.0f, 1.0f, 0.0f);
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
			MovePosition(MoveX, MoveY + 10 , MoveZ);
		glGetFloatv(GL_MODELVIEW_MATRIX, obj->org_m);
		//printf("H2 m[12] = %f , m[13] = %f , m[14] = %f \r\n" , obj->org_m[12], obj->org_m[13], obj->org_m[14]);			
		DrawCubeTexture(1.0, 2.0, 1.0, texture);
			
			MovePosition(0, MoveY + 20, 0);
			DrawRoof(0.5, 0.5, 0.5, TextureRoof);
				MovePosition(0, MoveY - 30, 0);
				DrawDoor(0.5, 0.5, 0.5, 0.2, 0.3, TextureDoor);
					MovePosition(0, MoveY - 5, 0);
					DrawWindows(0.5, 0.5, 0.5, 0.2, 0.3, 0.3, 0.3, TextureWindows);
	glPopMatrix();
}
void DrawObjCube05(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture) {
	glPushMatrix();
		//glColor3f(0.0f, 1.0f, 0.0f);
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(MoveX, MoveY, MoveZ);
		glGetFloatv(GL_MODELVIEW_MATRIX, obj->org_m);
		//printf(" m[12] = %f , m[13] = %f , m[14] = %f \r\n" , obj->org_m[12], obj->org_m[13], obj->org_m[14]);
		DrawCubeTexture(0.5, 0.5, 0.5, texture);
	glPopMatrix();
}

void DrawObjCube10(ObjBox* obj,float MoveX, float MoveY, float MoveZ,int texture) {
	glPushMatrix();
		//glColor3f(0.0f, 1.0f, 0.0f);
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(MoveX, MoveY, MoveZ);
		glGetFloatv(GL_MODELVIEW_MATRIX, obj->org_m);
		//printf(" m[12] = %f , m[13] = %f , m[14] = %f \r\n" , obj->org_m[12], obj->org_m[13], obj->org_m[14]);
		DrawCubeTexture(1,1,1,texture);
	glPopMatrix();
}

void DrawObjTree(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture) {
	// Tree Object
	glPushMatrix();
		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		MovePosition(MoveX, MoveY +20, MoveZ);
		glGetFloatv(GL_MODELVIEW_MATRIX, obj->org_m);
		//printf(" m[12] = %f , m[13] = %f , m[14] = %f \r\n" , obj->org_m[12], obj->org_m[13], obj->org_m[14]);
		DrawCubeTexture(0.5,2.5,0.5, TextureTreeBody);
		MovePosition(0, MoveY + 10, 0);
		DrawTriangleTexture(2,3,2, TextureTreeLeaf);
	glPopMatrix();
}


void checkTouch(ObjBox *obj) {
	float Px = 0.0;
	float Pz = 0.0;
	float Py = 0.0;
	bool BoundPy = false;
	bool BoundPx = false;
	bool BoundPz = false;
	Py = obj->org_m[12];
	Px = obj->org_m[13];
	Pz = obj->org_m[14];
	BoundPy = (Py < BoundPyU) && (BoundPyD < Py);
	BoundPx = (Px < BoundPxU) && (BoundPxD < Px);
	BoundPz = (Pz < BoundPzU) && (BoundPzD < Pz);
	obj->flag = BoundPx && BoundPy && BoundPz;
	printf(" Px = %f , ", Px);
	printf(" Py = %f , ", Py);	
	printf(" Pz = %f \r\n", Pz);
	printf(" BoundPx = %d , ", BoundPx);
	printf(" BoundPy = %d , ", BoundPy);	
	printf(" BoundPz = %d , ", BoundPz);
}

void checkTouch2(ObjBox *obj,float xU, float yU, float zU, float xD, float yD, float zD) {
	float Px = 0.0;
	float Pz = 0.0;
	float Py = 0.0;
	bool BoundPy = false;
	bool BoundPx = false;
	bool BoundPz = false;
	Py = obj->org_m[12];
	Px = obj->org_m[13];
	Pz = obj->org_m[14];
	BoundPy = (Py < yU) && (yD < Py);
	BoundPx = (Px < xU) && (xD < Px);
	BoundPz = (Pz < zU) && (zD < Pz);
	obj->flag = BoundPx && BoundPy && BoundPz;
	printf(" 2Py = %f , ", Py);
	printf(" 2Px = %f , ", Px);
	printf(" 2Pz = %f \r\n", Pz);
	printf(" BoundPy = %d , ", BoundPy);
	printf(" BoundPx = %d , ", BoundPx);
	printf(" BoundPz = %d \r\n", BoundPz);
}

void checkTouch3(ObjBox *obj, float m0U, float m0D , float m1U, float m1D, float m2U, float m2D) {
	float m0 = 0.0;
	float m1 = 0.0;
	float m2 = 0.0;
	bool Boundm0 = false;
	bool Boundm1 = false;
	bool Boundm2 = false;
	m0 = obj->org_m[12];
	m1 = obj->org_m[13];
	m2 = obj->org_m[14];
	Boundm0 = (m0 < m0U) && (m0D < m0);
	Boundm1 = (m1 < m1U) && (m1D < m1);
	Boundm2 = (m2 < m2U) && (m2D < m2);
	obj->flag = Boundm1 && Boundm0 && Boundm2;
	printf(" 2m0 = %f , ", m0);
	printf(" 2m1 = %f , ", m1);
	printf(" 2m2 = %f \r\n", m2);
	printf(" Boundm0 = %d , ", Boundm0);
	printf(" Boundm1 = %d , ", Boundm1);
	printf(" Boundm2 = %d \r\n", Boundm2);
}

ObjBox* FindLastNode(ObjBox *obj) {
	if (obj->NextObjLink == NULL) return obj;
	if (obj->NextObjLink != NULL)
		return FindLastNode(obj->NextObjLink);
}

ObjBox* CreateObjNode(ObjBox *obj) {
	obj = (ObjBox *)malloc(sizeof(ObjBox));
	printf("sizeof(ObjBox *) = %d byte \r\n",sizeof(ObjBox *));
	printf("sizeof(ObjBox) = %d byte \r\n", sizeof(ObjBox));
	obj->Pos[0] = 200;obj->Pos[1] = 0;obj->Pos[2] = -100;
	obj->MappingPos = NULL;
	obj->DetectTouch = CheckTouch;
	obj->DrawObj = DrawObjHouse1;
	obj->Boundary = &House1_B;
	obj->PreObjLink = FindLastNode(&MyHouse);
	obj->PreObjLink->NextObjLink = obj;
	obj->NextObjLink = NULL;
	obj->texture = 0;;
	return obj;
}

void DeleteNode(ObjBox *obj) {
	if (obj == NULL) return;
	if ((obj->PreObjLink != NULL) && (obj->NextObjLink != NULL)) {
		obj->PreObjLink->NextObjLink = obj->NextObjLink;
		obj->NextObjLink->PreObjLink = obj->PreObjLink;
		obj->hint = false;
		/*obj->PreObjLink = FindLastNode(obj);
		obj->PreObjLink->NextObjLink = obj;		
		obj->NextObjLink = NULL;
		obj->Pos[0] = rand()%500;
		obj->Pos[1] = 0;
		obj->Pos[2] = rand()%(rand() % (500+1)+1);
		obj->MappingPos = NULL;*/
	}
}

void CheckTouch(ObjBox *obj, ObjectBoundary *obj_B) {
	float m0 = 0.0;
	float m1 = 0.0;
	float m2 = 0.0;
	bool Boundm0 = false;
	bool Boundm1 = false;
	bool Boundm2 = false;
	m0 = obj->org_m[12];
	m1 = obj->org_m[13];
	m2 = obj->org_m[14];
	Boundm0 = (m0 < obj_B->m0_U) && (obj_B->m0_D < m0);
	Boundm1 = (m1 < obj_B->m1_U) && (obj_B->m1_D < m1);
	Boundm2 = (m2 < obj_B->m2_U) && (obj_B->m2_D < m2);
	obj->flag = Boundm1 && Boundm0 && Boundm2;
	/*printf(" 2m0 = %f , ", m0);
	printf(" 2m1 = %f , ", m1);
	printf(" 2m2 = %f \r\n", m2);
	printf(" Boundm0 = %d , ", Boundm0);
	printf(" Boundm1 = %d , ", Boundm1);
	printf(" Boundm2 = %d \r\n", Boundm2);*/
}


bool CheckObjTouchFlow(ObjBox *obj) {
	if (obj == NULL) return false;
	bool BigFlag = false;
	if ((obj->DetectTouch != NULL)&&(obj->Boundary != NULL) )
		obj->DetectTouch(obj,obj->Boundary);
	if (obj->NextObjLink != NULL) {		
		BigFlag = obj->flag || CheckObjTouchFlow(obj->NextObjLink);
		//printf("BigFlag = %d \r\n", BigFlag);
		return BigFlag;
	}
	else {
		if (obj->DetectTouch != NULL) 
			return obj->flag;
	}
}

void CheckObjFlagFlow(ObjBox *obj ) {
	if (obj == NULL) return;	
	if (obj->flag) 
		obj->hint = true;
	if (obj->NextObjLink != NULL) 
		CheckObjFlagFlow(obj->NextObjLink);

}

void DrawObjFlow(ObjBox *obj) {
	if (obj == NULL) return;	
	if (obj->DrawObj != NULL) {
		glColor3f(1.0f, 1.0f, 1.0f);
		if(obj->MappingPos == NULL)
			obj->DrawObj(obj, obj->Pos[0], obj->Pos[1], obj->Pos[2], obj->texture);
		else
			obj->DrawObj(obj, obj->MappingPos[0], obj->MappingPos[1], obj->MappingPos[2], obj->texture);
	}
	if (obj->NextObjLink != NULL)
		DrawObjFlow(obj->NextObjLink);
}
void DrawCenterLine(void) {
	glPushMatrix();
		glColor3f(0.0f, 0.0f, 0.0f);
		gluLookAt(0, 0, 20, 0, 0, 0, 0, 1, 0);
		// h
		glBegin(GL_POLYGON);
			glVertex3f(-1, 0, 1); //--
			glVertex3f(1, 0, 1); //--
			glVertex3f(1, 0.1, 1); //--
			glVertex3f(-1, 0.1, 1); //--
		glEnd();
		// v
		glBegin(GL_POLYGON);
			glVertex3f(0, -1, 1); //--
			glVertex3f(0, 1, 1); //--
			glVertex3f(0.1, 1, 1); //--
			glVertex3f(0.1, -1, 1); //--
		glEnd();
	glPopMatrix();
}
float f_abs(float x, float y) {
	float temp = 0.0;
	if (x > y)
		temp = x - y;
	else
		temp = y - x;
	return temp;
}
// w
void CameraForward(void) {
	My_LookAt.X = My_LookAt.X + PosXUnit;
	My_LookAt.Watch_X = My_LookAt.Watch_X + PosXUnit;
	My_LookAt.Z = My_LookAt.Z + PosZUnit;
	My_LookAt.Watch_Z = My_LookAt.Watch_Z + PosZUnit;
}
void CameraBackward(void) {
	My_LookAt.X = My_LookAt.X - PosXUnit;
	My_LookAt.Watch_X = My_LookAt.Watch_X - PosXUnit;
	My_LookAt.Z = My_LookAt.Z - PosZUnit;
	My_LookAt.Watch_Z = My_LookAt.Watch_Z - PosZUnit;
}
void CameraLeftward(void) {
	My_LookAt.X = My_LookAt.X + PosZUnit;
	My_LookAt.Watch_X = My_LookAt.Watch_X + PosZUnit;
	My_LookAt.Z = My_LookAt.Z - PosXUnit;
	My_LookAt.Watch_Z = My_LookAt.Watch_Z - PosXUnit;
}
void CameraRightward(void) {
	My_LookAt.X = My_LookAt.X - PosZUnit;
	My_LookAt.Watch_X = My_LookAt.Watch_X - PosZUnit;
	My_LookAt.Z = My_LookAt.Z + PosXUnit;
	My_LookAt.Watch_Z = My_LookAt.Watch_Z + PosXUnit;
}
void CalculateARC(float theta) {
	float h = My_LookAt.X;	// 0
	float k = My_LookAt.Z;	// 3.5
	float h1 = My_LookAt.X;	// 0
	float k1 = My_LookAt.Z - 1;	// 3.5

	float p = 1;
	float r = 3.5;
	float tempX = 0.0;
	float tempZ = 0.0;
	//r = r / p;	
	My_LookAt.Watch_Z = k + r*cos(theta*0.017445);
	My_LookAt.Watch_X = h + r*sin(theta*0.017445);
	
	#if DebugMode == 1
		tempZ = 0 + p*cos(theta*0.017445);
		tempX = 0 + p*sin(theta*0.017445);
		printf("plane Y-axis tempX = %f  \r\n", tempX);
		printf("plane X-axis tempZ = %f  \r\n", tempZ);
	#else
		PosZUnit = 0 + p*cos(theta*0.017445)*0.1;
		PosXUnit = 0 + p*sin(theta*0.017445)*0.1;
		printf(" PosXUnit = %f  \r\n", PosXUnit);
		printf(" PosZUnit = %f  \r\n", PosZUnit);
	#endif
	
	printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
	printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
	//DrawCubeI(0.1,0.1,0.1);
}