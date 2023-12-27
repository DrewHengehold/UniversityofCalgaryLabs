//
//  lab7Clock.cpp
//  Clock
//
//  Created by Drew Hengehold on 11/9/22.
//

#include <stdio.h>
#include "lab7Clock.h"

Clock::Clock(double hour, double min, double seconds): hourM(hour), minM(min), secM(seconds){
    check_time();
}

Clock::Clock(double seconds):secM(convert_seconds(seconds)), minM(convert_minutes(seconds)), hourM(convert_hours(seconds)){
    check_time();
}

double Clock::get_second() const{
    return secM;
}

double Clock::get_minute() const{
    return minM;
}

double Clock::get_hour() const{
    return hourM;
}

void Clock::set_second(double n){
    if(n< 60)
        secM = n;
}

void Clock::set_minute(double n){
    if(n < 60)
        minM = n;
}

void Clock::set_hour(double n){
    if(n < 24)
        hourM = n;
}

void Clock::increment(){
    double seconds = hms_to_second();
    seconds++;
    sec_to_hms(seconds);
}

void Clock::decrement(){
    double seconds = hms_to_second();
    seconds--;
    if(seconds<0){
        seconds = 86400-(((int)seconds%(-86400))*(-1));
    }
    sec_to_hms(seconds);
}

void Clock::add_seconds(double n){
    double seconds = hms_to_second();
    seconds += n;
    sec_to_hms(seconds);
}

//PRIVATE FUNCTIONS START

double Clock::hms_to_second(){
    return secM + (minM*60) + (hourM*3600);
}

void Clock::sec_to_hms(double n){
    secM = convert_seconds(n);
    minM = convert_minutes(n);
    hourM = convert_hours(n);
}
                 
double Clock::convert_hours(double seconds){
    double hours;
    hours = (double)(((int)seconds/3600)%24);
    return hours;
}

double Clock::convert_minutes(double seconds){
    double minutes;
    minutes = ((int)seconds%3600)/60;
    return (double)minutes;
}

double Clock::convert_seconds(double seconds){
    return (double)(((int)seconds%3600)%60);
}

void Clock::check_time(){
    if((secM < 0) or (secM >= 60) or (hourM < 0) or (hourM >= 24) or (minM < 0) or (minM >= 60)){
        secM = 0;
        minM = 0;
        hourM = 0;
    }
}
