/*
 * ---------------- www.spacesimulator.net --------------
 *   ---- Space simulators and 3d engine tutorials ----
 *
 * Author: Damiano Vitulli <info@spacesimulator.net>
 *
 * ALL RIGHTS RESERVED
 *
 *
 * Tutorial 4: 3d engine - 3ds models loader
 * 
 * 
 *
 * To compile this project you must include the following libraries:
 * opengl32.lib,glu32.lib,glut.lib
 * You need also the header file glut.h in your compiler directory.
 *  
 */

/*
 * 3DS Spaceship created by: Rene Reiter <renereiter@hotmail.com>
 */



#include <windows.h>
#include <glut.h>
#include "tutorial4.h"
#include "texture.h"
#include "3dsloader.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>


/**********************************************************
 *
 * VARIABLES DECLARATION
 *
 *********************************************************/

// The width and height of your window, change them as you like
int screen_width=800;
int screen_height=600;

int area_x=1000;
int area_y=100;
int area_z=1000;

int bulletSpeed=100;
float bulletDistance=800.0;

float moveSpeed=0.2;
float targetSpeed=50.0;
float tDrawTimer=100.0;
int hitTimer=0;

// Absolute rotation values (0-359 degrees) and rotation increments for each frame
float rotation_x=0, rotation_x_increment=0.0;
float rotation_y=0, rotation_y_increment=0.0;
float rotation_z=0, rotation_z_increment=0.0;
 
// Flag for rendering as lines or filled polygons
int filling=1; //0=OFF 1=ON

//Now the object is generic, the cube has annoyed us a little bit, or not?
obj_type area_object[8];
obj_type gun_object[4];
obj_type bullet_object[4];
obj_type target_object[6];
obj_type room_texture[6];

float VectorPos[3];
float VectorView[3];
float VectorUp[3];
float vVector[3];
float gunVector[3];
float bullet1Vector[3];
float bullet2Vector[3];
float place1Vector[3];
float place2Vector[3];
float targetInfo[5][3];

int mid_x,mid_y;
float rad_x,rad_z;
float angle_y,angle_z;
POINT mousePos;
int i,j,index,shoot,len;
float distance_x,distance_y,distance_z;
float bullet_x,bullet_y,bullet_z;
unsigned char keytemp;
char str1[128];
char str2[128];
int score;
int bulletNumer[3],bulletNumerMax[3];
int bulletTimer[3],bulletTimerMax[3];

typedef struct treenode{
   obj_type object;
   int index,timer,type,number;
   float px,py,pz,speed,tx,tz,rot_y;
   float obj_w,obj_l,obj_h;
   float gunPos;
   GLfloat m[16];
   void (*f)();
   struct treenode *sibling;
   struct treenode *child;
} treenode;

treenode area,gun,camera,bullet,bulletHit;
treenode block[8];
treenode target[12];

void setVector (float Vector[3],float x, float y, float z);
void decVector (float aVector[3], float bVector[3],float cVector[3]);
void drawOBJ (obj_type object);
void drawALine (GLfloat point1[3],GLfloat point2[3]);
void Draw_Skybox(float x, float y, float z, float width, float height, float length);
void Draw_Grid(float width);
void Move_Camera1(float cameraspeed);
void Move_Camera1(float cameraspeed);
void traverse(treenode *root);
void touch(treenode *obja,treenode *objb);
void print_bitmap_string(void* font, char* s);

void drawGun();
void drawBullet();
void drawBlock();
void drawArea();
void drawTeapot();
void checkCamera();

//--

/**********************************************************
 *
 * SUBROUTINE init()
 *
 * Used to initialize OpenGL and to setup our world
 *
 *********************************************************/

