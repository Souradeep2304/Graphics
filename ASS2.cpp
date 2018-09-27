#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h> 

GLint a,b,c,d;
int a1,b1,c1,d1;




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
int i=0;

void mouse(int button, int state, int mx, int my)
{


if(button == GLUT_LEFT_BUTTON && state==GLUT_DOWN)

{
a=mx;
b=480-my;
a1=mx;
b1=480-my;
}


else if(button == GLUT_LEFT_BUTTON && state==GLUT_UP)
{
c=mx;
d=480-my;
c1=mx;
d1=480-my;


display(a,b,c,d,0,0,1);


glFlush();
}

}

int h=1;int g=1;int l=1;

void draw(void)
{
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	//xaxis();
	//yaxis();
	
char string1[64]="Shivansh Thapliyal";
char string2[64]="Souradeep Banerjee";

char string7[64]="CG Assignment 2";

	name(0.0f,25.0f,string1,1,0,0);
	name(0.0f,50.0f,string2,0,1,0);

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



int a2,b2,c2,d2,temp;

void liangBrask(int a1, int b1, int c1, int d1)
{
int d1x=c1-a1;
int d1y=d1-b1;
int xwmin=160;
int ywmin=120;
int xwmax=480;
int ywmax=360;

int P[4],q[4];




P[1]=-d1x;	q[1]=d1x-xwmin;
P[2]=d1x;	q[2]=xwmax-d1x;
P[3]=-d1y;	q[3]=d1y-ywmin;
P[4]=d1y;	q[4]=ywmax-d1y;


for(int i=0;i<4;i++)
    {
        if(P[i]==0)
        {
            
            if(q[i]>=0)
            {
                if(i<2)
                {
                    if(b1<ywmin)
                    {
                        b1=ywmin;
                    }
                
                    if(d2>ywmax)
                    {
                        d2=ywmax;
                    }
                
                    display(a1,b1,c1,d1,0,5,1);

                }
                
                if(i>1)
                {
                    if(a1<xwmin)
                    {
                       a1=xwmin;
                    }
                    
                    if(c2>xwmax)
                    {
                        c2=xwmax;
                    }
                    
                    display(a1,b1,c1,d1,0,5,1);

                }
            }
        }
    }
    
    int t1=0;
    int t2=1;
    
    for(int i=0;i<4;i++)
    {
        temp=q[i]/P[i];
        
        if(P[i]<0)
        {
            if(t1<=temp)
                t1=temp;
        }
        else
        {
            if(t2>temp)
                t2=temp;
        }
    }
    
    if(t1<t2)
    {
        a2 = a1 + t1 * P[1];
        c2 = a1 + t2 * P[1];
        b2 = c1 + t1 * P[3];
        d2 = c1 + t2 * P[3];
        display(a2,b2,c2,d2,0,5,1);

    }
    


}

void keyboard(unsigned char key, int x, int y)
{
switch(key)
{
case 'c':

glColor3f(1,1,0);
	glBegin(GL_LINE_STRIP);
		glVertex2f(160.0f,120.0f);
		glVertex2f(480.0f,120.0f);
		glVertex2f(480.0f,360.0f);
		glVertex2f(160.0f,360.0f);
glVertex2f(160.0f,120.0f);
	glEnd();

liangBrask(a1,b1,c1,d1);

glFlush();

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

