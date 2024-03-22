# Nu primesc notă pentru că nu am pus titlu și descriere

## Cerințe obligatorii 

Nerespectarea duce la nepunctarea proiectului

- programul va fi scris în C++
- programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
- programul nu are erori de compilare
- programul nu are warning-uri (folosind -Wall)
- existența a minim un punct din fiecare cerință
- fară variabile globale
- datele membre private
- fara headere specifice unui sistem de operare (<windows.h>)
- teste unitare pentru cerințele implementate (unde se poate, dacă nu apar probleme cu setup-ul de teste 😅)

## Tema 1

#### Cerințe
- [ ] definirea a minim **2-3 clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic) (5p)
  - pentru o clasă:
    - [ ] constructori de inițializare
    - [ ] constructor supraîncărcat
    - [ ] constructori de copiere
    - [ ] `operator=` de copiere
    - [ ] destructor
    - [ ] `operator<<` pentru afișare (std::ostream)
    - [ ] `operator>>` pentru citire (std::istream)
    - [ ] alt operator supraîncărcat ca funcție membră
    - [ ] alt operator supraîncărcat ca funcție non-membră
  - pentru celelalte clase se va definii doar ce e nevoie
- [ ] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe (3p)
- nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector 
- [ ] scenariu de utilizare a claselor definite (1p):
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [ ] opțiune pentru citirea și afișarea a n obiecte (1p)

### Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp` (0.25p)
- [ ] cât mai multe `const` (0.25p)
- [ ] moșteniri (5p):
  - [ ] minim o clasă de bază și **2 clase derivate**
  - [ ] încercați să derivați o clasă creată anterior
    - dacă nu reușiți
      - creați o altă clasă care poate fi integrată cu clasele anterioare
      - menționați de ce nu ați reușit și ce ați încercat
  - [ ] ilustrați upcast-ul și downcast-ul folosind funcții virtuale și pointeri la clasa de bază
    - aceasta va fi făcută prin **2-3** metode specifice temei alese
    - funcțiile pentru citire / afișare sau destructorul nu sunt incluse 
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] suprascris cc/op= pentru copieri/atribuiri corecte
  - [ ] destructor virtual
- [ ] funcții și atribute `static` (în clase) (1p)
- [ ] excepții (1p)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [ ] folosirea unei clase abstracte (fie la exceptii, fie la moșteniri) (0.5p)
- [ ] actualizarea meniului & scenariului de utilizare (0.5p)
- [ ] citirea și afișarea a n obiecte (0.5p)
  - poate fi combinat cu demonstrarea upcasting-ului & downcast-ului printr-un vector către o clasă de bază
  - poate fi făcut oriunde (dacă aveți deja o clasă cu un vector, de exemplu o clasă Coș cu un vector<Produs>)
- [ ] existența unui pull request către branch-ul în care lucrați ce include adăugarea unei noi derivate ce evidențiază că modificările aduse sunt minimale (0.5p)
  - derivata nu poate fi una ștearsă și rescrisă
  - derivata va avea date membre noi + o modificare de comportament pe una dintre funcțiile virtuale

## Recomandare Tema

* rezolvați tema 1 cu niște itemi generali ca să puteți extinde tema cu ușurință la următoarele teme.
  - coș de cumpărături + produse
  - sistem de validare a documentelor + documente de identitate
  - sistem de gestionare a biletelor + bilet 
* funcționalitatea creată să folosească metode ale obiectului generic 
* ar fi bine ca relația de agregare să fie făcută cu un obiect general în stilul celor de mai sus ^
* branch-uri + commit-uri punctuale
