/*
 * Name: Trey Fullwood
 * NetID: rf802
 * Description: This program will ask for words of 50 chars to be entered
 *              When the computer reads "STOP", the operation will end and
 *              the inputs will be displayed in the opposite order they were entered
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Node struct
struct Node
{
    char str [50];
    struct Node *next;
}*top=NULL; // global variable

// PUSH
void push(char *x)
{
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        strcpy(t->str, x);
        t->next = top;
        top = t;
    }
}

// POP
void pop(char *x)
{
    struct Node *t;

    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;

        strcpy(x, t->str);
        free(t);
    }
}

int main()
{
    char string [50];

    printf("Enter 'STOP' to end loop\n");

    // Loop to entering words to stack
    while (strcmp(string, "STOP") != 0)
    {
        printf("Enter a word: ");
        gets(string);

        if (strcmp(string, "STOP") == 0)
            continue;

        push(string);
    }

    // Loop to empty stack & display contents in reverse order of input
    while (top != NULL)
    {
        pop(string);
        printf("%s\n", string);
    }
    return 0;
}
