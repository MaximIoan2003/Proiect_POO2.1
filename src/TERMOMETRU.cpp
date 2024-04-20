#include "Termometru.h"

Termometru::Termometru(const std::string firma1, int pret1) : firma(firma1), pret(pret1) {}

Termometru::Termometru(const Termometru& T) : firma(T.firma), pret(T.pret) {}

Termometru& Termometru::operator=(const Termometru& T) {
    if(this != &T) {
        firma = T.firma;
        pret = T.pret;
    }
    return *this;
}

Termometru::~Termometru() {}

std::string Termometru::getFirma() const {
    return firma;
}

int Termometru::getPret() const {
    return pret;
}