void init(void)
{
	srand(time(NULL));

    glClearColor(0.0, 0.0, 0.0, 0.0); // This clear the background color to black
    glShadeModel(GL_SMOOTH); // Type of shading for the polygons
	glClearDepth(1.0f);
   	
    // Viewport transformation
    glViewport(0,0,640,480);  

    // Projection transformation
    glMatrixMode(GL_PROJECTION); // Specifies which matrix stack is the target for matrix operations 
    glLoadIdentity(); // We initialize the projection matrix as identity
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,10.0f,10000.0f); // We define the "viewing volume"
   
    glEnable(GL_DEPTH_TEST); // We enable the depth test (also called z buffer)
	glDepthFunc(GL_LEQUAL);	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
    
    glEnable(GL_TEXTURE_2D); // This Enable the Texture mapping

	Load3DS (&area_object[0],"3DS/obj_00.3DS");
	Load3DS (&area_object[1],"3DS/obj_01.3DS");
	Load3DS (&area_object[2],"3DS/obj_02.3DS");
	Load3DS (&area_object[3],"3DS/obj_03.3DS");
	Load3DS (&area_object[4],"3DS/obj_04.3DS");
	Load3DS (&area_object[5],"3DS/obj_05.3DS");
	Load3DS ( &gun_object[0],"3DS/gun0.3DS");
	Load3DS ( &gun_object[1],"3DS/gun1.3DS");
	Load3DS ( &gun_object[2],"3DS/gun2.3DS");
	Load3DS (&bullet_object[0],"3DS/bullet0.3ds");
	Load3DS (&bullet_object[1],"3DS/bullet1.3ds");
	Load3DS (&bullet_object[2],"3DS/bullet2.3ds");
	Load3DS (&target_object[0],"3DS/target00.3DS");
	Load3DS (&target_object[1],"3DS/target01.3DS");
	Load3DS (&target_object[2],"3DS/target02.3DS");
	Load3DS (&target_object[3],"3DS/target03.3DS");
	Load3DS (&target_object[4],"3DS/target04.3DS");
	

    area_object[0].id_texture=LoadBitmap("texture/cwall.bmp"); // The Function LoadBitmap() return the current texture ID
	area_object[1].id_texture=LoadBitmap("texture/block1.bmp");
	area_object[2].id_texture=LoadBitmap("texture/block1.bmp");
	area_object[3].id_texture=LoadBitmap("texture/block1.bmp");
	area_object[4].id_texture=LoadBitmap("texture/block1.bmp");
	area_object[5].id_texture=LoadBitmap("texture/block1.bmp");
	gun_object[0].id_texture =LoadBitmap("texture/gun0.bmp");
	gun_object[1].id_texture =LoadBitmap("texture/gun1.bmp");
	gun_object[2].id_texture =LoadBitmap("texture/gun2.bmp");
	bullet_object[0].id_texture =LoadBitmap("texture/bullet.bmp");
	bullet_object[1].id_texture =LoadBitmap("texture/bullet.bmp");
	bullet_object[2].id_texture =LoadBitmap("texture/bullet.bmp");
	target_object[0].id_texture=LoadBitmap("texture/teapot.bmp");
	target_object[1].id_texture=LoadBitmap("texture/taper.bmp");
	target_object[2].id_texture=LoadBitmap("texture/star.bmp");
	target_object[3].id_texture=LoadBitmap("texture/MushRooms.bmp");
	target_object[4].id_texture=LoadBitmap("texture/ufo.bmp");

	room_texture[0].id_texture=LoadBitmap("texture/front.bmp");
	room_texture[1].id_texture=LoadBitmap("texture/back.bmp");
	room_texture[2].id_texture=LoadBitmap("texture/left.bmp");
	room_texture[3].id_texture=LoadBitmap("texture/right.bmp");
	room_texture[4].id_texture=LoadBitmap("texture/up.bmp");
	room_texture[5].id_texture=LoadBitmap("texture/down.bmp");

    
    // If the last function returns -1 it means the file was not found so we exit from the program
    /*if (object.id_texture==-1)
    {
        MessageBox(NULL,"Image file: spaceshiptexture.bmp not found", "Zetadeck",MB_OK | MB_ICONERROR);
        exit (0);
    }*/

	bulletNumer[0]=bulletNumerMax[0]=20;
	bulletNumer[1]=bulletNumerMax[1]=10;
	bulletNumer[2]=bulletNumerMax[2]=5;
	bulletTimer[0]=bulletTimerMax[0]=5;
	bulletTimer[1]=bulletTimerMax[1]=10;
	bulletTimer[2]=bulletTimerMax[2]=15;

	score=0;
	shoot=0;
	angle_y  = 0.0f;				
	angle_z  = 0.0f;


	setVector(VectorPos,0.0,60.0,600.0);
	setVector(VectorView,0.0,60.0,580.0);
	setVector(VectorUp,0.0,1.0,0.0);
	setVector(vVector,0,0,0);
	
	
	area.px= (VectorView[0]+VectorPos[0])/2.0;
	area.py= VectorView[1];
	area.pz= (VectorView[2]+VectorPos[2])/2.0;
	area.obj_w=8.0;
	area.obj_l=60.0;
	area.obj_h=8.0;
	area.type=4;


	gun.object=gun_object[0];
	gun.number=0;
	gun.gunPos=10.0;
	setVector(gunVector,0.0,-15.0,0.0);
	setVector(place1Vector,0.0,10.0,0.0);
	setVector(place2Vector,0.0,gun.gunPos,0.0);
	setVector(bullet1Vector,0.0,40.0,-bulletDistance);


	bullet.object=bullet_object[0];
	bullet.px=0.0;
	bullet.py=10.0;
	bullet.pz=0.0;
	bullet.obj_w=2.0;
	bullet.obj_l=2.0;
	bullet.obj_h=2.0;
	bullet.type=3;

	block[0].object=area_object[0];
	block[0].px=0.0;
	block[0].py=0.0;
	block[0].pz=0.0;
	block[0].index=0;
	block[0].type=0;

	for( i=1;i<6;i++){
		block[i].object=area_object[i];
		block[i].px=(float)((-rand()%area_x)+area_x/2);
		block[i].py=0.0;
		block[i].pz=(float)((-rand()%area_z)+area_z/2);
		block[i].index=i;
		block[i].type=1;
		switch (i)
		{
			case 1:
				block[i].obj_w=100.0;
				block[i].obj_l=60.0;
				block[i].obj_h=160.0;
			break;
			case 2:
				block[i].obj_w=100.0;
				block[i].obj_l=150.0;
				block[i].obj_h=200.0;
			break;
			case 3:
				block[i].obj_w=90.0;
				block[i].obj_l=104.0;
				block[i].obj_h=180.0;
			break;
			case 4:
				block[i].obj_w=100.0;
				block[i].obj_l=100.0;
				block[i].obj_h=150.0;
			break;
			case 5:
				block[i].obj_w=60.0;
				block[i].obj_l=60.0;
				block[i].obj_h=120.0;
			break;
		}
	}


	setVector(targetInfo[0],20.0,12.0,10.0);
	setVector(targetInfo[1],10.0,10.0,15.0);
	setVector(targetInfo[2],8.0,8.0,8.0);
	setVector(targetInfo[3],5.0,5.0,5.0);
	setVector(targetInfo[4],10.0,4.0,10.0);

	for( i=0;i<10;i++){
		target[i].number=0;
		target[i].object=target_object[ target[i].number];
		target[i].px=(float)((-rand()%area_x)+area_x/2);
		target[i].py=(float)(( rand()%area_y)+1.0);
		target[i].pz=(float)((-rand()%area_z)+area_z/2);
		target[i].speed=(float)((rand()%10+1.0)/targetSpeed);
		target[i].rot_y=0.0;
		target[i].index=i;
		target[i].type=2;
		target[i].timer=tDrawTimer;
		target[i].obj_w=targetInfo[ target[i].number][0];
		target[i].obj_l=targetInfo[ target[i].number][1];
		target[i].obj_h=targetInfo[ target[i].number][2];
	}


}


