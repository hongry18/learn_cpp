class A {
    private:
    void privateFnc() {}
    int privateNum;

    friend class B;
    friend void func();
};

class B {
    public:
    void b() {
        A a;
        // private 함수, 변수지만 firend를 선언했기에 접근가능
        a.privateFnc();
        a.privateNum = 2;
    }
};

void func() {
    A a;
    // private 함수, 변수지만 firend를 선언했기에 접근가능
    a.privateFnc();
    a.privateNum = 2;
}

int main() {
    
}