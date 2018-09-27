#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
const int INSIDE = 0; // 0000 
const int LEFT = 1;   // 0001 
const int RIGHT = 2;  // 0010 
const int BOTTOM = 4; // 0100 
const int TOP = 8;    // 1000 
const int x_max = 480; 
const int y_max = 360; 
const int x_min = 160; 
const int y_min = 120; 
GLint a,b,c,d;
int a1[500];
int b1[500];
int h=1;int g=1;int l=1;
int i=0;
int m=0;
int o=0;
int a2[500];int b2[500];
char string1[64]="Shivansh Thapliyal";
char string2[64]="Souradeep Banerjee";
char string3[64]="Yash Saraswat";

int max ( int a, int b ) { return a > b ? a : b; }
int min ( int a, int b ) { return a > b ? b : a; }



int reg(double x, double y) 
{ 
  
    int code = INSIDE; 
  
    if (x < x_min)     
        code |= LEFT; 
    else if (x > x_max)  
        code |= RIGHT; 
    if (y < y_min)      
        code |= BOTTOM; 
    else if (y > y_max)
        code |= TOP; 
  
    return code; 
} 

void intersect(double x1, double y1, 
                         double x2, double y2,int *u1, int *v1, int *u2,int *v2) 
{ 

    int code1 = reg(x1, y1); 
    int code2 = reg(x2, y2); 
 
    bool accept = false; 
  
    while (true) 
    { 
        if ((code1 == 0) && (code2 == 0)) 
        { 
  
            accept = true; 
            break; 
        } 
        else if (code1 & code2) 
        { 
  
            break; 
        } 
        else
        { 
        
            int code_out; 
            double x, y; 
  
 
            if (code1 != 0) 
                code_out = code1; 
            else
                code_out = code2; 
  
            if (code_out & TOP) 
            { 
         
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1); 
                y = y_max; 
            } 
            else if (code_out & BOTTOM) 
            { 
           
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1); 
                y = y_min; 
            } 
            else if (code_out & RIGHT) 
            { 
           
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1); 
                x = x_max; 
            } 
            else if (code_out & LEFT) 
            { 
          
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1); 
                x = x_min; 
            } 
  
     
            if (code_out == code1) 
            { 
                x1 = x; 
                y1 = y; 
                code1 = reg(x1, y1); 
            } 
            else
            { 
                x2 = x; 
                y2 = y; 
                code2 = reg(x2, y2); 
            } 
        } 
    } 
    if (accept) 
    { 
        *u1=x1;
	*u2=x2;
	*v1=y1;
	*v2=y2;
    } 
   
} 


  void put (int x, int y,int a,int b,int c)  
 {  
   glColor3f (a,b,c); 
   glBegin (GL_POINTS);  
   glVertex2i (x, y);   
   glEnd ();  
   glFlush ();  
  } 

void drawpol(int a[], int b[])
{
glColor3f (1,1,0);
glBegin(GL_LINE_STRIP);
for(int j=0;j<i;j++)
{
	glVertex2f(a[ j ],b[ j ] );
}
glVertex2f(a[0],b[0]);
glEnd();
glFlush();
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


void mouse(int button, int state, int mx, int my)
{


if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)
{
a=mx;
b=480-my;
a1[i]=a;
b1[i]=b;
i=i+1;
}
}





void draw(void)
{
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);

	


char string7[64]="CG Assignment 2";
	name(0.0f,75.0f,string2,1,0,0);	
	name(0.0f,25.0f,string1,0,0,5);
	name(0.0f,50.0f,string3,0,1,0);

glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);
		glVertex2f(160.0f,120.0f);
		glVertex2f(480.0f,120.0f);
		glVertex2f(480.0f,360.0f);
		glVertex2f(160.0f,360.0f);
glVertex2f(160.0f,120.0f);
	glEnd();
glFlush();

}




int a3[500];
int b3[500];



void printarr(int a[], int b[], int c[], int d[])
{
for(int n=0;n<o;n++)
{
printf("point:%d %d to point %d %d",a[n],b[n], c[n], d[n]);
printf("\n");

}
}

void points(int a[], int b[])
{
int u1, v1, u2, v2;

for(int m=0;m<i-1;m++)
{
intersect(a[m], b[m],a[m+1],b[m+1],&u1,&v1,&u2,&v2 );
a2[o]=u1;
b2[o]=v1;
a3[o]=u2;
b3[o]=v2;
o=o+1;
}

}


void drawlines(int a[], int b[], int c[], int d[])
{
glClearColor(0, 0, 0,0);
glClear(GL_COLOR_BUFFER_BIT);
name(0.0f,75.0f,string2,1,0,0);	
	name(0.0f,25.0f,string1,0,0,5);
	name(0.0f,50.0f,string3,0,1,0);

glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);
		glVertex2f(160.0f,120.0f);
		glVertex2f(480.0f,120.0f);
		glVertex2f(480.0f,360.0f);
		glVertex2f(160.0f,360.0f);
glVertex2f(160.0f,120.0f);
	glEnd();
glFlush();
glColor3f(0,0,139);
	glBegin(GL_LINE_STRIP);
for(int n=0;n<o;n++)
{
		glVertex2f(a[n],b[n]);
		glVertex2f(c[n],d[n]);
}
glEnd();
glColor3f(0,0,139);
	glBegin(GL_LINE_STRIP);
glVertex2f(c[o-1],d[o-1]);
glVertex2f(a[0],b[0]);
glEnd();
glFlush();
}


void keyboard(unsigned char key, int x, int y)
{
switch(key)
{
case 'c':

glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);
		glVertex2f(160.0f,120.0f);
		glVertex2f(480.0f,120.0f);
		glVertex2f(480.0f,360.0f);
		glVertex2f(160.0f,360.0f);
glVertex2f(160.0f,120.0f);
	glEnd();
glFlush();
drawpol(a1,b1);
break;
case 'd' :
points(a1,b1);
break;
case 'f' :
drawlines(a2,b2,a3,b3);
break;
}
}





int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200,200);
	glutInitWindowSize(640,480);
	glutCreateWindow("Assignment");
        glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

