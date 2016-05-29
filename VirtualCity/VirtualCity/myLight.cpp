#include "stdafx.h"
#include "myLight.h"
void InitLight_Ambient(glLight_Parameter Svalue) {
	Svalue.Ambient.Red = Init_Light_Ambient_Red;
	Svalue.Ambient.Green = Init_Light_Ambient_Green;
	Svalue.Ambient.Blue = Init_Light_Ambient_Blue;
	Svalue.Position.X = Init_Light_Position_X;
	Svalue.Position.Y = Init_Light_Position_Y;
	Svalue.Position.Z = Init_Light_Position_Z;
	SetupLight_Parameter(GL_LIGHT3,Svalue,true);
}
void SetupLight_Parameter(int source, glLight_Parameter Svalue,bool IsPoint){
	if (IsPoint) {
		GLfloat aValue[4] = { Svalue.Ambient.Red,Svalue.Ambient.Green,Svalue.Ambient.Blue ,1.0 };
		GLfloat dValue[4] = { Svalue.Diffuse.Red,Svalue.Diffuse.Green,Svalue.Diffuse.Blue ,1.0 };
		GLfloat sValue[4] = { Svalue.Specular.Red,Svalue.Specular.Green,Svalue.Specular.Blue ,1.0 };
		GLfloat pValue[4] = { Svalue.Position.X,Svalue.Position.Y,Svalue.Position.Z ,1.0 };
		glShadeModel(GL_SMOOTH);
		glLightfv(source, GL_AMBIENT, aValue);
		glLightfv(source, GL_DIFFUSE, dValue);
		glLightfv(source, GL_SPECULAR, sValue);
		glLightfv(source, GL_POSITION, pValue);
		glEnable(GL_LIGHTING);
		glEnable(source);
		glEnable(GL_DEPTH_TEST);
	}
	else {
		GLfloat aValue[4] = { Svalue.Ambient.Red,Svalue.Ambient.Green,Svalue.Ambient.Blue ,0.0 };
		GLfloat dValue[4] = { Svalue.Diffuse.Red,Svalue.Diffuse.Green,Svalue.Diffuse.Blue ,0.0 };
		GLfloat sValue[4] = { Svalue.Specular.Red,Svalue.Specular.Green,Svalue.Specular.Blue ,0.0 };
		GLfloat pValue[4] = { Svalue.Position.X,Svalue.Position.Y,Svalue.Position.Z ,0.0 };
		glShadeModel(GL_SMOOTH);
		glLightfv(source, GL_AMBIENT, aValue);
		glLightfv(source, GL_DIFFUSE, dValue);
		glLightfv(source, GL_SPECULAR, sValue);
		glLightfv(source, GL_POSITION, pValue);
		glEnable(GL_LIGHTING);
		glEnable(source);
		glEnable(GL_DEPTH_TEST);
	}

	
}
void LightSource(void) {
	/* preprocesing define variable */
	GLfloat mat_spec[] = { 1,1,1,1.0 };
	GLfloat mat_shine[] = { 50.0 };
	GLfloat light_ambient[] = { 0.0,0.0,0.0,1.0 };
	GLfloat light_diffuse[] = { 1,1,1,1.0 };
	GLfloat light_specular[] = { 1,1,1.0,1.0 };
	GLfloat light_position[] = { 1.0,0.0,0.0,0.0 };
	/* Step2 Create Light Source , Select model , decide position */
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void LightSource2(void) {
	/* preprocesing define variable */
	GLfloat mat_spec[] = { 1,0.2,1,1.0 };
	GLfloat mat_shine[] = { 100.0 };
	GLfloat light_ambient[] = { 1.0,1.0,0.0,1.0 };
	GLfloat light_diffuse[] = { 1,0.0,0,1.0 };
	GLfloat light_specular[] = { 1,0,0,1.0 };
	GLfloat light_position[] = { 1.0,2.0,1.0,1.0 };
	/* Step2 Create Light Source , Select model , decide position */
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);
}
void LightSource3(void) {
	/* preprocesing define variable */
	GLfloat mat_spec[] = { 3,0.2,1,1.0 };
	GLfloat mat_shine[] = { 80.0 };
	GLfloat light_ambient[] = { 4.0,1.0,-1.5,1.0 };
	GLfloat light_diffuse[] = { 4,2,1,1.0 };
	GLfloat light_specular[] = { 4,2,1,1.0 };
	GLfloat light_position[] = { 3.0,3.0,3.0,1.0 };
	/* Step2 Create Light Source , Select model , decide position */
	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shine);


	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT2);
	glEnable(GL_DEPTH_TEST);
}
GLfloat IsPoint(bool p) {
	if(p)
		return 1.0;
	else
		return 0.0;
}
