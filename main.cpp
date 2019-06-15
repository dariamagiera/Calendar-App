//
// Created by Daria Magiera on 2019-06-15.
//

//Daria Magiera

//sample usage of vector, map and iterator
#include "Calendar.h"
#include <unistd.h>
#include <iostream>

int main() {

    auto a = new Calendar;
    a->addEvent(19, "My Birthday!");
    a->printColoredCalendar();
    usleep(200000);
    std::cout << "Calendar App" << std::endl;
    usleep(500000);
    a->mainMenu();
    char option;
    std::cin >> option;
    while (option != '4') {

        switch (option) {
            case '0':
                a->printColoredCalendar();
                break;
            case '1': {
                std::cout << std::endl << "Day of July: ";
                int day;
                std::cin >> day;
                std::cin.ignore();
                std::cout << std::endl << "Title of event: ";
                std::string name;
                std::getline(std::cin, name);
                a->addEvent(day, name);
                break;
            }
            case '2': {
                std::cout << std::endl << "Day of July: ";
                int day;
                std::cin >> day;
                std::cin.ignore();
                std::cout << std::endl << std::endl;
                a->printEventsOfDay(day);
                std::cout << std::endl << std::endl << "Which event do you want to be deleted? ";
                int eventNum;
                std::cin >> eventNum;
                a->deleteEvent(day, eventNum);
                break;
            }
            case '3': {
                a->printAllTheEvents();
                break;
            }
            default:
                break;

        }

        a->mainMenu();
        std::cin >> option;

    }

    return 0;
}
