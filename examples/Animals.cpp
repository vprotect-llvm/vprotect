#include <iostream>

class Animal {
public:
    virtual void talk() = 0;
};

class Dog: public Animal {
public:
    virtual void talk() {
        std::cout << "Woof Woof\n";
    }
};

class Cat: public Animal {
public:
    virtual void talk() {
        std::cout << "Miaou Miaou\n";
    }
};

int main(){
    Cat *myCat = new Cat();
    delete myCat;

    Dog *myDog = new Dog();
    

    myDog->talk();
    myCat->talk();
    
    
    delete myDog;
    return 0;
}
