#include <iostream>
#include "dateType.h"
// precond: month, day, yr are valid values representing date, postcond: initializes date object with given month, day, yr
dateType::dateType(int month, int day, int year) {
    setDate(month, day, year);
}

void dateType::setDate(int m, int d, int y) {
    // precond: m, d, y are integers represending date, postcond: sets date object to specified month, day, yr if date valid
    if (isValidDate(m, d, y)) {
        month = m;
        day = d;
        year = y;
    }
    else {
        std::cerr << "Invalid date. Defaulting to 1/1/1900." << std::endl;
        month = 1;
        day = 1;
        year = 1900;
    }
}

int dateType::getMonth() const {
    // postcond: returns month of date object
    return month;
}

int dateType::getDay() const {
    // postcond: returns day of date object
    return day;
}

int dateType::getYear() const {
    // postcond: retuns yr of date object
    return year;
}

bool dateType::isLeapYear() const {
    // postcond: returns true if year of date object is leap yr, false if not
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int dateType::getDaysInMonth() const {
    // postcond: returns number of days in month of date obj
    return getDaysInMonth(month, year);
}

void dateType::printDate() const {
    // postcond: prints date object in format mm-dd-yy
    std::cout << month << "-" << day << "-" << year;
}

int dateType::daysPassed() const {
    // postcond: returns number of days passed since jan 1 of date objects' yr
    int daysPassed = day;
    for (int m = 1; m < month; ++m) {
        daysPassed += getDaysInMonth(m, year);
    }
    return daysPassed;
}

int dateType::daysRemaining() const {
    // postcond: returns number of days remaining in date objects yr
    return isLeapYear() ? (366 - daysPassed()) : (365 - daysPassed());
}

void dateType::setFutureDate(int days) {
    // precond: days is positive integer; postcond: sets date object to a future date that is days ahead of current date
    int totalDays = daysPassed() + days;
    while (totalDays > (isLeapYear() ? 366 : 365)) {
        totalDays -= isLeapYear() ? 366 : 365;
        year++;
    }
    int m = 1;
    while (totalDays > getDaysInMonth(m, year)) {
        totalDays -= getDaysInMonth(m, year);
        m++;
    }
    month = m;
    day = totalDays;
}

bool dateType::isValidDate(int m, int d, int y) const {
    // precond: m, d, and ya re integers representing date, postcond: returns true if date represneted by m, d, and y is valid, false otherwise
    if (m < 1 || m > 12) return false;
    if (d < 1 || d > getDaysInMonth(m, y)) return false;
    if (y < 1900) return false;
    return true;
}

int dateType::getDaysInMonth(int m, int y) const {
    // precond: m is integer representing a month, and y is an integer representing year, postcond: returns number of days in specified month of given year
    switch (m) {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear() ? 29 : 28;
    default:
        return 31;
    }
}
