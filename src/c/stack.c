/*
Linked list based stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
size_t getline(char **lineptr, size_t *n, FILE *stream);

typedef struct Stack Stack;
struct Stack {
    Stack *next;
    int value;
};

int Stack_push(Stack **this, int value) {
    Stack *new;
    new = malloc(sizeof(Stack));
    if (new == NULL) return 1;
    new->value = value;
    new->next = *this;
    *this = new;
    return 0;
}

int Stack_pop(Stack **this, int *ret) {
    Stack *buffer;
    if (*this == NULL) return 1;
    *ret = (*this)->value;
    buffer = (*this)->next;
    free(*this);
    *this = buffer;
    return 0;
}

int main(void) {
    size_t maxLineLen = 1024;
    char *line = (char*)malloc(maxLineLen);
    Stack *s = NULL;
    /*
    TODO improve API.

    while(getline(&line, &maxLineLen, stdin) != -1) {
        char *p = strtok(line, " ");
        while( p != NULL) {
            int d = atoi(p);
            Stack_push(&s, d);
            p = strtok(NULL, " ");
        }
    }
    while(s != NULL) {
        int ret;
        Stack_pop(&s, &ret);
        printf("%d ", ret);
        Stack_pop(&s, &ret);
    }
    */
}
