/*
 *  lab2exe_A.c
 *  Created by Mahmood Moussavi
 *  Completed by: Drew Hengehold
 *  Completed on: 24 September 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    //This checks to make sure you entered properly in the scan
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    return 0;
}

double Projectile_travel_time(double a, double v)
{
    return 2*v*sin(a)/G;
}

double Projectile_travel_distance(double a, double v)
{
    return pow(v, 2)/G*sin(2*a);
}

double degree_to_radian(double d)
{
    return d*PI/180;
}

void create_table(double v)
{
    printf("Angle\t\tt\t\t\td\n(deg\t\t(sec)\t\t(m)\n");
    for(double i=0.0; i<=90.0; i+=5)
    {
        printf("%lf\t%lf\t%lf\n", i, Projectile_travel_time(degree_to_radian(i),v), Projectile_travel_distance(degree_to_radian(i), v));
    }
}

