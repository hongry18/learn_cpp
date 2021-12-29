#include <iostream>

class Complex {
    private:
    double real, img;

    public:
    Complex(double real, double img): real(real), img(img) {}

    Complex operator+(const Complex& c) const;
    Complex operator-(const Complex& c) const;
    Complex operator*(const Complex& c) const;
    Complex operator/(const Complex& c) const;
    Complex operator=(const Complex& c);

    Complex operator+(const char* str);
    Complex operator-(const char* str);
    Complex operator*(const char* str);
    Complex operator/(const char* str);
    double get_number(const char* str, int from, int to) const;

    Complex(const char* str);

    Complex& operator+=(const Complex& c);
    Complex& operator-=(const Complex& c);
    Complex& operator*=(const Complex& c);
    Complex& operator/=(const Complex& c);

    void println() {
        std::cout << "( " << real << ", " << img << " )" << std::endl;
    }
};

// Complex Complex::operator+(const Complex& c) const {
//     Complex tmp(real + c.real, img + c.img);
//     return tmp;
// }

Complex Complex::operator+(const Complex& c) const {
    // real += c.real;
    // img += c.img;
    // return *this;
    Complex tmp(real + c.real, img + c.img);
    return tmp;
}

Complex Complex::operator-(const Complex& c) const {
    Complex tmp(real - c.real, img - c.img);
    return tmp;
}

Complex Complex::operator*(const Complex& c) const {
    Complex tmp(real * c.real - img * c.img, real * c.img + img * c.real);
    return tmp;
}

Complex Complex::operator/(const Complex& c) const {
    Complex tmp(
        (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
        (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img)
    );
    return tmp;
}

Complex Complex::operator=(const Complex& c) {
    real = c.real;
    img = c.img;
    return *this;
}

Complex& Complex::operator+=(const Complex& c) {
    (*this) = (*this) + c;
    return *this;
}

Complex& Complex::operator-=(const Complex& c) {
    (*this) = (*this) - c;
    return *this;
}

Complex& Complex::operator*=(const Complex& c) {
    (*this) = (*this) * c;
    return *this;
}

Complex& Complex::operator/=(const Complex& c) {
    (*this) = (*this) / c;
    return *this;
}

Complex::Complex(const char* str) {
    int begin = 0, end = strlen(str);
    img = 0.0;
    real = 0.0;

    int pos_i = -1;
    for (int i=0; i<end; i++) {
        if (str[i] != 'i') {
            continue;
        }
        pos_i=i;
        break;
    }

    if (pos_i == -1) {
        real = get_number(str, begin, end - 1);
        return;
    }

    real = get_number(str, begin, pos_i - 1);
    img = get_number(str, pos_i + 1, end - 1);

    if (pos_i >= 1 && str[pos_i - 1] == '-') img *= -1.0;
}

Complex Complex::operator+(const char* str) {
    Complex tmp(str);
    return (*this) + tmp;
}

Complex Complex::operator-(const char* str) {
    Complex tmp(str);
    return (*this) - tmp;
}

Complex Complex::operator*(const char* str) {
    Complex tmp(str);
    return (*this) * tmp;
}

Complex Complex::operator/(const char* str) {
    Complex tmp(str);
    return (*this) / tmp;
}

double Complex::get_number(const char* str, int from, int to) const {
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
            num += (str[i] - '0');
            continue;
        }
        
        if (str[i] == '.') {
            integer_part = false;
            continue;
        }
        
        if (isdigit(str[i]) && !integer_part) {
            decimal /= 10.0;
            num += ((str[i] - '0') * decimal);
            continue;
        }

        break;
    }

    if (minus) num *= -1.0;

    return num;
}

int main() {
    // Complex a(1.0, 2.0);
    // Complex b(3.0, -2.0);
    // a += b;
    // a.println();
    // b.println();

    Complex a(0, 0);
    a = a + "-1.1 + i3.923";
    a.println();
    a = a - "1.2 -i1.823";
    a.println();
    a = a * "2.3+i22";
    a.println();
    a = a / "-12 -i1.823";
    a.println();
    return 0;
}