// This program defines a class named dataType, which represents a day of the week
// It provides functionaslity to set the day, get the day, and print it, as well as the next day, previous day, and add days

#include <string>

class dayType {
public:
    static std::string dayNames[7];

    dayType(const std::string& startDay = dayNames[0]);

    void setDay(const std::string& aDay);
    std::string getDay() const;
    void printDay() const;
    std::string getNextDay() const;
    std::string getPrevDay() const;
    void addDays(int numDays);

private:
    std::string day;
};
