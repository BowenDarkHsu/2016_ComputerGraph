#ifndef RobotParameter_h
#define RobotParameter_h

class RobotParameter {
	public:
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

		float Link3_Height = 0.1;	// 可變動
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



#endif