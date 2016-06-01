#ifndef GL_FUNCTIONS_H
#define GL_FUNCTIONS_H

#define PI 3.14159265358979323846f

void drawString(const char* str);
void display();

void vassign(float *a, float x, float y, float z);
void vassign(float *a, const float *b);
void cross(float *a, const float *b, const float *c);
void normalize(float *a);
void mousebutton(int button, int state, int x, int y);
void mousemove(int x, int y);

extern float v0[3],v1[3];
extern float mo[16];
float clamp(float x, float a, float b);
float dot(const float *a, const float *b);
float norm(const float *a);
#endif