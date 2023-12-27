//
//  lab7Clock.h
//  Clock
//
//  Created by Drew Hengehold on 11/9/22.
//

#ifndef lab7Clock_h
#define lab7Clock_h

class Clock {
public:
// default consturctor
    Clock(): secM(0), minM(0), hourM(0) {}
    
// seconds constructor
    Clock(double secM);
    
// Full Initialization
    Clock(double secM, double minM, double hourM);
    
    double get_second() const;
    
    double get_minute() const;
    
    double get_hour() const;
    
    void set_second(double n);
    
    void set_minute(double n);
    
    void set_hour(double n);
    
    void increment();
    
    void decrement();
    
    void add_seconds(double n);
    
    
private:
    double hms_to_second();
    void sec_to_hms(double n);
    
    double convert_seconds(double seconds);
    double convert_minutes(double seconds);
    double convert_hours(double seconds);
    void check_time();
    
    double secM;
    double minM;
    double hourM;
    
    
};




#endif /* lab7Clock_h */
