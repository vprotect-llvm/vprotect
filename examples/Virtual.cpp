#include <iostream>

using namespace std;

class A {
private:

    char a;

public:
    char g(){
        return 'a';
    }
    
    virtual int f(){
        return 1;
    }
};

class B : public A {

private:
    long long int b;

public:
    char g(){
        return 'b';
    }

    virtual int f(){
        return 2;
    }
};


int main(){
    A *a = new B();
    cout << a->g() << endl;
    cout << a->f() << endl;
    return 0;
}
