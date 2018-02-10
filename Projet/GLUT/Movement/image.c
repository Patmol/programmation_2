#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#include "image.h"

int width, height;

char *img_read(char *name) {
    FILE *file = fopen(name, "rb");

    if (file == NULL) {
        exit(0);
    }

    int of;
    fseek(file, 10, SEEK_SET);
    fread(&of, sizeof(int), 1, file);
    fseek(file, 4, SEEK_CUR);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fseek(file, of, SEEK_SET);

    int by = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
    char *tmp_m = malloc(sizeof(char) * by * height);
    char *m = malloc(sizeof(char) * width * height * 3);
    fread(tmp_m, sizeof(char) * by * height, 1, file);

    free(tmp_m);

    return m; 
}

GLuint loadTexture(char *fileName, int w, int h) {
    char *wa = img_read(fileName);

    height = h;
    width = w;

    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, wa);
    free(wa);

    return textureId;
}