#include <iostream>
#include <cstring>

class Complex {
    private:
    double real, img;

    double getNumber(const char* str, int from, int to) const;

    public:
    Complex(double real, double img) : real(real), img(img) {}
    Complex(const Complex& c) {real = c.real; img = c.img;}
    Complex(const char* str);

    // Complex operator+(const Complex& c) const;
    Complex& operator=(const Complex& c);

    void println() {
        std::cout << "(" << real << ", " << img << ")" << std::endl;
    }

    friend Complex operator+(const Complex& a, const Complex& b);
};

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.img + b.img);
}

Complex::Complex(const char* str) {
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos = -1;
    for (int i=0; i<end; i++) {
        if (str[i] != 'i') {
            continue;
        }
        pos = i;
        break;
    }

    if (pos < 0) {
        real = this->getNumber(str, begin, end-1);
        return;
    }

    real = this->getNumber(str, begin, pos-1);
    img = this->getNumber(str, pos+1, end-1);

    if (pos > 0 && str[pos-1] == '-') img *= -1.0;
}

double Complex::getNumber(const char* str, int from, int to) const {
    bool minus = false;
    if (from > to) return 0;
    if (str[from] == '-') minus = true;
    if (str[from] == '-' || str[from] == '+') from++;

    double num = 0.0;
    double decimal = 1.0;

    bool integer_part = true;
    for (int i=from; i<=to; i++) {
        if (isdigit(str[i]) && integer_part) {
            num *= 10.0;
            num += str[i] - '0';
        } else if (str[i] == '.') {
            integer_part = false;
        } else if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
        } else {
            break;
        }
    }

    if (minus) num *= -1.0;

    return num;
}

// Complex Complex::operator+(const Complex& c) const {
//     return Complex(real + c.real, img + c.img);
// }

Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

int main() {
    Complex a(0, 0);
    a = "-1.1 + i3.923" + a;
    a = a+a;

    Complex b(1, 2);
    b = a + b;
    b.println();
}