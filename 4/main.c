#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"

int main()
{
    char line[32];
	
    for (;;) {

		double x; 
		char c; 

		//since scanf skips these, check manually 
		c = getchar();
		if (c == ' ') continue;

		if (c == '+' | c == '-' | c == '\n') {
			goto afterParsing;
		}
		ungetc(c, stdin); 


		//Number input
		if (scanf("%lf", &x) == 1) {
			push(x); 
			continue; 
		}

		
		//EOF/operator input 
		if (scanf("%c", &c) != 1) { 
			break; 
		} 

		//doing arithmetic 
		label: afterParsing:

			if (c == '\n') {
				//printing output at the new line key 
				printf("= %.8g\n", pop()); 
				continue;
			}

			switch (c) {
				case '+':	{ double r = pop(), l = pop();  push(l + r); }				break;
				case '-':	{ double r = pop(), l = pop();  push(l - r); }				break;
				case '*':	{ double r = pop(), l = pop();  push(l * r); }				break;
				case '/':	{ double r = pop(), l = pop();  push(l / r); }				break;
				case '%':	{ double r = pop(), l = pop();  push(l - r*(int)(l/r)); }	break;
				default:	printf("unknown operator: %i\n", c);						break;
			}
		


    }

    return 0;
}

