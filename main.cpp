#include <iostream>
#include <windows.h>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazka("Uzytkownicy3.txt");

    ksiazka.wypiszWszystkichUzytkownikow();

    ksiazka.rejestracjaUzytkownika();
    ksiazka.wypiszWszystkichUzytkownikow();

    return 0;
}
