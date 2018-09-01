#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void display(int x, int y, int a, int b)
{	static int i,j;
	j=y;
	i=x;
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	while(j<=b)
	{
		while(i<=a)
		{
		


			glVertex2f(i,j);
			j++;
			i++;
		}
		
	}
	glEnd();
	
	
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

	display(100,100,300,100);
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

