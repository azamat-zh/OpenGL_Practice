// Lab - 9 Planetary System
// This is where we are still learning about Painter's principle
// All we were asked to do is GL_DEPTH_TEST

#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

static int year = 0, day = 0;

void myInit(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}

void myDisplay(void)
{
    glEnable(GL_DEPTH_TEST); // The function that makes GPU automatically calculate the deapth
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	glPushMatrix();

	glColor3f(1.0,1.0,1.0);
	glTranslatef(0.0,0.0,0.0);
	glutSolidSphere(1.0,20,16); // draw the Sun
	glRotatef((GLfloat) year, 0.0,1.0,0.0);

	glRotatef((GLfloat) day, 0.0,1.0,0.0);
	glTranslatef(2.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glutWireTorus(0.1, 0.2, 10, 8); // draw smaller planet

    glRotatef((GLfloat) day, 1.0,0.0,0.0);
	glTranslatef(-4.0,0.0,0.0);
	glColor3f(0.0,1.0,0.0);
	glutWireCube(0.3); // draw smaller planet

    glRotatef((GLfloat) day, 0.0,1.0,0.0);
	glTranslatef(2.0,0.0,2.0);
	glColor3f(0.3,0.3,1.0);
	glutWireCone(0.2, 0.2, 8, 3); // draw smaller planet

    glRotatef((GLfloat) day, 0.0,1.0,0.0);
	glTranslatef(0.0,0.0,-4.0);
	glColor3f(0.8, 0.2, 0.4);
	glutWireTeapot(0.2); // draw smaller planet

	glPopMatrix();

	glutSwapBuffers();
}

void myReshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w / (GLfloat)h, 1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

void myKeyboard(unsigned char key, int x,int y)
{
	switch(key) {
	case 'd':
		day = (day + 10) % 360;
		glutPostRedisplay();
		break;

	case 'D':
		day = (day - 10) % 360;
		glutPostRedisplay();
		break;

	case 'y':
		year = (year + 5) % 360;
		glutPostRedisplay();
		break;

	case 'Y':
		year =(year - 5) % 360;
		glutPostRedisplay();
		break;

	case 27:
		exit(0);
		break;

	default:
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(400,100);
	glutInitWindowSize(500,500);
	glutCreateWindow("Planetary Systems");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	glutReshapeFunc(myReshape);
	myInit();
	glutMainLoop();
}

