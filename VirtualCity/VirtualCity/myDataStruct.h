#ifndef __MYDATASTRUCT_H
#define __MYDATASTRUCT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
/* __ Data Structure */
/* End of __ Data Structure */

/* Original Data Struct */
typedef struct glLookAt_Parameter {
	/*float X = 0.1;
	float Y = -0.2;
	float Z = 0.3;*/
	float X = 0;
	float Y = 1.5;
	float Z = 3.5;
	float Watch_X = 0.0;
	float Watch_Y = 0.0;
	float Watch_Z = 0.0;
	float Forward_X = 0.0;
	float Forward_Y = 1.0;
	float Forward_Z = 0.0;
};
typedef struct glOrtho_Parameter {
	float X1 = -20;
	float X2 = 20;
	float Y1 = -20;
	float Y2 = 20;
	float Z1 = -20;
	float Z2 = 20;
	float Value = 20;
};
/* End of Original Data Struct */

/* Light Source Data Struct */
typedef struct Ambient_Parameter {
	GLfloat Red = 0.0;
	GLfloat Green = 0.0;
	GLfloat Blue = 0.0;
	GLfloat IsPoint(bool p);
};
typedef struct Diffuse_Parameter {
	GLfloat Red = 1.0;
	GLfloat Green = 1.0;
	GLfloat Blue = 1.0;
	GLfloat IsPoint(bool p);
};
typedef struct Specular_Parameter {
	GLfloat Red = 1.0;
	GLfloat Green = 1.0;
	GLfloat Blue = 1.0;
	GLfloat IsPoint(bool p);
};
typedef struct Position_Parameter {
	GLfloat X = 0.0;
	GLfloat Y = 0.0;
	GLfloat Z = 0.0;
	GLfloat IsPoint(bool p);
};
typedef struct glLight_Parameter {
	Ambient_Parameter Ambient;
	Diffuse_Parameter Diffuse;
	Specular_Parameter Specular;
	Position_Parameter Position;
};
typedef struct glMaterial_Parameter {
	Ambient_Parameter Ambient;
	Diffuse_Parameter Diffuse;
	Specular_Parameter Specular;
	GLfloat Shininess;
};
/* End of Light Source Data Struct */

/* Object Data Structure */
typedef struct TreeNode{
	GLfloat m[16];
	void (*f)();
	struct TreeNode* Child;
	struct TreeNode* Sibling;
}TreeNode;

typedef struct HumanObject {
	TreeNode Torso;
	TreeNode Head;
	TreeNode LeftUpperArm;
	TreeNode LeftLowerArm;
	TreeNode RightUpperArm;
	TreeNode RightLowerArm;
	TreeNode LeftUpperLeg;
	TreeNode LeftLowerLeg;
	TreeNode RightUpperLeg;
	TreeNode RightLowerLeg;
}HumanObject;

extern float MoveX;
extern float MoveY;
extern float MoveZ;

extern HumanObject MajorRole;
/* End of Object Data Structure */

extern glOrtho_Parameter My_Ortho;
extern glLookAt_Parameter My_LookAt;
extern glLookAt_Parameter Initial_LookAt;

/* Light Source Data Struct */
extern glLight_Parameter mySource_1;
extern glMaterial_Parameter myMaterial_1;
/* End of Light Source Data Struct */
#ifdef __cplusplus
}
#endif
#endif