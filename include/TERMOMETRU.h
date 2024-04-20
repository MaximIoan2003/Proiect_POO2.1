#ifndef TERMOMETRU_H
#define TERMOMETRU_H

#include <string>
#include <iostream>

class Termometru {
private:
    std::string firma;
    int pret;
public:
    Termometru(const std::string& firma1, int pret1);

    Termometru(const Termometru& T);

    Termometru& operator=(const Termometru& T);

    virtual ~Termometru();

    virtual void temp_max() const = 0;

    virtual void baterie() const = 0;

    std::string getFirma() const;

    int getPret() const;
};

#endif
