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

void AdresatMenedzer::edytujAdresata(){
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << endl << "Podaj ID wybranego adresata: " << endl;
    idEdytowanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++) {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata) {
            czyIstniejeAdresat = true;
            wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor) {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::usunAdresata(){
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    cout << "podaj ID adresata, ktorego chcesz usunac: ";
    idUsuwanegoAdresata = MetodyPomocnicze::wczytajLiczbeCalkowita();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
               //numerLiniiUsuwanegoAdresata = zwrocNumerLiniiSzukanegoAdresata(idUsuwanegoAdresata);
                plikZAdresatami.usunDaneWybranegoAdresata(*itr);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
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


