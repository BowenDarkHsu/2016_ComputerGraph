#include "stdafx.h"
#include "House.h"
void DrawHouse(float Length, float Height, float Width){
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
}