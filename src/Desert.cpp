#include "../headerz/Desert.h"

Desert::Desert(const std::string& nume, const std::vector<std::string>& ingrediente,
               double pret, int gramaj, bool vegetarian, bool zahar, bool lactoza)
        : Preparat(nume, ingrediente, pret, gramaj, vegetarian),
          zahar(zahar), lactoza(lactoza) {}

Desert::Desert(const Desert& other)
        : Preparat(other), zahar(other.zahar), lactoza(other.lactoza) {}

Desert& Desert::operator=(const Desert& other) {
    if (this != &other) {
        Preparat::operator=(other);
        zahar = other.zahar;
        lactoza = other.lactoza;
    }
    return *this;
}

Desert::~Desert() {}

void Desert::creeazaPreparat() const  {
std::cout << "Desert " << getNume()
<< ", Ingrediente : ";
for (const auto& ingredient : getIngrediente()) {
std::cout << ingredient << ", ";
}
std::cout << ", Zahar: " << (zahar ? "Da" : "Nu")
<< ", Lactoza: " << (lactoza ? "Da" : "Nu")
<< ", Pret: " << getPret() << " lei"
<< ", Gramaj: " << getGramaj() << " g"
<< ", Vegetarian: " << (isVegetarian() ? "Da" : "Nu")
<< std::endl;
}


std::unique_ptr<Preparat> Desert::clone() const {
    return std::make_unique<Desert>(*this);
}



std::ostream& operator<<(std::ostream& os, const Desert& desert) {
    os << static_cast<const Preparat&>(desert)
       << "Zahar: " << (desert.zahar ? "Da" : "Nu")
       << "\nLactoza: " << (desert.lactoza ? "Da" : "Nu") << "\n";
    return os;
}
