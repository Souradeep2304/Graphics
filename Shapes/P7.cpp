// Shrinking and Expanding

#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <stdbool.h>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
void display(int x, int y, int i)
{
	glColor3f(0, 1, 0);
	
	glBegin(GL_LINE_STRIP);
		glVertex2f(x+i, y+i);
		glVertex2f((x+300)-i, y+i);
		glVertex2f((x+300)-i, (y+100)-i);
		glVertex2f(x+i, (y+100)-i);
		glVertex2f(x+i, y+i);
	glEnd();
}

void draw(void)
{
static bool flag=false;
	static float i=0;
	static float a=100,b=100;

	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	glColor3f(1, 0, 0);


display(a,b,i);
if(i<=40 && flag == false)
{
i=i+0.1;
//printf("%f\n",i);
}
if(i > 40)
{
flag=true;
}

if(i>0 && flag == true)
{
i=i-0.1;
//printf("%f\n",i);
}
if(i < 0)
{
flag=false;
}

glutPostRedisplay();


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

