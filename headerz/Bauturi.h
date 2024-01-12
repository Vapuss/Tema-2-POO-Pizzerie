#ifndef BAUTURI_H
#define BAUTURI_H

#include <iostream>
#include <string>
#include <vector>


class Bauturi {
    std::string nume_b;
    std::vector<std::string> ingrediente_b;
    bool alcool;
    double pret_b;
    int volum; // În mililitri

public:

    Bauturi(const std::string& nume, const std::vector<std::string>& ingrediente,
            bool alcool, double pret, int volum);

    Bauturi(const Bauturi& other);

    Bauturi& operator=(const Bauturi& other);


    ~Bauturi();

    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Bauturi& bautura);

    const std::string &getNumeB() const;

    };


#endif
