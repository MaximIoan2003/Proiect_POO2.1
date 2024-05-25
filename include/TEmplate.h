//
// Created by copac on 5/25/2024.
//

#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <iostream>
#include <list>
#include <algorithm>


template<typename T>
class Template1 {
public:
    virtual void afisare() const = 0;
};

template<typename T>

class Template2 : public Template1<T> {
private:
    T ex;
public:
    Template2(const T& ex) : ex(ex) {}

    void afisare() const override {
        std::cout << ex << std::endl;
    }
};

#endif // TEMPLATE_H