#ifndef CATALOGONLINE_H
#define CATALOGONLINE_H

#include <iostream>
#include <string>
#include <vector>
#include "Marfa.h"
#include "Termometru.h"

class Catalog_online {
private:
    std::string nume;
    std::string adresa;
    std::vector<Marfa> meds;
    static int medicamente;
    std::vector<Termometru*> termometre;

public:
    Catalog_online();
    Catalog_online(const std::string& name, const std::string& adress);
    Catalog_online(const Catalog_online& Main2);
    Catalog_online& operator=(const Catalog_online& Main2);
    ~Catalog_online();

    friend std::istream& operator>>(std::istream& citire, Catalog_online& pers);
    friend std::ostream& operator<<(std::ostream& afisare, const Catalog_online& pers);

    std::string nom() const;
    std::string adr() const;

    void adaugare_medicamente(const Marfa& prod);
    void adaugare_termometre(Termometru* t);

    Termometru_alcool_lemn* upcast1(Termometru* t);
    Termometru_electric* upcast2(Termometru* t);
    Termometru* downcast1(Termometru_alcool_lemn* t);
    Termometru* downcast2(Termometru_electric* t);

    void afisare_catalog();
    void comanda();

    static int nr_medicamente();
};

#endif
