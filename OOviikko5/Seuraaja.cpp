#include "Seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(std::string n)
    : nimi(n), next(nullptr)
{
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

std::string Seuraaja::getNimi() const {
    return nimi;
}

void Seuraaja::paivitys(std::string viesti) {
    std::cout << "Seuraaja " << nimi << " sai viestin " << viesti << std::endl;
}
