#include "../headerz/Angajat.h"


Angajat:: Angajat(const std::string &nume, int varsta, int perioadaContract, const std::string &contact,
        double salariu, const std::string &fostJob, int durata, const std::string &post)
        : nume_ang(nume), varsta_ang(varsta), perioada_contractului(perioadaContract),
          contact_ang(contact), salariu(salariu), experienta({fostJob, durata}), post(post) {}

// Constructor de copiere
Angajat::Angajat(const Angajat &other)
        : nume_ang(other.nume_ang), varsta_ang(other.varsta_ang),
          perioada_contractului(other.perioada_contractului),
          contact_ang(other.contact_ang), salariu(other.salariu), experienta(other.experienta), post(other.post) {}

// Operator de atribuire
Angajat& Angajat::operator=(const Angajat &other) {
    if (this != &other) {
        nume_ang = other.nume_ang;
        varsta_ang = other.varsta_ang;
        perioada_contractului = other.perioada_contractului;
        contact_ang = other.contact_ang;
        salariu = other.salariu;
        experienta = other.experienta;
        post = other.post;
    }
    return *this;
}

// Destructor
Angajat::~Angajat() {}


// Operator <<
std::ostream &operator<<(std::ostream &os, const Angajat &angajat) {
    os << "Angajat: " << angajat.nume_ang
       << "\nVarsta: " << angajat.varsta_ang
       << "\nPerioada contractului: " << angajat.perioada_contractului << " luni"
       << "\nContact: " << angajat.contact_ang
       << "\nSalariu: " << angajat.salariu
       << "\nExperienta: " << angajat.experienta.fostJob << " pentru " << angajat.experienta.durata << " luni"
       << "\nPost: " << angajat.post;
    return os;
}

double Angajat::getSalariu() const {
    return salariu;
}

void Angajat::maresteSalariu(double procent) {
    if (procent > 0) {
        salariu += (salariu * procent / 100.0);
    } else {
        std::cerr << "Procentul pentru majorarea salariului trebuie să fie pozitiv." << std::endl;
    }

};