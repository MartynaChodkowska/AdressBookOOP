#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
     idZalogowanegoUzytkownikaWKsiazkaAdresowa = uzytkownikMenedzer.logowanieUzytkownika();
        adresatMenedzer.wczytajAdresatowZPliku(idZalogowanegoUzytkownikaWKsiazkaAdresowa);
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
    adresatMenedzer.wyczyscAdresaciVector();
}

void KsiazkaAdresowa::dodawanieAdresata(int idZalogowanegoUzytkownika) {
    adresatMenedzer.dodawanieAdresata(idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::wypiszWszystkichAdresatow(){
adresatMenedzer.wypiszWszystkichAdresatow();
}
