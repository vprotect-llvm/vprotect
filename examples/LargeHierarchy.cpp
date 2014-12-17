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
