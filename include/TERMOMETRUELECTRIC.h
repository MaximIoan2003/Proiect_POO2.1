#ifndef TERMOMETRUELECTRIC_H
#define TERMOMETRUELECTRIC_H

#include "TERMOMETRU.h"
#include <iostream>

class Termometru_electric : public Termometru {
private:
    int capacitate;
public:
    Termometru_electric(const std::string& firma, int pret, int capacitate);

    Termometru_electric(const Termometru_electric& T);

    Termometru_electric& operator=(const Termometru_electric& T);

    ~Termometru_electric();

    int cap() const;

    void temp_max() const override;

    void baterie() const override;

};

#endif
