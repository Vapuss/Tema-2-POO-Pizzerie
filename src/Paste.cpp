#include "../headerz/Paste.h"

Paste::Paste(const std::string& nume, const std::vector<std::string>& ingrediente,
      double pret, int gramaj, bool vegetarian, const std::string& tipPaste, const std::string& tipAluat)
        : Preparat(nume, ingrediente, pret, gramaj, vegetarian),
          tipPaste(tipPaste), tipAluat(tipAluat) {}

// Constructor de copiere
Paste::Paste(const Paste& other)
        : Preparat(other), tipPaste(other.tipPaste), tipAluat(other.tipAluat) {}

// Operator de atribuire
Paste& Paste::operator=(const Paste& other) {
    if (this != &other) {
        Preparat::operator=(other);
        tipPaste = other.tipPaste;
        tipAluat = other.tipAluat;
    }
    return *this;
}

// Destructor
Paste::~Paste() {}

void Paste::creeazaPreparat() const{
std::cout << "Paste " << getNume()
<< ", Ingrediente : ";
for (const auto& ingredient : getIngrediente()) {
std::cout << ingredient << ", ";
}
std::cout << " - Tip Paste: " << tipPaste
<< ", Tip Aluat: " << tipAluat
<< ", Pret: " << getPret() << " lei"
<< ", Gramaj: " << getGramaj() << " g"
<< ", Vegetarian: " << (isVegetarian() ? "Da" : "Nu")
<< std::endl;
}


std::unique_ptr<Preparat> Paste::clone() const {
    return std::make_unique<Paste>(*this);
}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Paste& paste) {
    os << static_cast<const Preparat&>(paste) // Afișează partea de Preparat
       << "Tip Paste: " << paste.tipPaste
       << "\nTip Aluat: " << paste.tipAluat << "\n";
    return os;
}
