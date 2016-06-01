#include "stdafx.h"
#include "myGL_Init.h"
#include "Robot_Arm.h"
#include "myLight.h"
#include "glFunctions.h"
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

	myDisplay();
	/* Fix Camera Orig Position */
	My_LookAt.X = 0.0;
	My_LookAt.Y = 0.0;
	glutPostRedisplay();
}/* End of myInit */

void myMenuInit() {
	int X_Direction_menu = glutCreateMenu(X_DirectionMenuFunc);
	glutAddMenuEntry("Increase X (key D)", 1);
	glutAddMenuEntry("Decrease X (key A)", 2);

	int Y_Direction_menu = glutCreateMenu(Y_DirectionMenuFunc);
	glutAddMenuEntry("Increase Y (key W)", 1);
	glutAddMenuEntry("Decrease Y (key S)", 2);

	int ArmRotation_menu = glutCreateMenu(ArmRotationMenuFunc);
	glutAddMenuEntry("Clockwise (key 1)", 1);
	glutAddMenuEntry("CounterClockwise (key 2)", 2);

	int GripperHeight_menu = glutCreateMenu(GripperHeightMenuFunc);
	glutAddMenuEntry("Up (key 4)", 1);
	glutAddMenuEntry("Down (key 5)", 2);

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
	glutAddMenuEntry("Quit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void myMenu(int id) {
	switch (id) {
	case 1:
		Robot_Arm = Robot_Initial;
		DrawPosition();
		My_LookAt = Initial_LookAt;
		glutPostRedisplay();
		break;
	case 2:
		My_LookAt.X = 0.2;
		My_LookAt.Y = -0.3;
		My_LookAt.Z = 0.1;
		glutPostRedisplay();
		break;
	case 3: exit(0);
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
		Y_DirectionMenuFunc(1);
		break;
	case 's':
		Y_DirectionMenuFunc(2);
		break;
	case 'a':
		X_DirectionMenuFunc(2);
		break;
	case 'd':
		X_DirectionMenuFunc(1);
		break;
	case '1':
		ArmRotationMenuFunc(1);
		break;
	case '2':
		ArmRotationMenuFunc(2);
		break;
	case '4':
		GripperHeightMenuFunc(1);
		break;
	case '5':
		GripperHeightMenuFunc(2);
		break;
	case '7':
		GripperControlMenuFunc(1);
		break;
	case '8':
		GripperControlMenuFunc(2);
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
		if (My_LookAt.X < 1.0)
			My_LookAt.X = My_LookAt.X + 0.1;
		else
			My_LookAt.X = My_LookAt.X;
		break;
	case 2:		// decrease
		if (My_LookAt.X > -1.0)
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
		if (My_LookAt.Y < 1.0)
			My_LookAt.Y = My_LookAt.Y + 0.1;
		else
			My_LookAt.Y = My_LookAt.Y;
		break;
	case 2:		// decrease
		if (My_LookAt.Y > -1.0)
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
		if (My_LookAt.Z < 1.0)
			My_LookAt.Z = My_LookAt.Z + 0.1;
		else
			My_LookAt.Z = My_LookAt.Z;
		break;
	case 2:		// decrease
		if (My_LookAt.Z > -1.0)
			My_LookAt.Z = My_LookAt.Z - 0.1;
		else
			My_LookAt.Z = My_LookAt.Z;
		break;
	}/* End of swtich*/

	printf(" My_LookAt.Z = %f  \r\n", My_LookAt.Z);
	glutPostRedisplay();
}