#ifndef __MYDATASTRUCT_H
#define __MYDATASTRUCT_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"
/* __ Data Structure */
/* End of __ Data Structure */
#define DisplayInfoAdjWhite 0

/* Original Data Struct */
typedef struct glLookAt_Parameter {
	/*float X = 0.1;
	float Y = -0.2;
	float Z = 0.3;*/
	float X = 0;
	float Y = 0.1;
	float Z = 6.0;
	float Watch_X = 0.0;
	float Watch_Y = 0.0;
	float Watch_Z = 2.6;
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
typedef struct AvoidObject {
	bool F;
	bool B;
	bool R;
	bool L;
}AvoidObject;

typedef struct TreeNode{
	GLfloat m[16];
	void (*f)();
	struct TreeNode* Child;
	struct TreeNode* Sibling;
}TreeNode;



typedef struct ShowObject {
	TreeNode breath;
	TreeNode sleep;
}ShowObject;

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

typedef struct WorldObject {
	HumanObject Hum;
	ShowObject show;
}WorldObject;

typedef struct ObjectBoundary {
	float m0_U = 0.0;
	float m0_D = 0.0;
	float m1_U = 0.0;
	float m1_D = 0.0;
	float m2_U = 0.0;
	float m2_D = 0.0;
}ObjectBoundary;

typedef struct ObjBox {	
	float org_m[16];	
	float *MappingPos = NULL;	
	float Pos[3];
	float m[3];
	
	bool flag = false;
	bool hint = false;
	int texture = 0;
	int Counter = 0;
	void(*DetectTouch)(ObjBox *obj, ObjectBoundary *obj_B);
	void(*DrawObj)(ObjBox* obj, float MoveX, float MoveY, float MoveZ, int texture);
	ObjBox* PreObjLink;
	ObjBox* NextObjLink;
	ObjectBoundary *Boundary;
}ObjBox;
extern int TaskRNum;
extern int TaskRMax;
extern int TaskGNum;
extern int TaskGMax;
extern int TaskBNum;
extern int TaskBMax;
extern char TaskStringR[10];
extern char TaskStringG[10];
extern char TaskStringB[10];
extern char TaskFinish[20];
extern float ObjTaskPosMapping[7][3];
extern float ObjPosMapping[16][3];
extern int LevelCnt;
extern ObjBox MyHouse;
extern ObjBox MyTree_A;
extern ObjBox MyTree_B;
extern ObjectBoundary Tree1_B;
extern ObjectBoundary House1_B;
extern ObjectBoundary House2_B;
extern ObjectBoundary Cube10_B;
extern ObjectBoundary Cube05_B;
extern ObjBox ObjRed_A;
extern ObjBox ObjRed_B;
extern ObjBox ObjRed_C;
extern ObjBox ObjGreen_A;
extern ObjBox ObjGreen_B;
extern ObjBox ObjBlue_A;
extern ObjBox ObjBlue_B;
extern ObjBox ObjTree_A;
extern ObjBox ObjTree_B;
extern ObjBox ObjTree_C;
extern ObjBox ObjTree_D;
extern ObjBox ObjA;
extern ObjBox ObjB;
extern ObjBox ObjC;
extern ObjBox ObjD;
extern ObjBox ObjH1;
extern ObjBox ObjH2;
extern ObjBox ObjH3;
extern ObjBox ObjH4;
extern ObjBox ObjLast;
extern float MoveX;
extern float MoveY;
extern float MoveZ;
extern bool DrawHint;
extern float BoundPxU;
extern float BoundPxD;
extern float BoundPzU;
extern float BoundPzD;
extern float BoundPyU;
extern float BoundPyD;
extern float TempMoveX;
extern float TempMoveY;
extern HumanObject MajorRole;
extern WorldObject MyWorldObject;

extern AvoidObject NPC_Flag;
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