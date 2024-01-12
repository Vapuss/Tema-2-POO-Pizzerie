#include "../headerz/Pizza.h"



    Pizza::Pizza(const std::string &nume, const std::vector<std::string> &ingrediente,
          double pret, int gramaj, bool vegetarian, int dimensiuneBlat, const std::string &stilPizza)
            : Preparat(nume, ingrediente, pret, gramaj, vegetarian),
              dimensiuneBlat(dimensiuneBlat), stilPizza(stilPizza) {}

    // Constructor de copiere
    Pizza::Pizza(const Pizza &other)
            : Preparat(other), dimensiuneBlat(other.dimensiuneBlat), stilPizza(other.stilPizza) {}

    // Operator de atribuire
    Pizza& Pizza::operator=(const Pizza &other) {
        if (this != &other) {
            Preparat::operator=(other);
            dimensiuneBlat = other.dimensiuneBlat;
            stilPizza = other.stilPizza;
        }
        return *this;
    }

    // Destructor
    Pizza::~Pizza() {}

    // Funcții publice pentru personalizarea pizzei
    void Pizza::adaugaIngredientPizza(const std::string &ingredient) {
        adaugaIngredient(ingredient);
    }

    void Pizza::scoateIngredientPizza(const std::string &ingredient) {
        scoateIngredient(ingredient);
    }


    void Pizza::creeazaPreparat() const {
        std::cout << "Pizza " << getNume()
                  << " - Dimensiune blat: " << dimensiuneBlat << " cm"
                  << ", Stil: " << stilPizza
                  << ", Pret: " << getPret() << " lei"
                  << ", Gramaj: " << getGramaj() << " g"
                  << ", Vegetarian: " << (isVegetarian() ? "Da" : "Nu")
                  << std::endl;
    }



    std::unique_ptr<Preparat> Pizza::clone() const {
        return std::make_unique<Pizza>(*this);
    }



// Operator <<
    std::ostream &operator<<(std::ostream &os, const Pizza &pizza) {
        os << static_cast<const Preparat &>(pizza) // Afișează partea de Preparat
           << "Dimensiune Blat: " << pizza.dimensiuneBlat << " cm"
           << "\nStil Pizza: " << pizza.stilPizza << "\n";
        return os;
    }
