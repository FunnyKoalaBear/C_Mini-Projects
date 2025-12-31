#ifndef STACK_H
#define STACK_H

int stackDepth(void);
void push(double d);
double pop(void);

extern double stack[32];
extern int depth;

#endif