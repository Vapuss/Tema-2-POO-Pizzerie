#include "../headerz/Preparat.h"
#include "../headerz/PreparatExceptie.h"

Preparat::Preparat(const std::string& nume, const std::vector<std::string>& ingrediente,
                   double pret, int gramaj, bool vegetarian)
        : nume_miam(nume), ingrediente(ingrediente), pret(pret), gramaj(gramaj), vegetarian(vegetarian) {
    if (std::find(ingrediente.begin(), ingrediente.end(), "sos de roșii") == ingrediente.end()) {
        throw PreparatExceptie("Lipsește ingredientul esențial: sos de roșii");
    }
}

Preparat::Preparat(const Preparat& other)
        : nume_miam(other.nume_miam), ingrediente(other.ingrediente), pret(other.pret), gramaj(other.gramaj), vegetarian(other.vegetarian) {}

Preparat& Preparat::operator=(const Preparat& other) {
    if (this != &other) {
        nume_miam = other.nume_miam;
        ingrediente = other.ingrediente;
        pret = other.pret;
        gramaj = other.gramaj;
        vegetarian = other.vegetarian;
    }
    return *this;
}


Preparat::~Preparat() {}


void Preparat::adaugaIngredient(const std::string& ingredient) {
    ingrediente.push_back(ingredient);
}

void Preparat::scoateIngredient(const std::string& ingredient) {
    ingrediente.erase(std::remove(ingrediente.begin(), ingrediente.end(), ingredient), ingrediente.end());
}

const std::vector<std::string>& Preparat::getIngrediente() const {
    return ingrediente;
}

const std::string& Preparat::getNume() const {
    return nume_miam;
}
double Preparat::getPret() const {
    return pret;
}
int Preparat::getGramaj() const {
    return gramaj;
}
bool Preparat::isVegetarian() const {
    return vegetarian;
}


std::ostream& operator<<(std::ostream& os, const Preparat& preparat) {
    os << "Nume: " << preparat.nume_miam << "\nIngrediente: ";
    for (const auto& ingredient : preparat.ingrediente) {
        os << ingredient << ", ";
    }
    os << "\nPret: " << preparat.pret << " lei"
       << "\nGramaj: " << preparat.gramaj << " g"
       << "\nVegetarian: " << (preparat.vegetarian ? "Da" : "Nu") << "\n";
    return os;
}




