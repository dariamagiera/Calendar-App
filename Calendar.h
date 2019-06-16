#ifndef THELASTONE_CALENDAR_H
#define THELASTONE_CALENDAR_H
#include <iostream>
#include <map>
#include "Day.h"
#include <iomanip>

class Calendar {

private:

    static std::map<int, Day *> mapOfDays;

public:

    static std::map<int, Day *> init();

    static std::ostream &bold_on(std::ostream &os);

    static std::ostream &bold_off(std::ostream &os);

    static void printPlainCalendar();

    static void printColoredDay(int day);

    void printColoredCalendar();

    void addEvent(int day, const std::string &eventName);

    void deleteEvent(int day, int numOfEvent);

    void printEventsOfDay(int day);

    void printAllTheEvents();

    void mainMenu();
};

#endif //THELASTONE_CALENDAR_H
