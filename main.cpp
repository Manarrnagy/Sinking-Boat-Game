#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>
#define PI 3.1415927

float translatex; //used in boat animation
float rotatez=0; //used in boat falling movement
float star1=0; // used in stars animation
float star2=1;// used in stars animation
float crack1=0.1; // the crack in the ship color
float crack2=0.7;

//---------------------Draws the cylinders(Funnels of the ship)------------------------
void draw_cylinder(GLfloat radius,GLfloat height,GLubyte R,GLubyte G,GLubyte B)
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;

    /** Draw the tube */
    glColor3ub(R-0,G-100,B-100);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            glVertex3f(x, y , 0.0);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
        glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /* Draw the circle on top of cylinder */
    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height);
    glEnd();
}

//----------------------------Mouse clicking function------------------------
void onMouseClick(int button,int state,int x,int y){
    //when the left button is clicked the ship is moved one spot in the +ve x-axis
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        translatex ++;
        //when the ship moves 3 spots, it hits the ice and starts to sink into the sea
        if(translatex==3){
            rotatez=rotatez-1.5;
            crack1=0.0;
            crack2=0.0;
        }
    }

}

//------------------------------  reshapeFunc  ---------------------------------
//sets the reshape callback for the current window and the callback happens when the shapes are added to the window
void reshapeFunc (int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}
//-----------------------------   Timer   ------------------------------------
//changes the color of the stars every 0.5 second and does a recursion on itself so it keeps changing colors every 0.5 seconds
void timer(int){
    glutPostRedisplay();//redisplays the current window
    glutTimerFunc(500,timer,0);
    //Changes the color of stars from black to white and vice versa every 0.5 seconds
    if(star1==0){
        star1++;
        }
    else{
        star1--;
    }
    if(star2==0){
        star2++;
        }
    else{
        star2--;
    }
    }
//------------------------------  display Function  -------------------------------

