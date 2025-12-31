#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//structure to hold coordinates
typedef struct {
    double x; 
    double y; 
} Point; 


//distance check function
double distance(Point dest, Point origin) {
    return sqrt((origin.x - dest.x)*(origin.x - dest.x) + (origin.y - dest.y)*(origin.y - dest.y));
}


int main(int argc, char *argv[]) {
    
    //checking CLI argument count
    if (argc != 2) {
        printf("Usage: ./2 int\n");
        return 1;
    }

    //checking if cli argument is an integer 
    int pointCount = atoi(argv[1]);
    if (pointCount <= 0) {
        printf("Usage: ./2 int\n");
        return 1;
    }

    //defining circle center coordinates
    Point circleCenter; 
    circleCenter.x = 1;
    circleCenter.y = 1;

    //main loop
    int innerCount = 0; 
    srand(time(NULL)); //random time seed 
    
    for (int i = 0; i < pointCount; i++) {

        Point newP;
        newP.x = 2 * ((double) rand() / RAND_MAX); 
        newP.y = 2 * ((double) rand() / RAND_MAX);

        if (distance(newP, circleCenter) < 1.0) {
            innerCount++;
        }

    }

    //pi calculatoin 
    //area of square is 4, circle is pi, ratio is pi/4
    double pi = 4*((double) innerCount/pointCount); 

    printf("%i out of %i points inside the circle\n", innerCount, pointCount);
    printf("pi is approximately %.8f\n", pi);

    //MADE THIS SHOW 8 DECIMAL PLACE

    return 0; 
}


//mini question answer
//why oes int counters not give more than 9 sf? 
//since max value is 2*10^9, precession
//1/max value gives precession of 0.00000000186