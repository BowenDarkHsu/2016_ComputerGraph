#ifndef Robot_Arm_h
#define Robot_Arm_h

#include "glut.h"
#include "RobotArmPosition.h"
#include "glOrtho_Parameter.h"
#include "RobotParameter.h"

class Robot_Arm
{
	public:
		Robot_Arm;
		void* DrawPosition(void);
		void* X_DirectionMenuFunc(int id);
		void* Y_DirectionMenuFunc(int id);
		void* ArmRotationMenuFunc(int id);
		void* GripperHeightMenuFunc(int id);
		void* GripperControlMenuFunc(int id);
		void* DrawRobotArm(void);
		void* DrawCube(float Length, float Height, float Width);
	private:

};

extern 	RobotParameter myRobotParameter;
extern 	RobotArmPosition Robot_Position;			
extern 	glOrtho_Parameter My_Ortho;
extern 	RobotParameter Robot_Initial;



#endif