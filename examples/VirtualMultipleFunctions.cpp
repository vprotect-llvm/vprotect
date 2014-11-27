#include <stdio.h>

class IntSimple {
public:
    int a;
};

class CharSimple {
public:
    char a;
};

class LongSimple {
public:
    long a;
};

typedef int fun();
class FunctionSimple {
public:
    long t;
    fun** u;
    virtual int a(int b){return b+3;}
};

class A {
public:
    int a;

    virtual int x(){return 1;}
    virtual char y(){return 11;}
    virtual long z(){return 111;}

};

class B: public A {
public:
    int b;
    virtual int a(){return 45;}
    virtual int x(){return 2;}
    virtual char y(){return 22;}
    virtual long z(){return 222;}
};

class C: public B {
public:
    long c;
    virtual int a(){return 54;} 
    virtual char y(){return 33;}
};

int stoopid(){
    return 42;
}

int main(void){
    IntSimple* a = new IntSimple();
    CharSimple* b = new CharSimple();
    LongSimple* c = new LongSimple();
    FunctionSimple* d = new FunctionSimple();
    fun* t = &stoopid;
    d->u = &t;
    int e = d->a(a->a);

    A* var = new B();
    int x = var->x();
    char y = var->y();
    long z = var->z();
    B* val = new C();
    printf("%d\n", val->a());

    printf("%d %d %ld\n", x, y, z);
    delete var;
    return 0;
}
