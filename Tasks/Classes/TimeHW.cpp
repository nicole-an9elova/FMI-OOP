#include <iostream>

//9.1
class Time
{
public:
    size_t hours;
    size_t minutes;

    Time();
    Time(const size_t h, const size_t m);
    Time(const Time& other);

    void setHours(size_t hours);
    size_t getHours();
    void setMinutes(size_t minutes);
    size_t getMinutes();

    void print();

    void addMinutes(size_t minutesToAdd);
    size_t minutesPassed();
    bool operator< (Time other);
    Time operator+ (Time other);
    Time operator- (Time other);
    Time operator* (int number);
};

int main()
{
    Time time1 = Time(9, 55);
    time1.addMinutes(131);
    time1.print();
    std::cout << time1.minutesPassed() << std::endl;
    Time time2 = Time(1, 55);
    Time time3 = time1 + time2;
    time3.print();
    Time time4 = time3 - time1; 
    time4.print();
    Time time5 = time2 * 3;
    time5.print();

    return 0;
}

Time::Time()
{
    this->hours = 0;
    this->minutes = 0;
}

Time::Time(const size_t h, const size_t m)
{
    setHours(h);
    setMinutes(m);
}

Time::Time(const Time& other)
{
    setHours(other.hours);
    setMinutes(other.minutes);
}

void Time::setHours(size_t hours)
{
    if (hours >= 0 && hours <= 23)
        this->hours = hours;
    else
        this->hours = hours - 24;
}

size_t Time::getHours()
{
    return this->hours;
}

void Time::setMinutes(size_t minutes)
{
    if (minutes >= 0 && minutes < 60)
        this->minutes = minutes;
    else {
        this->minutes = minutes - 60;
    }
}

size_t Time::getMinutes()
{
    return this->minutes;
}

void Time::print()
{
    if (getMinutes() < 10)
        std::cout << getHours() << ":0" << getMinutes() << std::endl;
    else
        std::cout << getHours() << ":" << getMinutes() << std::endl;
}

void Time::addMinutes(size_t minutesToAdd)
{
    size_t newMinutes = this->minutes + minutesToAdd;
    size_t newHours = this->hours;
    while (newMinutes >= 60) {
        newHours++;
        newMinutes -= 60;
    }
    setMinutes(newMinutes);
    setHours(newHours);
}

size_t Time::minutesPassed()
{
    return this->hours * 60 + this->minutes;
}

bool Time::operator<(Time other)
{
    return this->minutesPassed() < other.minutesPassed();
}

Time Time::operator+(Time other)
{
    size_t allMinutes = this->minutesPassed() + other.minutesPassed();
    size_t hour = allMinutes / 60;
    size_t mins = allMinutes % 60;
    return Time(hour, mins);
}

Time Time::operator-(Time other)
{
    size_t allMins = this->minutesPassed() - other.minutesPassed();
    size_t hour = allMins / 60;
    size_t mins = allMins % 60;
    return Time(hour, mins);
}

Time Time::operator*(int number)
{
    size_t allMins = this->minutesPassed() * number;
    return Time(allMins / 60, allMins % 60);
}
