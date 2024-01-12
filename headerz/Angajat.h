#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>




class Angajat {
    std::string nume_ang;
    int varsta_ang;
    int perioada_contractului; // În luni
    std::string contact_ang; // Număr de telefon
    double salariu;
    struct Experienta {
        std::string fostJob;
        int durata; // În luni sau ani
    } experienta;
    std::string post; // Bucătărie, ospătar, logistică

public:
    Angajat(const std::string &nume, int varsta, int perioadaContract, const std::string &contact,
            double salariu, const std::string &fostJob, int durata, const std::string &post);

    Angajat(const Angajat &other);
    Angajat &operator=(const Angajat &other);

    ~Angajat();

    //virtual std::unique_ptr<Angajat> clone() const = 0;
    // Operator <<
    friend std::ostream &operator<<(std::ostream &os, const Angajat &angajat);

    void maresteSalariu(double procent);

    double getSalariu() const;

};

#endif