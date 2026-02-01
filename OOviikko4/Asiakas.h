#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "Pankkitili.h"
#include "Luottotili.h"
#include <string>

class Asiakas {
private:
    std::string nimi;
    Pankkitili* kayttoTili;
    Luottotili* luottoTili;

public:
    Asiakas(const std::string& nimi, double luottoRaja);
    ~Asiakas();

    double getKayttoTilinSaldo() const;
    double getLuottoTilinSaldo() const;

    std::string getNimi() const;
    void showSaldo() const;

    bool talletus(double summa);
    bool nosto(double summa);
    bool luotonMaksu(double summa);
    bool luotonNosto(double summa);
    bool tiliSiirto(double summa, Asiakas& vastaanottaja);
};

#endif // ASIAKAS_H