void display (void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//it clears the buffers
    glLoadIdentity ();//it loads the identity matrix and replaces the current matrix
    glTranslatef(0.0, 0.0, -15.0);//moves the object -15 in z axis

    //Sphere(Moon)
    //the push and pop matrix functions takes one object and apply all changes to that object only
    glPushMatrix();
    glTranslatef(-4,4,0);//moves the object
    glColor3f(1.0f, 1.0f, 0.8f);//sets the color of the object
    glutSolidSphere(0.6,60,60);//draws a sphere
    glPopMatrix();

    //Stars
    //the push and pop matrix functions takes one object and apply all changes to that object only
    glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);//rotates by angle 45 on yz plane
    glColor3f(star2, star2, star2);//the star2 changes by timer from black to white and vice versa
    glTranslatef(4,3.0,1.0);//moves the object
    glScalef(0.1,0.1,0.0);//changes the dimensions of the object with a certain scale
    glutSolidOctahedron();//draws an octahedron
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(5,2,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(-2,4,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(7,1,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(5,1,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(3,4,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(4,1,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(-1,6,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(2,2,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(-3,4,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(4,1,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(-2,5,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(2,1,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(0,5,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(3,3,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(2,5,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(1,2,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(-1,3,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(1,6,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(0,3,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

     glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(1,7,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star2, star2, star2);
    glTranslatef(0.5,4,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();

      glPushMatrix();
    glRotatef(45.0,0.0f, 0.3f, 0.5f);
    glColor3f(star1, star1, star1);
    glTranslatef(1.5,5.5,1.0);
    glScalef(0.1,0.1,0.0);
    glutSolidOctahedron();
    glPopMatrix();


glRotatef(10,0.0,0.0,rotatez);//rotates the boat (the rest of the display code) by angle 10 and when the boat moves 3 spaces and hits the ice it move in the z axis(sinks in the water)

 //------------------Boat's Bottom part--------------------
     glBegin(GL_QUADS);
      // Top face
        glColor3f(0.1f, 0.1f, 0.7f);//sets the color of the top face of the ship
        //position of the points(the translate x is a variable for the movement of the ship when clicking on the mouse)
        glVertex3f(2.0f+translatex-2, 1.0f, 2.0f);
        glVertex3f(2.0f+translatex-2, 1.0f, -2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, -2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, 1.0f);

        // Bottom face
        glColor3f(0.1f, 0.1f, 0.7f);
        glVertex3f(-1.0f+translatex-2, -1.0f, -2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, -2.0f);
        glVertex3f(1.0f+translatex-2, -1.0f, -2.0f);
        glVertex3f(1.0f+translatex-2, -1.0f, 2.0f);

        // Front face
        glColor3f(0.9f, 0.9f, 0.7f);
        glVertex3f(2.0f+translatex-2, 1.0f, 2.0f);
        glVertex3f(-2.0f+translatex-2, 1.0f, 2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, 2.0f);
        glVertex3f(1.0f+translatex-2, -1.0f, 2.0f);

        // Back face
        glColor3f(0.1f, 0.1f, 0.7f);
        glVertex3f(2.0f+translatex-2, 1.0f, -2.0f);
        glVertex3f(-2.0f+translatex-2, 1.0f, -2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, -2.0f);
        glVertex3f(1.0f+translatex-2, -1.0f, -2.0f);

        // Left face
        glColor3f(0.1f, 0.1f, 0.7f);
        glVertex3f(-2.0f+translatex-2, 1.0f, 2.0f);
        glVertex3f(-2.0f+translatex-2, 1.0f, -2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, -2.0f);
        glVertex3f(-1.0f+translatex-2, -1.0f, 2.0f);

        // Right face
        glColor3f(0.1f, 0.1f, 0.7f);
        glVertex3f(2.0f+translatex-2, 1.0f, -2.0f);
        glVertex3f(2.0f+translatex-2, 1.0f, 2.0f);
        glVertex3f(1.0f+translatex-2, -1.0f, 2.0f);
        glVertex3f(1.0f+translatex-2, -1.0f, -2.0f);

   glEnd();
    //-------------------------cuboid(Boat's middle part)------------------------
      glBegin(GL_QUADS);
      // Top face
        glColor3f(1.0f, 0.0f, 0.0f);//sets the color to red
        //position of the points(the translate x is a variable for the movement of the ship when clicking on the mouse)
        glVertex3f(1.5f+translatex-2, 1.0f, -1.0f);
        glVertex3f(-1.5f+translatex-2, 1.0f, -1.0f);
        glVertex3f(-1.5f+translatex-2, 1.0f, 1.0f);
        glVertex3f(1.5f+translatex-2, 1.0f, 1.0f);

        // Bottom face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.5f+translatex-2, 1.5f, 1.0f);
        glVertex3f(-1.5f+translatex-2, 1.5f, 1.0f);
        glVertex3f(-1.5f+translatex-2, 1.5f, -1.0f);
        glVertex3f(1.5f+translatex-2, 1.5f, -1.0f);

        // Front face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.5f+translatex-2, 1.0f, 1.0f);
        glVertex3f(-1.5f+translatex-2, 1.0f, 1.0f);
        glVertex3f(-1.5f+translatex-2, 1.5f, 1.0f);
        glVertex3f(1.5f+translatex-2, 1.5f, 1.0f);

        // Back face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.5f+translatex-2, 1.5f, -1.0f);
        glVertex3f(-1.5f+translatex-2, 1.5f, -1.0f);
        glVertex3f(-1.5f+translatex-2, 1.0f, -1.0f);
        glVertex3f(1.5f+translatex-2, 1.0f, -1.0f);

        // Left face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.5f+translatex-2, 1.0f, 1.0f);
        glVertex3f(-1.5f+translatex-2, 1.0f, -1.0f);
        glVertex3f(-1.5f+translatex-2, 1.5f, -1.0f);
        glVertex3f(-1.5f+translatex-2, 1.5f, 1.0f);

        // Right face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.5f+translatex-2, 1.0f, -1.0f);
        glVertex3f(1.5f+translatex-2, 1.0f, 1.0f);
        glVertex3f(1.5f+translatex-2, 1.5f, 1.0f);
        glVertex3f(1.5f+translatex-2, 1.5f, -1.0f);

   glEnd();  // End of drawing cuboid(Middle part of the boat)

   //--------------------cuboid(upper part of the boat)-------------------
         glBegin(GL_QUADS);
      // Top face
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.25f+translatex-2, 2.0f, -1.0f);
        glVertex3f(-1.25f+translatex-2,2.0f, -1.0f);
        glVertex3f(-1.25f+translatex-2, 2.0f, 1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, 1.0f);

        // Bottom face
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, 1.0f);
        glVertex3f(-1.25f+translatex-2, 1.5f, 1.0f);
        glVertex3f(-1.25f+translatex-2,  1.5f, -1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, -1.0f);

        // Front face
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.25f+translatex-2, 2.0f, 1.0f);
        glVertex3f(-1.25f+translatex-2, 2.0f, 1.0f);
        glVertex3f(-1.25f+translatex-2,  1.5f, 1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, 1.0f);

        // Back face
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, -1.0f);
        glVertex3f(-1.25f+translatex-2,  1.5f, -1.0f);
        glVertex3f(-1.25f+translatex-2, 2.0f, -1.0f);
        glVertex3f(1.25f+translatex-2, 2.0f, -1.0f);

        // Left face
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.25f+translatex-2, 2.0f, 1.0f);
        glVertex3f(-1.25f+translatex-2, 2.0f, -1.0f);
        glVertex3f(-1.25f+translatex-2,  1.5f, -1.0f);
        glVertex3f(-1.25f+translatex-2,  1.5f, 1.0f);

        // Right face
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.25f+translatex-2, 2.0f, -1.0f);
        glVertex3f(1.25f+translatex-2, 2.0f, 1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, 1.0f);
        glVertex3f(1.25f+translatex-2,  1.5f, -1.0f);

   glEnd();  // End of drawing cuboid

   // crack in ship
   glBegin(GL_POLYGON);
   glColor3f(crack1, crack1, crack2);
   glVertex3f(1.1f+translatex-2, -1.1f, 1.0f);
   glVertex3f(1.0f+translatex-2, -1.0f, 1.0f);
   glVertex3f(1.0f+translatex-2, -0.1f, 1.0f);
   glVertex3f(0.8f+translatex-2, -0.4f, 1.0f);
   glVertex3f(0.5f+translatex-2, -1.1f, 1.0f);
   glEnd();

   //--------------Windows-----------------------------
     glBegin(GL_POLYGON);//first window
        glColor3f(0.8f,0.9f,0.9f);//sets a color to the window
        //position of the points(the translate x is a variable for the movement of the ship when clicking on the mouse)
        glVertex2f(1.30f+translatex-2, 1.30f);
        glVertex2f(0.70f+translatex-2, 1.30f);
        glVertex2f(0.70f+translatex-2, 1.05f);
        glVertex2f(1.30f+translatex-2, 1.05f);
        glEnd();

    glBegin(GL_POLYGON);//second window
        glColor3f(0.8f,0.9f,0.9f);
        glVertex2f(0.45f+translatex-2, 1.30f);
        glVertex2f(-0.15f+translatex-2, 1.30f);
        glVertex2f(-0.15f+translatex-2, 1.05f);
        glVertex2f(0.45f+translatex-2, 1.05f);
    glEnd();

      glBegin(GL_POLYGON);//third window
        glColor3f(0.8f,0.9f,0.9f);
        glVertex2f(-0.40f+translatex-2, 1.30f);
        glVertex2f(-1.0f+translatex-2, 1.30f);
        glVertex2f(-1.0f+translatex-2, 1.05f);
        glVertex2f(-0.40f+translatex-2, 1.05f);
    glEnd();

    //------------------Floaties(rings)--------------------------
    //the push and pop matrix functions takes one object and apply all changes to that object only
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);//sets the color
    glTranslatef(-1+translatex-2,0.5,0); //position of the object(the translate x is a variable for the movement of the ship when clicking on the mouse)
    glutSolidTorus(0.06,0.2,200,200);//draws torus (the rings on the ship)
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
     glTranslatef(0+translatex-2,0.5,0);
    glutSolidTorus(0.06,0.2,200,200);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(1+translatex-2,0.5,0);
    glutSolidTorus(0.06,0.2,200,200);
    glPopMatrix();

    //------------(Cylinders)Funnel------------------------------
    //the push and pop matrix functions takes one object and apply all changes to that object only
    glPushMatrix();
    glTranslatef(-0.8+translatex-2,2.4,1.0); //position of the points(the translate x is a variable for the movement of the ship when clicking on the mouse)
    glRotatef(90.0, 1.0f, 0.0f, 0.0f);//rotates the cylinder by 90 degrees on the x axis
    draw_cylinder(0.15, 0.4, 255, 160, 100); // draws cylinder 1 by calling this function
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0+translatex-2,2.3,1.75);
    glRotatef(90.0, 1.0f, 0.0f, 0.0f);
    draw_cylinder(0.15, 0.4, 255, 160, 100);// draws cylinder 2 by calling this function
    glPopMatrix();

    glPushMatrix();
     glTranslatef(0.8+translatex-2,2.3,1.75);
     glRotatef(90.0, 1.0f, 0.0f, 0.0f);
     draw_cylinder(0.15, 0.4, 255, 160, 100); //draws cylinder 3 by calling this function
     glPopMatrix();

glRotatef(10,0.0,0.0,-rotatez);//rotates the ice (the rest of the display code) by angle 10

    //Ice
    //the push and pop matrix functions takes one object and apply all changes to that object only
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);//sets the color of the ice
    glTranslatef(3.5,-1,0);//sets the position of the ice
    glutSolidDodecahedron();//draws a dodecahedron
    glPopMatrix();

    //------------The sea(Rectangle)-------------------------
    //the blend and depth and color4f are all used for making the sea transparent
      glEnable( GL_BLEND );//it enables blending of the incoming color with the color in the buffer
      glDepthMask( GL_FALSE );//specifies that the depth buffer is disabled
      glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
      glBegin(GL_POLYGON);
        glColor4f(0.0f,0.3f,0.9f,0.5f);//sets the color and transparency of the sea
        //puts the points of the sea
        glVertex2f(15.0f, -0.50f);
        glVertex2f(15.0f, -6.0f);
        glVertex2f(-15.0f, -6.0f);
        glVertex2f(-15.0f, -0.50f);
    glEnd();
    glDepthMask( GL_TRUE );//enables the depth buffer again
    glDisable( GL_BLEND );//disables the blending buffer after this part

    glutSwapBuffers();//instructs the computer that you are done with this frame and that it should swap the buffers to display the frame
}

//--------------------------------  idleFunc  ----------------------------------

void idleFunc (void)
{
    glutPostRedisplay();//it marks that the window needs to be redisplayed in every iteration of the main loop
}

//----------------------------------  main Function  ------------------------------------
int main (int argc, char **argv)
{
    glutInit(&argc, argv);//used to initialize glut library
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//sets the type of display mode
    glutInitWindowSize     (800, 700);//sets the size of the window
    glutInitWindowPosition (700, 200);//sets where the window appears on the screen
    glutCreateWindow ("18101888-18102985");//sets a name to the window
    glutDisplayFunc (display);//calls the display function and executes it
    glutReshapeFunc (reshapeFunc);//sets the reshape callback for the current window and the callback happens when the shapes are added to the window
    glutIdleFunc    (idleFunc);//it marks that the window needs to be redisplayed in every iteration of the ma
    glutTimerFunc(0,timer,0);//calls timer function
    glClearColor(0.2,0.1,0.3,1);//Sets the background color of the sky
    glutMouseFunc(onMouseClick);//executes the on mouse click function

    glutMainLoop();//it keeps the window open as it keeps calling the display function
}

