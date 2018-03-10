#ifndef LISTEC_H
#define LISTEC_H

typedef struct node {
    int data;
    struct node *nextptr;
} node;

int menu();
void* creer(void *);
void* supprimer(void *);
void montrer(void *);

#endif