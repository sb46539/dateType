#include <iostream>
#include "dateType.h"

int main() {

    dateType date1;
    std::cout << "Default constructor: ";
    date1.printDate();
    std::cout << std::endl;

    dateType date2(2003, 2, 20);
    std::cout << "Constructor: ";
    date2.printDate();
    std::cout << std::endl;

    std::cout << "Number of days passed: " << date2.daysPassed() << std::endl;
    std::cout << "Number of days left: " << date2.daysRemaining() << std::endl;

    std::cout << "Number of days in a month: " << date2.getDaysInMonth() << std::endl;

    date2.setFutureDate(15);
    std::cout << "After 15 days, date will be: ";
    date2.printDate();
    std::cout << std::endl;


    date2.setDate(2000, date2.getMonth(), date2.getDay());
    std::cout << "Resetting year to 2000: ";
    date2.printDate();
    std::cout << std::endl;

    return 0;
}
