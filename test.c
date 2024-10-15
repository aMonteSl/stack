#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int
main(void)
{
	Stack *s = newStack();

	if (s == NULL) {
		fprintf(stderr,
			"Error: no se pudo crear la pila, memoria insuficiente.\n");
		exit(EXIT_FAILURE);
	}

	for (char i = 'a'; i <= 'z'; i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			char str[3] = { i, j, '\0' };
			push(str, s);
		}
	}

	while (s->top != NULL) {
		char *str = pop(s);

		if (str == NULL) {
			fprintf(stderr,
				"Error: no se pudo extraer el elemento de la pila.\n");
			break;
		}
		printf("%s\n", str);
		free(str);
	}

	destroystack(s);
	s = NULL;

	exit(EXIT_SUCCESS);
}