void setVector (float Vector[3], float x, float y, float z)
{
	Vector[0]=x;
	Vector[1]=y;
	Vector[2]=z;
}

void decVector (float aVector[3], float bVector[3],float cVector[3])
{
	aVector[0]=bVector[0]-cVector[0];
	aVector[1]=bVector[1]-cVector[1];
	aVector[2]=bVector[2]-cVector[2];
}


void Move_Camera1(float cameraspeed)
{
	setVector(vVector,0,0,0);
	decVector(vVector,VectorView,VectorPos);
	
	// forward positive cameraspeed and backward negative -cameraspeed.
	VectorPos[0]  = VectorPos[0]  + vVector[0] * cameraspeed;
	VectorPos[2]  = VectorPos[2]  + vVector[2] * cameraspeed;
	VectorView[0] = VectorView[0] + vVector[0] * cameraspeed;
	VectorView[2] = VectorView[2] + vVector[2] * cameraspeed;
	
	area.px= (VectorView[0]+VectorPos[0])/2.0;
	area.py= VectorView[1];
	area.pz= (VectorView[2]+VectorPos[2])/2.0;
}

void Move_Camera2(float cameraspeed)
{
	setVector(vVector,0,0,0);
	decVector(vVector,VectorView,VectorPos);
	
	// forward positive cameraspeed and backward negative -cameraspeed.
	VectorPos[0]  = VectorPos[0]  + vVector[2] * (-cameraspeed);
	VectorPos[2]  = VectorPos[2]  + vVector[0] * cameraspeed;
	VectorView[0] = VectorView[0] + vVector[2] * (-cameraspeed);
	VectorView[2] = VectorView[2] + vVector[0] * cameraspeed;

	area.px= (VectorView[0]+VectorPos[0])/2.0;
	area.py= VectorView[1];
	area.pz= (VectorView[2]+VectorPos[2])/2.0;
}

