#include <iostream>

class Foo {

public:
    // single parameter constructor, can be used as an implicit conversion
    explicit Foo (int foo) : m_foo (foo) {} 
    Foo(double foo) : m_foo(foo - 1) {}

    int GetFoo () { return m_foo; }

private:
    int m_foo;
};
    
// Here's a simple function that takes a Foo object:
void DoBar (Foo foo){
    int i = foo.GetFoo ();
    std::cout << i << std::endl;
}

// and here's where the DoBar function is called.
int main (){
    DoBar (42);
}
