#include <GL/glut.h>
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
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	/*glBegin(GL_LINES);
	glVertex2f(0.1, 0.1);
	glVertex2f(0.400, 0.400);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);

                glColor3f(1.0f, 0.0f, 0.0f);
                glVertex3f(-1.0f, -0.5f, -1.0f);    // A

                glColor3f(0.0f, 1.0f, 0.0f);
                glVertex3f( 1.0f, -0.5f, -1.0f);    // B

                glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f( 0.0f,  0.5f, -1.0f);    // C

	        glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f( 0.0f,  0.5f, -1.0f);    // C

		glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f( 0.0f,  0.5f, -1.0f);    // C

	        glColor3f(0.0f, 0.0f, 1.0f);
                glVertex3f( 0.0f,  0.5f, -1.0f);    // C

    glEnd();*/


	glPointSize(20);
	glBegin(GL_POINTS);
		glVertex2f(-0.8,0.8);
		glVertex2f(0.8,0.8);
		glVertex2f(0.8,-0.8);
		glVertex2f(-0.8,-0.8);
	glEnd();
	glColor3f(0,1,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.8,0.8);
		glVertex2f(0.8,0.8);
		glVertex2f(0.8,-0.8);
		glVertex2f(-0.8,-0.8);
	glEnd();


	glFlush();
}


void main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("line drawing in opengl");
	//init2D(0.0, 0.0, 0.0);  // uncomment to draw in pixels otherwise use normalizaed(0-1) value for vertex functions
	glutDisplayFunc(display);
	glutMainLoop();
}
