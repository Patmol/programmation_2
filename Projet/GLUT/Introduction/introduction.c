#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#include "introduction.h"

float angle = 0.0f;
// Colors of the triangle
float red = 1.0f, blue = 1.0f, green = 1.0f;

int main(int argc, char **argv) {
    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 320);
    glutCreateWindow("Lighthouse3D - GLUT");

    // Register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    return 1;
}

/*
 * Rendering
 */
void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();
    // Set the camera
    gluLookAt(  0.0f, 0.0f, 10.0f,
                0.0f, 0.0f,  0.0f,
                0.0f, 1.0f,  0.0f);

    glRotatef(angle, 0.0f, 1.0f, 0.0f);

    glColor3f(red, green, blue);
    glBegin(GL_TRIANGLES);
        glVertex3f(-2.0f, -2.5f, 0.0f);
        glVertex3f( 2.0f,  0.0f, 0.0f);
        glVertex3f( 0.0f,  2.0f, 0.0f);
    glEnd();

    angle += 0.1f;

    glutSwapBuffers();
}

/*
 * Function call when window is resize
 */
void changeSize(int h, int w) {
    // Prevent a divide by zero when window is too short
    if (h == 0)
        h = 1;

    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get back the Modelview
    glMatrixMode(GL_MODELVIEW);
}

/*
 * Handling normal keys (ASCII characters)
 */
void processNormalKeys(unsigned char key, int x, int y) {
    if (key == ESCAPE) {
        exit(0);
    } else if (key == 'r') {
        // We check if the ALT key is also press (if it's ALT+R or just R)
        int modifier = glutGetModifiers();

        if (modifier == GLUT_ACTIVE_ALT) {
            red = 0.0f;
        } else {
            red = 1.0f;
        }
    }
}

/*
 * Handling special keys (F keys, Up, Down, ...)
 */
void processSpecialKeys(int key, int x, int y) {
    int modifier;
    switch (key) {
        case GLUT_KEY_F1:
            modifier = glutGetModifiers();
            // We check if the user has also press CTRL + ALT
            if (modifier == (GLUT_ACTIVE_CTRL | GLUT_ACTIVE_ALT)) {
                red     = 1.0;
                green   = 0.0f;
                blue    = 0.0f;
            }
            break;
        case GLUT_KEY_F2:
            red     = 0.0;
            green   = 1.0f;
            blue    = 0.0f;
            break;
        case GLUT_KEY_F3:
            red     = 0.0;
            green   = 0.0f;
            blue    = 1.0f;
            break;
    }
}