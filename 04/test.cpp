#include <iostream>

const int last_day_of_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class Date {
private:
    int year_;
    int month_;
    int day_;

public:
    void set_date(int y, int m, int d) {
        year_ = y;
        month_ = m;
        day_ = d;
    }

    void add_day(int inc) {
        day_ += inc;

        while (1) {
            int calc_day = last_day_of_month[month_ - 1];
            if (month_ == 2 && ((year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0)) {
                calc_day += 1;
            }

            if (day_ <= calc_day) {
                break;
            }

            day_ -= calc_day;
            add_month(1);

            if (month_ < 13) {
                continue;
            }

            add_month(-12);
            add_year(1);
        }
    }

    void add_month(int inc) {
        month_ += inc;

        if (month_ < 13) {
            return;
        }

        int tmp = month_ / 12;
        add_year(tmp);
        month_ = month_ % 12;

        if (month_ == 0) {
            month_ = 12;
        }
    }

    void add_year(int inc) {
        year_ += inc;
    }

    void show_date() {
        std::cout << year_ << "-" << month_ << "-" << day_ << std::endl;
    }
};

int main() {
    Date date;
    date.set_date(2012, 2, 28);

    //date.add_year(5);
    //date.add_month(11);
    date.add_day(365*5);

    date.show_date();
    return 0;
}
