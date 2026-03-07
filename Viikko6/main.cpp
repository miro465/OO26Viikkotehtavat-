#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "student.h"

using namespace std;

void tulostaKaikki(const vector<Student>& opiskelijat) {
    if (opiskelijat.empty()) {
        cout << "Ei yhtaan opiskelijaa listalla.\n";
        return;
    }
    for (const auto& opp : opiskelijat) {
        opp.printStudentInfo();
    }
}

void jarjestaJaTulostaNimella(vector<Student> opiskelijat) {
    sort(opiskelijat.begin(), opiskelijat.end(),
         [](const Student& a, const Student& b) {
             return a.getName() < b.getName();
         });
    cout << "\nOpiskelijat aakkosjarjestyksessa (nimi):\n";
    tulostaKaikki(opiskelijat);
}

void jarjestaJaTulostaIalla(vector<Student> opiskelijat) {
    sort(opiskelijat.begin(), opiskelijat.end(),
         [](const Student& a, const Student& b) {
             return a.getAge() < b.getAge();
         });
    cout << "\nOpiskelijat jarjestyksessa ian mukaan:\n";
    tulostaKaikki(opiskelijat);
}

void etsiJaTulostaNimella(const vector<Student>& opiskelijat, const string& hakunimi) {
    auto it = find_if(opiskelijat.begin(), opiskelijat.end(),
                      [&hakunimi](const Student& s) { return s.getName() == hakunimi; });

    if (it != opiskelijat.end()) {
        cout << "\nLoytyi opiskelija nimella \"" << hakunimi << "\":\n";
        it->printStudentInfo();
    } else {
        cout << "\nOpiskelijaa nimella \"" << hakunimi << "\" ei loytynyt.\n";
    }
}

void muutaOpiskelijanTietoja(vector<Student>& opiskelijat, const string& vanhaNimi) {
    auto it = find_if(opiskelijat.begin(), opiskelijat.end(),
                      [&vanhaNimi](const Student& s) { return s.getName() == vanhaNimi; });

    if (it == opiskelijat.end()) {
        cout << "\nOpiskelijaa nimella \"" << vanhaNimi << "\" ei loydy.\n";
        return;
    }

    string uusiNimi;
    int uusiIka;

    cout << "Anna uusi nimi: ";
    cin >> ws;
    getline(cin, uusiNimi);

    cout << "Anna uusi ika: ";
    cin >> uusiIka;

    it->setName(uusiNimi);
    it->setAge(uusiIka);

    cout << "Tiedot paivitetty:\n";
    it->printStudentInfo();
}

int main() {
    vector<Student> opiskelijat;
    int valinta = -1;

    opiskelijat.emplace_back("Sofia", 21);
    opiskelijat.emplace_back("Mikko", 24);
    opiskelijat.emplace_back("Aada", 19);

    do {
        cout << "\n=== Opiskelijarekisteri ===\n";
        cout << " 0 = Lisaa uusi opiskelija\n";
        cout << " 1 = Tulosta kaikki opiskelijat\n";
        cout << " 2 = Jarjesta ja tulosta nimien mukaan\n";
        cout << " 3 = Jarjesta ja tulosta ian mukaan\n";
        cout << " 4 = Etsi opiskelija nimella\n";
        cout << " 5 = Muuta opiskelijan nimi ja ika\n";
        cout << " 6 = Lopeta ohjelma\n";
        cout << "Valitse toiminto: ";
        cin >> valinta;

        switch (valinta) {
        case 0: {
            string nimi;
            int ika;
            cout << "Opiskelijan nimi: ";
            cin >> ws;
            getline(cin, nimi);
            cout << "Opiskelijan ika: ";
            cin >> ika;
            opiskelijat.emplace_back(nimi, ika);
            cout << "Opiskelija lisatty.\n";
            break;
        }
        case 1:
            cout << "\nKaikki opiskelijat:\n";
            tulostaKaikki(opiskelijat);
            break;
        case 2:
            jarjestaJaTulostaNimella(opiskelijat);
            break;
        case 3:
            jarjestaJaTulostaIalla(opiskelijat);
            break;
        case 4: {
            string hakunimi;
            cout << "Etsittavan opiskelijan nimi: ";
            cin >> ws;
            getline(cin, hakunimi);
            etsiJaTulostaNimella(opiskelijat, hakunimi);
            break;
        }
        case 5: {
            string vanhaNimi;
            cout << "Muutettavan opiskelijan nimi: ";
            cin >> ws;
            getline(cin, vanhaNimi);
            muutaOpiskelijanTietoja(opiskelijat, vanhaNimi);
            break;
        }
        case 6:
            cout << "\nOhjelma suljetaan. Kiitos kaytosta!\n";
            break;
        default:
            cout << "Virheellinen valinta - yrita uudelleen.\n";
        }
    } while (valinta != 6);

    return 0;
}
