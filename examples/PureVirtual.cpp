#include <stdio.h>
#include <typeinfo>

void printptr(void* p){
    ::printf("Pointer: %p\n", p);
}

class A {
public:
    virtual void f(int i) = 0; 
};

class C: public A {
public:
    virtual void f(int i) {
        ::printf("C::f(%d)\n", i);
    }
};

class B: public A {
public:
    virtual void f(int i) {
        ::printf("B::f(%d)\n", i);
    }
}; 

int main(void){
    A* a = new B();
    a->f(1);
    ::printf("typeid.name = %s\n", typeid(a).name());
    return 0;
}
