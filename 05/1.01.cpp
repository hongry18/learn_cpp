#include <iostream>
#include <string.h>

class MyString {
    char* _c;
    int _len;
    int _cap;

    public:

    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    int length() const;
    int capacity() const;
    void reserve(int size);

    void print() const;
    void println() const;

    char at(int i) const;

    int compare(MyString& str);
    bool operator==(MyString& str);
};

MyString::MyString(char c) {
    _c = new char[1];
    _c[0] = c;
    _cap = 1;
    _len = 1;
}

MyString::MyString(const char* str) {
    _len = strlen(str);
    _cap = _len;
    _c = new char[_len];
    for (int i=0; i<_len; i++) _c[i] = str[i];
}

MyString::MyString(const MyString& str) {
    _len = str._len;
    _cap = str._cap;
    _c = new char[_len];
    for (int i=0; i<_len; i++) _c[i] = str._c[i];
}

MyString::~MyString() {
    delete[] _c;
}

int MyString::length() const { return _len; }

void MyString::print() const {
    for (int i=0; i<_len; i++) {
        std::cout << _c[i];
    }
}

void MyString::println() const {
    this->print();
    std::cout << std::endl;
}

int MyString::capacity() const { return _cap; }

void MyString::reserve(int size) {
    if (size <= _cap) {
        return;
    }

    char* tmp = _c;
    _cap = size;
    _c = new char[_cap];

    for (int i=0; i<_len; i++) {
        _c[i] = tmp[i];
    }

    delete[] tmp;
}

char MyString::at(int i) const {
    if (i >= _len || i < 0) {
        return 0;
    }

    return _c[i];
}

int MyString::compare(MyString& str) {
    for (int i=0, e=std::min(_len, str._len); i<e; i++) {
        if (_c[i] > str._c[i]) {
            return 1;
        }

        if (_c[i] < str._c[i]) {
            return -1;
        }
    }

    if (_len == str._len) return 0;
    if (_len > str._len) return 1;

    return -1;
}

bool MyString::operator==(MyString& str) {
    return !this->compare(str);
}

int main() {
    MyString s1("a word");
    MyString s2("sentence");
    MyString s3("sentence");
    
    if (s1 == s2) {
        std::cout << "s1 == s2" << std::endl;
    } else {
        std::cout << "s1 != s2" << std::endl;
    }

    if (s2 == s3) {
        std::cout << "s2 == s3" << std::endl;
    } else {
        std::cout << "s2 != s3" << std::endl;
    }
    return 0;
}