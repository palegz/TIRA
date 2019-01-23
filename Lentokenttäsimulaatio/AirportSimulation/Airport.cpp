#include "Airport.h"
#include <iostream>
using std::cout; using std::endl;

Airport::Airport(int limit, Runway_role role) :currentSelection(0)
{
    runways.push_back(Runway(limit, role));
}
Airport::~Airport()
{
}
void Airport::addRunway(int limit, Runway_role role)
{
    runways.push_back(Runway(limit, role));
}
int Airport::runwayCount()
{
    return runways.size();
}
Error_code Airport::can_land(const Plane &current)
{
    return runways.at(currentSelection).can_land(current);
}
Error_code Airport::can_depart(const Plane &current)
{
    return runways.at(currentSelection).can_depart(current);
}
Runway_activity Airport::activity(int time, Plane &moving)
{
    return runways.at(currentSelection).activity(time, moving);
}
void Airport::shut_down(int time) const
{
    cout << "\nAIRPORT SIMULATION FINISHED"
        << "\nPrinting stats for all runways" << endl;
    for (unsigned i = 0; i < runways.size(); i++)
    {
        cout << "\nRunway number " << i + 1 << ".";
        runways.at(i).shut_down(time);
    }
}
void Airport::selectNext()
{
    currentSelection++;
    if (currentSelection >= runways.size())
        currentSelection = 0;
}
Runway_role Airport::roleOfSelection()
{
    return runways.at(currentSelection).getRole();
}
unsigned Airport::sizeOfIncomingQueueForSelection()
{
    return runways.at(currentSelection).sizeOfIncomingQueue();
}
unsigned Airport::sizeOfOutgoingQueueForSelection()
{
    return runways.at(currentSelection).sizeOfOutoingQueue();
}

