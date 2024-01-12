#ifndef PREPARAT_H
#define PREPARAT_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

class Preparat {
    std::string nume_miam;
    std::vector<std::string> ingrediente;
    double pret;
    int gramaj;
    bool vegetarian;

public:
    Preparat(const std::string& nume, const std::vector<std::string>& ingrediente,
             double pret, int gramaj, bool vegetarian);
    Preparat(const Preparat& other);
    Preparat& operator=(const Preparat& other);
    ~Preparat();


    void adaugaIngredient(const std::string& ingredient);
    void scoateIngredient(const std::string& ingredient);

    const std::vector<std::string>& getIngrediente() const;
    const std::string& getNume() const;
    double getPret() const;
    int getGramaj() const;
    bool isVegetarian() const;

    virtual void creeazaPreparat() const = 0;
    virtual std::unique_ptr<Preparat> clone() const = 0;


    friend std::ostream& operator<<(std::ostream& os, const Preparat& preparat);
};

#endif // PREPARAT_H
