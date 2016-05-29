#include "stdafx.h"
#include "DrawFunctions.h"

void MovePosition(float x , float y , float z) {
	glTranslated((x / My_Ortho.Value), (y / My_Ortho.Value), (z / My_Ortho.Value));
}

void DrawHouse(float Length, float Height, float Width, float door_L, float door_H, float Windows_L, float Windows_H) {
	DrawCubeF(Length, Height, Width);

	DrawDoor(Length, Height, Width, door_L, door_H);

	DrawWindows(Length, Height, Width, door_L, door_H, Windows_L, Windows_H);

	MovePosition(0, Height, 0);
	DrawRoof(Length, Height, Width);
}
void DrawRoof (float Length, float Height, float Width) {
	//glBegin(GL_LINE_LOOP);
	GLfloat DrawRange[5][3] = {
		{ Length,0,Width },{ -Length,0,Width },{ -Length,0,-Width },{ Length,0,-Width },{ Length,0,Width }	// 5
	};

	GLfloat DrawPoint[3] = { 0.0,0.0,0.0 };

	GLfloat Draw_Triangle[12][3] = {
		{ Length , 0 , Width } ,{ -Length , 0 , Width } ,{ ((-Length) / 4 / My_Ortho.Value) , Height , ((-Width) / 2 / My_Ortho.Value) } , // ABM
		{ Length , 0 , Width } ,{ Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.Value) , Height , ((-Width) / 2 / My_Ortho.Value) } , // ADM
		{ -Length , 0 , Width } ,{ -Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.Value) , Height , ((-Width) / 2 / My_Ortho.Value) } , // BCM
		{ -Length , 0 , -Width } ,{ Length , 0 , -Width } ,{ ((-Length) / 4 / My_Ortho.Value) , Height , ((-Width) / 2 / My_Ortho.Value) } , // CDM
	};

	GLfloat Draw_A[3] = { Length , 0 , Width };
	GLfloat Draw_B[3] = { -Length , 0 , Width };
	GLfloat Draw_C[3] = { -Length , 0 , -Width };
	GLfloat Draw_D[3] = { Length , 0 , -Width };
	GLfloat Draw_M[3] = { ((-Length)/4 / My_Ortho.Value) , Height , ((-Width)/2/ My_Ortho.Value) };


	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; i++) {	
		DrawPoint[0] = DrawRange[i][0];
		DrawPoint[1] = DrawRange[i][1];
		DrawPoint[2] = DrawRange[i][2];
		glNormal3fv(DrawPoint);
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
void DrawDoor(float Length, float Height, float Width, float door_L , float door_H) {
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
void DrawWindows(float Length, float Height, float Width, float door_L, float door_H , float W_L , float W_H) {

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
	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; i++) {
		DrawPoint[0] = DrawRange0[i][0];
		DrawPoint[1] = DrawRange0[i][1];
		DrawPoint[2] = DrawRange0[i][2];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 5; i++) {
		DrawPoint[0] = DrawRange1[i][0];
		DrawPoint[1] = DrawRange1[i][1];
		DrawPoint[2] = DrawRange1[i][2];
		glNormal3fv(DrawPoint);
		glVertex3fv(DrawPoint);
	}
	glEnd();
}