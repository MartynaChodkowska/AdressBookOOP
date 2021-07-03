#include "AdresatMenedzer.h"

void AdresatMenedzer::dodawanieAdresata() {
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
        cout << "Nowy adresat zostal dodany." << endl;
    } else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku." << endl;
    system("pause");
}

void AdresatMenedzer::wypiszWszystkichAdresatow() {
    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i = 0; i < adresaci.size(); i++) {
            cout << endl << "Id:                 " << adresaci[i].pobierzId() << endl;
            cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wypiszAdresatowZZadanymImieniem() {
    string szukanieImie;

    cout << "podaj imie adresata, ktorego szukasz: ";
    szukanieImie = MetodyPomocnicze::wczytajLinie();

    system("cls");
    cout << "        >>> ADRESACI z imieniem: " << szukanieImie << " <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    if (!adresaci.empty()) {
        for (vector<Adresat>::iterator itr = adresaci.begin(); itr < adresaci.end(); itr++) {
            if(itr->pobierzImie() == szukanieImie) {

                cout << endl << "Id:                 " << itr->pobierzId() << endl;
                cout << "Imie:               " << itr->pobierzImie() << endl;
                cout << "Nazwisko:           " << itr->pobierzNazwisko() << endl;
                cout << "Numer telefonu:     " << itr->pobierzNumerTelefonu() << endl;
                cout << "Email:              " << itr->pobierzEmail() << endl;
                cout << "Adres:              " << itr->pobierzAdres() << endl;
            }
            cout << endl;
        }
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::wypiszAdresatowZZadanymNazwiskiem() {
    string szukanieNazwisko;

    cout << "podaj imie adresata, ktorego szukasz: ";
    szukanieNazwisko = MetodyPomocnicze::wczytajLinie();

    system("cls");
    cout << "        >>> ADRESACI z nazwiskiem: " << szukanieNazwisko << " <<<" << endl;
    cout << "-----------------------------------------------" << endl;

    if (!adresaci.empty()) {
        for (vector<Adresat>::iterator itr = adresaci.begin(); itr < adresaci.end(); itr++) {
            if(itr->pobierzNazwisko() == szukanieNazwisko) {

                cout << endl << "Id:                 " << itr->pobierzId() << endl;
                cout << "Imie:               " << itr->pobierzImie() << endl;
                cout << "Nazwisko:           " << itr->pobierzNazwisko() << endl;
                cout << "Numer telefonu:     " << itr->pobierzNumerTelefonu() << endl;
                cout << "Email:              " << itr->pobierzEmail() << endl;
                cout << "Adres:              " << itr->pobierzAdres() << endl;
            }
            cout << endl;
        }
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;
    string linia;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    linia = MetodyPomocnicze::wczytajLinie();
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(linia));

    cout << "Podaj nazwisko: ";
    linia = MetodyPomocnicze::wczytajLinie();
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(linia));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}
