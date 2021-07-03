#include "PlikZAdresatami.h"


bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;

}

vector<Adresat> PlikZAdresatami::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika) {
    vector<Adresat> adresaciVector;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    int idOstatniegoAdresataZPliku = 0;
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    int nrlinii=1;

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaciVector.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresataZPliku = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        idOstatniegoAdresata = idOstatniegoAdresataZPliku;
    } else idOstatniegoAdresata = 0;

    return adresaciVector;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

bool PlikZAdresatami::czyPlikJestPusty() {
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() == 0)
            return true;
        else
            return false;
    } else
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_ADRESATAMI << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocnicze::konwersjaStringNaInt(MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    string idAdresataPrzedKonwersja = MetodyPomocnicze::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata);
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(idAdresataPrzedKonwersja);

    return idAdresata;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

void PlikZAdresatami::usunWybranaLinieWPliku(string liniaZDanymiAdresata) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1, zapisanyAdresat = 0;
    int idAdresataDoUsuniecia = 0, idAdresataSprawdzanego = 0;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
            // aby na koncu pliku nie bylo pustej linii
            idAdresataDoUsuniecia = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresata);
            idAdresataSprawdzanego = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            if (idAdresataDoUsuniecia == idAdresataSprawdzanego) {}
            else if((idAdresataDoUsuniecia != idAdresataSprawdzanego) && zapisanyAdresat == 0) {
                tymczasowyPlikTekstowy << wczytanaLinia;
                zapisanyAdresat++;
            } else {
                tymczasowyPlikTekstowy << endl << wczytanaLinia;
                zapisanyAdresat++;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        MetodyPomocnicze::usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        MetodyPomocnicze::zmienNazwePliku(NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
    }
}

void PlikZAdresatami::usunDaneWybranegoAdresata(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    usunWybranaLinieWPliku(liniaZDanymiAdresata);
    ustawIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresata));

    cout << endl << "Adresat zostal usuniety" << endl << endl;
}

void PlikZAdresatami::edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true) {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
            if (pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresataOddzielonePionowymiKreskami) == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia)) {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            } else {
                if (numerWczytanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        MetodyPomocnicze::usunPlik(NAZWA_PLIKU_Z_ADRESATAMI);
        MetodyPomocnicze::zmienNazwePliku(NAZWA_PLIKU_TYMCZASOWEGO_Z_ADRESATAMI, NAZWA_PLIKU_Z_ADRESATAMI);
    }

}

void PlikZAdresatami::zaktualizujDaneWybranegoAdresata(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}


void PlikZAdresatami::ustawIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(int idUsuwanegoAdresata) {
    if (idUsuwanegoAdresata == idOstatniegoAdresata)
        idOstatniegoAdresata = pobierzZPlikuIdOstatniegoAdresata();
}

int PlikZAdresatami::pobierzZPlikuIdOstatniegoAdresata() {
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {}
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        plikTekstowy.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (daneOstaniegoAdresataWPliku != "") {
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    return idOstatniegoAdresata;
}
