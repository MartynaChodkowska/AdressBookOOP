#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"


using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;
    int idZalogowanegoUzytkownikaWKsiazkaAdresowa;
    char wyborZMenu;
  public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
    adresatMenedzer(nazwaPlikuZAdresatami){};
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlMenu(int idZalogowanegoUzytkownika);
    char pobierzWyborZMenu();
    void wylogujUzytkownika(int idWylogowanegoUzytkownika);
    void dodawanieAdresata(int idZalogowanegoUzytkownika);
    void wypiszWszystkichAdresatow();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif // KSIAZKAADRESOWA_H
