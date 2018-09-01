/*			first openGL program		*/
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
void display(int x, int y, int a, int b,int c)
{
	glColor3f(a, b, c);
	glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x+200, y);
		glVertex2f(x+200, y+200);
		glVertex2f(x, y+200);
	glEnd();
}

void draw(void)
{
	static float a=100,b=100;
	static float r=0,g=1,c=0;
	glClearColor(0, 0, 0,0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0,480.0);
	glColor3f(1, 0, 0);


display(a,b,r,g,c);
a=a+0.01;
b=b+0.01;
r=r+0.1;
g=g+0.1;
b=b+0.1;


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

