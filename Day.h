//
// Created by Daria Magiera on 2019-06-15.
//
#ifndef THELASTONE_DAY_H
#define THELASTONE_DAY_H
#include <iostream>
#include <vector>
#include "Event.h"


class Day {

    bool availability;

public:

    std::vector<Event> events;

    Day();

    void setAvailability(bool input);

    bool isAvailable();

};


#endif //THELASTONE_DAY_H

