#ifndef PASTE_H
#define PASTE_H

#include <iostream>
#include <string>
#include <vector>
#include "../headerz/Preparat.h"



class Paste : public Preparat {
    std::string tipPaste; // Ex: fussili, spaghetti, etc.
    std::string tipAluat; // Ex: integral, normal, gluten free

public:
    Paste(const std::string &nume, const std::vector<std::string> &ingrediente,
          double pret, int gramaj, bool vegetarian, const std::string &tipPaste, const std::string &tipAluat);
    Paste(const Paste &other);

    Paste &operator=(const Paste &other);

    ~Paste();


    void creeazaPreparat() const override;


    std::unique_ptr<Preparat> clone() const override;

    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Paste &paste);
};

#endif
