#include <iostream>

int func() {
    int a = 5;
    return a;
}

int main() {
    const int& c = func();
    std::cout << "c : " << c << std::endl;
    return 0;
}
