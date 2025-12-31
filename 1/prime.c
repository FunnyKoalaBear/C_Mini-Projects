//Prime number generator 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int main(int argc, char *argv[]) {

    //checking for correct usage and input 
    if (argc == 1) {
        printf("Usage: ./primes max-prime \n");
        return 0;
    }

    const int max = atoi(argv[1]) + 1; ///added +1 to include the max number 

    if (max < 2) {
        printf("./primes: max-prime %i is too small (must be at least 2)\n", max);
        return 0;
    }

    bool *P = malloc((max) * sizeof(bool)); //array made

    if (!P) {
        perror("Malloc Failed");
        return 0;
    }

    //making all elements in P true
    P[0] = P[1] = false;

    for (int i = 2; i < max; i++) {
        P[i] = true;
    }
    
    //the seiving algorithm 
    for (int i = 2; i <= sqrt(max); i++){ 

        if (P[i] == true) {

            for (int j = i; j*i < max; j++) { //i^2 optimization done here 
                P[i * j] = false;  
            }

        }

    }

    //printing the primes
    for (int i = 2; i < max; i++) {
        if (P[i] == true) {
            printf("%i\n", i);
        }
    }

    free(P);

}