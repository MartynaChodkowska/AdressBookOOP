#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include "Adresat.h"

class PlikZAdresatami{

string nazwaPlikuZAdresatami;
public:
    PlikZAdresatami();
    void dopiszAdresataDoPliku();
    vector<Adresat> wczytajAdresatowDoPliku();
    bool czyPlikJestPusty();
};


#endif // PLIKZADRESATAMI_H
