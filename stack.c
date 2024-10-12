#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

Stack *newStack(void) {
    Stack *s;
    s = malloc(sizeof(Stack));
    if (s == NULL){
        return NULL;
    }
    s->top = NULL;
    return s;
}

void push(char *str, Stack *s) {
    if (s == NULL || str == NULL){
        return;
    }

    if (strlen(str) > Strsz - 1){
        return;
    }

    Node *node;
    node = malloc(sizeof(Node));
    if (node == NULL){
        return;
    }
    strcpy(node->str, str);
    node->next = s->top;
    s->top = node;
}

char *pop(Stack *s){
    Node *topNode;
    char *data;
    if (s == NULL || s->top == NULL){
        return NULL;
    }

    topNode = s->top;
    s->top = topNode->next;

    data = malloc(strlen(topNode->str) + 1);
    if (data == NULL){
        return NULL;
    }

    strcpy(data, topNode->str);

    free(topNode);

    return data;

}

void destroystack(Stack *s) {
    Node *topNode;
    if (s == NULL){
        return;
    }

    while(s->top != NULL){
        topNode = s->top;
        s->top = topNode->next;
        free(topNode);
    }

    free(s);
}