#include <stdio.h>

#define GENERATE(CLASS, MEMBER, VALUE) \
class CLASS { \
public: \
  int MEMBER; \
  CLASS(): MEMBER(VALUE) { \
    printf("%s: yay, my address is %p, my size is %zu, and my a is %d!\n", \
           #CLASS, this, sizeof(*this), this->MEMBER); \
  }\
  virtual void print() {\
    printf("I am %s(%d)\n", #CLASS, MEMBER);\
  }\
}

GENERATE(A, a, 1);
GENERATE(B, b, 2);
GENERATE(C, c, 3);
GENERATE(D, d, 4);
GENERATE(E, e, 5);
GENERATE(F, f, 6);
GENERATE(G, g, 7);


class ALL: public A, public B, public C, public D, public E, public F, public G {
public:

  ALL() {
    printf("ALL: yay, my address is %p, my size is %zu, my a, b, c, d, e, f, g are %d, %d, %d, %d, %d, %d, %d!\n",
           this, sizeof(*this), this->a, this->b, this->c, this->d, this->e, this->f, this->g);
  }

  virtual void print() {
    printf("I am ALL(%d, %d, %d, %d, %d, %d, %d)\n", a, b, c, d, e, f, g);
  }
};

int main(){
    ALL all;
    
    A *a = &all;
    B *b = &all;
    C *c = &all;
    D *d = &all;
    E *e = &all;
    F *f = &all;
    G *g = &all;

    all.print();
    a->print();
    b->print();
    c->print();
    d->print();
    e->print();
    f->print();
    g->print();

    return 0;
}
