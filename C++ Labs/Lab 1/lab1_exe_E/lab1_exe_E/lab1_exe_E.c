/*
* File Name: lab1exe_E.c
* Assignment: Lab 1 Exercise E
* Lab section: B01
* Completed by: Drew Hengehold
* Development Date: Sept 16, 2022
*/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    
    printf("This code will exectute the quadratic formula, please enter\nthe first coefficent \"a\", second coefficent \"b\", and third coefficent \"c\"\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    if(0 > (pow(b,2)-4*a*c)){
        printf("The values are %lf + %lfi,\nand %lf - %lfi\n", (b*-1)/(2*a), sqrt(fabs((pow(b,2)-4*a*c)))/(2*a), (b*-1)/(2*a), sqrt(fabs((pow(b,2)-4*a*c)))/(2*a));
    }
    else
    {
        printf("The first value is %lf\n The second value is %lf\n", ((b*-1)+sqrt(pow(b,2)-4*a*c))/(2*a), ((b*-1)-sqrt(pow(b,2)-4*a*c))/(2*a));
    }
    
    return 0;
}

