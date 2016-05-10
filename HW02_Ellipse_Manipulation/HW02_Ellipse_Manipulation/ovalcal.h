
#define __ovalcal_h__

#include "stdafx.h"
#include <iostream>
#include <math.h>
/* OpenGL library */
#include "glut.h"

/*
pi = 3.1415926
1 degree = 2*pi/360 = 0.017445 radian
*/
#define degree 0.017445

/*
Function Define
*/

extern void DrawVertialOval(double h, double a, double k, double b);
extern void DrawHorizontalOval(double h, double a, double k, double b);
extern double OvalCal_X(double h, double a, double t);
extern double OvalCal_Y(double k, double b, double t);
