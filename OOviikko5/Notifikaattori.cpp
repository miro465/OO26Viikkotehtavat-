#include "Notifikaattori.h"
#include <iostream>

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {
    std::cout << "Luodaan notifikaattori" << std::endl;
}

Notifikaattori::~Notifikaattori() {
    Seuraaja* ptr = seuraajat;
    while (ptr != nullptr) {
        Seuraaja* seuraava = ptr->next;
        delete ptr;
        ptr = seuraava;
    }
}

void Notifikaattori::lisaa(Seuraaja* s) {
    if (s == nullptr) return;

    std::cout << "Notifikaattori lisaa seuraajan " << s->getNimi() << std::endl;

    s->next = seuraajat;
    seuraajat = s;
}

void Notifikaattori::poista(Seuraaja* s) {
    if (seuraajat == nullptr || s == nullptr) return;

    if (seuraajat == s) {
        seuraajat = seuraajat->next;
        return;
    }

    Seuraaja* ptr = seuraajat;
    while (ptr->next != nullptr && ptr->next != s) {
        ptr = ptr->next;
    }

    if (ptr->next == s) {
        ptr->next = s->next;
    }
}

void Notifikaattori::tulosta() const {
    std::cout << "Notifikaattorin seuraajat:" << std::endl;
    Seuraaja* ptr = seuraajat;
    while (ptr != nullptr) {
        std::cout << "  " << ptr->getNimi() << std::endl;
        ptr = ptr->next;
    }
    if (seuraajat == nullptr) {
        std::cout << "  (ei seuraajia)" << std::endl;
    }
}

void Notifikaattori::postita(std::string viesti) {
    std::cout << "Notifikaattori postaa viestin \"" << viesti << "\"" << std::endl;

    Seuraaja* ptr = seuraajat;
    while (ptr != nullptr) {
        ptr->paivitys(viesti);
        ptr = ptr->next;
    }
}
