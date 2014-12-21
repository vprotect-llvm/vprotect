#include <stdio.h>
class BAD {
public:
    virtual int one(){return 666;}
    virtual int two(){return 666;}
    virtual char three(){return 666;}
    virtual long four(){return 666;}
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
    printf("lodaed vptr for A = %p\n", ((void**) new A())[0]);
    printf("lodaed vptr for B = %p\n", ((void**) new B())[0]);
    printf("lodaed vptr for C = %p\n", ((void**) new C())[0]);
    printf("lodaed vptr for BAD = %p\n", ((void**) new BAD())[0]);
  

    A* var = new B();
    ((void**) var)[0] = ((void**) new BAD())[0];

    int x = var->x();
    char y = var->y();
    long z = var->z();
    B* val = new C();
    printf("%d\n", val->a());

    printf("%d %d %ld\n", x, y, z);
    delete var;
    return 0;
}
