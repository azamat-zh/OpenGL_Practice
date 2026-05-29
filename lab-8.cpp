#include <GL/glut.h>
#include <cmath>
float angleX = 0.0f, angleY = 0.0f;
float hoopRotation = 0.0f;
float hoopMove = 0.0f;
const float PI = 3.1415926535;
GLfloat lightPos[] = { 4.0f, 8.0f, 1.0f, 1.0f };
GLfloat groundPlane[4] = { 0.0f, 1.0f, 0.0f, -0.2f };
void drawGround()
{
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
        glVertex3f(-5.0f, 0.0f, -5.0f);
        glVertex3f(-5.0f, 0.0f, 5.0f);
        glVertex3f(5.0f, 0.0f, 5.0f);
        glVertex3f(5.0f, 0.0f, -5.0f);
    glEnd();
}
void myShadowMatrix(GLfloat plane[4], GLfloat light[4])
{
    GLfloat dot = plane[0] * light[0] + plane[1] * light[1] + plane[2] * light[2] + plane[3] * light[3];
    GLfloat shadowMat[16];
    shadowMat[0] = dot - light[0] * plane[0];
    shadowMat[4] = 0.0f - light[0] * plane[1];
    shadowMat[8] = 0.0f - light[0] * plane[2];
    shadowMat[12] = 0.0f - light[0] * plane[3];

    shadowMat[1] = 0.0f - light[1] * plane[0];
    shadowMat[5] = dot - light[1] * plane[1];
    shadowMat[9] = 0.0f - light[1] * plane[2];
    shadowMat[13] = 0.0f - light[1] * plane[3];

    shadowMat[2] = 0.0f - light[2] * plane[0];
    shadowMat[6] = 0.0f - light[2] * plane[1];
    shadowMat[10] = dot - light[2] * plane[2];
    shadowMat[14] = 0.0f - light[2] * plane[3];

    shadowMat[3] = 0.0f - light[3] * plane[0];
    shadowMat[7] = 0.0f - light[3] * plane[1];
    shadowMat[11] = 0.0f - light[3] * plane[2];
    shadowMat[15] = dot - light[3] * plane[3];

    glMultMatrixf(shadowMat);
}
// Lighting setup
void setupLighting() {
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
}
void shadowpeople()
{

//teapot shadow
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef (0, 2, 0);
    glRotatef(50.0,0.0,1.0, 0.0);
    glutSolidTeapot(0.5);
    glPopMatrix();
    glEnd();
//cube shadow
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef (0, 0.8, 0);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();

}

void people()
{//teapot
    glPushMatrix();
    glColor3f(1.0,0.6,0.2);
    glTranslatef (0, 1, 0);
    glRotatef(50.0,0.0,1.0, 0.0);
    glutSolidTeapot(0.5);
    glPopMatrix();
    glEnd();
//cube
    glPushMatrix();
    glColor3f(0.6,0.3,0.8);
    glTranslatef (0, 0, 0);
    glutSolidCube(1);
    glPopMatrix();
    glEnd();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setupLighting();
    drawGround();
    // Draw shadow
    glDisable(GL_LIGHTING);
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    myShadowMatrix(groundPlane, lightPos);
    shadowpeople();
    glPopMatrix();
    glEnable(GL_LIGHTING);
    // Draw object
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    people();
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int value)
{
    hoopRotation += 8.0f;
    if (hoopRotation > 360.0f) hoopRotation -= 360.0f;
    hoopMove = 0.4f * sin(hoopRotation * PI / 180.0f);
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}
void reshape(int w, int h)
 {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 0.1, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 5.0, 5.0, 0.0, 2.0, 0.0, 0.0, 1.0, 0.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teapot");
    glClearColor(1.0,1.0,1.0,0.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
   // glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}

