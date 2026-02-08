#include "Notifikaattori.h"
#include <iostream>

int main() {
    Notifikaattori n;

    Seuraaja* a = new Seuraaja("A");
    Seuraaja* b = new Seuraaja("B");
    Seuraaja* c = new Seuraaja("C");

    n.lisaa(a);
    n.lisaa(b);
    n.lisaa(c);

    std::cout << "\n";
    n.tulosta();
    std::cout << "\n";

    n.postita("Tama on viesti 1");

    std::cout << "\n";
    n.poista(b);
    delete b;

    std::cout << "\n";
    n.postita("Tama on viesti 2");

    return 0;
}
