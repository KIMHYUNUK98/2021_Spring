// Implementation file "time.cpp"
#include "time.h"
#include  <iostream>
using namespace std;

// TODO: Set() sets the Time using parameters  
void Time::Set(int hours, int minutes, int seconds)
{
    hrs = hours;
    mins = minutes;
    secs = seconds;
}

// TODO: Increment() increments time by 1sec
void Time::Increment()
{
    secs++;
    if(secs > 59) {
        secs = 0;
        mins++;
        if(mins > 59) {
            mins = 0;
            hrs++;
            if(hrs > 23) {
                hrs = 0;
            }
        }
    }
}

// TODO: Print Time (Format: hrs:mins:sec \n)
void Time::Print() const
{
    cout << hrs << ": " <<  mins << ": " << secs << endl;
}

bool Time::Equal(Time otherTime) const  
{
    return ((hrs == otherTime.hrs)  
           && (mins == otherTime.mins)
           && (secs  == otherTime.secs));
}
