/////////////////////////
// glutTest13.cpp
//
// Created by Gary Ho, ma_hty@hotmail.com, 2007
//
/*
配合 滑鼠 和 Axis-Angle 來作 旋轉介面 是最有效的方案, 但是 每一次當我向網友們推薦它時, 網友們總是因為它的概念比較複雜而對它 敬而遠之. 或許, Axis-Angle 的概念真的是比較複雜, 可是, 程式編寫起來倒是蠻簡潔的, 承接著上一個教學的 按鍵旋轉介面, 這一個教學, 就讓我介紹一下 如何利用 Axis-Angle 來編寫
滑鼠旋轉介面.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/glut.h>

#define PI 3.14159265358979323846f

float v0[3], v1[3];
float mo[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };

float clamp( float x, float a, float b );
float dot( const float *a, const float *b );
float norm( const float *a );
void vassign( float *a, float x, float y, float z );
void vassign( float *a, const float *b );
void cross( float *a, const float *b, const float *c );
void normalize( float *a );

void display();
void mousebutton(int button, int state, int x, int y );
void mousemove(int x, int y);


void main( int argc, char **argv )
{
  glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
  glutInitWindowSize( 512, 512 );

  glutCreateWindow( "test09" );
  glutDisplayFunc( display );

  glutMouseFunc( mousebutton );
  glutMotionFunc( mousemove );

  glutMainLoop();
}

void display()
{
  GLint viewport[4];
    glGetIntegerv( GL_VIEWPORT, viewport );

  glEnable( GL_DEPTH_TEST );
  glEnable( GL_LIGHTING );
  glEnable( GL_LIGHT0 );

  glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

  glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 45, double(viewport[2])/viewport[3], 0.1, 10 );
  
  glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0,0,3, 0,0,0, 0,1,0 );
    glMultMatrixf( mo );

    glutSolidTeapot(1);

  glutSwapBuffers();
}

void mousebutton(int button, int state, int x, int y )
{
  vassign( v0, 2.0*x/512-1, -2.0*y/512+1, 1 );
  normalize(v0);
}

void mousemove(int x, int y)
{
  float axis[3], angle;

  vassign( v1, 2.0*x/512-1, -2.0*y/512+1, 1 );
  normalize(v1);
  if( dot(v0,v1)>.999 )
    return;
  cross(axis,v0,v1);
  normalize(axis);
  angle = acosf( clamp(dot(v0,v1),-1,1) );
  vassign( v0, v1 );

  glPushMatrix();
    glLoadIdentity();
    glRotatef( angle*180/PI, axis[0], axis[1], axis[2] );
    glMultMatrixf( mo );
    glGetFloatv( GL_MODELVIEW_MATRIX, mo );
  glPopMatrix();
  glutPostRedisplay();
}


float clamp( float x, float a, float b ){ return x<a ? a : (x<b?x:b); }
float dot( const float *a, const float *b ){ return a[0]*b[0]+a[1]*b[1]+a[2]*b[2]; }
float norm( const float *a ){ return sqrtf(dot(a,a)); }
void vassign( float *a, float x, float y, float z ){ a[0]=x; a[1]=y; a[2]=z; }
void vassign( float *a, const float *b ){ a[0]=b[0]; a[1]=b[1]; a[2]=b[2]; }

void cross( float *a, const float *b, const float *c )
{
  a[0] = b[1]*c[2] - c[1]*b[2];
  a[1] = -b[0]*c[2] + c[0]*b[2];
  a[2] = b[0]*c[1] - c[0]*b[1];
}

void normalize( float *a )
{
  float l = norm(a);
  a[0]/=l; a[1]/=l; a[2]/=l;
}