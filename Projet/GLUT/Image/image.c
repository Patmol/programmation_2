#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int w, h;
int lissage = GL_NEAREST;
int x, y, xold, yold;

char *img_read(char *name) {
    FILE *file = fopen(name, "rb");

    if (file == NULL) {
        exit(0);
    }

    int of;
    fseek(file, 10, SEEK_SET);
    fread(&of, sizeof(int), 1, file);
    fseek(file, 4, SEEK_CUR);
    fread(&w, sizeof(int), 1, file);
    fread(&h, sizeof(int), 1, file);
    fseek(file, of, SEEK_SET);

    int by = ((w * 3 + 3) / 4) * 4 - (w * 3 % 4);
    char *tmp_m = malloc(sizeof(char) * by * h);
    char *m = malloc(sizeof(char) * w * h * 3);
    fread(tmp_m, sizeof(char) * by * h, 1, file);

    free(tmp_m);

    return m; 
}

GLuint loadTexture(char *fileName) {
    char *wa = img_read(fileName);

    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, wa);
    free(wa);

    return textureId;
}

void display() {
    loadTexture("image.bmp");

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

    loadTexture("image.bmp");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}