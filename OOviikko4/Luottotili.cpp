#include "Luottotili.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

Luottotili::Luottotili(const std::string& omistaja, double luottoRaja)
    : Pankkitili(omistaja, 0.0), luottoRaja(std::max(0.0, luottoRaja)) {}

bool Luottotili::deposit(double summa) {
    if (summa <= 0.0) return false;
    saldo += summa;
    if (saldo > 0.0) saldo = 0.0;
    return true;
}

bool Luottotili::withdraw(double summa) {
    if (summa <= 0.0) return false;
    double uusi = saldo - summa;
    if (uusi < -luottoRaja) return false;
    saldo = uusi;
    return true;
}

void Luottotili::tulosta() const {
    std::cout << "Luottotilin saldo " << std::fixed << std::setprecision(0) << saldo << "\n";
}

double Luottotili::getLuottoRaja() const {
    return luottoRaja;
}
