#include <iostream>

using namespace std;

class Clock {
private:
    int _hour;
    int _minute;
    bool _morning;
public:
    Clock();
    void set_time(int hour, int minute, bool morning);
    void advance(int minute);
    int get_hour() const;
    int get_mintute() const;
    bool is_morning() const;
};


//1. Implementation

Clock::Clock() {}

void set_time(int hour, int minute, bool morning) {


}

void Clock::advance(int minute) {
 int newMinute = minute + minute;
 if(newMinute>60)
 {
     int newHour = hour + 1;
 }
}

int Clock::get_hour() const{
    return hour;
}

int Clock::get_minute() const {
    return minute;
}

bool Clock::is_morning() const {
    if(hour<12)
    {
        return true;
    }
    else
        return false;
}


class Daylight_Clock {



};





int main()
{

    return 0;
}
