#include <iostream>

class Test {
    int x;

    public:
    Test(int x) : x(x) {}
    Test(const Test& t) : x(t.x) {}

    Test& operator++() {
        x++;
        std::cout << "전위 증감" << std::endl;
        return *this;
    }

    Test operator++(int) {
        Test tmp(*this);
        x++;
        std::cout << "후위 증감" <<  std::endl;
        return tmp;
    }

    int get() const {
        return x;
    }
};

void func(const Test& t) {
    std::cout << "x : " << t.get() << std::endl;
}

int main() {
    Test t(3);

    func(++t);
    func(t++);
    std::cout << "x : " << t.get() << std::endl;

    return 0;
}