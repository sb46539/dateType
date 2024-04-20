#include <iostream>
#include "dateType.h"

int main() {
    // postconds: creates dateType object using default constructor, initalized to 1/1/1900
    dateType date1;
    // postcond: prints date object in format mm-dd-yy to console
    std::cout << "Default constructor: ";
    date1.printDate();
    std::cout << std::endl;

    //postcond: creates dateType object using constructor with specified values, initialized to 2/20/2003
    dateType date2(2003, 2, 20);
    // postcond: prints date object in format mm-dd-yy to console
    std::cout << "Constructor: ";
    date2.printDate();
    std::cout << std::endl;

    //postcond: prints number of days passed since jan 1 of the date object's year
    std::cout << "Number of days passed: " << date2.daysPassed() << std::endl;
    // postcond: prints number of days remaining in date objects yr after current date
    std::cout << "Number of days left: " << date2.daysRemaining() << std::endl;

    // postcond: prints numebr of days in the month of the date object
    std::cout << "Number of days in a month: " << date2.getDaysInMonth() << std::endl;

    // precond: days is a positive integer, postcond: sets date object to a future date that is 'days' days ahead of current date
    date2.setFutureDate(15);
    std::cout << "After 15 days, date will be: ";
    // postcond: prints date object in format mm-dd-yy to console
    date2.printDate();
    std::cout << std::endl;

    // precond: m, d, and y are valid integers representing a date, postcond: set date object to specified month, day, yr
    date2.setDate(2000, date2.getMonth(), date2.getDay());
    std::cout << "Resetting year to 2000: ";
    date2.printDate();
    std::cout << std::endl;

    return 0;
}
