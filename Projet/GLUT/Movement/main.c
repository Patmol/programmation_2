#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

int lissage = GL_NEAREST;

void display() {
    loadTexture("bubble.bmp", 133, 126);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, lissage);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, lissage);

    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        glVertex2f(-1,  1);
        glTexCoord2f(0.0, 1.0);
        glVertex2f(-1, -1);
        glTexCoord2f(1.0, 1.0);
        glVertex2f( 1,  -1);
        glTexCoord2f(1.0, 0.0);
        glVertex2f( 1,  1);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Image");

    loadTexture("bubble.bmp", 133, 126);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}