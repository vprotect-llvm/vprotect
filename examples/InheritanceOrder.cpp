#include <iostream>

#define offsetof(CLASS, MEMBER) ((size_t) &((CLASS*) NULL)->MEMBER)

class A {
public:
    int a;
};

class B {
public:
    int b;
};

class C: public A, public B {
public:
    int c;
};

class D: public B, public A {
public:
    int d;
};

int main(void){
    std::cout << "sizeof(A) = " << sizeof(A) << std::endl;
    std::cout << "sizeof(B) = " << sizeof(B) << std::endl;
    std::cout << "sizeof(C) = " << sizeof(C) << std::endl;

    std::cout << "offsetof(A, a) = " << offsetof(A, a) << std::endl;
    std::cout << "offsetof(B, b) = " << offsetof(B, b) << std::endl;

    std::cout << "offsetof(C, a) = " << offsetof(C, a) << std::endl;
    std::cout << "offsetof(C, b) = " << offsetof(C, b) << std::endl;
    std::cout << "offsetof(C, c) = " << offsetof(C, c) << std::endl;

    std::cout << "offsetof(D, a) = " << offsetof(D, a) << std::endl;
    std::cout << "offsetof(D, b) = " << offsetof(D, b) << std::endl;
    std::cout << "offsetof(D, d) = " << offsetof(D, d) << std::endl;
    
    return 0;
}
