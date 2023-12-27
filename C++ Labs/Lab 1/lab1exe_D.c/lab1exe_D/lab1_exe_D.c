/*
* File Name: lab1exe_D.c
* Assignment: Lab 1 Exercise D
* Lab section: B01
* Completed by: Drew Hengehold
* Development Date: Sept 16, 2022
*/

#include <stdio.h>
#include <math.h>

int main() {
    
    double angle_radian, angle_degree, angle_sin;
    printf("Please enter the input angle in radians:\n");
    scanf("%lf", &angle_radian);
    
    angle_degree = angle_radian*180/M_PI;
    printf("The angle is %lf\n", angle_degree);
    
    angle_sin = sin(angle_radian);
    printf("The sin of the angle is %lf\n", angle_sin);
    
    angle_sin = angle_radian - (((pow(angle_radian,3))/(3*2*1)))+((pow(angle_radian,5))/(5*4*3*2*1))-((pow(angle_radian,7))/(7*6*5*4*3*2*1));
    printf("The taylor series value is %lf\n", angle_sin);
    return 0;
}
