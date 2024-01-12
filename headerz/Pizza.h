#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <string>
#include <vector>

#include "../headerz/Preparat.h"


class Pizza : public Preparat {
    int dimensiuneBlat; // 24, 32, 40 cm
    std::string stilPizza; // neapolitan, roman, chicago, etc.

public:

    Pizza(const std::string &nume, const std::vector<std::string> &ingrediente,
          double pret, int gramaj, bool vegetarian, int dimensiuneBlat, const std::string &stilPizza);

    Pizza(const Pizza &other);


    Pizza &operator=(const Pizza &other);

    ~Pizza();

    // Funcții publice pentru personalizarea pizzei
    void adaugaIngredientPizza(const std::string &ingredient);
    void scoateIngredientPizza(const std::string &ingredient);

    void creeazaPreparat() const override;
    std::unique_ptr<Preparat> clone() const override;



    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Pizza &pizza);
};
void swap(Pizza& first, Pizza& second);
#endif