void Mouse_Move(int x, int y)
{
	
	mid_x = screen_width  >> 1;	
	mid_y = screen_height >> 1;	
							
	
	GetCursorPos(&mousePos);	// Get the 2D mouse cursor (x,y) position					
	
	if( (mousePos.x == mid_x) && (mousePos.y == mid_y) ) return;

	SetCursorPos(mid_x, mid_y);	// Set the mouse cursor in the middle of the window						

	// Get the direction from the mouse, and bring the number down to a reasonable amount
	angle_y = (float)( (mid_x - mousePos.x) ) / 1000;		
	angle_z = (float)( (mid_y - mousePos.y) ) / 1000;

	// The higher the number(acceleration) is the faster the camera looks around.
	VectorView[1] += angle_z * 2;
	// limit the rotation around the x-axis
	if((VectorView[1] - VectorPos[1]) > 8)  VectorView[1] = VectorPos[1] + 8;
	if((VectorView[1] - VectorPos[1]) <-8)  VectorView[1] = VectorPos[1] - 8;

	bullet1Vector[1] += angle_z * 80.0;
	if(bullet1Vector[1]  > 360.0)  bullet1Vector[1] = 360.0;
	if(bullet1Vector[1]  <-280.0)  bullet1Vector[1] = -280.0;

	rotation_y_increment = angle_y * 57.3;
	rotation_y += rotation_y_increment;

	if (rotation_y > 360.0) rotation_y -= 360.0;
	if (rotation_y < -360.0) rotation_y += 360.0;


	setVector(vVector,0,0,0);
	decVector(vVector,VectorPos,VectorView);

	VectorPos[0] = (float)(VectorView[0] + cos(-angle_y)*vVector[0] - sin(-angle_y)*vVector[2]);
	VectorPos[2] = (float)(VectorView[2] + sin(-angle_y)*vVector[0] + cos(-angle_y)*vVector[2]);

//	setVector(vVector,0,0,0);
//	decVector(vVector,VectorView,VectorPos);

//	VectorView[0] = (float)(VectorPos[0] + cos(-angle_y)*vVector[0] - sin(-angle_y)*vVector[2]);
//	VectorView[2] = (float)(VectorPos[2] + sin(-angle_y)*vVector[0] + cos(-angle_y)*vVector[2]);

}


void Mouse_Click(int button, int state, int x, int y) 
{ 
	if(state) 
	{
		if(bulletNumer[gun.number]>0){
			if(shoot==0){
				shoot=1;
				bulletNumer[gun.number]--;
				bullet.timer=bulletSpeed;
				setVector(place2Vector,0.0,gun.gunPos,0.0);

				bullet.px=VectorView[0];
				bullet.py=VectorView[1];
				bullet.pz=VectorView[2];
		   }
	   }
	   
	}
 
} 


