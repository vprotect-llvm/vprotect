#include<stdio.h>

void printptr(void* p){
    ::printf("Pointer: %p\n", p);
}

class A {
    public: 
    virtual void foo(int i) { 
        printf("A::foo(%d)\n", i); 
    }
};

class B : public A {
    public: 
    virtual void foo(int i) { 
        printf("B::foo(%d)\n", i); 
    }
};

int main(){
    void (A::*f)(int); // declare f as ptr to some method of A
    f = &A::foo; // f now points to the foo method
    A* a = new A();
    a->foo(1);
    (a->*f)(2); // method call via f ptr, invokes A::foo
    
    a = new B();
    a->foo(3);
    (a->*f)(4); // method call via f ptr, invokes B::foo
    
    return 0;
}
