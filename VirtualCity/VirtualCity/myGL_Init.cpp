#include "stdafx.h"
#include "myGL_Init.h"
#include "Robot_Arm.h"
#include "myLight.h"
#include "glFunctions.h"
#include "texture.h"
//#include "3dsloader.h"
void OpenGL_Init(int argc, char** argv) {

	// OpenGL - initializes GLUT and should be called before any other GLUT routine.
	glutInit(&argc, (char **)argv);

	// OpenGL - specifies the color model (RGB or color-index color model)
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// OpenGL - specifies the size, in pixels, of your window.
	glutInitWindowSize(1024, 768);

	// OpenGL - specifies the screen location for the upper - left corner
	glutInitWindowPosition(500, 0);

	// OpenGL - creates a window with an OpenGL context.
	glutCreateWindow(" Final Project - Virtual City ");

	glutDisplayFunc(myDisplay);
	//glutDisplayFunc(display);
	//glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	myInit();

	glutMouseFunc(mousebutton);
	glutMotionFunc(mousemove);

	glutMainLoop();
}/* End of OpenGL_Init */

void myInit() {
	/* set color */
	// OpenGL -  establishes what color the window will be cleared to.
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// OpenGL -  establishes what color to use for drawing objects.
	glColor3f(1.0, 1.0, 1.0);

	myMenuInit();
	glOrtho(My_Ortho.X1 , My_Ortho.X2  , My_Ortho.Y1, My_Ortho.Y2, My_Ortho.Z1, My_Ortho.Z2);

	/* Init Light Value*/
	//InitLight_Ambient(mySource_1);
	myTexture();	
	//glEnable(GL_TEXTURE_2D);
	myDisplay();
	//display();
	/* Fix Camera Orig Position */
	My_LookAt.X = 0.0;
	My_LookAt.Y = 0.0;
	glutPostRedisplay();
}/* End of myInit */
void myTexture() {
	//glGenTextures(2, texName);
	//glBindTexture(GL_TEXTURE_2D, texName[0]);
	id_texture = LoadBitmap2("texture/back.bmp");
	
}


void myMenuInit() {
	int X_Direction_menu = glutCreateMenu(X_DirectionMenuFunc);
	glutAddMenuEntry("Increase X (key D)", 1);
	glutAddMenuEntry("Decrease X (key A)", 2);

	int Y_Direction_menu = glutCreateMenu(Y_DirectionMenuFunc);
	glutAddMenuEntry("Increase Y (key W)", 1);
	glutAddMenuEntry("Decrease Y (key S)", 2);

	int ArmRotation_menu = glutCreateMenu(ArmRotationMenuFunc);
	glutAddMenuEntry("往前", 1);
	glutAddMenuEntry("往後", 2);

	int GripperHeight_menu = glutCreateMenu(GripperHeightMenuFunc);
	glutAddMenuEntry("抬頭", 1);
	glutAddMenuEntry("低頭", 2);

	int GripperControl_menu = glutCreateMenu(GripperControlMenuFunc);
	glutAddMenuEntry("Open (key 7)", 1);
	glutAddMenuEntry("Close (key 8)", 2);
	/* Camera LookAt Setting */
	int LookAt_X_menu = glutCreateMenu(LookAt_X_MenuFunc);
	glutAddMenuEntry("Increase X (key z)", 1);
	glutAddMenuEntry("Decrease X (key x)", 2);
	int LookAt_Y_menu = glutCreateMenu(LookAt_Y_MenuFunc);
	glutAddMenuEntry("Increase Y (key c)", 1);
	glutAddMenuEntry("Decrease X (key v)", 2);
	int LookAt_Z_menu = glutCreateMenu(LookAt_Z_MenuFunc);
	glutAddMenuEntry("Increase Z (key b)", 1);
	glutAddMenuEntry("Decrease X (key n)", 2);
	/* Camera LookAt Setting */
	
	glutCreateMenu(myMenu);
	glutAddSubMenu("X Direction", X_Direction_menu);
	glutAddSubMenu("Y Direction", Y_Direction_menu);
	glutAddSubMenu("Arm-Rotation", ArmRotation_menu);
	glutAddSubMenu("Gripper Height", GripperHeight_menu);
	glutAddSubMenu("Gripper Control", GripperControl_menu);
	glutAddSubMenu("Camera Position X", LookAt_X_menu);
	glutAddSubMenu("Camera Position Y", LookAt_Y_menu);
	glutAddSubMenu("Camera Position Z", LookAt_Z_menu);
	glutAddMenuEntry("Home", 1);
	glutAddMenuEntry("Viewer0", 2);
	glutAddMenuEntry("Viewer1", 3);
	glutAddMenuEntry("Quit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myMenu(int id) {
	switch (id) {
	case 1:
		Robot_Arm = Robot_Initial;
		DrawPosition();
		My_LookAt = Initial_LookAt;
		MoveX = 0.0;
		MoveY = 0.0;
		MoveZ = 0.0;
		glutPostRedisplay();
		break;
	case 2:
		My_LookAt.X = 0;
		My_LookAt.Y = 1.5;
		My_LookAt.Z = 3.5;
		glutPostRedisplay();
		break;
	case 3:
		My_LookAt.X = -1.5;
		My_LookAt.Y = 2;
		My_LookAt.Z = 3.5;
		glutPostRedisplay();
		break;
	case 4: exit(0);
	}/* End of switch */
}


void myMouse(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		glutPostRedisplay();
	}/* End of if*/
}

void myKeyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 'w':
		MoveZ = MoveZ + 5;
		//My_LookAt.Z = My_LookAt.Z + 0.25 / My_Ortho.Value;
		//printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
		printf(" MoveZ = %f  \r\n", MoveZ);
		glutPostRedisplay();
		break;
	case 's':
		MoveZ = MoveZ - 5 ;
		//My_LookAt.Z = My_LookAt.Z - 0.25 / My_Ortho.Value;
		//printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
		printf(" MoveZ = %f  \r\n", MoveZ);
		glutPostRedisplay();
		break;
	
	case 'a':
		MoveX = MoveX - 5 ;
		/*if (4 == ++tempX1) {
			My_LookAt.Watch_X = My_LookAt.Watch_X - 0.1;
			printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
			tempX1 = 0;
		}*/
		/*My_LookAt.Watch_X = My_LookAt.Watch_X - 0.01 / My_Ortho.Value;
		My_LookAt.X = My_LookAt.X + 0.5 / My_Ortho.Value;
		printf(" My_LookAt.X = %f  \r\n", My_LookAt.X);
		printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);	*/	
		printf(" MoveX = %f  \r\n", MoveX);
		glutPostRedisplay();
		break;
	case 'd':
		MoveX = MoveX + 5 ;
		/*if (4 == ++tempX2) {
			My_LookAt.Watch_X = My_LookAt.Watch_X + 0.1;
			printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
			tempX2 = 0;
		}*/
		/*My_LookAt.Watch_X = My_LookAt.Watch_X + 0.01 / My_Ortho.Value;
		My_LookAt.X = My_LookAt.X - 0.5 / My_Ortho.Value;
		printf(" My_LookAt.X = %f  \r\n", My_LookAt.X);
		printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);*/
		printf(" MoveX = %f  \r\n", MoveX);
		glutPostRedisplay();
		break;
	case '1': // 前進
		My_LookAt.Watch_Z = My_LookAt.Watch_Z - 0.1;
		printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
		LookAt_Z_MenuFunc(2);
		glutPostRedisplay();
		break;
	case '2': // 後退
		My_LookAt.Watch_Z = My_LookAt.Watch_Z + 0.1;
		printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
		LookAt_Z_MenuFunc(1);
		glutPostRedisplay();
		break;
	case '4': // 低頭
		LookAt_Y_MenuFunc(1);
		My_LookAt.Watch_Y = My_LookAt.Watch_Y - 0.1;
		printf(" My_LookAt.Watch_Y = %f  \r\n", My_LookAt.Watch_Y);
		glutPostRedisplay();
		break;
	case '5': // 抬頭
		LookAt_Y_MenuFunc(2);
		My_LookAt.Watch_Y = My_LookAt.Watch_Y + 0.1;
		printf(" My_LookAt.Watch_Y = %f  \r\n", My_LookAt.Watch_Y);
		glutPostRedisplay();
		break;
	case '7': // 左轉
		LookAt_X_MenuFunc(2);
		My_LookAt.Watch_X = My_LookAt.Watch_X - 0.1;
		printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
		glutPostRedisplay();
		break;
	case '8': // 右轉
		LookAt_X_MenuFunc(1);
		My_LookAt.Watch_X = My_LookAt.Watch_X + 0.1;
		printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
		glutPostRedisplay();
		break;
	case 'z':
		LookAt_X_MenuFunc(1);
		break;
	case 'x':
		LookAt_X_MenuFunc(2);
		break;
	case 'c':
		LookAt_Y_MenuFunc(1);
		break;
	case 'v':
		LookAt_Y_MenuFunc(2);
		break;
	case 'b':
		LookAt_Z_MenuFunc(1);
		break;
	case 'n':
		LookAt_Z_MenuFunc(2);
		break;
	case 'f':
		My_LookAt.Forward_X = My_LookAt.Forward_X + 0.1;
		printf(" My_LookAt.Forward_X = %f  \r\n", My_LookAt.Forward_X);
		glutPostRedisplay();
		break;
	case 'g':
		My_LookAt.Forward_X = My_LookAt.Forward_X - 0.1;
		printf(" My_LookAt.Forward_X = %f  \r\n", My_LookAt.Forward_X);
		glutPostRedisplay();
		break;
	case 'h':
		My_LookAt.Forward_Y = My_LookAt.Forward_Y + 0.1;
		printf(" My_LookAt.Forward_Y = %f  \r\n", My_LookAt.Forward_Y);
		glutPostRedisplay();
		break;
	case 'j':
		My_LookAt.Forward_Y = My_LookAt.Forward_Y - 0.1;
		printf(" My_LookAt.Forward_Y = %f  \r\n", My_LookAt.Forward_Y);
		glutPostRedisplay();
		break;
	case 'k':
		My_LookAt.Forward_Z = My_LookAt.Forward_Z + 0.1;
		printf(" My_LookAt.Forward_Z = %f  \r\n", My_LookAt.Forward_Z);
		glutPostRedisplay();
		break;
	case 'l':
		My_LookAt.Forward_Z = My_LookAt.Forward_Z - 0.1;
		printf(" My_LookAt.Forward_Z = %f  \r\n", My_LookAt.Forward_Z);
		glutPostRedisplay();
		break;
	case 'r':
		My_LookAt.Watch_X = My_LookAt.Watch_X + 0.1;
		printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
		glutPostRedisplay();
		break;
	case 't':
		My_LookAt.Watch_X = My_LookAt.Watch_X - 0.1;
		printf(" My_LookAt.Watch_X = %f  \r\n", My_LookAt.Watch_X);
		glutPostRedisplay();
		break;
	case 'y':
		My_LookAt.Watch_Y = My_LookAt.Watch_Y + 0.1;
		printf(" My_LookAt.Watch_Y = %f  \r\n", My_LookAt.Watch_Y);
		glutPostRedisplay();
		break;
	case 'u':
		My_LookAt.Watch_Y = My_LookAt.Watch_Y - 0.1;
		printf(" My_LookAt.Watch_Y = %f  \r\n", My_LookAt.Watch_Y);
		glutPostRedisplay();
		break;
	case 'i':
		My_LookAt.Watch_Z = My_LookAt.Watch_Z + 0.1;
		printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
		glutPostRedisplay();
		break;
	case 'o':
		My_LookAt.Watch_Z = My_LookAt.Watch_Z - 0.1;
		printf(" My_LookAt.Watch_Z = %f  \r\n", My_LookAt.Watch_Z);
		glutPostRedisplay();
		break;

	//	/* Light Source Diffuse */
	//case 'z':
	//	mySource_1.Diffuse.Red = mySource_1.Diffuse.Red + 0.1;
	//	printf(" mySource_1.Diffuse.Red = %f  \r\n", mySource_1.Diffuse.Red);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'x':
	//	mySource_1.Diffuse.Green = mySource_1.Diffuse.Green + 0.1;
	//	printf(" mySource_1.Diffuse.Green = %f  \r\n", mySource_1.Diffuse.Green);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'c':
	//	mySource_1.Diffuse.Blue = mySource_1.Diffuse.Blue + 0.1;
	//	printf(" mySource_1.Diffuse.Blue = %f  \r\n", mySource_1.Diffuse.Blue);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'v':
	//	mySource_1.Diffuse.Red = mySource_1.Diffuse.Red - 0.1;
	//	printf(" mySource_1.Diffuse.Red = %f  \r\n", mySource_1.Diffuse.Red);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'b':
	//	mySource_1.Diffuse.Green = mySource_1.Diffuse.Green - 0.1;
	//	printf(" mySource_1.Diffuse.Green = %f  \r\n", mySource_1.Diffuse.Green);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'n':
	//	mySource_1.Diffuse.Blue = mySource_1.Diffuse.Blue - 0.1;
	//	printf(" mySource_1.Diffuse.Blue = %f  \r\n", mySource_1.Diffuse.Blue);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//	/* Light Source Position */
	//case ',':
	//	mySource_1.Position.X = mySource_1.Position.X + 0.1;
	//	printf(" mySource_1.Position.X = %f  \r\n", mySource_1.Position.X);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case '.':
	//	mySource_1.Position.Y = mySource_1.Position.Y + 0.1;
	//	printf(" mySource_1.Position.Y = %f  \r\n", mySource_1.Position.Y);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case '/':
	//	mySource_1.Position.Z = mySource_1.Position.Z + 0.1;
	//	printf(" mySource_1.Position.Z = %f  \r\n", mySource_1.Position.Z);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'k':
	//	mySource_1.Position.X = mySource_1.Position.X - 0.1;
	//	printf(" mySource_1.Position.X = %f  \r\n", mySource_1.Position.X);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case 'l':
	//	mySource_1.Position.Y = mySource_1.Position.Y - 0.1;
	//	printf(" mySource_1.Position.Y = %f  \r\n", mySource_1.Position.Y);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;
	//case ';':
	//	mySource_1.Position.Z = mySource_1.Position.Z - 0.1;
	//	printf(" mySource_1.Position.Z = %f  \r\n", mySource_1.Position.Z);
	//	SetupLight_Parameter(GL_LIGHT3, mySource_1, true);
	//	glutPostRedisplay();
	//	break;


	default:
		break;
	}

}

