#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//#include "getop.h"
//#include "atod.h"
#include "stack.h"

/* main - the main calculator program */
int main()
{
    char line[32];
	
    for (;;) {

		//getting number input
		double x; 
		char c; 

		//since scanf skips these, check manually 
		c = getchar();
		if (c == ' ') continue;

		if (c == '+' | c == '-' | c == '\n') {
			goto afterParsing;
		}
		ungetc(c, stdin); 


		//pushes float number into stack if scanf succesful 
		if (scanf("%lf", &x) == 1) {
			push(x); //pushing normally if its a number 
			continue; //go to next loop
		}

		
		//checking for operator and space before continuing to next loop iteration
		if (scanf("%c", &c) != 1) { 
			break; //EOF check 
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


// gcc main.c stack.c -o calc
// ./calc