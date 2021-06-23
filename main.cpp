#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazka;

    ksiazka.wypiszWszystkichUzytkownikow();

    ksiazka.rejestracjaUzytkownika();
    ksiazka.wypiszWszystkichUzytkownikow();

    return 0;
}
