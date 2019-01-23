#pragma once
enum Plane_status { null, arriving, departing };
class Plane
{
public:
    /*
    Post:  The Plane data members flt_num, clock_start,
    state are set to illegal default values.
    */
    Plane();
    /*
    Post:  The Plane data members flt_num, clock_start,
    and state are set to the values of the parameters flt,
    time and status, respectively.
    */
    Plane(int flt, int time, Plane_status status);
    ~Plane();
    /*
    Post: Processes a Plane wanting to use Runway, when
    the Queue is full.
    */
    void refuse() const;
    /*
    Post: Processes a Plane that is landing at the specified time.
    */
    void land(int time) const;
    /*
    Post: Process a Plane that is taking off at the specified time.
    */
    void fly(int time) const;
    /*
    Post: Return the time that the Plane entered the airport system.
    */
    int started() const;

private:
    int flt_num;
    int clock_start;
    Plane_status state;
};


