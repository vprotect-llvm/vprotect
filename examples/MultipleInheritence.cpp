#include<stdio.h>

void printptr(void* p){
    ::printf("Pointer: %p\n", p);
}

class A {
public:
    virtual void foo(int i){ ::printf("A::foo(%d)\n", i); }
};

class B {
public:
    virtual void bar(int i){ ::printf("B::bar(%d)\n", i); }
};

class C: public A, public B {
public:
    virtual void foo(int i){ ::printf("C::foo(%d)\n", i); }
    virtual void bar(int i){ ::printf("C::bar(%d)\n", i); }
};

int main(void){
    A *a = new C();

    a->foo(1);
    
    B *b = new C();

    b->bar(2);
    
    return 0;
}
