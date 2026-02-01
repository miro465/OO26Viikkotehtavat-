#ifndef CHEF_H
#define CHEF_H

#include <string>

class Chef
{
protected:
    std::string chefName;

public:
    Chef(std::string name);
    virtual ~Chef();
    std::string getName();
    int makeSalad(int ingredients);
    int makeSoup(int ingredients);
};

#endif
