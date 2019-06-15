//
// Created by Daria Magiera on 2019-06-15.
//
#include "Day.h"


Day::Day() {

    events.reserve(10);
    availability = true;

}

void Day::setAvailability(bool input) {
    availability = input;
}

bool Day::isAvailable() {
    return availability;
}


