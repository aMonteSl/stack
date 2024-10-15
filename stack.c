#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

static int
isNullPointer(void *p)
{
	return p == NULL;
}

Stack *
newStack(void)
{
	Stack *s;

	s = malloc(sizeof(Stack));
	if (isNullPointer(s)) {
		return NULL;
	}
	s->top = NULL;
	return s;
}

static int
isNullOnePointer(Stack *s, void *ptr)
{
	return isNullPointer(s) || isNullPointer(ptr);
}

static int
isLongerThanStrsz(char *str)
{
	return strlen(str) > Strsz - 1;
}

void
push(char *str, Stack *s)
{
	if (isNullOnePointer(s, str)) {
		return;
	}

	if (isLongerThanStrsz(str)) {
		return;
	}

	Node *node;

	node = malloc(sizeof(Node));
	if (isNullPointer(node)) {
		return;
	}
	strcpy(node->str, str);
	node->next = s->top;
	s->top = node;
}

static void
swapTopWithNext(Stack *s)
{
	s->top = s->top->next;
}

char *
pop(Stack *s)
{
	Node *topNode;
	char *data;

	if (isNullOnePointer(s, s->top)) {
		return NULL;
	}

	topNode = s->top;
	swapTopWithNext(s);

	data = malloc(strlen(topNode->str) + 1);
	if (isNullPointer(data)) {
		return NULL;
	}

	strcpy(data, topNode->str);

	free(topNode);

	return data;

}

void
destroystack(Stack *s)
{
	Node *topNode;

	if (isNullPointer(s)) {
		return;
	}

	while (!isNullPointer(s->top)) {
		topNode = s->top;
		swapTopWithNext(s);
		free(topNode);
	}

	free(s);
}