/**********************************************************
 *
 * SUBROUTINE display()
 *
 * This is our main rendering subroutine, called each frame
 * 
 *********************************************************/

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // This clear the background color to dark blue
   

    glMatrixMode(GL_MODELVIEW); // Modeling transformation
    glLoadIdentity(); // Initialize the model matrix as identity
	gluLookAt(VectorPos[0],VectorPos[1],VectorPos[2],VectorView[0],VectorView[1],VectorView[2],VectorUp[0],VectorUp[1],VectorUp[2]);
	glGetFloatv(GL_MODELVIEW_MATRIX, area.m);
	area.f = drawArea;
	area.sibling = NULL;
	area.child = &gun;


	glLoadIdentity();
	glTranslatef(gunVector[0],gunVector[1],gunVector[2]);
	glTranslatef(VectorView[0],VectorView[1],VectorView[2]);
	glRotatef(rotation_y,0.0,1.0,0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, gun.m);
	gun.f = drawGun;
	gun.sibling = &block[0];
	gun.child = &bullet;

	glLoadIdentity();
	glTranslatef(place2Vector[0],place2Vector[1],place2Vector[2]);
	glRotatef(-180.0,1.0,0.0,0.0);
	glGetFloatv(GL_MODELVIEW_MATRIX, bullet.m);
	bullet.f = drawBullet;
	bullet.sibling = NULL;
	bullet.child = NULL;


	for( i=0;i<6;i++){
		
		glLoadIdentity();

		for(j=1;j<6;j++){
			if(j!=i)
				touch( &block[i], &block[j]);
		}

		glTranslatef(block[i].px,block[i].py,block[i].pz);
		glRotatef( -90.0,1.0,0.0,0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, block[i].m);
		block[i].f = drawBlock;
		block[i].sibling = &block[i+1];
		block[i].child = NULL;
	}
	block[5].sibling = &target[0];



	for( i=0;i<10;i++){
		
		glLoadIdentity();

		if(target[i].speed==0.0){
			if(target[i].number<4){
				target[i].number+=1;
				target[i].object=target_object[ target[i].number];
			}

			if(target[i].number<3){
				target[i].px=(float)((-rand()%area_x)+area_x/2);
				target[i].py=(float)(( rand()%area_y)+1.0);
				target[i].pz=(float)((-rand()%area_z)+area_z/2);
				target[i].speed=(float)((rand()%10+1.0)/targetSpeed);
			}else if(target[i].number==3){
				target[i].px=(float)((-rand()%area_x)+area_x/2);
				target[i].py=3.0;
				target[i].pz=(float)((-rand()%area_z)+area_z/2);
				target[i].speed=(float)((rand()%10+1.0)/targetSpeed*2.0);
			}else if(target[i].number==4){
				target[i].px=(float)((-rand()%area_x)+area_x/2);
				target[i].py=(float)(( rand()%area_y)+40.0);
				target[i].pz=(float)((-rand()%area_z)+area_z/2);
				target[i].speed=(float)((rand()%10+1.0)/targetSpeed*3.0);
			}
			target[i].rot_y=0.0;
			target[i].index=i;
			target[i].type=2;
			target[i].timer=tDrawTimer;
			target[i].obj_w=targetInfo[ target[i].number][0];
			target[i].obj_l=targetInfo[ target[i].number][1];
			target[i].obj_h=targetInfo[ target[i].number][2];
		}

		for(j=1;j<6;j++){
			touch( &target[i], &block[j]);
		}
		for(j=0;j<10;j++){
			if(j!=i)
				touch( &target[i], &target[j]);
		}
		touch( &target[i], &area);

		glTranslatef(target[i].px,target[i].py,target[i].pz);
		glRotatef( target[i].rot_y,0.0,1.0,0.0);
		glRotatef( -90.0,1.0,0.0,0.0);
		glGetFloatv(GL_MODELVIEW_MATRIX, target[i].m);
		target[i].f = drawTeapot;
		target[i].sibling = &target[i+1];
		target[i].child = NULL;

	}
	target[9].sibling = NULL;
	
	glLoadIdentity();
	traverse(&area);


    glFlush(); // This force the execution of OpenGL commands
    glutSwapBuffers(); // In double buffered mode we invert the positions of the visible buffer and the writing buffer
}

void drawArea()
{
	Draw_Skybox(0.0, 0.0, 0.0, 4000.0, 2000.0, 4000.0);
	Draw_Grid(8000.0);
}

void drawGun()
{

	drawOBJ(gun.object);
	if(shoot==1 && bullet.timer!=0)	{
		drawALine(place1Vector,bullet1Vector);
	}

	glTranslatef(-gunVector[0],-gunVector[1],-gunVector[2]);
	sprintf(str1,"Score : %d",score);
	sprintf(str2,"Bullet count: %d",bulletNumer[gun.number]);
	glColor4f(0.0, 1.0, 0.0, 0.0);
	glRasterPos3f(+9.0, 6.0, -1.0);
	print_bitmap_string( GLUT_BITMAP_9_BY_15,str1);
	glRasterPos3f(-12.0, -6.0, -1.0);
	print_bitmap_string( GLUT_BITMAP_9_BY_15,str2);
	glTranslatef(gunVector[0],gunVector[1],gunVector[2]);

	if(hitTimer>0){
		glPushMatrix();
		glMultMatrixf(bulletHit.m);
		glColor4f(1.0, 0.0, 0.0, 0.0);
		glRasterPos3f(0.0, 0.0, 0.0);
		print_bitmap_string( GLUT_BITMAP_9_BY_15,"HIT");
		hitTimer--;
		glPopMatrix();
	}
}

void drawBullet()
{
	if(shoot==1 && bullet.timer!=0)	{
		
		decVector(bullet2Vector,place1Vector,bullet1Vector);
		setVector(place2Vector,place2Vector[0]-bullet2Vector[0]/(float)bulletSpeed,place2Vector[1]-bullet2Vector[1]/(float)bulletSpeed,place2Vector[2]-bullet2Vector[2]/(float)bulletSpeed);


		bullet.px -= (sin((rotation_y/180.0)*3.14159)*bulletDistance)/(float)bulletSpeed;
		bullet.py -= bullet2Vector[1]/(float)bulletSpeed;
		bullet.pz -= (cos((rotation_y/180.0)*3.14159)*bulletDistance)/(float)bulletSpeed;

		
		drawOBJ(bullet.object);

		for(j=1;j<6;j++){
			touch( &bullet, &block[j]);
		}
		for(j=0;j<10;j++){
			touch( &bullet, &target[j]);
		}
		
		bullet.timer--;
	}else{
		shoot=0;
	}

}

