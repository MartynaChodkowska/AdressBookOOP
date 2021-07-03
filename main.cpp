#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazka("Uzytkownicy.txt", "Adresaci.txt");

    char wybor;

    while (true) {
        if (!ksiazka.czyUzytkownikJestZalogowany()) {
            wybor = ksiazka.wybierzOpcjeZMenuGlownego();
            switch (wybor) {
            case '1':
                ksiazka.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazka.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            wybor = ksiazka.wybierzOpcjeZMenuUzytkownika();
            switch (wybor) {
            case '1':
                ksiazka.dodawanieAdresata();
                break;
            case '2':
                ksiazka.wypiszAdresatowZZadanymImieniem();
                break;
            case '3':
                ksiazka.wypiszAdresatowZZadanymNazwiskiem();
                break;
            case '4':
                ksiazka.wypiszWszystkichAdresatow();
                break;
            case '5':
                ksiazka.usunAdresata();
                break;
            case '6':
                ksiazka.edytujAdresata();
                break;
            case '7':
                ksiazka.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazka.wylogujUzytkownika();
                break;
            }
        }
    }
    return 0;
}
