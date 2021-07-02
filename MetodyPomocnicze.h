#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H


#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;

class MetodyPomocnicze {
public:
    static char wczytajZnak();
    static string wczytajLinie();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int konwersjaStringNaInt(string liczba);
    static string konwersjaIntNaString(int liczba);
};



#endif // METODYPOMOCNICZE_H
