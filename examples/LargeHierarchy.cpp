class A {
    virtual int a(){return 1;}
};
class B : public A {
    virtual int a(){return 2;}
};
class C : public A {
    virtual int a(){return 3;}
};
class D : public C {
    virtual int a(){return 4;}
};
class E : public D {
    virtual int a(){return 5;}
};
class F : public D {
    virtual int a(){return 6;}
};
class G : public C {
    virtual int a(){return 7;}
};

int main(){return 0;}
