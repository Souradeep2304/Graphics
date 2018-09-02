#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <stdlib.h>
void yaxis()
{
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
glVertex2f(0,-100);
glVertex2f(0,100);
glEnd();

}
void xaxis()
{
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
glVertex2f(100,0);
glVertex2f(-100,0);
glEnd();

}


void display(int x0, int y0, int x1, int y1,int a, int b, int c)
{
   float x=x0,y=y0;
   float dy=(float)(abs(y1)-abs(y0));
   float dx=(float)(abs(x1)-abs(x0));

if(dy<dx)
{
   float p=2*dy-dx;
 if(x1>x)
{
  if(y1>y)
{
    while(x<=x1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        x=x+1;
    }
}
if(y1<y)
{
while(x<=x1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            y=y-1;
            p=p+2*dy-2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        x=x+1;
    }
}
	

}
 if(x1<x)
{
  if(y1>y)
{
    while(x!=x1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        x=x-1;
    }
}
if(y1<y)
{
while(x!=x1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            y=y-1;
            p=p+2*dy-2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        x=x-1;
    }
}
	

}
}

if(dy>dx)
{
   float p=2*dx-dy;
 if(x1>x)
{
  if(y1>y)
{
    while(y<=y1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            x=x+1;
            p=p+2*dy+2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        y=y+1;
    }
}
if(y1<y)
{
while(y!=y1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            x=x+1;
            p=p+2*dy+2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        y=y-1;
    }
}
	

}
 if(x1<x)
{
  if(y1>y)
{
    while(y<=y1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            x=x-1;
            p=p+2*dy+2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        y=y+1;
    }
}
if(y1<y)
{
while(y!=y1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            x=x-1;
            p=p+2*dy+2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(a,b,c);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        y=y-1;
    }
}
	

}
}





}


void name(int x, int y, char String[], int a, int b, int c)
{
    glColor3f(a,b,c);
    glRasterPos2i(x,y);
    int l=strlen(String);
    for (int i=0; i<l; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
}

void draw(void)
{
	static int a=100;
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0,100.0);
	char string1[64]="Shivansh Thapliyal";
	char string2[64]="Souradeep Banerjee";
	char string3[64]="Shishir Goyal";
	char string4[64]="Siddharth Sharma";
	char string5[64]="X";
	char string6[64]="Y";

    	name(-100,-99,string1,1,0,0);
	name(-100,-90,string2,0,1,0);
	name(-100,-80,string3,255,165,0);
	name(-100,-70,string4,0,0,1);
	name(5,95,string5,1,1,1);
	name(95,5,string6,1,1,1);

	display(10,10,40,30,1,0,0);
	display(10,30,50,90,1,0,0);
	display(-10,30,-20,60,255,165,0);
	display(-10,10,-50,20,255,165,0);
	display(-20,-10,-35,-20,0,1,0);
	display(-10,-40,-30,-70,0,1,0);
	display(10,-10,25,-55,0,0,1);
	display(35,-25,55,-30,0,0,1);
	

	
	
	xaxis();
	yaxis();
	glFlush();

}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(30, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Assignment");
 	
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

