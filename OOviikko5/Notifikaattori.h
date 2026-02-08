#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include "Seuraaja.h"
#include <string>

class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:
    Notifikaattori();
    ~Notifikaattori();

    void lisaa(Seuraaja* s);
    void poista(Seuraaja* s);
    void tulosta() const;
    void postita(std::string viesti);
};

#endif // NOTIFIKAATTORI_H
