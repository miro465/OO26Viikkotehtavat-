#include <iostream>
#include <algorithm>
#include "Chef.h"
#include "ItalianChef.h"

using namespace std;

Chef::Chef(string name)
{
    chefName = name;
    cout << "Chef " << chefName << " konstruktori" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " destruktori" << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int ingredients)
{
    int portions = ingredients / 5;
    cout << "Chef " << chefName << " with " << ingredients
         << " items can make salad " << portions << " portions" << endl;
    return portions;
}

int Chef::makeSoup(int ingredients)
{
    int portions = ingredients / 3;
    cout << "Chef " << chefName << " with " << ingredients
         << " items can make soup " << portions << " portions" << endl;
    return portions;
}

ItalianChef::ItalianChef(string name) : Chef(name)
{
    cout << "Chef " << chefName << " konstruktori" << endl;
    cout << "ItalianChef " << chefName << " konstruktori" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << chefName << " destruktori" << endl;
}

int ItalianChef::makepizza(int flour_amount, int water_amount)
{
    int portions_by_flour  = flour_amount  / 5;
    int portions_by_water  = water_amount  / 5;
    int portions = min(portions_by_flour, portions_by_water);

    cout << "ItalianChef " << chefName << " with " << flour_amount
         << " flour and " << water_amount << " water can make "
         << portions << " pizzas" << endl;

    return portions;
}

bool ItalianChef::askSecret(string given_password, int flour_amount, int water_amount)
{
    if (given_password == password)
    {
        cout << "Password ok!" << endl;
        makepizza(flour_amount, water_amount);
        return true;
    }
    return false;
}

int main()
{
    Chef gordon("Gordon");
    gordon.makeSalad(11);
    gordon.makeSoup(11);
    gordon.makeSoup(14);

    ItalianChef mario("Mario");
    mario.makeSalad(9);
    mario.askSecret("pizza", 12, 12);

    return 0;
}
