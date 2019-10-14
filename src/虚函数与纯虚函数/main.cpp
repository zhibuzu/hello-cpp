#include <iostream>
#include <cstdio>

// Parent-Parent class
class ParentParent {
public:
    ParentParent() {
        std::cout << "Hi, I am ParentParent\n";
    }
    virtual ~ParentParent() {
        std::cout << "Bye, I am ParentParent\n";
    }
};

// Base class
class Base : public ParentParent {
public:
    Base() {
        std::cout << "Hi, I am Base\n";
    }
    virtual ~Base() {
        std::cout << "Bye, I am Base\n";
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {
        std::cout << "Hi, I am Derived\n";
    }
    ~Derived() {
        std::cout << "Bye, I am Derived\n";
    }
};

int main() {
    std::cout << "===========实例化子类=========\n";
    Derived a;

    std::cout << "===========使用new实例化子类并将子类对象地址赋值给父类指针=======\n";
    Base *b = new Derived;

    std::cout << "==========释放new实例化出来的对象=====\n";
    delete b;

    std::cout << "==========释放stack上的对象=====\n";
}