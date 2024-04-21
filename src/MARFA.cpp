//
// Created by copac on 4/20/2024.
//
#include "Marfa.h"

Marfa::Marfa() : medicamente(""), pret_actual(0) {}

Marfa::Marfa(const std::string& m, int pret) : medicamente(m), pret_actual(pret) {}

std::string Marfa::medicine() const {
    return medicamente;
}

int Marfa::price() const {
    return pret_actual;
}

Marfa operator+(const Marfa& obj1, const Marfa& obj2) {
    std::string nouN = obj1.medicine() + "-" + obj2.medicine();
    int nouP = obj1.price() + obj2.price();
    return Marfa(nouN, nouP);
}

Marfa operator/(const Marfa& obj3, int nr) {
    if (nr != 0) {
        return Marfa(obj3.medicine(), obj3.price() / nr);
    } else {
        return Marfa();
    }
}