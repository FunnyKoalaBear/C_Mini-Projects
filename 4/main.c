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

			//put back the character scanf read for getchar() in getop() function 
			ungetc(c, stdin);
			int tempIndex = tolower(c) - 'a'; 
			
			int type = getop(line , sizeof(line));

			if (type == 5) {
				//equal sign was detected
				letterIndex = tempIndex;  
				continue;
			}

			//if 
			if (type == 4) {
				//just letter detected, push it into stack 
				push(atof(line));
				continue; 
			}

			//continue; 
		}

		//doing arithmetic 
		afterParsing:

			if (c == '\n') {
				//printing output at the new line key 
				double output = pop();
				
				//setting output to a variable if needed
				if (letterIndex != -1) {
					variables[letterIndex] = output;
					//printf("Vaaraiable is %f\n", variables[letterIndex]);
				}
				
				printf("= %.8g\n", output);
				 
				letterIndex = -1; 
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
			continue; 
		
			letterIndex = -1; 

    }

    return 0;
}

