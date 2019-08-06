#include <GL/glut.h>
// 1) Line is drawn from left to right. 
// 2) x1 < x2 and y1 < y2 
// 3) Slope of the line is between 0 and 1. 
// We draw a line from lower left to upper 
// right.
// function for line generation 
void bresenham(int x1, int y1, int x2, int y2) 
{ 
	int m_new = 2 * (y2 - y1); 
	int slope_error_new = m_new - (x2 - x1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1);
	glBegin(GL_POINTS); 
	for (int x = x1, y = y1; x <= x2; x++) 
	{
		glVertex2f(x,y);

		// Add slope to increment angle formed 
		slope_error_new += m_new; 

		// Slope error reached limit, time to 
		// increment y and update slope error. 
		if (slope_error_new >= 0) 
		{ 
			y++; 
			slope_error_new -= 2 * (x2 - x1); 
		} 
	} 
	glEnd();
	glFlush();
}
void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);
	// used to set up the view volume, GL_MODELVIEW can be used to set up viewing transformation
	glMatrixMode(GL_PROJECTION);
	// gluOrtho2D specifies the coordinates to be used with the viewport which defaults to the window size.
	gluOrtho2D(0.0, 600, 0.0, 600);
}
void display(void)
{
	bresenham(1,1,110,60);

}
void main (int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("line drawing in opengl attempt 2");
	init2D(0.0, 0.0, 0.0);  
	glutDisplayFunc(display);
	glutMainLoop();
}
