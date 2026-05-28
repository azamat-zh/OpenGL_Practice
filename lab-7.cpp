// This one is Mickey Mouse made with Rings

#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
void init(void)
{

    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 100.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat Light_Model_Ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0f,0.0f,0.0f); //RED
    glScalef(1.1,1.1,2);
    glTranslatef(-0.7,0.4,0);
    glRotatef(-20,0,0.5,0);
    glutSolidTorus(0.05,0.5,40,200);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f,1.0f,0.0f); //GREEN
    glScalef(1.2,1.2,3);
    glTranslatef(0.5,0.5,0);
    glRotatef(20,0.5,0.5,0);
    glutSolidTorus(0.05,0.5,40,100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f,0.0f,1.0f); //BLUE
    glRotatef(20,0.5,0.5,0);
    glScalef(1.7,1.7,2);
    glTranslatef(0,-0.3,0);
    glutSolidTorus(0.05,0.5,40,100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8f,0.8f,0.0f); //Yellow Eye
//    glRotatef(40,0.5,0.5,0);
    glScalef(0.2,0.3,2);
    glTranslatef(0,-1,0);
    glutSolidTorus(0.05,0.5,40,100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8f,0.8f,0.0f); //Yellow Eye
//    glRotatef(40,0.5,0.5,0);
    glScalef(0.2,0.3,2);
    glTranslatef(2,-1,0);
    glutSolidTorus(0.05,0.5,40,100);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8f,0.8f,0.0f); //Yellow Nose
//    glRotatef(40,0.5,0.5,0);
    glScalef(0.3,0.2,2);
    glTranslatef(1,-3,0);
    glutSolidTorus(0.05,0.5,40,8);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5*(GLfloat)h / (GLfloat)w, 1.5*(GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5*(GLfloat)w / (GLfloat)h, 1.5*(GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D circles");
    init();
    glEnable(GL_COLOR_MATERIAL);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
