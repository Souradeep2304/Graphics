
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void draw(void)
{
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	glColor3f(1, 0, 0);

	glBegin(GL_LINE_STRIP);
		glVertex2f(100, 100);
		glVertex2f(300, 100);
		glVertex2f(300, 300);
		glVertex2f(100, 300);
		glVertex2f(100, 100);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex2f(100, 300);
		glVertex2f(300, 300);
		glVertex2f(200, 400);
		glVertex2f(100, 300);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex2f(200, 400);
		glVertex2f(500,400);
		glVertex2f(600,300);
		glVertex2f(300, 300);
	glEnd();
	glBegin(GL_LINE_STRIP);
		glVertex2f(600,300);
		glVertex2f(600,100);
		glVertex2f(300,100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(310,320);
		glVertex2f(550,320);
		glVertex2f(490,380);
		glVertex2f(250,380);
		
		
	glEnd();
	glFlush();
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(30, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("First OpenGL Program");
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}

