#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"
#include "getop.h"


int main() {
	
    char line[32];

	
    for (;;) {

		double x; 
		char c; 

		//since scanf skips these, check manually 
		c = getchar();
		if (c == ' ') continue;

		if (c == '+' || c == '-' || c == '\n') {
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

		//checking for variables
		if (isalpha(c)) {
			letterIndex = tolower(c) - 97; 
			continue; 
		}

		//doing arithmetic 
		label: afterParsing:

			if (c == '\n') {
				//printing output at the new line key 
				double output = pop();

				//setting output to a variable if needed
				if (letterIndex >= 0) {
					variables[letterIndex] = output;
					//printf("Vaaraiable is %f\n", variables[letterIndex]);
				}

				printf("= %.8g\n", output); 
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

	letterIndex = -1; 
    return 0;
}

