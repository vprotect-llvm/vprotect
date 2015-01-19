#include <stdio.h>

void print3ptr(void* base, void* end, void* ptr){
    ::printf("Base: %p -- End: %p -- Ptr: %p\n", base, end, ptr);
}

void printptr(void* p){
    ::printf("Pointer: %p\n", p);
}

class A {
public:
    virtual int a(){return 1;}
};
class B : public A {
public:
    virtual int a(){return 2;}
};
class C : public A {
public:
    virtual int a(){return 3;}
};
class D : public C {
public:
    virtual int a(){return 4;}
};
class E : public D {
public:
    virtual int a(){return 5;}
};
class F : public D {
public:
    virtual int a(){return 6;}
};
class G : public C {
public:
    virtual int a(){return 7;}
};

int main(){return (new G())->a();}
