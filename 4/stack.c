#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>

/* stack - last-in first-out storage of doubles */
int depth = 0; 
double stack[32];


int stackDepth(void)
{
    return depth;
}

void push(double d)
{
    if (depth > 31)
	printf("stack overflow\n");
    else
	stack[depth++] = d;
}

double pop(void)
{
    if (depth < 1) {
	printf("stack underflow\n");
	return 0;
    }
    return stack[--depth];
}
