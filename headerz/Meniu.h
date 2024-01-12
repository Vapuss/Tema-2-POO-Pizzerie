#ifndef MENIU_H
#define MENIU_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include "../headerz/Pizza.h"
#include "../headerz/Paste.h"
#include "../headerz/Bauturi.h"
#include "../headerz/Desert.h"
#include "../headerz/Preparat.h"

class Meniu {

private:
    std::vector<std::shared_ptr<Preparat>> preparate;
    std::vector<Pizza> pizze;
    std::vector<Paste> paste;
    std::vector<Bauturi> bauturi;
    std::vector<Desert> deserturi;

public:
    Meniu();
    Meniu(const Meniu& other);
    Meniu& operator=(const Meniu& other);
    ~Meniu();

    void adaugaPizza(const Pizza& pizza);
    void adaugaPaste(const Paste& paste);
    void adaugaBautura(const Bauturi& bautura);
    void adaugaDesert(const Desert& desert);


    void adaugaPreparat(const std::shared_ptr<Preparat>& preparat);
    void afiseazaMeniu() const;
    double calculeazaBonul(const std::vector<std::string>& numePreparate) const;

    void scoatePizza(const std::string& nume);
    void scoatePaste(const std::string& nume);
    void scoateBautura(const std::string& nume);
    void scoateDesert(const std::string& nume);

    friend std::ostream& operator<<(std::ostream& os, const Meniu& meniu);
};

#endif
