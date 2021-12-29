#include <iostream>

class A {
    mutable int _data;

    public:
    A(int data): _data(data) {}
    void doSomething(int x) const {
        _data = x;
    }

    void printData() const {
        std::cout << "data: " << _data << std::endl;
    }
};

int main() {
    A a(10);
    a.doSomething(3);
    a.printData();
}