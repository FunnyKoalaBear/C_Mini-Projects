#include <stdio.h>


typedef struct Mat3 {
    double m[3][3];
} Mat3;


void Mat3_print_dynamic(const Mat3* M) {

    printf("{ ");

    for (int row = 0; row < 3; row++) {
        
        printf("{");

        for (int col = 0; col < 3; col++) {

            if (col == 2) { printf("%.6f", M->m[row][col]); continue;}
            
            printf("%.6f, ", M->m[row][col]);
        }


        if (row == 2) {
            printf("}} \n");
            return;
        }
        printf("}, \n");

    }

}

void Mat3_mulMat3(const Mat3* A, const Mat3* B, Mat3* P) {

    for (int row = 0; row < 3; row++) {

        for (int col = 0; col < 3; col ++) {
            
            P->m[row][col] = 0; //initializing 

            //noticed A matrix column is same as B matrix row. 
            for (int aCol = 0; aCol < 3; aCol++){
                
                P->m[row][col] += A->m[row][aCol] * B->m[aCol][col];

            }
        }
    }
}

int main(void){

    //double braces for struct, then array initialiser 
    Mat3 A = {{{ 2,  1,  5}, { 2, 10,  5}, { 3,  1,  4} }};
    Mat3 B = {{ { 8,  7,  1}, { 4,  2,  7}, { 2,  3,  5} }};
    Mat3 P; 

    Mat3_mulMat3(&A, &B, &P);
    Mat3_print_dynamic(&P);

    return 0;
}