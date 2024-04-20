#ifndef TERMOMETRUALCOOLLEMN_H
#define TERMOMETRUALCOOLLEMN_H

#include "TERMOMETRU.h"
#include <iostream>

class Termometru_alcool_lemn : public Termometru {
public:
    Termometru_alcool_lemn(const std::string& firma, int pret);

    Termometru_alcool_lemn(const Termometru_alcool_lemn& T);

    Termometru_alcool_lemn& operator=(const Termometru_alcool_lemn& T);

    ~Termometru_alcool_lemn();

    void temp_max() const override;

    void baterie() const override;

};

#endif