void drawBlock()
{
	i=index;
	drawOBJ(block[i].object);
}

void drawTeapot()
{
	i=index;

	if(target[i].speed!=0){
		drawOBJ(target[i].object);
	}

	if(target[i].timer==0){
		target[i].tx=(float)(((-rand()%3)+1.0)*target[i].speed);
		target[i].tz=(float)(((-rand()%3)+1.0)*target[i].speed);
		target[i].px+=target[i].tx;
		target[i].pz+=target[i].tz;
		if(target[i].px>=area_x/2 || target[i].px<=-area_x/2){
			target[i].px-=target[i].tx;
		}
		if(target[i].pz>=area_z/2 || target[i].pz<=-area_z/2){
			target[i].pz-=target[i].tz;
		}
		
		target[i].rot_y+=(float)((rand()%100+1.0)/10.0);
		if (target[i].rot_y > 360.0) target[i].rot_y -= 360.0;
		if (target[i].rot_y < -360.0) target[i].rot_y += 360.0;

		target[i].timer=tDrawTimer;
	}else{
		target[i].px+=target[i].tx;
		target[i].pz+=target[i].tz;
		if(target[i].px>=area_x/2 || target[i].px<=-area_x/2){
			target[i].px-=target[i].tx;
		}
		if(target[i].pz>=area_z/2 || target[i].pz<=-area_z/2){
			target[i].pz-=target[i].tz;
		}

		target[i].timer--;
	}

}

void touch(treenode *obja,treenode *objb)
{
	distance_x = (obja->obj_w/2.0)+(objb->obj_w/2.0);
	distance_y = (objb->obj_h);
	distance_z = (obja->obj_l/2.0)+(objb->obj_l/2.0);

	if(obja->type==1 ){

		while(( abs(obja->px - objb->px) <= distance_x ) && (abs(obja->pz - objb->pz) <= distance_z) ){

			obja->px=(float)((-rand()%area_x)+area_x/2);
			obja->pz=(float)((-rand()%area_z)+area_z/2);

	}

	}else if(obja->type==2 ){
	
		while(( abs(obja->px - objb->px) <= distance_x ) && (abs(obja->py - objb->py) <= distance_y) && (abs(obja->pz - objb->pz) <= distance_z) ){
			if (obja->px >= objb->px)
				obja->px += 1;
			else
				obja->px -= 1;

			if (obja->pz >= objb->pz)
				obja->pz += 1;
			else
				obja->pz -= 1;

		}
	}else if(obja->type==3 ){

		if(( abs(obja->px - objb->px) <= distance_x ) && (abs(obja->py - objb->py) <= distance_y) && (abs(obja->pz - objb->pz) <= distance_z) ){
			obja->timer=1;
			objb->speed=0.0;

			if(objb->type==2){
				score+=objb->number+1;
				hitTimer=100;
				glGetFloatv(GL_MODELVIEW_MATRIX, bulletHit.m);
			}

		}
	}else if(obja->type==4 ){

		if(( abs(obja->px - objb->px) <= distance_x ) && (abs(obja->py - objb->py) <= distance_y) && (abs(obja->pz - objb->pz) <= distance_z) ){

			switch (keytemp)
			{
				case 'w': case 'W':
					Move_Camera1(-moveSpeed*3.0);
				break;
				case 's': case 'S':
					Move_Camera1(moveSpeed*3.0);
				break;
				case 'a': case 'A':
					Move_Camera2(moveSpeed*3.0);
				break;
				case 'd': case 'D':
					Move_Camera2(-moveSpeed*3.0);
				break;
			}

		}
	}

}


void traverse(treenode *root)
{
  if(root == NULL) return;
  glPushMatrix();
  glMultMatrixf(root->m);
  index=root->index;
  root->f();
  if(root->child != NULL) 
     traverse(root->child);
  glPopMatrix();
  if(root->sibling != NULL) 
     traverse(root->sibling);
}


