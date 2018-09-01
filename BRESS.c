#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>

void display(int x0, int y0, int x1, int y1)
{
   float x=x0,y=y0;
   float m=(float)(y1-y0)/(x1-x0);
   float dy=(float)(y1-y0);
   float dx=(float)(x1-x0);
 
   float p=2*dy-dx;
 
    while(x<=x1)
    {
        if(p>=0)
        {
            glBegin(GL_POINTS);
	    glColor3f(1, 0, 0);
	    glVertex2f(x,y);
	    glEnd();
            y=y+1;
            p=p+2*dy-2*dx;
        }
        else
        {
            glBegin(GL_POINTS);
	    glColor3f(1, 0, 0);
	    glVertex2f(x,y);
	    glEnd();
            p=p+2*dy;
        }
        x=x+1;
    }
}

void draw(void)
{
	static int a=100;
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	unsigned char string[] = "The quick god jumps over the lazy brown fox."
int w;
w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(0.5, 0.5);
	glColor3f(1, 0, 0);
	int len = strlen(string);
for (int i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string);
}

	display(100,100,600,200);
	glFlush();

}
void name()
{
	
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(30, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Fourth OpenGL Program");
 	
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

