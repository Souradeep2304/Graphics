#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 
GLint a,b,c,d;
void yaxis()
{
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
glVertex2f(320,0);
glVertex2f(320,480);
glEnd();

}
void xaxis()
{
glColor3f(1,1,1);
glBegin(GL_LINE_STRIP);
glVertex2f(640,240);
glVertex2f(0,240);
glEnd();

}
  void put (int x, int y,int a,int b,int c)  
 {  
   glColor3f (a,b,c); 
   glBegin (GL_POINTS);  
   glVertex2i (x, y);   
   glEnd ();  
   glFlush ();  
  } 

void display(int x0, int y0, int x1, int y1,int a, int b, int c)
{
   int dx = abs (x1 - x0);  
  int dy = abs (y1 - y0);  
  int x, y;  
  if (dx >= dy)  
  {  
   int d = 2*dy-dx;  
   int ds = 2*dy;  
   int dt = 2*(dy-dx);  
       if (x0 < x1)   
      {  
            x = x0;  
            y = y0;  
       }  
       else  
        {   
             x = x1;  
            y = y1;  
             x1 = x0;  
            y1 = y0;  
        }  
      put (x, y,a,b,c);  
   while (x < x1)  
  {  
        if (d < 0)  
        d += ds;  
       else {  
            if (y < y1) {  
              y++;  
             d += dt;  //pk+1=pk + 2*(dy-dx)
             }   
            else {  
              y--;  
           d += dt;  //pk+1=pk + 2*(dy-dx)
          }  
            }  
   x++;  
       put (x, y,a,b,c);  
      }  
       }  
       else {   
            int d = 2*dx-dy;  
             int ds = 2*dx;  
             int dt = 2*(dx-dy);  
            if (y0 < y1) {  
           x = x0;  
           y = y0;  
             }  
             else {   
           x = x1;  
             y = y1;  
             y1 = y0;  
             x1 = x0;  
            }  
            put (x, y,a,b,c);   
       while (y < y1)  
        {  
             if (d < 0)  
                 d += ds;  
             else {  
                     if (x > x1){  
                     x--;  
                      d += dt;   //pk+1=pk+2*(dx-dy)
                   } else {  
                     x++;  
                     d += dt;  //pk+1=pk+2*(dx-dy)
                   }  
              }  
              y++;  
              put (x, y,a,b,c);  
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


void mouse(int button, int state, int mx, int my)
{


if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)

{
a=mx;
b=480-my;
}


else if(button == GLUT_LEFT_BUTTON && state==GLUT_UP)
{
c=mx;
d=480-my;
display(a,b,c,d,0,0,1);
//printf("%d %d %d %d",a,b,c,d);

glFlush();
}
}



void draw(void)
{
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0.0f, 640.0f, 0.0f,480.0f);
	xaxis();
	yaxis();
	
char string1[64]="Shivansh Thapliyal";
char string2[64]="Souradeep Banerjee";
char string3[64]="Shishir Goyal";
char string4[64]="Siddharth Sharma";
char string5[64]="X";
char string6[64]="Y";
char string7[64]="CG Assignment";

	name(0.0f,25.0f,string1,1,0,0);
	name(0.0f,50.0f,string2,0,1,0);
	name(0.0f,75.0f,string3,255,165,0);
	name(0.0f,100.0f,string4,0,0,1);
	name(320.f,460.0f,string7,255,0,0);
	//name(5,475,string5,1,1,1);
	//name(475,5,string6,1,1,1);
glFlush();

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
//init();
	glutMainLoop();
	return 0;
}

