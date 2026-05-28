#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

float rtrix, rtriy, rtriz;
float tquadx;
float tquady;
float CR = 1.0;
float CG = 1.0;
float CB = 1.0;

void myInit(GLvoid) {
	glShadeModel(GL_SMOOTH);// smooth shading- Gouraud shading
	glClearColor(0.0f,0.0f,0.0f,0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);// stores fragments their z-values in the depth buffer
	glDepthFunc(GL_LEQUAL);// compare each incoming pixel depth value with the depth value present in the depth buffer
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();//()//reset projection
	glPushMatrix();
	glTranslatef(-1.5f,0.0f,-6.0f);
	glRotatef(rtrix,1.0f,0.0f,0.0f);
	glRotatef(rtriy,0.0f,1.0f,0.0f);
	glRotatef(rtriz,0.0f,0.0f,1.0f);

	glBegin(GL_POLYGON);
        glColor3f(0.4,0.0,0.8); //blue
		glVertex3f(0.0f,1.0f,-1.0f); //1st vertex
		glVertex3f(-1.0f,-1.0f,0.0f); //2nd vertex
		glVertex3f(1.0f,-1.0f,0.0f); //3rd vertex
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.0,0.9,0.2); //green
		glVertex3f(0.0f,1.0f,-1.0f); //1st vertex
		glVertex3f(1.0f,-1.0f,-2.0f); //2nd vertex
		glVertex3f(1.0f,-1.0f,0.0f); //3rd vertex
	glEnd();
    glBegin(GL_POLYGON);
        glColor3f(0.8,0.1,0.2); //red
		glVertex3f(0.0f,1.0f,-1.0f); //1st vertex
		glVertex3f(-1.0f,-1.0f,-2.0f); //2nd vertex
		glVertex3f(1.0f,-1.0f,-2.0f); //3rd vertex
	glEnd();
	glBegin(GL_POLYGON);
        glColor3f(0.2,0.2,0.2); //grey
		glVertex3f(0.0f,1.0f,-1.0f); //1st vertex
		glVertex3f(-1.0f,-1.0f,-2.0f); //2nd vertex
		glVertex3f(-1.0f,-1.0f,0.0f); //3rd vertex
	glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.2,0.6,0.2); //green
		glVertex3f(-1.0f,-2.0f,-2.0f); //1st vertex
		glVertex3f(-1.0f,-1.0f,-2.0f); //2nd vertex
		glVertex3f(-1.0f,-1.0f,0.0f); //3rd vertex
		glVertex3f(-1.0f,-2.0f,0.0f); //4th vertex
	glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.2,0.6,0.2); //green
		glVertex3f(-1.0f,-2.0f,-2.0f); //1st vertex
		glVertex3f(-1.0f,-1.0f,-2.0f); //2nd vertex
		glVertex3f(-1.0f,-1.0f,0.0f); //3rd vertex
		glVertex3f(-1.0f,-2.0f,0.0f); //4th vertex
	glEnd();

	glLoadIdentity();
	glTranslatef(1.5f,0.0f,-6.0f);
	glTranslatef(tquadx,tquady,0.0f);
	glColor3f(CR,CG,CB);

	glPopMatrix();
	glutSwapBuffers();
}

void myReshape(int w, int h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (h == 0)
		gluPerspective(80,(float)w,1.0,5000);
	else
		gluPerspective(80,(float)w / (float)h,1.0,5000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myKeyboard(unsigned char key, int x, int y) {
	switch(key) {
	case 'x':
		rtrix += 10.5f;
		break;
	case 'y':
		rtriy += 10.5f;
		break;
	case 'z':
		rtriz += 10.5f;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

void myArrow_keys(int a_keys, int x, int y) {
	switch(a_keys) {
	case GLUT_KEY_LEFT:
		tquadx -= 0.5f;
		break;
	case GLUT_KEY_RIGHT:
		tquadx += 0.5f;
		break;
	case GLUT_KEY_UP:
		tquady += 0.5f;
		break;
	case GLUT_KEY_DOWN:
		tquady -= 0.5f;
		break;
	default:
	break;
	}
}

void myMouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		CR = 1.0;
		CG = 0.0;
		CB = 0.0;
	}
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		CR = 0.0;
		CG = 1.0;
		CB = 0.0;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		CR = 0.0;
		CG = 0.0;
		CB = 1.0;
	}
	myDisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Transformation");
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(myArrow_keys);
    glutMouseFunc(myMouse);
    rtrix = rtriy = rtriz = 0.0f;
    tquadx = tquady = 0.0f;
    myInit();
    glutMainLoop();
    return 0;
}


