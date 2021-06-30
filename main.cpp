#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"
#include "MetodyPomocnicze.h"
#include "PlikZAdresatami.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazka("Uzytkownicy3.txt", "Adresaci.txt");


    char wybor;
    int idZalogowanegoUzytkownika = 0;
    while (true) {
            idZalogowanegoUzytkownika = ksiazka.pobierzIdZalogowanegoUzytkownika();
            ksiazka.wyswietlMenu(idZalogowanegoUzytkownika);
            wybor = ksiazka.pobierzWyborZMenu();
            if (idZalogowanegoUzytkownika == 0){
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

            else{

                /*     if (adresaci.empty() == true)
                            // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                            // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                            // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                            idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
            }
           */


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
                //zmianaHaslaZalogowanegoUzytkownika(uzytkownicy, idZalogowanegoUzytkownika);
                break;
            case '8':
                ksiazka.wylogujUzytkownika(0);
               // adresaci.clear();
                break;
            }

    }
}
    // ksiazka.wypiszWszystkichUzytkownikow();

    //ksiazka.rejestracjaUzytkownika();
    //ksiazka.wypiszWszystkichUzytkownikow();



    return 0;
}
