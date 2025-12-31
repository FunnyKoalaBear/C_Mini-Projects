#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "getop.h"

double variables[26] = {0.0}; 
int letterIndex; 

/* getop - read and return operator, or read a number into a buffer */

int getop(char line[], int limit)
{
    int n = 0;
    
	for (;;) {
		int c = getch(); //reading first character

		//termination cases 
		if (c == EOF)    return -1;
		if (c == '\n')   return 0;
		if (c <= ' ')    continue; 

		//checking for "=" sign
		if (isalpha(c)) {

			int nextC; 
			letterIndex = tolower(c) - 'a';

			//parsing through spaces till next character found 
			do {
				nextC = getch();
			} while (nextC == ' ');

			if (nextC == '=') {
				return getop(line, limit);
			}

			//puts last char back into stdin 
			ungetch(c);
			//prints a value if no =
			sprintf(line, "%.8g", variables[letterIndex]);
			return NUMBER;


		}

		if (!isdigit(c)) return c; //returning operator chaaracter + - / *

		//stores digits into line
		do if (n < limit - 1) 
				line[n++] = c; 
		while (isdigit(c = getch())); //puts . into c at final char if decimal number
		
		//reading decimal part 
		if ('.' == c) {
			do if (n < limit - 1) 
				line[n++] = c; //puts . in line at first loop 
			while (isdigit(c = getch()));
		}
		
		line[n] = '\0';
		ungetch(c); //push back extra charcter for next getop() call 

		return NUMBER; 
    }
}


int saved = 0; //single character buffer 

int getch(void)
{
    int c = saved;

    if (c  < 0) return c; //if c has a character return it 
    if (c == 0) return getchar(); //otherwise return char from stdin 

    saved = 0; //resetting saved 
    return c;
}

void ungetch(int c)
{
    saved = c;
}

