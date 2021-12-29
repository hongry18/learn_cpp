#include <iostream>

class MyString {
    char *content;
    int len;
    int cap;

    public:
    explicit MyString(int capacity);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length() const;
};

MyString::MyString(int capacity) {
    cap = capacity;
    len = 0;
    content = new char[cap];
    std::cout << "Capacity : " << cap << std::endl;
}

MyString::MyString(const char* str) {
    len = 0;
    while(str[len++]) {}
    content = new char[len];
    cap = len;
    for (int i=0; i<len; i++) {
        content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    len = str.len;
    cap = str.len;
    content = new char[len];
    for (int i=0; i<len; i++) {
        content[i] = str.content[i];
    }
}

MyString::~MyString() {
    delete[] content;
}

int MyString::length() const {
    return len;
}

void doSomethingWithString(MyString s) {

}

int main() {
    MyString s1(3);
    doSomethingWithString("abc");
    return 0;
}
