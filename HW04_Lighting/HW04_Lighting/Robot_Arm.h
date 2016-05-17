#ifndef __ROBOT_ARM_H
#define __ROBOT_ARM_H
#ifdef __cplusplus
extern "C" {
#endif
#include "glut.h"

typedef struct glOrtho_Parameter {
	float X1 = -5;
	float X2 = 5;
	float Y1 = -5;
	float Y2 = 5;
	float Z1 = -5;
	float Z2 = 5;
	float Value = 5;
};

typedef struct RobotParameter {
	float Base_X = 0;
	float Base_Y = 0;
	float BaseHeight = 0.4;
	float BaseWidth = 0.4;
	float BaseLength = 0.4;

	float Link1_Height = 0.6;
	float Link1_Width = 0.2;
	float Link1_Length = 0.2;
	float Link1_theta = 0;

	float Link2_Height = 0.2;
	float Link2_Width = 0.2;
	float Link2_Length = 1.0;

	float Cube1_Height = 0.2;
	float Cube1_Width = 0.2;
	float Cube1_Length = 0.2;

	float Link3_Height = 0.1;	// ?¯è???
	float Link3_Width = 0.1;
	float Link3_Length = 0.1;

	float Link4_Height = 0.1;
	float Link4_Width = 0.1;
	float Link4_Length = 0.6;

	float Link5_Height = 0.2;
	float Link5_Width = 0.1;
	float Link5_Length = 0.1;

	float Link6_Height = 0.2;
	float Link6_Width = 0.1;
	float Link6_Length = 0.1;

	float GripperWidth = 0.1;

};

typedef struct RobotArmPosition {
	float Link1_RP_Y1;
	float Link1_DP_Y2;
	float Link2_DP_X1;
	float Link2_DP_Y1;
	float Cube1_DP_X1;
	float Cube1_DP_Y1;
	float Link4_DP_Y1;

	float Base_DP_X1;
	float Base_DP_Y1;
	float Link3_DP_Y1;
	float Link5_DP_X1;
	float Link5_DP_Y1;
	float Link6_DP_X1;
	float Link6_DP_Y1;

};
extern RobotParameter Robot_Arm;
extern RobotParameter Robot_Initial;
extern glOrtho_Parameter My_Ortho;
extern RobotArmPosition Robot_Position;

void DrawPosition(void);
void DrawRobotArm(void);
void DrawCube(float Length, float Height, float Width);

void X_DirectionMenuFunc(int id);
void Y_DirectionMenuFunc(int id);
void ArmRotationMenuFunc(int id);
void GripperHeightMenuFunc(int id);
void GripperControlMenuFunc(int id);
#ifdef __cplusplus
}
#endif
#endif