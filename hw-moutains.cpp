#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //big mountain
    glColor3f(0.4, 0.4, 0.45);
    glBegin(GL_POLYGON);
        glVertex2f(-0.9708, -0.4927);
        glVertex2f(-0.7853, -0.0287);
        glVertex2f(-0.7251, -0.1807);
        glVertex2f(-0.5196, 0.5073);
        glVertex2f(-0.4344, 0.1873);
        glVertex2f(-0.274, 0.6833);
        glVertex2f(-0.1587, 0.3873);
        glVertex2f(-0.1136, 0.4513);
        glVertex2f(-0.0033, 0.0673);
        glVertex2f(0.1771, 0.3073);
        glVertex2f(0.2172, 0.1073);
        glVertex2f(0.3024, 0.1873);
        glVertex2f(0.3776, -0.1487);
        glVertex2f(0.4779, -0.0047);
        glVertex2f(0.7536, -0.4287);
    glEnd();

    //small mountain
    glColor3f(0.3, 0.3, 0.35);
    glBegin(GL_POLYGON);
        glVertex2f(-0.8505, -0.5327);
        glVertex2f(-0.6249, -0.1247);
        glVertex2f(-0.5698, -0.2447);
        glVertex2f(-0.4645, -0.0207);
        glVertex2f(-0.4043, -0.1327);
        glVertex2f(-0.3342, -0.0207);
        glVertex2f(-0.2189, -0.3247);
        glVertex2f(-0.1738, -0.2287);
        glVertex2f(-0.0234, -0.5167);
    glEnd();

    //ground
    glColor3f(0.3, 0.6, 0.3);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0, -0.4);
        glVertex2f(-1.0, -1.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(1.0, -0.4);
    glEnd();

    //side ground triangle
    glColor3f(0.3, 0.7, 0.3);
    glBegin(GL_POLYGON);
        glVertex2f(0.1551, -0.5362);
        glVertex2f(1.0, -0.716);
        glVertex2f(1.0, -0.3265);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.53, 0.81, 0.92, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mountain Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

