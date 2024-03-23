#include <iostream>
#include <string>
#include <vector>

class Marfa
{
private:
    std::string medicamente;
    int pret_actual;
public:

    Marfa() : medicamente(""), pret_actual(0) {}

    Marfa(const std::string& m,int pret) : medicamente(m), pret_actual(pret) {}

    std::string medicine() const
    {
        return medicamente;
    }

    int price() const
    {
        return pret_actual;
    }

    friend Marfa operator+(const Marfa& obj1, const Marfa& obj2)
    {
        std::string nouN = obj1.medicine() + "-" + obj2.medicine();
        int nouP = obj1.price() + obj2.price();
        return Marfa(nouN,nouP);
    }

    friend Marfa operator/(const Marfa& obj3,int nr);

};

Marfa operator/(const Marfa& obj3,int nr)
{
    if(nr != 0)
    {
        return Marfa(obj3.medicine(),obj3.price()/nr);
    } else
    {
        return Marfa();
    }


}

class Catalog_online
{
private:
    std::string nume;
    std::string adresa;
    std:: vector<Marfa> meds;
public:

    Catalog_online() :nume(""), adresa("") {}

    Catalog_online(const std::string& name, const std::string& adress) : nume(name),adresa(adress) {}

    Catalog_online(const Catalog_online& Main2) : nume(Main2.nume), adresa(Main2.adresa) {}

    Catalog_online& operator=(const Catalog_online& Main2) {
        if (this != &Main2) {
            nume = Main2.nume;
            adresa = Main2.adresa;
            meds = Main2.meds;
        }
        return *this;
    }

    ~Catalog_online() {}

    friend std::istream& operator>>(std::istream& citire, Catalog_online& pers);

    friend std::ostream& operator>>(std::ostream& afisare, const Catalog_online& pers);

    std::string nom() const
    {
        return nume;
    }

    std::string adr() const
    {
        return adresa;
    }


    void adaugare_medicamente(const Marfa& prod)
    {
        meds.push_back(prod);
    }

    void afisare_catalog()
    {
        std::cout << "Mai jos veti avea catalogul cu  medicamente in format produs - pret"<<std::endl;
        std::cout << "*CATALOG : ";
        for(const auto& x : meds)
        {
            std::cout << x.medicine() << "->" << x.price() << " lei"<< " ";
        }
        std::cout << std::endl;
    }

    void comanda()
    {
        std:: vector<std:: string> comanda1;
        int produse = 0;
        int suma = 0;
        std::cout << nom() << ", acum ca ai vazut catalogul , te rog plaseaza o comanda !" << std:: endl;

        while(true)
        {
            std::cout << "Numele produsului pe care vreti sa-l comandati sau * pentru a termina comanda" << std:: endl;
            std:: string MED;
            std:: cin >> MED;
            if(MED == "*")
            {
                break;
            }

            bool x = false;
            for(const auto& y : meds)
            {
                if(MED == y.medicine())
                {
                    ++produse;
                    x = true;
                    comanda1.push_back(MED);
                    suma = suma + y.price();
                }
            }

            if(!x)
            {
                std:: cout << "Ops! Produsul cautat nu exista in catalog !" << std:: endl;
            }


        }
        if(produse != 0)
        {
            std:: cout << "Cosul dumneavoastra : " << std:: endl;
            for(const auto&y : comanda1)
            {
                std:: cout << y << ", ";
            }
            std::cout << std:: endl;
            std::cout << "Subtotal : " << suma << std:: endl;
            std::cout << "Va rog tastati CONFIRM pentru finalizare comanda sau alta tasta pentru terminarea sesiunii ";
            std:: string n;
            std:: cin >> n;
            if(n == "CONFIRM")
            {
                std:: cout << "Va multumim ca ne-ati ales! Comanda dumneavoastra va fi livrata in 2-3 zile lucratoare la adresa " << adr() << "intre orele 10-18.O zi buna " << nom() << "!";
            } else
            {
                std:: cout << nom() << ",te mai asteptam !";
            }


        } else
        {
            std::cout << "Cosul dumneavoastra este gol !";
        }
    }

};


std::istream& operator>>(std::istream& citire, Catalog_online& pers)
{
    std::cout << " Bine a-ti venit !" << std:: endl;
    std::cout << " Numele dumneavoastra : ";
    std:: getline(citire,pers.nume);
    std::cout << " Adresa dumneavoastra : ";
    std:: getline(citire,pers.adresa);
    return citire;
}

std::ostream& operator<<(std::ostream& afisare, const Catalog_online& pers)
{
    afisare << pers.nom() << ",ne bucuram ca a-ti ales sa faceti cumparaturile cu noi ! Produsele pe care le veti comanda vor veni la adresa : " << pers.adr() << ". Spor la cumparaturi !" << std:: endl;
    afisare << std::endl;
    return afisare;
}


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
    Marfa K = B / 2;
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