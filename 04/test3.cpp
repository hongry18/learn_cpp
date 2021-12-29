#include <iostream>

class string {
    char* str;
    int len;

public:
    string(char c, int n);
    string(const char *s);
    string(const string &s);
    ~string();

    int strlen();
    void addString(const string &s);
    void copyString(const string &s);
};


int string::strlen() {
    return len;
}

string::string(char c, int n) {
    len = n;
    int i;
    str = new char[len+1];
    for (i=0; i<n; i++) {
        str[i] = c;
    }
    str[i] = (char)NULL;
}

string::string(const char *s) {
    len = 0;
    while(*s) {
        len++;
        s++;
    }

    s -= len;

    int i;
    str = new char[len+1];
    for (i=0; i<len; i++, s++) {
        str[i] = *s;
    }

    str[i] = (char)NULL;
}

string::string(const string &s) {
    len = s.len;
    str = new char[len+1];
    char *c = s.str;
    int i;
    for (i=0; i<len; i++, c++) {
        str[i] = *c;
    }
    str[i] = (char)NULL;
}

string::~string() {
    if (str) delete[] str;
}

void string::addString(const string &s) {
    int new_len = len + s.len;
    char *tmp = new char[new_len+1];
    char *ori = str;
    char *add = s.str;
    int i=0;

    while(*ori) {
        tmp[i++] = *ori;
        ori++;
    }
    while(*add) {
        tmp[i++] = *add;
        add++;
    }
    tmp[i] = (char)NULL;

    if (str) {
        delete[] str;
    }
    len = new_len;
    str = new char[len+1];
    i=0;
    while(*tmp) {
        str[i++] = *tmp;
        tmp++;
    }
    str[i] = (char)NULL;
}

void string::copyString(const string &s) {
    if (str) {
        delete[] str;
    }
    len = s.len;
    str = new char[len+1];
    char *c = s.str;
    int i;
    for(i=0; i<len; i++, c++) {
        str[i] = *c;
    }
    str[i] = (char)NULL;
}

int main() {

    string s1('o', 4);
    string s2("abcd");
    string s3(s1);
    string s4(s2);

    std::cout << s1.strlen() << std::endl;
    std::cout << s2.strlen() << std::endl;
    s3.addString(s1);
    std::cout << s3.strlen() << std::endl;
    s4.copyString(s3);
    std::cout << s4.strlen() << std::endl;

    return 0;
}
