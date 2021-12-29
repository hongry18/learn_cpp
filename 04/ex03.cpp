#include <iostream>

class Date {
private:
    int year_;
    int month_;
    int day_;

public:
    void setDate(int y, int m, int d);
    void addDay(int i);
    void addMonth(int i);
    void addYear(int i);

    // total days in month
    int getTotalDaysInMonth(int y, int m);

    void showDate();

    Date(int y, int m, int d) {
        year_ = y;
        month_ = m;
        day_ = d;
    }
};

void Date::setDate(int y, int m, int d) {
    year_ = y;
    month_ = m;
    day_ = d;
}

int Date::getTotalDaysInMonth(int y, int m) {
    static int last_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m != 2) {
        return last_day[m - 1];
    }

    // 윤년
    if (y % 4 == 0 && y % 100 != 0) {
        return 29;
    }

    return 28;
}

void Date::addDay(int i) {
    while(true) {
        int last_day = getTotalDaysInMonth(year_, month_);

        if (day_ + i <= last_day) {
            day_ += i;
            return;
        }

        i -= (last_day - day_ + 1);
        day_ = 1;
        addMonth(1);
    }
}

void Date::addMonth(int i) {
    addYear((i+month_-1)/12);

    month_ = month_ + i % 12;
    month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::addYear(int i) { year_ += i; }

void Date::showDate() {
    std::cout << "today is " << year_ << "/" << month_ << "/" << day_ << std::endl;
}

int main() {
/*
    Date day;
    day.setDate(2011,3,1);
    day.showDate();

    day.addDay(30);
    day.showDate();

    day.addDay(2000);
    day.showDate();

    day.setDate(2012,1,31);
    day.addDay(29);
    day.showDate();

    day.setDate(2012,8,4);
    day.addDay(2500);
    day.showDate();
*/

    Date day(2011, 3, 1);
    day.showDate();
    day.addYear(10);
    day.showDate();

    return 0;
}
