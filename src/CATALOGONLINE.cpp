#include "Catalog_online.h"
#include <stdexcept>
#include <iostream>
#include <cctype>

Catalog_online::Catalog_online() : nume(""), adresa("") {}

Catalog_online::Catalog_online(const std::string& name, const std::string& adress) : nume(name), adresa(adress) {}

Catalog_online::Catalog_online(const Catalog_online& Main2) : nume(Main2.nume), adresa(Main2.adresa) {}

Catalog_online& Catalog_online::operator=(const Catalog_online& Main2) {
    if (this != &Main2) {
        nume = Main2.nume;
        adresa = Main2.adresa;
        meds = Main2.meds;
    }
    return *this;
}

Catalog_online::~Catalog_online() {}

std::istream& operator>>(std::istream& citire, Catalog_online& pers) {
    std::cout << "Bine ati venit !" << std::endl;
    std::cout << "Numele dumneavoastra :";
    std::getline(citire, pers.nume);
    std::cout << "Adresa dumneavoastra :";
    std::getline(citire, pers.adresa);
    return citire;
}

std::ostream& operator<<(std::ostream& afisare, const Catalog_online& pers) {
    afisare << pers.nom() << ", ne bucuram ca ati ales sa faceti cumparaturile cu noi ! Produsele pe care le veti comanda vor veni la adresa : " << pers.adr() << ". Spor la cumparaturi !" << std::endl;
    afisare << std::endl;
    return afisare;
}

int Catalog_online::medicamente = 0;

void Catalog_online::adaugare_medicamente(const Marfa& prod) {
    meds.push_back(prod);
    medicamente = medicamente + 1;
}

void Catalog_online::adaugare_termometre(Termometru* t) {
    termometre.push_back(t);
}

Termometru_alcool_lemn* Catalog_online::upcast1(Termometru* t) {
    return dynamic_cast<Termometru_alcool_lemn*>(t);
}

Termometru_electric* Catalog_online::upcast2(Termometru* t) {
    return dynamic_cast<Termometru_electric*>(t);
}

Termometru* Catalog_online::downcast1(Termometru_alcool_lemn* t) {
    return dynamic_cast<Termometru*>(t);
}

Termometru* Catalog_online::downcast2(Termometru_electric* t) {
    return dynamic_cast<Termometru*>(t);
}

void Catalog_online::afisare_catalog() {
    std::cout << "Mai jos veti avea catalogul cu medicamente in format produs - pret" << std::endl;
    std::cout << "*CATALOG : ";
    for (const auto& x : meds) {
        std::cout << x.medicine() << "->" << x.price() << " lei" << " ";
    }
    std::cout << std::endl;
}

void Catalog_online::comanda() {
    std::vector<std::string> comanda1;
    std::vector<std::string> comanda2;
    int produse = 0;
    int suma = 0;
    std::cout << nom() << ", acum ca ati vazut catalogul , va rugam sa plasati o comanda !" << std:: endl;

    while (true) {
        std::cout << "Numele medicamentului pe care doriti sa-l comandati sau * pentru a termina comanda de medicamente" << std:: endl;
        std:: string MED;
        try {
            std:: cin >> MED;
            if(MED == "*") {
                break;
            }

            bool cifre = false;
            for(char a : MED) {
                if(std::isdigit(a)) {
                    cifre = true;
                    break;
                }
            }

            if(cifre) {
                throw std::runtime_error("Un medicament nu poate contine cifre in nume !");
            }

            bool x = false;
            for(const auto& y : meds) {
                if(MED == y.medicine()) {
                    ++produse;
                    x = true;
                    comanda1.push_back(MED);
                    suma = suma + y.price();
                    break;
                }
            }

            if(!x) {
                std:: cout << "Ops! Medicamentul cautat nu exista in catalog !" << std:: endl;
            }
        } catch (const std:: runtime_error& eroare) {
            std::cerr << "A survenit o eroare : " << eroare.what() << std::endl;
        }
    }
    std::cout << "De asemenea avem si termometre la preturi foarte accesibile !" << std:: endl;

    for(const auto& t : termometre) {
        std::cout << t->firma1() << " -> " << t->pret1() << " ";
    }
    std::cout << std:: endl;

    std::cout << "Daca doriti informatii despre bateriilor tastati 1, daca doriti informatii despre temperaturile maxime tastati 2, daca nu vreti sa aflati informatii tastati 3";
    int x;
    std:: cin >> x;
    if(x == 1) {
        for(const auto& y : termometre) {
            y->baterie();
            std:: cout << std:: endl;
        }
    } else if(x == 2) {
        for(const auto& y : termometre) {
            y->temp_max();
            std:: cout << std:: endl;
        }
    }

    while(true) {
        std::cout << "Numele termometrului pe care doriti sa-l comandati sau * pentru a termina comanda de termometre" << std:: endl;
        std:: string term;
        std:: cin >> term;
        if(term == "*") {
            break;
        }
        bool z = false;
        for(const auto& y : termometre) {
            if(y->firma1() == term) {
                z = true;
                comanda2.push_back(term);
                ++produse;
                suma = suma + y->pret1();
                break;
            }
        }
        if(!z) {
            std:: cout << "Ops! Termometrul cautat nu exista in catalog ! " << std:: endl;
        }
    }
    if(produse != 0) {
        std:: cout << "Cosul dumneavoastra : " << std:: endl;
        for(const auto&y : comanda1) {
            std:: cout << y << ", ";
        }
        for(const auto&y : comanda2) {
            std:: cout << y << ", ";
        }
        std::cout << std:: endl;
        std::cout << "Subtotal : " << suma << std:: endl;
        std::cout << "Va rog tastati CONFIRM pentru finalizare comanda sau alta tasta pentru terminarea sesiunii ";
        std:: string n;
        std:: cin >> n;
        if(n == "CONFIRM") {
            std:: cout << "Va multumim ca ne-ati ales! Comanda dumneavoastra va fi livrata in 2-3 zile lucratoare la adresa " << adr() << " intre orele 10-18.O zi buna " << nom() << "!";
        } else {
            std:: cout << nom() << ",te mai asteptam !";
        }

    } else
        std::cout << "Cosul dumneavoastra este gol !";
}

int Catalog_online::nr_medicamente() {
    return medicamente;
}
