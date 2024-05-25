//
// Created by copac on 5/25/2024.
//

#include "TEmplate.h"

template<typename T>
void afisare(const std::list<Template1<T>*>& ex) {
for (const auto& x : ex) {
    x->afisare();
    }
}