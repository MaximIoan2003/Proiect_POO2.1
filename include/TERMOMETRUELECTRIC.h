#ifndef TERMOMETRUELECTRIC_H
#define TERMOMETRUELECTRIC_H

#include "TERMOMETRU.h"
#include <iostream>

class Termometru_electric : public Termometru {
public:
    Termometru_electric(const std::string& firma, int pret);

    Termometru_electric(const Termometru_electric& T);

    Termometru_electric& operator=(const Termometru_electric& T);

    ~Termometru_electric();

    void temp_max() const override;

    void baterie() const override;

};

#endif
