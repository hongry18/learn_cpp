#include <iostream>
#include <string.h>

class MyString {
    char *content;
    int len;
    int cap;

    public:
    MyString(char c);
    MyString(const char* str);
    MyString(const MyString& str);
    ~MyString();

    MyString& assign(const MyString& str);
    MyString& assign(const char* str);

    int length() const;
    int capacity() const;

    void reserve(int size);

    void print() const;
    void println() const;

    char at(int i) const;

    int find(int find_from, const MyString& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, char c) const;

    int compare(const MyString& str) const;

    MyString& insert(int loc, const MyString& str);
    MyString& insert(int loc, const char* str);
    MyString& insert(int loc, char c);

    MyString& erase(int loc, int num);
};

MyString::MyString(char c) {
    content = new char[1];
    content[0] = c;
    len = 1;
    cap = 1;
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
    cap = str.len;
    content = new char[len];
    for (int i=0; i<len; i++) {
        content[i] = str.content[i];
    }
}

MyString::~MyString() {
    delete[] content;
}

MyString& MyString::assign(const MyString& str) {
    if (str.len > cap) {
        delete[] content;
        content = new char[str.len];
        cap = str.len;
    }

    for (int i=0; i<str.len; i++) {
        content[i] = str.content[i];
    }

    len = str.len;
    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_len = strlen(str);
    if (str_len > cap) {
        delete[] content;
        content = new char[str_len];
        cap = str_len;
    }

    for (int i=0; i<str_len; i++) {
        content[i] = str[i];
    }

    len = str_len;
    return *this;
}

int MyString::capacity() const { return cap; }

int MyString::length() const {
    return len;
}

void MyString::print() const {
    for (int i=0; i<len; i++) {
        std::cout << content[i];
    }
}

void MyString::println() const {
    for (int i=0; i<len; i++) {
        std::cout << content[i];
    }
    std::cout << std::endl;
}

void MyString::reserve(int size) {
    if (size <= cap) {
        return;
    }

    char* prev_content = content;
    content = new char[size];
    cap = size;

    for (int i=0; i<len; i++) {
        content[i] = prev_content[i];
    }
    delete[] prev_content;
}

char MyString::at(int i) const {
    if (i >= len || i < 0 ) {
        return 0;
    }

    return content[i];
}

MyString& MyString::insert(int loc, const char* str) {
    MyString tmp(str);
    return insert(loc, tmp);
}

MyString& MyString::insert(int loc, char c) {
    MyString tmp(c);
    return insert(loc, tmp);
}

MyString& MyString::insert(int loc, const MyString& str) {
    if (loc < 0 || loc > len ) {
        return *this;
    }

    if (len + str.len > cap) {
        if (cap * 2 > len + str.len ) {
            cap *= 2;
        } else {
            cap = len + str.len;
        }

        char* prev_content = content;
        content = new char[cap];

        int i;
        for (i =0; i<loc; i++) {
            content[i] = prev_content[i];
        }
        for (int j=0; j < str.len; j++) {
            content[i+j] = str.content[j];
        }

        for (; i < len; i++) {
            content[str.len + i] = prev_content[i];
        }

        delete[] prev_content;

        len = len + str.len;
        return *this;
    }

    for (int i=len-1; i >= loc; i--) {
        content[i + str.len] = str.content[i];
    }

    for (int i=0; i<str.len; i++) {
        content[i + loc] = str.content[i];
    }

    len = len + str.len;
    return *this;
}

MyString& MyString::erase(int loc, int num) {
    if (num < 0 || loc < 0 || loc > len || loc+num > len) return *this;

    for (int i=loc+num; i<len; i++) {
        content[i-num] = content[i];
    }

    len -= num;
    return *this;
}

int MyString::find(int find_from, char c) const {
    MyString tmp(c);
    return find(find_from, tmp);
}
int MyString::find(int find_from, const char* str) const {
    MyString tmp(str);
    return find(find_from, tmp);
}
int MyString::find(int find_from, const MyString& str) const {
    if (str.len == 0) return -1;
    int i,j;
    for (i=find_from; i<= len - str.len; i++) {
        for (j=0; j<str.len; j++) {
            if (content[i + j] != str.content[j]) {
                break;
            }
        }

        if ( j == str.len ) return i;
    }

    return -1;
}

int MyString::compare(const MyString& str) const {
    for (int i=0, e=std::min(len, str.len); i<e; i++) {
        if (content[i] > str.content[i]) {
            return 1;
        }

        if (content[i] < str.content[i]) {
            return -1;
        }
    }

    if (len == str.len) return 0;

    if (len > str.len) return 1;

    return -1;
}

int main() {
    MyString s1("abcdef");
    MyString s2("abcde");

    std::cout << "s1 and s2 compare : " << s1.compare(s2) << std::endl;

    return 0;
}
