#ifndef MARFA_H
#define MARFA_H

#include <string>

class Marfa {
private:
    std::string medicamente;
    int pret_actual;
public:
    Marfa();
    
    Marfa(const std::string& m, int pret);

    std::string medicine() const;

    int price() const;

    friend Marfa operator+(const Marfa& obj1, const Marfa& obj2);

    friend Marfa operator/(const Marfa& obj3, int nr);
};

#endif
