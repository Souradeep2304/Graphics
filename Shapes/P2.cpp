#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
void display(int x, int y)
{
	glColor3f(0, 255, 255);
	glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x+100, y-50);
		glVertex2f(x+200, y);
		glVertex2f(x+200, y+100);
		glVertex2f(x+100, y+150);
		glVertex2f(x, y+100);
	glEnd();
}

void display1(int x, int y)
{
	glColor3f(255, 0, 255);

	glBegin(GL_LINE_STRIP);
		glVertex2f(x, y);
		glVertex2f(x+100, y-50);
		glVertex2f(x+200, y);
		glVertex2f(x+200, y+100);
		glVertex2f(x+100, y+150);
		glVertex2f(x, y+100);
		glVertex2f(x, y);
	glEnd();
}

void draw(void)
{
	int x;
	int y;
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	
	display(100,200);
	display1(100,200);

	glFlush();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(30, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Hexagon");
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

