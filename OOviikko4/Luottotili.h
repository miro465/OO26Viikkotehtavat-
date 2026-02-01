#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoRaja;

public:
    Luottotili(const std::string& omistaja, double luottoRaja);

    bool deposit(double summa) override;
    bool withdraw(double summa) override;
    void tulosta() const override;

    double getLuottoRaja() const;
};

#endif // LUOTTOTILI_H
