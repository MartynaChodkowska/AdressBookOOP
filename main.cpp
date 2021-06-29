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
                //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                cout << "wyszukaj po imieniu" << endl;
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                cout << "wyszukaj po nazwisku" << endl;
                //wyszukajAdresatowPoNazwisku(adresaci);
                break;

            case '4':
                cout << "wyswietl wszystkich adresatow" << endl;
               // ksiazka.wypiszWszystkichAdresatow();
                break;
            case '5':
                cout << "usun adresata" << endl;
               // idUsunietegoAdresata = usunAdresata(adresaci);
               //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                cout << "edytuj adresata" << endl;
               // edytujAdresata(adresaci);
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
