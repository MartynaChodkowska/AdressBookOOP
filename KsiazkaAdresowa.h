#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"


using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    int idZalogowanegoUzytkownika;
    char wyborZMenu;
  public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
            };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void wyswietlMenu(int idZalogowanegoUzytkownika);
    char pobierzWyborZMenu();
    void wylogujUzytkownika(int idWylogowanegoUzytkownika);
};


#endif // KSIAZKAADRESOWA_H
