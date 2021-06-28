#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

int KsiazkaAdresowa::logowanieUzytkownika() {
    return idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();

}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlMenu(int idZalogowanegoUzytkownika) {
    if (idZalogowanegoUzytkownika == 0)
        wyborZMenu = MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
    else
        wyborZMenu = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
}

char KsiazkaAdresowa::pobierzWyborZMenu() {
    return wyborZMenu;
}

void KsiazkaAdresowa::wylogujUzytkownika(int idWylogowanegoUzytkownika) {
    uzytkownikMenedzer.ustawIdZalogowanegoUzytkownika(idWylogowanegoUzytkownika);
}
