#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "Chef.h"
#include <string>

class ItalianChef : public Chef
{
private:
    std::string password = "pizza";

    int makepizza(int flour_amount, int water_amount);

public:
    ItalianChef(std::string name);
    ~ItalianChef();
    bool askSecret(std::string given_password, int flour_amount, int water_amount);
};

#endif