/* Camera LookAt Functions */
void LookAt_X_MenuFunc(int id) {
	switch (id) {
	case 1:		// Increase
		if (My_LookAt.X < 100.0)
			My_LookAt.X = My_LookAt.X + 0.1;
		else
			My_LookAt.X = My_LookAt.X;
		break;
	case 2:		// decrease
		if (My_LookAt.X > -100.0)
			My_LookAt.X = My_LookAt.X - 0.1;
		else
			My_LookAt.X = My_LookAt.X;
		break;
	}/* End of swtich*/
	
	printf(" My_LookAt.X = %f  \r\n", My_LookAt.X);
	glutPostRedisplay();
}
void LookAt_Y_MenuFunc(int id) {
	switch (id) {
	case 1:		// Increase
		if (My_LookAt.Y < 100.0)
			My_LookAt.Y = My_LookAt.Y + 0.1;
		else
			My_LookAt.Y = My_LookAt.Y;
		break;
	case 2:		// decrease
		if (My_LookAt.Y > -100.0)
			My_LookAt.Y = My_LookAt.Y - 0.1;
		else
			My_LookAt.Y = My_LookAt.Y;
		break;
	}/* End of swtich*/

	printf(" My_LookAt.Y = %f  \r\n", My_LookAt.Y);
	glutPostRedisplay();
}
void LookAt_Z_MenuFunc(int id) {
	switch (id) {
	case 1:		// Increase
		if (My_LookAt.Z < 100.0)
			My_LookAt.Z = My_LookAt.Z + 0.1;
		else
			My_LookAt.Z = My_LookAt.Z;
		break;
	case 2:		// decrease
		if (My_LookAt.Z > -100.0)
			My_LookAt.Z = My_LookAt.Z - 0.1;
		else
			My_LookAt.Z = My_LookAt.Z;
		break;
	}/* End of swtich*/

	printf(" My_LookAt.Z = %f  \r\n", My_LookAt.Z);
	glutPostRedisplay();
}