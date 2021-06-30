#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazka("Uzytkownicy3.txt", "Adresaci.txt");

    char wybor;
    int idZalogowanegoUzytkownika = 0;
    while (true) {
        idZalogowanegoUzytkownika = ksiazka.pobierzIdZalogowanegoUzytkownika();
        ksiazka.wyswietlMenu(idZalogowanegoUzytkownika);
        wybor = ksiazka.pobierzWyborZMenu();
        if (idZalogowanegoUzytkownika == 0) {
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
        }
        else {
            switch (wybor) {
            case '1':
                ksiazka.dodawanieAdresata(idZalogowanegoUzytkownika);
                break;
            case '4':
                cout << "wyswietl wszystkich adresatow" << endl;
                ksiazka.wypiszWszystkichAdresatow();
                break;
            case '7':
                cout << "zmiana hasla" << endl;
                ksiazka.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazka.wylogujUzytkownika(0);
                break;
            }
        }
    }

    return 0;
}
