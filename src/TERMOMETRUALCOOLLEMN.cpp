#include "TERMOMETRUALCOOLLEMN.h"

Termometru_alcool_lemn::Termometru_alcool_lemn(const std::string& firma, int pret) : Termometru(firma, pret) {}

Termometru_alcool_lemn::Termometru_alcool_lemn(const Termometru_alcool_lemn& T) : Termometru(T) {}

Termometru_alcool_lemn& Termometru_alcool_lemn::operator=(const Termometru_alcool_lemn& T) {
    if(this != &T) {
        Termometru::operator=(T);
    }
    return *this;
}

Termometru_alcool_lemn::~Termometru_alcool_lemn() {}

void Termometru_alcool_lemn::temp_max() const {
    std::cout << "Temperatura maxima a termometrului cu alcool din lemn " << getFirma() << " este de 50 de grade";
}

void Termometru_alcool_lemn::baterie() const {
    std::cout << "Termometrul " << getFirma()  << " nu are baterie ! Acesta costa : " << getPret();
}

