#include "Pankkitili.h"
#include <iostream>
#include <iomanip>
#include <algorithm> // std::max

Pankkitili::Pankkitili(const std::string& omistaja, double alkusaldo)
    : omistaja(omistaja), saldo(std::max(0.0, alkusaldo)) {}

double Pankkitili::getBalance() const {
    return saldo;
}

bool Pankkitili::deposit(double summa) {
    if (summa <= 0.0) return false;
    saldo += summa;
    return true;
}

bool Pankkitili::withdraw(double summa) {
    if (summa <= 0.0) return false;
    if (summa > saldo) return false;
    saldo -= summa;
    return true;
}

void Pankkitili::tulosta() const {
    std::cout << "Kayttotilin saldo " << std::fixed << std::setprecision(0) << saldo << "\n";
}

const std::string& Pankkitili::getOmistaja() const {
    return omistaja;
}
