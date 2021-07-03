#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
/*
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
*/
void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::wylogujUzytkownika() {
    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::dodawanieAdresata() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer->dodawanieAdresata();
    } else {
        cout << "Aby dodac adresata musisz sie zalgowac." << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wypiszAdresatowZZadanymImieniem() {
    adresatMenedzer->wypiszAdresatowZZadanymImieniem();
}

void KsiazkaAdresowa::wypiszAdresatowZZadanymNazwiskiem(){
    adresatMenedzer->wypiszAdresatowZZadanymNazwiskiem();
}
void KsiazkaAdresowa::wypiszWszystkichAdresatow() {
    adresatMenedzer->wypiszWszystkichAdresatow();
}

void KsiazkaAdresowa::edytujAdresata(){
    adresatMenedzer->edytujAdresata();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

bool KsiazkaAdresowa::czyUzytkownikJestZalogowany() {
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
        return true;
    else
        return false;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    return MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    return MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
}

