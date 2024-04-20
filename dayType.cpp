#include "dayType.h"
#include <iostream>

std::string dayType::dayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

dayType::dayType(const std::string& startDay) {
    // precond: day of the week
    setDay(startDay);
    // postcond: day is set to startDay 
}

void dayType::setDay(const std::string& aDay) {
    // precond: aDay should be a valid day of the week
    for (const std::string& name : dayNames) {
        if (name == aDay) {
            day = aDay;
            return;
        }
    }
    day = dayNames[0];
    // Postcondition: day is set to aDay if it's valid, otherwise set to "Sunday".
}

std::string dayType::getDay() const {
    // postcond: returns the current day
    return day;
}

void dayType::printDay() const {
    // postcond: prints the current day
    std::cout << day << std::endl;
}

std::string dayType::getNextDay() const {
    // postcond: returns the next day of the current day
    for (int i = 0; i < 7; ++i) {
        if (dayNames[i] == day) {
            return dayNames[(i + 1) % 7];
        }
    }
    return "";
}

std::string dayType::getPrevDay() const {
    // postcond: returns the previous day of the current day
    for (int i = 0; i < 7; ++i) {
        if (dayNames[i] == day) {
            return dayNames[(i + 6) % 7];
        }
    }
    return "";
}

void dayType::addDays(int numDays) {
    // postcond: advances the current day by numDays
    for (int i = 0; i < 7; ++i) {
        if (dayNames[i] == day) {
            day = dayNames[(i + numDays) % 7];
            return;
        }
    }
}