void drawOBJ (obj_type object)
{
    int l_index;

    glBindTexture(GL_TEXTURE_2D, object.id_texture); // We set the active texture 

    glBegin(GL_TRIANGLES); // glBegin and glEnd delimit the vertices that define a primitive (in our case triangles)
    for (l_index=0;l_index<object.polygons_qty;l_index++)
    {
        //----------------- FIRST VERTEX -----------------
        // Texture coordinates of the first vertex
        glTexCoord2f( object.mapcoord[ object.polygon[l_index].a ].u,
                      object.mapcoord[ object.polygon[l_index].a ].v);
        // Coordinates of the first vertex
        glVertex3f( object.vertex[ object.polygon[l_index].a ].x,
                    object.vertex[ object.polygon[l_index].a ].y,
                    object.vertex[ object.polygon[l_index].a ].z); //Vertex definition

        //----------------- SECOND VERTEX -----------------
        // Texture coordinates of the second vertex
        glTexCoord2f( object.mapcoord[ object.polygon[l_index].b ].u,
                      object.mapcoord[ object.polygon[l_index].b ].v);
        // Coordinates of the second vertex
        glVertex3f( object.vertex[ object.polygon[l_index].b ].x,
                    object.vertex[ object.polygon[l_index].b ].y,
                    object.vertex[ object.polygon[l_index].b ].z);
        
        //----------------- THIRD VERTEX -----------------
        // Texture coordinates of the third vertex
        glTexCoord2f( object.mapcoord[ object.polygon[l_index].c ].u,
                      object.mapcoord[ object.polygon[l_index].c ].v);
        // Coordinates of the Third vertex
        glVertex3f( object.vertex[ object.polygon[l_index].c ].x,
                    object.vertex[ object.polygon[l_index].c ].y,
                    object.vertex[ object.polygon[l_index].c ].z);
    }
    glEnd();

}


void drawALine (GLfloat point1[3],GLfloat point2[3])
{   
	glBegin(GL_LINES);
		glVertex3fv(point1);
		glVertex3fv(point2);
	glEnd();
}

void Draw_Skybox(float x, float y, float z, float width, float height, float length)
{
	// Center the Skybox around the given x,y,z position
	x = x - width  / 2;
	y = -1 ;
	z = z - length / 2;


	// Draw Front side
	glBindTexture(GL_TEXTURE_2D, room_texture[0].id_texture);
	glBegin(GL_QUADS);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height, z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height, z+length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z+length);
	glEnd();

	// Draw Back side
	glBindTexture(GL_TEXTURE_2D, room_texture[1].id_texture);
	glBegin(GL_QUADS);		
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height, z); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
	glEnd();

	// Draw Left side
	glBindTexture(GL_TEXTURE_2D, room_texture[2].id_texture);
	glBegin(GL_QUADS);		
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z+length); 
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z);		
	glEnd();

	// Draw Right side
	glBindTexture(GL_TEXTURE_2D, room_texture[3].id_texture);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y+height,	z+length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y+height,	z);
	glEnd();

	// Draw Up side
	glBindTexture(GL_TEXTURE_2D, room_texture[4].id_texture);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x+width, y+height, z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x+width, y+height, z+length); 
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,		  y+height,	z+length);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,		  y+height,	z);
	glEnd();

	// Draw Down side
	glBindTexture(GL_TEXTURE_2D, room_texture[5].id_texture);
	glBegin(GL_QUADS);		
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,		  y,		z);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x,		  y,		z+length);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x+width, y,		z+length); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x+width, y,		z);
	glEnd();

}

void Draw_Grid( float width )
{			
	for(float i = -(width / 2); i <= width / 2; i += width/100)
	{
		glBegin(GL_LINES);
			glColor3f(0, 0, 1);						
			glVertex3f(-(width / 2), -2, i);					
			glVertex3f((width / 2), -2, i);
			glVertex3f(i, -2,-(width / 2));							
			glVertex3f(i, -2, (width / 2));
		glEnd();
	}
}

void print_bitmap_string(void* font, char* s)
{
   if (s && strlen(s)) {
      while (*s) {
         glutBitmapCharacter(font, *s);
         s++;
      }
   }
}

/**********************************************************
 *
 * SUBROUTINE resize(int,int)
 *
 * This routine must be called everytime we resize our window.
 * 
 *********************************************************/

void resize (int width, int height)
{
    screen_width=width; // We obtain the new screen width values and store it
    screen_height=height; // Height value

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // We clear both the color and the depth buffer so to draw the next frame
    glViewport(0,0,screen_width,screen_height); // Viewport transformation

    glMatrixMode(GL_PROJECTION); // Projection transformation
    glLoadIdentity(); // We initialize the projection matrix as identity
	gluPerspective(50.0f,(GLfloat)screen_width/(GLfloat)screen_height,10.0f,10000.0f);

    glutPostRedisplay (); // This command redraw the scene (it calls the same routine of glutDisplayFunc)

}



