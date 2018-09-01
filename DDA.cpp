#include <math.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
static int e,f;
void display(int x1, int y1, int a, int b)
{		
	float x=x1,y=y1;
	float m=(float)(b-y1)/(a-x1);
while(x<=a)
{
	if (m >1)
{
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(x,y);
	glEnd();
	x=x+(float)(1/m);
	y=y+1;
}
	else
{   	
	glBegin(GL_POINTS);
	glColor3f(1, 0, 0);
	glVertex2f(x,y);
	glEnd();
	x=x+1;
	y=y+m;
}	
}
	
}
const int SCREEN_WIDTH = 200;
const int SCREEN_HEIGHT = 200;

void draw(void)
{
	static int a=100;
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	display(100,100,400,300);
	glFlush();

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

