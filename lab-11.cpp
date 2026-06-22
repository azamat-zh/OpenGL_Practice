#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#define STB_IMAGE_IMPLEMENTATION// loading image to program
#include "stb_image.h"//single-header file image loading libraryz

int w = 800, h = 600;
void *fontTitle   = GLUT_BITMAP_HELVETICA_18;
void *fontNormal  = GLUT_BITMAP_HELVETICA_12;
void *fontBigName = GLUT_BITMAP_HELVETICA_18;

GLuint textureID = 0;

const char *filename = "rickroll.jpg"; //change to the real path

static void resize(int width, int height)
{
    if (height == 0) height = 1;
    w = width;
    h = height;
    glViewport(0, 0, width, height);
}

void setOrthographicProjection()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glScalef(1, -1, 1);
    glTranslatef(0, -h, 0);
    glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}



void drawStudentCard()
{
    float cardW = 600.0f;
    float cardH = 340.0f;
    float x0 = (w - cardW) / 2.0f;
    float y0 = (h - cardH) / 2.0f;
    float x1 = x0 + cardW;
    float y1 = y0 + cardH;



    glColor3f(0.75f, 0.78f, 0.85f);
    glBegin(GL_QUADS);
        glVertex2f(x0 + 8, y0 + 8);
        glVertex2f(x1 + 8, y0 + 8);
        glVertex2f(x1 + 8, y1 + 8);
        glVertex2f(x0 + 8, y1 + 8);
    glEnd();

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(x0, y0); glTexCoord2f(0.1, 0.1);
        glVertex2f(x1, y0); glTexCoord2f(0.1, 0.9);
        glVertex2f(x1, y1); glTexCoord2f(0.9, 0.9);
        glVertex2f(x0, y1); glTexCoord2f(0.9, 0.1);
    glEnd();

    glColor3f(0.2f, 0.3f, 0.45f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y1);
        glVertex2f(x0, y1);
    glEnd();

    float headerH = 60.0f;
    glColor3f(0.18f, 0.32f, 0.6f);
    glBegin(GL_QUADS);
        glVertex2f(x0, y0);
        glVertex2f(x1, y0);
        glVertex2f(x1, y0 + headerH);
        glVertex2f(x0, y0 + headerH);
    glEnd();

    float logoCX = x0 + 60.0f;
    float logoCY = y0 + headerH / 2.0f;
    float logoR  = 22.0f;

    glColor3f(0.95f, 0.95f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(logoCX, logoCY);
        for (int i = 0; i <= 40; ++i) {
            float t = 2.0f * 3.1415926f * i / 40.0f;
            glVertex2f(logoCX + cosf(t) * logoR,
                       logoCY + sinf(t) * logoR);
        }
    glEnd();

    glColor3f(0.18f, 0.32f, 0.6f);
    renderBitmapString(logoCX - 18, logoCY + 8, fontTitle, "AZA");

    glColor3f(1.0f, 1.0f, 1.0f);
    renderBitmapString(x0 + 110, y0 + 22, fontTitle, "Student Card");
    renderBitmapString(x0 + 110, y0 + 40, fontNormal,
                       "Xiamen University Malaysia");

    float textLeft  = x0 + 40.0f;
    float textTop   = y0 + headerH + 40.0f;
    float lineStep  = 30.0f;

    glColor3f(0.1f, 0.15f, 0.25f);
    renderBitmapString(textLeft, textTop, fontBigName, "Name:");
    renderBitmapString(textLeft + 120, textTop, fontBigName, "John Cina");

    glColor3f(0.15f, 0.2f, 0.3f);
    renderBitmapString(textLeft, textTop + lineStep, fontNormal, " ID:");
    renderBitmapString(textLeft + 120, textTop + lineStep, fontNormal,
                       "WTF1010101010");

    renderBitmapString(textLeft, textTop + 2 * lineStep, fontNormal, "Course:");
    renderBitmapString(textLeft + 120, textTop + 2 * lineStep, fontNormal,
                       "PhD in Memology");

    renderBitmapString(textLeft, textTop + 3 * lineStep, fontNormal, "Phone Number:");
    renderBitmapString(textLeft + 120, textTop + 3 * lineStep, fontNormal,
                       "+60-11-11111111");

    renderBitmapString(textLeft, textTop + 4 * lineStep, fontNormal, "Email:");
    renderBitmapString(textLeft + 120, textTop + 4 * lineStep, fontNormal,
                       "Your Cool A$$ Email");

    renderBitmapString(textLeft, textTop + 5 * lineStep, fontNormal, "University:");
    renderBitmapString(textLeft + 120, textTop + 5 * lineStep, fontNormal,
                       "Moscow Gov Uni");
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setOrthographicProjection();
    glLoadIdentity();

    drawStudentCard();

    glutSwapBuffers();
}

// Add at global scope


void initGL()
{
    glClearColor(0.93f, 0.95f, 0.98f, 1.0f);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    // Load texture once
    int width = 0, height = 0, channels = 0;
    stbi_uc *image = stbi_load(filename, &width, &height, &channels, 3);

    if (image == NULL) {
        printf("Failed to load image: %s\n", filename);
        return;
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    stbi_image_free(image);
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(100, 50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("SWE2409096");

    initGL();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}