/**********************************************************
 *
 * SUBROUTINE keyboard(unsigned char,int,int)
 *
 * Used to handle the keyboard input (ASCII Characters)
 * 
 *********************************************************/

void keyboard (unsigned char key, int x, int y)
{

	keytemp=key;
    switch (key)
    {
        case '1':
			gun.object=gun_object[0];
			gun.gunPos=10.0;
			setVector(gunVector,0.0,-15.0,0.0);
			setVector(place1Vector,0.0,10.0,0.0);
			setVector(place2Vector,0.0,gun.gunPos,0.0);
			bulletDistance=800;
			setVector(bullet1Vector,0.0,bullet1Vector[1],-800);
			bullet.object=bullet_object[0];
			gun.number=0;
			bullet.px=0.0;
			bullet.py=10.0;
			bullet.pz=0.0;
			bullet.obj_w=2.0;
			bullet.obj_l=2.0;
			bullet.obj_h=2.0;
        break;
        case '2':
			gun.object=gun_object[1];
			gun.gunPos=2.0;
			setVector(gunVector,0.0,-6.0,0.0);
			setVector(place1Vector,0.0,0.0,0.0);
			setVector(place2Vector,0.0,gun.gunPos,0.0);
			bulletDistance=800;
			setVector(bullet1Vector,0.0,bullet1Vector[1],-800);
			bullet.object=bullet_object[1];
			gun.number=1;
			bullet.px=0.0;
			bullet.py=10.0;
			bullet.pz=0.0;
			bullet.obj_w=4.0;
			bullet.obj_l=4.0;
			bullet.obj_h=4.0;

        break;
        case '3':
			gun.object=gun_object[2];
			gun.gunPos=2.0;
			setVector(gunVector,0.0,-12.0,0.0);
			setVector(place1Vector,0.0,0.0,0.0);
			setVector(place2Vector,0.0,gun.gunPos,0.0);
			bulletDistance=800;
			setVector(bullet1Vector,0.0,bullet1Vector[1],-800);
			bullet.object=bullet_object[2];
			gun.number=2;
			bullet.px=0.0;
			bullet.py=10.0;
			bullet.pz=0.0;
			bullet.obj_w=10.0;
			bullet.obj_l=10.0;
			bullet.obj_h=2.0;

        break;
        case 'r': case 'R':
            if (filling==0)
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
                filling=1;
            }   
            else 
            {
                glPolygonMode (GL_FRONT_AND_BACK, GL_LINE); // Polygon rasterization mode (polygon outlined)
                filling=0;
            }
        break;
		case 'w': case 'W':
			Move_Camera1(moveSpeed);
			checkCamera();
		break;
		case 's': case 'S':
			Move_Camera1(-moveSpeed);
			checkCamera();
		break;
		case 'a': case 'A':
			Move_Camera2(-moveSpeed);
			checkCamera();
		break;
		case 'd': case 'D':
			Move_Camera2(moveSpeed);
			checkCamera();
		break;
		case VK_ESCAPE:
            exit(0);
        break;

    }

}

void checkCamera()
{
	for(j=1;j<6;j++){
		touch( &area, &block[j]);
	}
	for(j=0;j<10;j++){
		touch( &area, &target[j]);
	}
}

void myTimer(int value)
{
	for(j=0;j<3;j++){
		if(bulletNumer[j]==bulletNumerMax[j]){
		}else if(bulletTimer[j]!=0){
			bulletTimer[j]--;
		}else{
			bulletTimer[j]=bulletTimerMax[j];
			bulletNumer[j]++;
		}
	}

	glutTimerFunc(1000/value,myTimer,10 );
}

/**********************************************************
 *
 * The main routine
 * 
 *********************************************************/

int main(int argc, char **argv)
{
    // We use the GLUT utility to initialize the window, to handle the input and to interact with the windows system
    glutInit(&argc, argv);    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(screen_width,screen_height);
    glutInitWindowPosition(0,0);
    glutCreateWindow("www.spacesimulator.net - 3d engine tutorials: Tutorial 4");    
	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc (resize);
    glutKeyboardFunc (keyboard);
	glutPassiveMotionFunc(Mouse_Move);
	glutMouseFunc(Mouse_Click);
	glutTimerFunc(1000/10,myTimer,10 );
    init();
    glutMainLoop();

    return(0);    
}
