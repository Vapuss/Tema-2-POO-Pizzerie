#ifndef DESERT_H
#define DESERT_H

#include <iostream>
#include <string>
#include <vector>
#include "../headerz/Preparat.h"

class Desert : public Preparat {
    bool zahar;
    bool lactoza;

public:
    Desert(const std::string& nume, const std::vector<std::string>& ingrediente,
           double pret, int gramaj, bool vegetarian, bool zahar, bool lactoza);
    Desert(const Desert& other);
    Desert& operator=(const Desert& other);
    ~Desert();


    void creeazaPreparat() const override;


    std::unique_ptr<Preparat> clone() const override;

    friend std::ostream& operator<<(std::ostream& os, const Desert& desert);
};

#endif // DESERT_H
