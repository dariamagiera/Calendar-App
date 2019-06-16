#ifndef THELASTONE_EVENT_H
#define THELASTONE_EVENT_H
#include <iostream>

class Event {

    std::string event;

public:

    Event(std::string e);

    std::string getEventName();

};

#endif //THELASTONE_EVENT_H
