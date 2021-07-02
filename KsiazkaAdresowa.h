#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"


using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
        const string NAZWA_PLIKU_Z_ADRESATAMI;
    char wyborZMenu;
  public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
    adresatMenedzer = NULL;
    };
    ~KsiazkaAdresowa(){
    delete adresatMenedzer;
    adresatMenedzer = NULL;
    }
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlMenu(int idZalogowanegoUzytkownika);
    char pobierzWyborZMenu();
    void wylogujUzytkownika();
    void dodawanieAdresata();
    void wypiszWszystkichAdresatow();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif // KSIAZKAADRESOWA_H
