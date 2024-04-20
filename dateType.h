#pragma once

class dateType {
public:

    // postcond: initializes date object w/ given month, day, year
    dateType(int month = 1, int day = 1, int year = 1900);

    // postcond: sets date object to specified month, day, year
    void setDate(int month, int day, int year);

    // postcond: returns monnth of date object
    int getMonth() const;

    // postcond: returns day of date object
    int getDay() const;

    // postcond: returns year of date object
    int getYear() const;

    // postcond: returns true if year of date object is a leap year, false if not
    bool isLeapYear() const;

   // postcond: retuyrns number of days in month of date object 
    int getDaysInMonth() const;

    // postcond: prints mm/dd/yy
    void printDate() const;

    // postcond: displays number of days passed since jan 1 of date of yr
    int daysPassed() const;

    // postcond: returns number of days remaining in yr
    int daysRemaining() const;

    // postcond: sets date object to a future date that is days ahead 
    void setFutureDate(int days);

private:
    int month;
    int day;
    int year;

    // precond: month, day, yr are valid values representing a date, postcond: displays true if date is valid, else false
    bool isValidDate(int month, int day, int year) const;

    // precond: month and yr are valid values representing a date, postcond: returns number of days in the spcified month of the given  yr
    int getDaysInMonth(int month, int year) const;
};
