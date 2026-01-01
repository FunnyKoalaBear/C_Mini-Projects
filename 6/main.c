#include <stdio.h>


typedef struct Mat3 {
    double m[3][3];
} Mat3;

typedef struct Vec3 {
    double v[3];
} Vec3; 


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

// new vector print func
void Vec3_print(const Vec3* V) {

    printf("{");

    for (int i = 0; i < 2; i++) {

        printf("%.6f, ", V->v[i]);

    }

    printf("%.6f } \n", V->v[2]); //final element in V 
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

//new vector matrix multiplication func
void Mat3_mulVec3(const Mat3* M, const Vec3* V, Vec3* P) {

    //M X V, need to transpose V, s go by rows 
    for (int row = 0; row < 3; row++) {
        
        P->v[row] = 0; //initialising

        for (int aCol =0; aCol < 3; aCol++) {

            P->v[row] += V->v[aCol] * M->m[row][aCol];

        }

    }

}


int main(void){

    Vec3 V = {3, 4 ,1};
    Vec3_print(&V);


    Mat3 S = {{ {3, 0, 0}, {0, 2, 0}, {0, 0, 1} }};
    Vec3 SV; 
    Mat3_mulVec3(&S, &V, &SV);
    Vec3_print(&SV);


    Mat3 T = {{ {1, 0, 5,}, {0, 1, 7}, {0, 0, 1} }};
    Vec3 TV;
    Mat3_mulVec3(&T, &V, &TV);
    Vec3_print(&TV);


    Mat3 TS;
    Mat3_mulMat3(&T, &S, &TS);
    Vec3 TSV;
    Mat3_mulVec3(&TS, &V, &TSV);
    Vec3_print(&TSV);

    
    //return 0;

    //the just for fun part 
    Vec3 V_point = { 3, 4, 1 }; 

    // Theory: If we change S to scale by 2 on X and 2 on Y, 
    // the point (3,4) should become (6,8).
    Mat3 S_test = {{ { 2, 0, 0 }, { 0, 2, 0 }, { 0, 0, 1 } }};
    Vec3 V_scaled;
    Mat3_mulVec3(&S_test, &V_point, &V_scaled);
    
    printf("Result: ");
    Vec3_print(&V_scaled); // You should see { 6.0, 8.0, 1.0 }
    printf("\n");

    return 0;
}