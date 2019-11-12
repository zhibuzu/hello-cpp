/***************************************************************************
 * 
 * Copyright (c) 2019 Hulifa.cn, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file src/类的拷贝函数与赋值函数/main.cpp
 * @author hulifa(hulifa@gmail.com)
 * @date 2019/11/07 11:14:14
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <vector>

class Dog {
public:
    Dog(std::string name, int age) {
        _name = name;
        _age = age;
    };
    ~Dog() {};

public:
    // say 
    void say() {
        std::cout << "My name is " << _name << ", ";
        std::cout << "I am " << _age << " years old." << std::endl;
    };

public:
    // copy constuctor
    Dog(const Dog& d)  {
        std::cout << "Copy" << std::endl;
        std::cout << "My name is " << d._name << ", ";
        std::cout << "I am " << d._age << " years old." << std::endl;
        std::cout << "End copy" << std::endl;
        _name = d._name;
        _age = d._age;
    };

public:
    // move constructor
    Dog(Dog&& d) {
        std::cout << "Move" << std::endl;
        std::cout << "My name is " << d._name << ", ";
        std::cout << "I am " << d._age << " years old." << std::endl;
        std::cout << "End move" << std::endl;
        _name = d._name;
        _age = d._age;
        d._name = "";
        d._age = 0;
    };

    // move assignment
    Dog& operator=(Dog&& d) {
        std::cout << "Move Assignment" << std::endl;
        std::cout << "My name is " << d._name << ", ";
        std::cout << "I am " << d._age << " years old." << std::endl;
        std::cout << "End Move Assignment" << std::endl;
    
        if (this != &d) {
            _name = d._name;
            _age = d._age;
            d._name = "";
            d._age = 0;
        }

        return *this;
    };
public:
    // assignment
    Dog& operator=(const Dog& d) {
        std::cout << "Assignment" << std::endl;
        std::cout << "My name is " << d._name << ", ";
        std::cout << "I am " << d._age << " years old." << std::endl;
        std::cout << "End Assignment" << std::endl;

        _name = d._name;
        _age = d._age;
        return *this;
    };

private:
    std::string _name;
    int _age;
};

template <class T> void swap(T& a, T& b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
};

int main() {
    Dog a(std::string("wangcai"), 2);
    a.say();
    //Dog a = Dog(std::string("wangcai"), 2);
    //a.say();

    Dog b("xiaohei", 4);
    //Dog b = Dog(std::string("xiaohei"), 4);
    b.say();

    // copy a
    Dog c(a);
    c.say();

    Dog e = a;
    e.say();
    
    Dog f(Dog("dabin", 5));
    f.say();

    std::vector<Dog> vt;
    vt.push_back(Dog("xiaobao", 7));

    // assignment
    Dog d("xiaobai", 8);
    d.say();
    d = b;
    d.say();

    d = Dog("baba", 6);
    d.say();

    Dog g = Dog("gg", 1);
    g.say();
    g = Dog("gg2", 2);
    g.say();
    
    // swap
    Dog a1("a1", 1);
    Dog a2("a2", 2);
    swap(a1, a2);
}


/* vim: set ts=4 sw=4 sts=4 tw=100 */
