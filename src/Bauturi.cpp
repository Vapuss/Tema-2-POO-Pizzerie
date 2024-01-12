#include "../headerz/Bauturi.h"


Bauturi::Bauturi(const std::string& nume, const std::vector<std::string>& ingrediente,
        bool alcool, double pret, int volum)
        : nume_b(nume), ingrediente_b(ingrediente),
          alcool(alcool), pret_b(pret), volum(volum) {}

// Constructor de copiere
Bauturi::Bauturi(const Bauturi& other)
        : nume_b(other.nume_b), ingrediente_b(other.ingrediente_b),
          alcool(other.alcool), pret_b(other.pret_b), volum(other.volum) {}

// Operator de atribuire
Bauturi& Bauturi::operator=(const Bauturi& other) {
    if (this != &other) {
        nume_b = other.nume_b;
        ingrediente_b = other.ingrediente_b;
        alcool = other.alcool;
        pret_b = other.pret_b;
        volum = other.volum;
    }
    return *this;
}

// Destructor
Bauturi::~Bauturi() {}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Bauturi& bautura) {
    os << "Nume: " << bautura.nume_b << "\nIngrediente: ";
    for (const auto& ingredient : bautura.ingrediente_b) {
        os << ingredient << ", ";
    }
    os << "\nAlcool: " << (bautura.alcool ? "Da" : "Nu")
       << "\nPret: " << bautura.pret_b << " lei"
       << "\nVolum: " << bautura.volum << " ml\n";
    return os;
}

const std::string &Bauturi::getNumeB() const {
    return nume_b;
}