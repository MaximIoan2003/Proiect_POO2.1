#include <iostream>
#include "Catalog_online.h"

int main() {
    // Toate cerintele din tema sunt prezente in clasa Catalog_online/Marfa;

    // adaugam Medicamentele in clasa Marfa
    Marfa A("Rivanol", 20);
    Marfa B("Nurofen", 15);
    Marfa C("ACC", 10);
    Marfa E("Strepsils", 30);
    Marfa F("Debridat", 20);
    Marfa G("Faringosept", 30);

    // citim/afisam meniul interactiv prin operatorii<<
    Catalog_online D;
    std::cin >> D;
    std::cout << D;

    // adaugam in catalog respectivele medicamente
    D.adaugare_medicamente(A);
    D.adaugare_medicamente(C);
    D.adaugare_medicamente(B);
    D.adaugare_medicamente(E);
    D.adaugare_medicamente(F);
    D.adaugare_medicamente(G);

    // adaugam termometre cu alcool de lemn si electrice
    //Termometru_alcool_lemn T1("Altex", 40);
    //Termometru_alcool_lemn T2("Flanco", 60);
    //Nu stiu dece nu ma lasa sa le adaug
    //D.adaugare_termometre(&T1);
    //D.adaugare_termometre(&T2);
    Termometru_electric T3("Emag", 60, 150);
    Termometru_electric T4("Blade", 500, 1000);
    D.adaugare_termometre(&T3);
    D.adaugare_termometre(&T4);

    // upcasting si downcasting
    //Termometru* p1 = D.upcast1(&T1);
   // Termometru* p2 = D.upcast2(&T4);
   // Termometru_alcool_lemn* p3 = dynamic_cast<Termometru_alcool_lemn*>(p1);
   // Termometru_electric* p4 = dynamic_cast<Termometru_electric*>(p2);

    Termometru_electric Ex1("Vraze",70,250);
    Termometru* ex1 = D.upcast1(&Ex1);

    if(ex1) {
        std::cout << std::endl;
    }

    Termometru_electric Ex2("Vraze2",70,250);
    Termometru* ex2 = D.upcast2(&Ex2);
    if(ex2) {
        std::cout << std::endl;
    }


    // Initializam H prin operatorul +
    Marfa H = C + E;
    D.adaugare_medicamente(H);

    // Operatorul =
    Catalog_online I;
    I = D;

    // Constructorul de copiere
    Catalog_online J(D);

    // Afisare catalog
    D.afisare_catalog();

    // Prelucrare comanda
    D.comanda();

    // operator /
    // Marfa K = B / 2;
    // D.adaugare_medicamente(K);

    return 0;
}