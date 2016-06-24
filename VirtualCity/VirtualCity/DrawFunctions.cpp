#include "stdafx.h"
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
	MovePosition(MoveX +0 , MoveY + 0, MoveZ + 0);
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
		glBindTexture(GL_TEXTURE_2D, id_texture);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z1); //--
			glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X2, 0, My_Ortho.Z1); //+-
			glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X2, 0, My_Ortho.Z2); //++ 
			glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z2); //-+ 
		glEnd();
	glPopMatrix();

	glPushMatrix();

		gluLookAt(My_LookAt.X, My_LookAt.Y, My_LookAt.Z, My_LookAt.Watch_X, My_LookAt.Watch_Y, My_LookAt.Watch_Z, My_LookAt.Forward_X, My_LookAt.Forward_Y, My_LookAt.Forward_Z);
		//glMultMatrixf(mo);
		glColor3f(0.3, 0.3, 0.4);
		//glBegin(GL_POLYGON);			
		glBindTexture(GL_TEXTURE_2D, id_texture);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);glVertex3f(My_Ortho.X1, My_Ortho.Y2, My_Ortho.Z2); //--
		glTexCoord2f(1.0, 0.0);glVertex3f(My_Ortho.X2, My_Ortho.Y2, My_Ortho.Z2); //+-
		glTexCoord2f(1.0, 1.0);glVertex3f(My_Ortho.X2, 0, My_Ortho.Z2); //++ 
		glTexCoord2f(0.0, 1.0);glVertex3f(My_Ortho.X1, 0, My_Ortho.Z2); //-+ 
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
		gluLookAt(0, 0.1, 6, 0, 0, 2.6, 0, 1, 0);
		MovePosition(-150, 100, 0);
		glBindTexture(GL_TEXTURE_2D, id_texture2);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);glVertex3f(0, 0, 0); //--
			glTexCoord2f(1.0, 0.0);glVertex3f(0.8, 0, 0); //+-
			glTexCoord2f(1.0, 1.0);glVertex3f(0.8, 0.8, 0); //++ 
			glTexCoord2f(0.0, 1.0);glVertex3f(0, 0.8, 0); //-+ 
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