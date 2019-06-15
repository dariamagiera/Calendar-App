
//
// Created by Daria Magiera on 2019-06-15.
//
#include "Calendar.h"
#include <map>
#include <iomanip>
#include <unistd.h>
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define RESET   "\033[0m"

std::map<int, Day *> Calendar::init() {
    std::map < int, Day * > map;
    for (int i = 1; i <= 31; i++)
        map.insert(std::make_pair(i, new Day));

    return map;
}

std::ostream& Calendar::bold_on(std::ostream &os) {
    return os << "\e[1m";
}

std::ostream& Calendar::bold_off(std::ostream &os) {
    return os << "\e[0m";
}

void Calendar::printPlainCalendar() {
    std::cout << std::setw(41) << " _________ " << std::endl;
    std::cout << std::setw(41) << "|         |" << std::endl;
    std::cout << std::setw(34) << bold_on << "|   JULY  |" << bold_off << std::endl;
    std::cout << " _________ _________ ________ . _______ . ________ _________ _________" << std::endl;
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|    M    |    T    |    W    |    T    |    F    |    S    |    S    |" << std::endl;
    std::cout << "|.....................................................................|" << std::endl;
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|    1    |    2    |    3    |    4    |    5    |    6    |    7    |" << std::endl;
    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|    8    |    9    |    10   |    11   |    12   |    13   |    14   |" << std::endl;
    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|    15   |    16   |    17   |    18   |    19   |    20   |    21   |" << std::endl;
    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|    22   |    23   |    24   |    25   |    26   |    27   |    28   |" << std::endl;
    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    std::cout << "|         |         |         |" << std::endl;
    std::cout << "|    29   |    30   |    31   |" << std::endl;
    std::cout << "|_________|_________|_________|" << std::endl;
    std::cout << std::endl << std::endl;

}

void Calendar::printColoredDay(int day) {

    Day *dayToColor = mapOfDays[day];
    std::cout << "    ";
    if (dayToColor->isAvailable())
        std::cout << GREEN << day << RESET;
    else
        std::cout << RED << day << RESET;
    if (day >= 10)
        std::cout << "   |";
    else
        std::cout << "    |";
}

void Calendar::printColoredCalendar() {

    std::cout << std::endl << std::endl;
    std::cout << std::setw(41) << " _________ " << std::endl;
    std::cout << std::setw(41) << "|         |" << std::endl;
    std::cout << std::setw(34) << bold_on << "|   JULY  |" << bold_off << std::endl;
    std::cout << " _________ _________ ________ . _______ . ________ _________ _________" << std::endl;
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|    M    |    T    |    W    |    T    |    F    |    S    |    S    |" << std::endl;
    std::cout << "|.....................................................................|" << std::endl;
    usleep(200000);
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;
    std::cout << "|";

    for (int i = 1; i <= 7; i++) {
        printColoredDay(i);
    }
    std::cout << std::endl;
    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    usleep(200000);
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;

    std::cout << "|";

    for (int i = 8; i <= 14; i++) {
        printColoredDay(i);
    }
    std::cout << std::endl;

    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    usleep(200000);
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;

    std::cout << "|";

    for (int i = 15; i <= 21; i++) {
        printColoredDay(i);
    }
    std::cout << std::endl;

    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    usleep(200000);
    std::cout << "|         |         |         |         |         |         |         |" << std::endl;

    std::cout << "|";


    for (int i = 22; i <= 28; i++) {
        printColoredDay(i);
    }
    std::cout << std::endl;


    std::cout << "|_________|_________|_________|_________|_________|_________|_________|" << std::endl;
    usleep(200000);
    std::cout << "|         |         |         |" << std::endl;

    std::cout << "|";

    for (int i = 29; i <= 31; i++) {
        printColoredDay(i);
    }
    std::cout << std::endl;
    std::cout << "|_________|_________|_________|" << std::endl;
    std::cout << std::endl << std::endl;

}

void Calendar::addEvent(int day, const std::string &eventName) {

    Day *dayToUpdate = mapOfDays[day];

    //adding new event to list (vector) of events
    dayToUpdate->events.push_back(*new Event(eventName));

    //availability update
    if (dayToUpdate->isAvailable()) {
        dayToUpdate->setAvailability(false);
    }


}

void Calendar::deleteEvent(int day, int numOfEvent) {

    Day *dayToUpdate = mapOfDays[day];

    //removing element from list (vector) of events
    dayToUpdate->events.erase(dayToUpdate->events.begin() + (numOfEvent - 1));

    //availability update
    if (dayToUpdate->events.empty()) {
        dayToUpdate->setAvailability(true);
    }


}

void Calendar::printEventsOfDay(int day) {

    Day *d = mapOfDays[day];
    std::vector<Event>::iterator it;
    int i = 1;
    for (it = d->events.begin(); it < d->events.end(); it++) {
        std::cout << i++ << ". " << it->getEventName() << std::endl;
    }

}

void Calendar::printAllTheEvents() {

    std::cout << std::endl << std::endl;
    int i = 1;
    Day *d;
    for (int j = 1; j <= mapOfDays.size(); j++) {
        if (!(d = mapOfDays[j])->isAvailable()) {

            std::vector<Event>::iterator it;
            for (it = d->events.begin(); it < d->events.end(); it++) {
                std::cout << i++ << ". " << j << "/07/2019 " << it->getEventName() << std::endl;
            }

        }
    }

}

void Calendar::mainMenu() {

    std::cout << std::endl;
    std::cout << "   Press:" << std::endl;
    std::cout << "      0 to display the calendar;" << std::endl;
    std::cout << "      1 to add the new event;" << std::endl;
    std::cout << "      2 to delete the event;" << std::endl;
    std::cout << "      3 to display the list of events;" << std::endl;
    std::cout << "      4 to quit" << std::endl;

}

std::map<int, Day *> Calendar::mapOfDays = Calendar::init();

