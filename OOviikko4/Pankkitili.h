#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    Pankkitili(const std::string& omistaja, double alkusaldo = 0.0);
    virtual ~Pankkitili() = default;

    double getBalance() const;
    virtual bool deposit(double summa);
    virtual bool withdraw(double summa);
    virtual void tulosta() const;

    const std::string& getOmistaja() const;
};

#endif // PANKKITILI_H
