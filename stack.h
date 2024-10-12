#ifndef STACK_H
#define STACK_H

enum {
    Strsz = 32,
};

typedef struct Node Node;
struct Node {
    char str[Strsz];
    Node *next;
};

typedef struct Stack Stack;
struct Stack {
    Node *top;
};

Stack *newStack(void);
void push(char *str, Stack *s);
char *pop(Stack *s);
void destroystack(Stack *s);


#endif