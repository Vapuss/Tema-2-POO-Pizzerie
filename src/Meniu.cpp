#include "../headerz/Meniu.h"
#include <algorithm>

Meniu::Meniu() {}

Meniu::Meniu(const Meniu& other)
        : pizze(other.pizze), paste(other.paste), bauturi(other.bauturi), deserturi(other.deserturi) {}

Meniu& Meniu::operator=(const Meniu& other) {
    if (this != &other) {
        pizze = other.pizze;
        paste = other.paste;
        bauturi = other.bauturi;
        deserturi = other.deserturi;
    }
    return *this;
}

Meniu::~Meniu() {}

void Meniu::adaugaPizza(const Pizza& pizza) {
    pizze.push_back(pizza);
}

void Meniu::adaugaPaste(const Paste& paste) {
    this->paste.push_back(paste);
}

void Meniu::adaugaBautura(const Bauturi& bautura) {
    bauturi.push_back(bautura);
}

void Meniu::adaugaDesert(const Desert& desert) {
    deserturi.push_back(desert);
}

void Meniu::scoatePizza(const std::string& nume) {
    pizze.erase(std::remove_if(pizze.begin(), pizze.end(),
                               [&](const Pizza& pizza){ return pizza.getNume() == nume; }), pizze.end());
}

void Meniu::scoatePaste(const std::string& nume) {
    paste.erase(std::remove_if(paste.begin(), paste.end(),
                               [&](const Paste& paste){ return paste.getNume() == nume; }), paste.end());
}

void Meniu::scoateBautura(const std::string& nume) {
    bauturi.erase(std::remove_if(bauturi.begin(), bauturi.end(),
                                 [&](const Bauturi& bautura){ return bautura.getNumeB() == nume; }), bauturi.end());
}

void Meniu::scoateDesert(const std::string& nume) {
    deserturi.erase(std::remove_if(deserturi.begin(), deserturi.end(),
                                   [&](const Desert& desert){ return desert.getNume() == nume; }), deserturi.end());
}




void Meniu::adaugaPreparat(const std::shared_ptr<Preparat>& preparat) {
    preparate.push_back(preparat);
}

void Meniu::afiseazaMeniu() const {
    for (const auto& preparat : preparate) {
        preparat->creeazaPreparat();  // Polimorfism
    }
}

double Meniu::calculeazaBonul(const std::vector<std::string>& numePreparate) const {
    double costTotal = 0.0;
    for (const auto& nume : numePreparate) {
        for (const auto& preparat : preparate) {
            if (preparat->getNume() == nume) {
                costTotal += preparat->getPret();
                break; // Întrerupe bucla interioară odată ce preparatul este găsit
            }
        }
    }
    return costTotal;
}







std::ostream& operator<<(std::ostream& os, const Meniu& meniu) {
    os << "Meniu:\n";
    os << "Pizze:\n";
    for (const auto& pizza : meniu.pizze) {
        os << pizza << "\n";
    }
    os << "Paste:\n";
    for (const auto& paste : meniu.paste) {
        os << paste << "\n";
    }
    os << "Bauturi:\n";
    for (const auto& bautura : meniu.bauturi) {
        os << bautura << "\n";
    }
    os << "Deserturi:\n";
    for (const auto& desert : meniu.deserturi) {
        os << desert << "\n";
    }
    return os;
}
