#include "Menu.h"
Menu::Menu(){
cout << "poszlo";
}

void Menu::wyswietlMenu(){
char wybor;
int idZalogowanegoUzytkownika = 0;//uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();

while (true) {
        if (idZalogowanegoUzytkownika == 0) {
            wybor = wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                uzytkownikMenedzer.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } /*else {

            if (adresaci.empty() == true)
                // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
                // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
                // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
                idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
*/

}
}

char Menu::wybierzOpcjeZMenuGlownego() {
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}


