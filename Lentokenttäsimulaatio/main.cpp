#include "Airport.h"
#include "RANDOM.H"
#include <iostream>
using std::cin; using std::endl; using std::cout; using std::flush; using std::cerr;
void run_idle(int time);
void initialize(int &end_time, int &queue_limit, double &arrival_rate, double &departure_rate);
void selectNextIncoming(Airport &airport);
void selectNextOutgoing(Airport &airport);
void assigment1();
void assigment2();
int main()
{
    char userInput[2];
    cout << "Type either 1 for the 1 point assigment, or 2 for the 2 point assigment..." << endl;
    cin.getline(userInput, 2);
    switch (userInput[0]) {
    case '1':
		assigment1();
        break;
    case '2':
		assigment2();
        break;
	default: 
		cout << "Type either 1 or 2  and press ENTER...." << endl;
    };
    system("pause");
    return 0;
}
void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
    cout << time << ": Runway is idle." << endl;
}
void initialize(int &end_time, int &queue_limit,
    double &arrival_rate, double &departure_rate)
    /*
    Pre:  The user specifies the number of time units in the simulation,
    the maximal queue sizes permitted,
    and the expected arrival and departure rates for the airport.
    Post: The program prints instructions and initializes the parameters
    end_time, queue_limit, arrival_rate, and departure_rate to
    the specified values.
    Uses: utility function user_says_yes
    */

{
    cout << "This program simulates an airport." << endl
        << "One plane can land or depart on each runway in each unit of time." << endl;
    cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time? " << flush;
    cin >> queue_limit;
    cout << "How many units of time will the simulation run?" << flush;
    cin >> end_time;
    bool acceptable = false;
    do {
        cout << "Expected number of arrivals per unit time?" << flush;
        cin >> arrival_rate;
        cout << "Expected number of departures per unit time?" << flush;
        cin >> departure_rate;
        if (arrival_rate < 0.0 || departure_rate < 0.0)
            cerr << "These rates must be nonnegative." << endl;
        else
            acceptable = true;

        //if (acceptable && arrival_rate + departure_rate > 1.0)
        //cerr << "Safety Warning: This airport will become saturated. " << endl;

    } while (!acceptable);
}
void selectNextIncoming(Airport &airport)
{
    while (airport.roleOfSelection() != incoming)
        airport.selectNext();
}
void selectNextOutgoing(Airport &airport)
{
    while (airport.roleOfSelection() != outgoing)
        airport.selectNext();
}

void assigment1()
{
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable(true);
    Runway small_airport(queue_limit, both);
    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (small_airport.can_land(current_plane) != success)
                current_plane.refuse();
        }

        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }

        Plane moving_plane;
        switch (small_airport.activity(current_time, moving_plane)) {
            //  Let at most one Plane onto the Runway at current_time.
        case land:
            moving_plane.land(current_time);
            break;
        case takeoff:
            moving_plane.fly(current_time);
            break;
        case idle:
            run_idle(current_time);
        }
    }
    small_airport.shut_down(end_time);
}
void assigment2()
{
    const int RUNWAYS = 2;
    int end_time;            //  time to run simulation
    int queue_limit;         //  size of Runway queues
    int flight_number = 0;
    double arrival_rate, departure_rate;
    initialize(end_time, queue_limit, arrival_rate, departure_rate);
    Random variable(true);
    Airport small_airport(queue_limit, incoming);
    small_airport.addRunway(queue_limit, outgoing);

    for (int current_time = 0; current_time < end_time; current_time++) { //  loop over time intervals

        while (small_airport.roleOfSelection() != incoming) // select the runway for incoming flights
            small_airport.selectNext();
        int number_arrivals = variable.poisson(arrival_rate);  //  current arrival requests
        for (int i = 0; i < number_arrivals; i++) {
            Plane current_plane(flight_number++, current_time, arriving);
            if (small_airport.can_land(current_plane) != success)
                current_plane.refuse();
        }
        while (small_airport.roleOfSelection() != outgoing) // select the runway for outgoing flights
            small_airport.selectNext();
        int number_departures = variable.poisson(departure_rate); //  current departure requests
        for (int j = 0; j < number_departures; j++) {
            Plane current_plane(flight_number++, current_time, departing);
            if (small_airport.can_depart(current_plane) != success)
                current_plane.refuse();
        }
        Plane moving_plane[RUNWAYS];
        for (int i = 0; i < RUNWAYS; i++)
        {
            switch (small_airport.activity(current_time, moving_plane[i])) {
                //  Let at most one Plane onto the Runway at current_time.
            case land:
                moving_plane[i].land(current_time);
                break;
            case takeoff:
                moving_plane[i].fly(current_time);
                break;
            case idle:
                run_idle(current_time);
            }
            small_airport.selectNext();
        }
    }
    small_airport.shut_down(end_time);
}