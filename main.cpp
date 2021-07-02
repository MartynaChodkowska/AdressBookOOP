#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazka("Uzytkownicy3.txt", "Adresaci.txt");

    char wybor;

    while (true) {
        ksiazka.wyswietlMenu(ksiazka.pobierzIdZalogowanegoUzytkownika());
        wybor = ksiazka.pobierzWyborZMenu();
        if (ksiazka.pobierzIdZalogowanegoUzytkownika() == 0) {
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
                ksiazka.dodawanieAdresata();
                break;
            case '4':
                 ksiazka.wypiszWszystkichAdresatow();
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
