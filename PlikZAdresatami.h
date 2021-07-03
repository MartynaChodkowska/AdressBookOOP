#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    const string NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami (string daneOstaniegoAdresataWPliku);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void usunWybranaLinieWPliku(string liniaZDanymiAdresatat);
    void edytujWybranaLinieWPliku(string liniaZDanymiAdresata);
    void ustawIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata);
    int pobierzZPlikuIdOstatniegoAdresata();
public:
    PlikZAdresatami(string nazwaPlikuZAdresatami, string nazwaPlikuTymczasowegoZAdresatami = "Adresaci_tymczasowy.txt")
        : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami), NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI(nazwaPlikuTymczasowegoZAdresatami) {
        idOstatniegoAdresata = 0;
    };
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector<Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void usunDaneWybranegoAdresata(Adresat adresat);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);
};

#endif // PLIKZADRESATAMI_H
