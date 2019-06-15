//
// Created by Daria Magiera on 2019-06-15.
//

#include "Event.h"
#include <iostream>

Event::Event(std::string e) {
    event = e;
}

std::string Event::getEventName()  {
    return event;
}
