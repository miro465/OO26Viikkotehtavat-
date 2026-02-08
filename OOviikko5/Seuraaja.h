#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <string>

class Seuraaja {
public:
    std::string nimi;
    Seuraaja* next;

    Seuraaja(std::string n);

    std::string getNimi() const;
    void paivitys(std::string viesti);
};

#endif // SEURAAJA_H
