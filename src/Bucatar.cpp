#include "../headerz/Bucatar.h"

Bucatar::Bucatar(const std::string& nume, int varsta, int perioadaContract, const std::string& contact,
                 double salariu, const std::string& fostJob, int durata, const std::string& post,
                 const std::string& grad)
        : Angajat(nume, varsta, perioadaContract, contact, salariu, fostJob, durata, post), grad(grad) {}

Bucatar::Bucatar(const Bucatar& other)
        : Angajat(other), grad(other.grad), specialitati(other.specialitati) {}

Bucatar& Bucatar::operator=(const Bucatar& other) {
    if (this != &other) {
        Angajat::operator=(other);
        grad = other.grad;
        specialitati = other.specialitati;
    }
    return *this;
}

Bucatar::~Bucatar() {}

//std::unique_ptr<Angajat> Bucatar::clone() const {
//    return std::make_unique<Bucatar>(*this);
//}
void Bucatar::promoveazaGrad(const std::string& nouGrad) {
    grad = nouGrad;
}

void Bucatar::adaugaSpecialitate(const std::string& specialitate) {
    specialitati.push_back(specialitate);
}

std::ostream& operator<<(std::ostream& os, const Bucatar& bucatar) {
    os << static_cast<const Angajat&>(bucatar)
       << "\nGrad: " << bucatar.grad
       << "\nSpecialitati: ";
    for (const auto& specialitate : bucatar.specialitati) {
        os << specialitate << ", ";
    }
    return os;
}
