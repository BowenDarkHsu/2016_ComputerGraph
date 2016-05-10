
/* OvalCal library */
#include "glut.h"
#include "ovalcal.h"

void DrawVertialOval(double h, double a, double k, double b) {
	/* define variable X , Y */
	double X = 0.0;
	double Y = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		X = OvalCal_X(h, a, i);
		Y = OvalCal_Y(k, b, i);
		glVertex3f(X, Y, 0.0);
	}
	glEnd();
}/* End of DrawVertialOval */

void DrawHorizontalOval(double h, double a, double k, double b) {
	/* define variable X , Y */
	double X = 0.0;
	double Y = 0.0;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++) {
		X = OvalCal_X(h, a, i);
		Y = OvalCal_Y(k, b, i);
		glVertex3f(X, Y, 0.0);
	}
	glEnd();
}/* End of DrawHorizontalOval */

double OvalCal_X(double h, double a, double t) {
	double x = 0.0;
	x = h + a * cos(t);
	return x;
}/* End of OvalCal_X */
double OvalCal_Y(double k, double b, double t) {
	double y = 0.0;
	y = k + b * sin(t);
	return y;
}/* End of OvalCal_Y */
