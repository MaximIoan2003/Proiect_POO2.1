#include <TERMOMETRUELECTRIC.h>

Termometru_electric::Termometru_electric(const std::string& firma, int pret) : Termometru(firma, pret) {}

Termometru_electric::Termometru_electric(const Termometru_electric& T) : Termometru(T) {}

Termometru_electric& Termometru_electric::operator=(const Termometru_electric& T) {
    if(this != &T) {
        Termometru::operator=(T);
    }
    return *this;
}

Termometru_electric::~Termometru_electric() {}


void Termometru_electric::temp_max() const {
    std::cout << "Temperatura maxima a termometrului electric" << getFirma() << " este de 100 de grade";
}

void Termometru_electric::baterie() const {
    std::cout << "Termometrul costa : " << getPret();
}


