#include <windows.h>
#include <GL/glut.h>
#include <math.h>


//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
	glEnable(GL_LIGHT1); //Enable light #1
	glEnable(GL_NORMALIZE); //Automatically normalize normals
	glShadeModel(GL_SMOOTH); //Enable smooth shading
}

//Called when the window is resized
void handleResize(int w, int h) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = -7.0f,posLight1=0.1f,posLight2=0.1f,posLight3=0.1f,R=0,G=0,B=0;
int night = 0;

void Ground()
{
    int i, p, r=25;
    float x=0.0, y=-1, z=0.0, q = 0.0, radius = 20.0, Pi = 3.1412;

        glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
        glColor3f(0.2, 1, 0.4);
        glVertex3f(x, y, z); // centre of circle
        for (i = 0; i <= 2*r; i++)
        {
            glVertex3f ((x + (radius * cos(i * Pi / r))), y, (z + (radius * sin(i * Pi / r))));
        }
        glEnd();
}
void dayLight()
{
    //Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.25f, 0.1f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);



	//Add directed light
	GLfloat lightColor1[] = {0.2f, 0.25f, 0.1f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {0.0f, 3.5f, 2.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	if(night==1)
        return;
}
void nightLight()
{
    //Add positioned light
	GLfloat lightColor0[] = {posLight1, posLight2, posLight3, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {0.0f, -8.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
}

//Draws the 3D scene
void drawScene() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(R,G,B,1);
	glMatrixMode(GL_MODELVIEW); // keep it like this
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -12.0f);




        nightLight();



	glRotatef(10, 1.0f, 0.0f, 0.0f);
	glRotatef(-10, 0.0f, 0.0f, 1.0f);
	glRotatef(_angle,0.0f, 1.0f, 0.0f);
	//glRotatef(10, 1.0f, 0.0f, 0.0f);
	//glRotatef(-10, 0.0f, 0.0f, 1.0f);
	//glRotatef(_angle,0.0f, 1.0f, 0.0f);

		glColor3f(1.0f, 1.0f, 0.0f);
		 glTranslatef(0.0f,0.0f,-3.0f);
	glBegin(GL_QUADS);
//---------------------------- Top start ----------------
	//Front


    glColor3f(1,0.6,0.2);

    glVertex3f(-2.0f, 2.0f, 1.0f); //1
	glVertex3f(2.0f, 2.0f, 1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);
    glVertex3f(-2.0f, 1.0f, 1.0f);

    glVertex3f(-2.0f, 1.0f, 1.0f); //2
	glVertex3f(-0.75f, 1.0f, 1.0f);
	glVertex3f(-0.75f, -1.0f, 1.0f);
    glVertex3f(-2.0f, -1.0f, 1.0f);

    glVertex3f(0.75f, 1.0f, 1.0f); //3
	glVertex3f(2.0f, 1.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);
    glVertex3f(0.75f, -1.0f, 1.0f);

    glVertex3f(-0.75f, -0.5f, 1.0f); //4
	glVertex3f(-0.75f, -1.0f, 1.0f);
	glVertex3f(0.75f, -1.0f, 1.0f);
    glVertex3f(0.75f, -0.5f, 1.0f);

    glVertex3f(-2.0f, 2.0f, 0.5f); //1
	glVertex3f(2.0f, 2.0f, 0.5f);
	glVertex3f(2.0f, 1.0f, 0.5f);
    glVertex3f(-2.0f, 1.0f, 0.5f);

    glVertex3f(-2.0f, 1.0f, 0.5f); //2
	glVertex3f(-0.75f, 1.0f, 0.5f);
	glVertex3f(-0.75f, -1.0f, 0.5f);
    glVertex3f(-2.0f, -1.0f, 0.5f);

    glVertex3f(0.75f, 1.0f, 0.5f); //3
	glVertex3f(2.0f, 1.0f, 0.5f);
	glVertex3f(2.0f, -1.0f, 0.5f);
    glVertex3f(0.75f, -1.0f, 0.5f);

    glVertex3f(-0.75f, -0.5f, 0.5f); //4
	glVertex3f(-0.75f, -1.0f, 0.5f);
	glVertex3f(0.75f, -1.0f, 0.5f);
    glVertex3f(0.75f, -0.5f, 0.5f);

    glVertex3f(-2.0f, 2.0f, 0.5f); //1234 top
	glVertex3f(2.0f, 2.0f, 0.5f);
	glVertex3f(2.0f, 2.0f, 1.0f);
    glVertex3f(-2.0f, 2.0f, 1.0f);

    glVertex3f(0.75f, 1.0f, 0.5f); //1234 middle
	glVertex3f(0.75f, 1.0f, 1.0f);
	glVertex3f(0.75f, -1.0f, 1.0f);
    glVertex3f(0.75f, -1.0f, 0.5f);

    glVertex3f(-0.75f, 1.0f, 0.5f); //1234 middle
	glVertex3f(-0.75f, 1.0f, 1.0f);
	glVertex3f(-0.75f, -1.0f, 1.0f);
    glVertex3f(-0.75f, -1.0f, 0.5f);

    glVertex3f(-2.0f, 2.0f, 0.5f); //5 back
	glVertex3f(-2.5f, 1.75f, 0.5f);
	glVertex3f(-2.5f, -1.0f, 0.5f);
    glVertex3f(-2.0f, -1.0f, 0.5f);

    glVertex3f(-2.0f, 2.0f, 1.0f); //5 front
	glVertex3f(-2.5f, 1.75f, 1.0f);
	glVertex3f(-2.5f, -1.0f, 1.0f);
    glVertex3f(-2.0f, -1.0f, 1.0f);

    glVertex3f(-2.0f, 2.0f, 1.0f); //5 top
	glVertex3f(-2.0f, 2.0f, 0.5f);
	glVertex3f(-2.5f, 1.75f, 0.5f);
    glVertex3f(-2.5f, 1.75f, 1.0f);

    glVertex3f(-2.5f, 1.75f, 0.5f); //6 back
	glVertex3f(-2.75f, 1.50f, 0.5f);
	glVertex3f(-2.75f, -1.0f, 0.5f);
    glVertex3f(-2.5f, -1.0f, 0.5f);

    glVertex3f(-2.5f, 1.75f, 1.0f); //6 back
	glVertex3f(-2.75f, 1.50f, 1.0f);
	glVertex3f(-2.75f, -1.0f, 1.0f);
    glVertex3f(-2.5f, -1.0f, 1.0f);

    glVertex3f(-2.50f, 1.75f, 1.0f); //6 top
	glVertex3f(-2.50f, 1.75f, 0.5f);
	glVertex3f(-2.75f, 1.5f, 0.5f);
    glVertex3f(-2.75f, 1.5f, 1.0f);
    glEnd();
    glBegin(GL_POLYGON);

    glVertex3f(-2.75f,1.5f,1.0f);  //1
    glVertex3f(-3.00f,1.5f,1.0f);  //2
    glVertex3f(-3.25f,1.25f,1.0f); //3
    glVertex3f(-3.50f,1.25f,1.0f);  //4
    glVertex3f(-3.70f,1.00f,1.0f);  //5
    glVertex3f(-4.00f,0.75f,1.0f); //6
glVertex3f(-4.10f,0.60f,1.0f);  //7
    glVertex3f(-4.50f,0.30f,1.0f); //8 -------------------
    //------------------------------

    glVertex3f(-4.50f,-1.0f,1.0f);
    glVertex3f(-2.75f,-1.0f,1.0f);

    glVertex3f(-2.75f,1.5f,0.5f);  //1
    glVertex3f(-3.00f,1.5f,0.5f);  //2
    glVertex3f(-3.25f,1.25f,0.5f); //3
    glVertex3f(-3.50f,1.25f,0.5f);  //4
    glVertex3f(-3.70f,1.00f,0.5f);  //5
    glVertex3f(-4.00f,0.75f,0.5f); //6
    glVertex3f(-4.10f,0.60f,0.5f);  //7
    glVertex3f(-4.50f,0.30f,0.5f); //8 -------------------
    //------------------------------

    glVertex3f(-4.50f,-1.0f,0.5f);
    glVertex3f(-2.75f,-1.0f,0.5f);
	glEnd();
	//glutSolidTeapot(2.5);
	glBegin(GL_QUADS);

	glVertex3f(-4.50f,0.30f,0.5f);
    glVertex3f(-5.50f,0.30f,0.5f);
    glVertex3f(-5.50f,-1.0f,0.5f);
    glVertex3f(-4.50f,-1.0f,0.5f);
    glVertex3f(-4.50f,0.30f,1.0f);
    glVertex3f(-5.50f,0.30f,1.0f);
    glVertex3f(-5.50f,-1.0f,1.0f);
    glVertex3f(-4.50f,-1.0f,1.0f);
    glVertex3f(-4.50f,0.30f,1.0f);
    glVertex3f(-5.50f,0.30f,1.0f);
    glVertex3f(-5.50f,0.30f,0.5f);
    glVertex3f(-4.50f,0.30f,0.5f);
	glEnd();

	glBegin(GL_POLYGON);

	glVertex3f(-5.50f,0.30f,0.5f);
    glVertex3f(-5.75f,0.50f,0.5f);
    glVertex3f(-6.25f,0.65f,0.5f);
    glVertex3f(-6.75f,0.45f,0.5f);
    glVertex3f(-7.25f,0.10f,0.5f);
    glVertex3f(-7.25f,-1.0f,0.5f);
    glVertex3f(-5.50f,-1.0f,0.5f);
    glEnd();
    //-------------------------
    glBegin(GL_POLYGON);
    glVertex3f(-5.50f,0.30f,1.0f);
    glVertex3f(-5.75f,0.50f,1.0f);
    glVertex3f(-6.25f,0.65f,1.0f);
    glVertex3f(-6.75f,0.45f,1.0f);
    glVertex3f(-7.25f,0.10f,1.0f);
    glVertex3f(-7.25f,-1.0f,1.0f);
    glVertex3f(-5.50f,-1.0f,1.0f);
    //------------------------
    glEnd();
    glBegin(GL_QUADS);
    glVertex3f(-7.25f,-1.0f,1.0f);
    glVertex3f(-7.25f,-1.0f,0.5f);
    glVertex3f(-7.25f,0.10f,0.5f);
    glVertex3f(-7.25f,0.10f,1.0f); //-------- left fill side wall

    glVertex3f(-7.25f,0.10f,1.0f);
    glVertex3f(-6.75f,0.45f,1.0f);
    glVertex3f(-6.75f,0.45f,0.5f);
    glVertex3f(-7.25f,0.10f,0.5f);


    glVertex3f(-6.75f,0.45f,1.0f);
    glVertex3f(-6.25f,0.65f,1.0f);
    glVertex3f(-6.25f,0.65f,0.5f);
    glVertex3f(-6.75f,0.45f,0.5f);


    glVertex3f(-6.25f,0.65f,1.0f);
    glVertex3f(-5.75f,0.50f,1.0f);
    glVertex3f(-5.75f,0.50f,0.5f);
    glVertex3f(-6.25f,0.65f,0.5f);


    glVertex3f(-5.75f,0.50f,1.0f);
    glVertex3f(-5.50f,0.30f,1.0f);
    glVertex3f(-5.50f,0.30f,0.5f);
    glVertex3f(-5.75f,0.50f,0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(2.0f,2.0f,1.0f);
    glVertex3f(2.50f,1.80f,1.15f);
    glVertex3f(2.50f,-1.0f,1.15f);
    glVertex3f(2.0f,-1.0f,1.0f);

    glVertex3f(2.0f,2.0f,0.5f);
    glVertex3f(2.50f,1.80f,0.65f);
    glVertex3f(2.50f,-1.0f,0.65f);
    glVertex3f(2.0f,-1.0f,0.5f);

    glVertex3f(2.0f,2.0f,1.0f);
    glVertex3f(2.0f,2.0f,0.5f);
    glVertex3f(2.50f,1.80f,0.65f);
    glVertex3f(2.50f,1.80f,1.15f);//----------------right wall

    glVertex3f(2.50f,1.80f,1.15f);
    glVertex3f(3.00f,2.0f,1.20f);
    glVertex3f(3.00f,-1.0f,1.20f);
    glVertex3f(2.50f,-1.0f,1.15f);

    glVertex3f(2.50f,1.80f,0.65f);
    glVertex3f(3.00f,2.0f,0.70f);
    glVertex3f(3.00f,-1.0f,0.70f);
    glVertex3f(2.50f,-1.0f,0.65f);

    glVertex3f(2.50f,1.80f,1.15f);
    glVertex3f(2.50f,1.80f,0.65f);
    glVertex3f(3.00f,2.0f,0.70f);
    glVertex3f(3.00f,2.0f,1.20f); //-----------------------------------

    glVertex3f(3.00f,2.0f,1.20f);
    glVertex3f(4.00f,2.0f,1.35f);
    glVertex3f(4.00f,-1.0f,1.35f);
    glVertex3f(3.00f,-1.0f,1.20f);

    glVertex3f(3.00f,2.0f,0.70f);
    glVertex3f(4.00f,2.0f,0.85f);
    glVertex3f(4.00f,-1.0f,0.85f);
    glVertex3f(3.00f,-1.0f,0.70f);

    glVertex3f(3.0f,2.0f,1.20f);
    glVertex3f(3.0f,2.0f,0.70f);
    glVertex3f(4.00f,2.0f,0.85f);
    glVertex3f(4.00f,2.0f,1.35f);//---------------------------

    glVertex3f(4.00f,2.0f,1.35f);
    glVertex3f(4.25f,1.80f,1.45f);
    glVertex3f(4.25f,-1.0f,1.45f);
    glVertex3f(4.00f,-1.0f,1.35f);

    glVertex3f(4.00f,2.0f,0.85f);
    glVertex3f(4.25f,1.80f,0.95f);
    glVertex3f(4.25f,-1.0f,0.95f);
    glVertex3f(4.00f,-1.0f,0.85f);

    glVertex3f(4.00f,2.0f,0.85f);
    glVertex3f(4.00f,2.0f,1.35f);
    glVertex3f(4.25f,1.80f,1.45f);
    glVertex3f(4.25f,1.80f,0.95f); //-----------------------

    glVertex3f(4.25f,1.80f,1.45f);
    glVertex3f(5.00f,0.50f,1.65f);
    glVertex3f(5.00f,-1.0f,1.65f);
    glVertex3f(4.25f,-1.0f,1.45f);

    glVertex3f(4.25f,1.80f,0.95f);
    glVertex3f(5.00f,0.50f,1.15f);
    glVertex3f(5.00f,-1.0f,1.15f);
    glVertex3f(4.25f,-1.0f,0.95f);

    glVertex3f(4.25f,1.80f,0.95f);
    glVertex3f(4.25f,1.80f,1.45f);
    glVertex3f(5.00f,0.50f,1.65f);
    glVertex3f(5.00f,0.50f,1.15f); //-------------------

    glVertex3f(5.00f,0.50f,1.65f);
    glVertex3f(5.25f,0.50f,1.75f);
    glVertex3f(5.25f,-1.0f,1.75f);
    glVertex3f(5.00f,-1.0f,1.65f);

    glVertex3f(5.00f,0.50f,1.15f);
    glVertex3f(5.25f,0.50f,1.25f);
    glVertex3f(5.25f,-1.0f,1.25f);
    glVertex3f(5.00f,-1.0f,1.15f);

    glVertex3f(5.00f,0.50f,1.15f);
    glVertex3f(5.00f,0.50f,1.65f);
    glVertex3f(5.25f,0.50f,1.75f);
    glVertex3f(5.25f,0.50f,1.25f); //-----------------------

    glVertex3f(5.25f,0.50f,1.75f);
    glVertex3f(5.75f,0.35f,1.95f);
    glVertex3f(5.75f,-1.0f,1.95f);
    glVertex3f(5.25f,-1.0f,1.75f);

    glVertex3f(5.25f,0.50f,1.25f);
    glVertex3f(5.75f,0.35f,1.45f);
    glVertex3f(5.75f,-1.0f,1.45f);
    glVertex3f(5.25f,-1.0f,1.25f);

    glVertex3f(5.25f,0.50f,1.25f);
    glVertex3f(5.25f,0.50f,1.75f);
    glVertex3f(5.75f,0.35f,1.95f);
    glVertex3f(5.75f,0.35f,1.45f);  //----------------

    glVertex3f(5.75f,0.35f,1.95f);
    glVertex3f(6.25f,0.25f,2.15f);
    glVertex3f(6.25f,-1.0f,2.15f);
    glVertex3f(5.75f,-1.0f,1.95f);

    glVertex3f(5.75f,0.35f,1.45f);
    glVertex3f(6.25f,0.25f,1.65f);
    glVertex3f(6.25f,-1.0f,1.65f);
    glVertex3f(5.75f,-1.0f,1.45f);

    glVertex3f(5.75f,0.35f,1.45f);
    glVertex3f(5.75f,0.35f,1.95f);
    glVertex3f(6.25f,0.25f,2.15f);
    glVertex3f(6.25f,0.25f,1.65f); //------------------


    glVertex3f(6.25f,0.25f,2.15f);
    glVertex3f(6.25f,0.25f,1.65f);
    glVertex3f(6.25f,-1.0f,1.65f);
    glVertex3f(6.25f,-1.0f,2.15f); //-------------right fill side wall

    glVertex3f(-7.25f,-0.7f,4.5f);
    glVertex3f(-7.25f,-1.0f,4.5f);
    glVertex3f(6.25f,-1.0f,4.5f);
    glVertex3f(6.25f,-0.7f,4.5f); //----------black front red boundary

    glVertex3f(-7.25f,-0.7f,4.5f);
    glVertex3f(-7.25f,-0.7f,4.3f);
    glVertex3f(6.25f,-0.7f,4.3f);
    glVertex3f(6.25f,-0.7f,4.5f); //----------black front red boundary

    glColor3f(0.8,0.5,0.5);

    glVertex3f(-4.25f,-0.7f,4.5f);
    glVertex3f(-4.25f,-0.7f,4.7f);
    glVertex3f(2.25f,-0.7f,4.7f);
    glVertex3f(2.25f,-0.7f,4.5f); //----------staircase

    glVertex3f(-4.25f,-0.7f,4.7f);
    glVertex3f(-4.25f,-1.0f,4.7f);
    glVertex3f(2.25f,-1.0f,4.7f);
    glVertex3f(2.25f,-0.7f,4.7f); //----------staircase

    glVertex3f(-4.25f,-0.7f,4.5f);
    glVertex3f(-4.25f,-1.0f,4.5f);
    glVertex3f(-4.25f,-1.0f,4.7f);
    glVertex3f(-4.25f,-0.7f,4.7f); //----------staircase

    glVertex3f(2.25f,-0.7f,4.5f);
    glVertex3f(2.25f,-1.0f,4.5f);
    glVertex3f(2.25f,-1.0f,4.7f);
    glVertex3f(2.25f,-0.7f,4.7f); //----------staircase

    glVertex3f(-4.25f,-0.85f,4.7f);
    glVertex3f(-4.25f,-0.85f,5.0f);
    glVertex3f(2.25f,-0.85f,5.0f);
    glVertex3f(2.25f,-0.85f,4.7f); //----------staircase

    glVertex3f(-4.25f,-0.85f,5.0f);
    glVertex3f(-4.25f,-1.0f,5.0f);
    glVertex3f(2.25f,-1.0f,5.0f);
    glVertex3f(2.25f,-0.85f,5.0f); //----------staircase

    glVertex3f(-4.25f,-0.85f,4.7f);
    glVertex3f(-4.25f,-1.0f,4.7f);
    glVertex3f(-4.25f,-1.0f,5.0f);
    glVertex3f(-4.25f,-0.85f,5.0f); //----------staircase

    glVertex3f(2.25f,-0.85f,4.7f);
    glVertex3f(2.25f,-1.0f,4.7f);
    glVertex3f(2.25f,-1.0f,5.0f);
    glVertex3f(2.25f,-0.85f,5.0f); //----------staircase END

    glVertex3f(2.75f,-0.7f,5.5f);
    glVertex3f(2.75f,-1.0f,5.5f);
    glVertex3f(2.75f,-1.0f,8.5f);
    glVertex3f(2.75f,-0.7f,8.5f); // right decor

    glVertex3f(2.75f,-0.7f,5.5f);
    glVertex3f(3.00f,-0.7f,5.5f);
    glVertex3f(3.00f,-0.7f,8.5f);
    glVertex3f(2.75f,-0.7f,8.5f); // right decor

    glVertex3f(2.75f,-0.7f,8.5f);
    glVertex3f(2.75f,-1.0f,8.5f);
    glVertex3f(5.75f,-1.0f,8.5f);
    glVertex3f(5.75f,-0.7f,8.5f); // right decor

    glVertex3f(2.75f,-0.7f,8.5f);
    glVertex3f(5.75f,-0.7f,8.5f);
    glVertex3f(5.75f,-0.7f,8.25f);
    glVertex3f(2.75f,-0.7f,8.25f); // right decor

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,0,0);

     glVertex3f(0.75f, 1.0f, 4.0f); //---- black box start
	glVertex3f(2.0f, 1.0f, 4.0f);
	glVertex3f(2.0f, -1.0f, 4.0f);
    glVertex3f(0.75f, -1.0f, 4.0f);

    glVertex3f(0.75f, 1.0f, 3.0f);
	glVertex3f(2.0f, 1.0f, 3.0f);
	glVertex3f(2.0f, -1.0f, 3.0f);
    glVertex3f(0.75f, -1.0f, 3.0f);

    glVertex3f(0.75f, 1.0f, 4.0f);
	glVertex3f(0.75f, 1.0f, 3.0f);
	glVertex3f(0.75f, -1.0f, 3.0f);
    glVertex3f(0.75f, -1.0f, 4.0f);

    glVertex3f(2.0f, 1.0f, 4.0f);
	glVertex3f(2.0f, 1.0f, 3.0f);
	glVertex3f(2.0f, -1.0f, 3.0f);
    glVertex3f(2.0f, -1.0f, 4.0f);

    glVertex3f(0.75f, 1.0f, 4.0f);
	glVertex3f(0.75f, 1.0f, 3.0f);
	glVertex3f(2.0f, 1.0f, 3.0f);
    glVertex3f(2.0f, 1.0f, 4.0f);  //---------- black box end

    glVertex3f(-0.25f, 1.0f, 3.5f);
	glVertex3f(-0.30f, 1.0f, 3.5f);
	glVertex3f(-0.30f, -1.0f, 3.5f);
    glVertex3f(-0.25f, -1.0f, 3.5f);  //---------- black stand
    glVertex3f(-0.25f, 1.0f, 3.48f);
	glVertex3f(-0.30f, 1.0f, 3.48f);
	glVertex3f(-0.30f, -1.0f, 3.48f);
    glVertex3f(-0.25f, -1.0f, 3.48f);  //---------- black stand

    glVertex3f(-7.25f, -1.0f, 4.5f);
	glVertex3f(-7.25f, -1.0f, 1.0f);
	glVertex3f(6.25f, -1.0f, 1.8f);
    glVertex3f(6.25f, -1.0f, 4.5f);

    glVertex3f(-7.25f, -0.8f, 4.5f);
	glVertex3f(-7.25f, -0.8f, 1.0f);
	glVertex3f(6.25f, -0.8f, 1.8f);
    glVertex3f(6.25f, -0.8f, 4.5f);

    glVertex3f(-7.25f, -0.8f, 4.5f);
	glVertex3f(-7.25f, -1.0f, 4.5f);
	glVertex3f(-7.25f, -1.0f, 1.0f);
    glVertex3f(-7.25f, -0.8f, 1.0f);

    glVertex3f(6.25f, -0.8f, 4.5f);
	glVertex3f(6.25f, -1.0f, 4.5f);
	glVertex3f(6.25f, -1.0f, 1.8f);
    glVertex3f(6.25f, -0.8f, 1.8f);


    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,1,0.4);
    glVertex3f(-0.25f, 1.0f, 3.49f);
	glVertex3f(0.20f, 1.0f, 3.49f);
	glVertex3f(0.20f, 0.65f, 3.49f);
    glVertex3f(-0.25f, 0.65f, 3.49f);  //---------- flag


    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-0.18f, 0.85f, 3.49f);
	glVertex3f(0.02f, 0.85f, 3.49f);
	glVertex3f(0.02f, 0.75f, 3.49f);
	glVertex3f(-0.18f, 0.75f, 3.49f);
    glVertex3f(-0.1f, 0.88f, 3.49f);
	glVertex3f(0.02f, 0.85f, 3.49f);
	glVertex3f(-0.1f, 0.75f, 3.49f);
	glVertex3f(-0.18f, 0.85f, 3.49f);
    glColor3f(0,0,0);
     glVertex3f(-7.25f, -0.7f, 6.5f);
	glVertex3f(-7.30f, -0.7f, 6.5f);
	glVertex3f(-7.30f, -1.0f, 6.5f);
    glVertex3f(-7.25f, -1.0f, 6.5f);  //----------  tree black stand
    glVertex3f(-7.25f, -0.7f, 6.48f);
	glVertex3f(-7.30f, -0.7f, 6.48f);
	glVertex3f(-7.30f, -1.0f, 6.48f);
    glVertex3f(-7.25f, -1.0f, 6.48f);  //---------- tree black stand



    glEnd();

glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(-7.27,-0.5,6.49);
    glutSolidSphere(0.25,10,10);
    glPopMatrix;

    Ground();






	glutSwapBuffers();
}

void update(int value) {
	_angle += 1.5f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
void processSpecialKeys(int key, int x, int y) {

	switch(key) {
		case GLUT_KEY_F1 : R = 0.0; G = 0.4; B = 1.0;
             dayLight();
			break;
		case GLUT_KEY_F2 : R = 0.0; G = 0.0; B = 0.0;
              night = 1;

			break;

	}
}
int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);


	//Create the window
	glutCreateWindow("table bookshelf with books");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);


	//adding here the setting of keyboard processing

	glutSpecialFunc(processSpecialKeys);
	update(0);

	glutMainLoop();
	return 0;
}









