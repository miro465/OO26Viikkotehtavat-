#include "Asiakas.h"
#include <iostream>

Asiakas::Asiakas(const std::string& nimi, double luottoRaja)
    : nimi(nimi),
    kayttoTili(new Pankkitili(nimi, 0.0)),
    luottoTili(luottoRaja > 0.0 ? new Luottotili(nimi, luottoRaja) : nullptr) {}

Asiakas::~Asiakas() {
    delete kayttoTili;
    delete luottoTili;
}

std::string Asiakas::getNimi() const {
    return nimi;
}

void Asiakas::showSaldo() const {
    kayttoTili->tulosta();
    if (luottoTili) {
        luottoTili->tulosta();
    }
    std::cout << "\n";
}

bool Asiakas::talletus(double summa) {
    bool ok = kayttoTili->deposit(summa);
    if (ok) std::cout << "Kayttotili: talletus " << summa << " tehty\n";
    return ok;
}

bool Asiakas::nosto(double summa) {
    bool ok = kayttoTili->withdraw(summa);
    if (ok) std::cout << "Kayttotili: nosto " << summa << " tehty\n";
    return ok;
}

bool Asiakas::luotonMaksu(double summa) {
    if (!luottoTili) return false;
    bool ok = luottoTili->deposit(summa);
    if (ok) std::cout << "Luottotili: maksu " << summa << " tehty\n";
    return ok;
}

bool Asiakas::luotonNosto(double summa) {
    if (!luottoTili) return false;
    bool ok = luottoTili->withdraw(summa);
    if (ok) {
        double jaljella = luottoTili->getLuottoRaja() + luottoTili->getBalance();
        std::cout << "Luottotili: nosto " << summa << " tehty, luottoa jaljella " << jaljella << "\n";
    }
    return ok;
}

bool Asiakas::tiliSiirto(double summa, Asiakas& vastaanottaja) {
    if (summa <= 0.0) {
        std::cout << "Summan pitaa olla positiivinen.\n";
        return false;
    }

    bool nostoOk = kayttoTili->withdraw(summa);
    if (!nostoOk) {
        std::cout << "Pankkitili: " << nimi << ": nosto " << summa << " epaonnistui\n";
        return false;
    }

    bool talletusOk = vastaanottaja.kayttoTili->deposit(summa);
    if (!talletusOk) {
        kayttoTili->deposit(summa); // rollback
        std::cout << "Siirto epaonnistui – rahat palautettu.\n";
        return false;
    }

    std::cout << "Pankkitili: " << nimi << " siirtaa " << summa << " " << vastaanottaja.getNimi() << ":lle\n";
    std::cout << "Kayttotili: " << vastaanottaja.getNimi() << ": talletus " << summa << " tehty\n";
    return true;
}

double Asiakas::getKayttoTilinSaldo() const {
    return kayttoTili->getBalance();
}

double Asiakas::getLuottoTilinSaldo() const {
    if (luottoTili) {
        return luottoTili->getBalance();
    }
    return 0.0;
}
