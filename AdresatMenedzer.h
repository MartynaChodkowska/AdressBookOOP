#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenedzer {
    vector<Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    //void wyswietlDaneAdresata();
public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void dodawanieAdresata(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void wyczyscAdresaciVector();


};


#endif // ADRESATMENEDZER_H
