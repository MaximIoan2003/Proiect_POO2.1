#include <iostream>
#include <string>
#include <vector>
#include <CATALOGONLINE.h>
#include <TERMOMETRU.h>

int main()
{
    //Toate cerintele din tema sunt prezente in clasa Catalog_online/Marfa;

    //adaugam Medicamentele in clasa Marfa
    Marfa A("Rivanol",20);
    Marfa B("Nurofen",15);
    Marfa C("ACC",10);
    Marfa E("Strepsils", 30);
    Marfa F("Debridat", 20);
    Marfa G("Faringosept",30);

    //citim/afisam meniul interactiv prin operatorii<</>>
    Catalog_online D;
    std:: cin >> D;
    std::cout << D;

    //adaugam in catalog respectivele medicamente
    D.adaugare_medicamente(A);
    D.adaugare_medicamente(C);
    D.adaugare_medicamente(B);
    D.adaugare_medicamente(E);
    D.adaugare_medicamente(F);
    D.adaugare_medicamente(G);

    //Initializam H prin operatorul +
    Marfa H = C + E;
    D.adaugare_medicamente(H);

    //Operatorul =
    Catalog_online I;
    I = D;

    //Constructorul de copiere
    Catalog_online J(D);

    //Afisare catalog
    D.afisare_catalog();

    //Prelucrare comanda
    D.comanda();

    //operator /
    // Marfa K = B / 2;
    //D.adaugare_medicamente(K);

    /*1.Sesiune incepe cu adaugarea numelui si adresa(puteti adauga numele/adresa din mai multe
     * cuvinte datorita functiei getline , insa la adresa nu pot folosi cin.ignore() care elimina
     * bufferul de la nume din cauza ca o sa pierd prima litera din adresa in cazul in care nu este.
     * 2.Comanda online are 3 stagii : Prima in care alegem produsele si confirmam comanda, A doua
     * in care alegem produsele insa nu finalizam comanda , si A treia in care nu alegem niciun
     * produs si cosul ramane gol.
     * De asemenea puteti gresi numele produselor si nu va survenii o eroare, ci un mesaj in care
     * anunta utilizatorul ca produsul nu exista*/

    return 0;

}
