#pragma once

#include <vector>

#include "Runway.h"


class Airport
{
public:
    // Constructs the airport with one runway
    Airport(int limit, Runway_role role);
    ~Airport();

    // Adds 1 runway to the airport
    void addRunway(int limit, Runway_role role);
    // Returns current amount of runways
    int runwayCount();

    Error_code can_land(const Plane &current);
    Error_code can_depart(const Plane &current);
    Runway_activity activity(int time, Plane &moving);

    void shut_down(int time) const;
    // Select next runway for operations
    void selectNext();
    // Return the role of currently selected runway
    Runway_role roleOfSelection();
    // Return the size of current incoming queue for the selected runway
    unsigned sizeOfIncomingQueueForSelection();
    // Return the size of current outgoing queue for the selected runway
    unsigned sizeOfOutgoingQueueForSelection();

private:
    std::vector<Runway> runways;
    unsigned currentSelection;

};


