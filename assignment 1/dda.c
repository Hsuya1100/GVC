#include <GL/glut.h>

int abs (int n) {
	if (n>0) {
		return n;
	} else {
		return n * (-1);
	}
} 

void DDA(int X0, int Y0, int X1, int Y1) 
{ 
	// calculate dx & dy 
	int dx = X1 - X0; 
	int dy = Y1 - Y0; 

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 

	// calculate increment in x & y for each steps 
	float Xinc = dx / (float) steps; 
	float Yinc = dy / (float) steps; 

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1);
	glBegin(GL_POINTS);
	float X = X0; 
	float Y = Y0; 
		for (int i = 0; i <= steps; i++) 
		{
			// Put pixel for each step
   			glVertex2f(X,Y);
			X += Xinc;
			Y += Yinc;
		} 
	glEnd();
	glFlush();
} 
void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 600, 0.0, 600);
}
void display(void)
{
	DDA(1,1,100,100);

}
void main (int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("line drawing in opengl attempt 1");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}
