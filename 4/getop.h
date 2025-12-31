#ifndef GETOP_H
#define GETOP_H

#define NUMBER '0' // `operator' representing a number

extern double variables[26];
extern int letterIndex; 

int getch(void);
void ungetch(int c);
int getop(char line[], int limit);

#endif