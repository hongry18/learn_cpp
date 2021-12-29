#include <iostream>

class A {
    int x;

    public:
    A(int c): x(c) {}

    int &accessX() { return x; }
    int getX() { return x; }
    void showX() { std::cout<< x << std::endl; }
};

int main() {
    A a(5);
    a.showX();

    int &c = a.accessX();
    c = 4;
    std::cout << std::endl;
    std::cout << c << std::endl;
    a.showX();

    int d = a.accessX();
    d = 3;
    std::cout << std::endl;
    std::cout << d << std::endl;
    a.showX();

    int f = a.getX();
    f = 1;
    std::cout << std::endl;
    std::cout << f << std::endl;
    a.showX();

    return 0;
}
