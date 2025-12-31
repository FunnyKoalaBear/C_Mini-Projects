#include <stdio.h>


typedef struct  {
    double m[3][3];
} Mat3;

int main(void){

    //double braces for struct, then array initialiser 
    Mat3 mat3 = {{ {1, 2, 3}, {4, 5, 6}, {7, 8 ,9}  }}; 

}