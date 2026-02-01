#include "Asiakas.h"
#include <iostream>

int main() {
    Asiakas aapeli("Aapeli", 1000);
    Asiakas bertta("Bertta", 1000);

    std::cout << "Pankkitili luotu Aapelille, luottoraja 1000\n";
    std::cout << "Luottotili luotu Aapelille, luottoraja 1000\n";
    std::cout << "Asiakkuus luotu Aapelille\n";

    aapeli.talletus(250);
    aapeli.luotonNosto(150);
    aapeli.showSaldo();

    std::cout << "Pankkitili luotu Bertalle, luottoraja 1000\n";
    std::cout << "Luottotili luotu Bertalle, luottoraja 1000\n";
    std::cout << "Asiakkuus luotu Bertta\n";
    bertta.showSaldo();

    aapeli.tiliSiirto(50, bertta);

    std::cout << "Kayttotilin saldo " << aapeli.getKayttoTilinSaldo() << "\n";
    std::cout << "Luottotilin saldo " << aapeli.getLuottoTilinSaldo() << "\n";
    std::cout << "Kayttotilin saldo " << bertta.getKayttoTilinSaldo() << "\n";
    std::cout << "Luottotilin saldo " << bertta.getLuottoTilinSaldo() << "\n";

    std::cout << "\nPress <RETURN> to close this window...\n";
    std::cin.get();
    return 0;
}
