#include "Utility.h"
#include <time.h>
#include <stdlib.h>

using std::cout; using std::cin; using std::endl; using std::flush;


bool user_says_yes()
{
    int c;
    bool initial_response = true;

    do {  //  Loop until an appropriate input is received.
        if (initial_response)
            cout << " (y,n)? " << flush;

        else
            cout << "Respond with either y or n: " << flush;

        do { //  Ignore white space.
            c = cin.get();
        } while (c == '\n' || c == ' ' || c == '    ');
        initial_response = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
    return (c == 'y' || c == 'Y');
}

int create_rand(int floor, int roof)
{
    return floor + (rand() % (roof - floor) + 1);
}


