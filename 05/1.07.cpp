#include <iostream>
#include <cstring>

class MyString {
    char* content;
    int len;
    int cap;

    public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length();

    void print() const;
    void println() const;

    char& operator[](const int idx);
};

MyString::MyString(char c) {
    content = new char[1];
    content[0] = c;
    cap = 1;
    len = cap;
}

MyString::MyString(const char* str) {
    len = strlen(str);
    cap = len;
    content = new char[len];
    for (int i=0; i<len; i++) {
        content[i] = str[i];
    }
}

MyString::MyString(const MyString& str) {
    len = str.len;
    content = new char[len];
    for (int i=0; i<len; i++) {
        content[i] = str.content[i];
    }
}

MyString::~MyString() {
    delete[] content;
}

int MyString::length() { return len; }

void MyString::print() const {
    for (int i=0; i<len; i++) {
        std::cout << content[i];
    }
}

void MyString::println() const {
    this->print();
    std::cout << std::endl;
}

char& MyString::operator[](const int idx) { return content[idx]; }

int main() {
    MyString str("abcdef");
    str[3] = 'c';

    str.println();
}