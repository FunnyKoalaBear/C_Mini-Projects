#include <stdio.h>


typedef struct Mat3 {
    double m[3][3];
} Mat3;

//hard coded
void Mat3_print(Mat3 M) {
    printf("{ ");

    printf("{%f, %f, %f},\n", M.m[0][0], M.m[0][1], M.m[0][2]);
    printf("{%f, %f, %f},\n", M.m[1][0], M.m[1][1], M.m[1][2]);
    printf("{%f, %f, %f}",  M.m[2][0], M.m[2][1], M.m[2][2]);

    printf("} \n ");   
}


void Mat3_print_dynamic(const Mat3* M) {

    printf("{ ");

    for (int row = 0; row < 3; row++) {
        
        printf("{");

        for (int col = 0; col < 3; col++) {

            if (col == 2) { printf("%f", M->m[row][col]); continue;}
            
            printf("%f, ", M->m[row][col]);
        }


        if (row == 2) {
            printf("}} \n");
            return;
        }
        printf("}, \n");

    }

}

int main(void){

    //double braces for struct, then array initialiser 
    Mat3 mat3 = {{ {1, 2, 3}, {4, 5, 6}, {7, 8 ,9}  }}; 

    Mat3_print(mat3);

    putchar('\n');

    Mat3_print_dynamic(&mat3);

    return 0;
}