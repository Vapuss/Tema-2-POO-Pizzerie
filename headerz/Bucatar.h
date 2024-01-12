#ifndef BUCATAR_H
#define BUCATAR_H

#include <string>
#include <vector>
#include <ostream>
#include "../headerz/Angajat.h"

class Bucatar : public Angajat {
    std::string grad;
    std::vector<std::string> specialitati;

public:
    Bucatar(const std::string& nume, int varsta, int perioadaContract, const std::string& contact,
            double salariu, const std::string& fostJob, int durata, const std::string& post,
            const std::string& grad);
    Bucatar(const Bucatar& other);
    Bucatar& operator=(const Bucatar& other);
    ~Bucatar();
//    std::unique_ptr<Angajat> clone() const override;
    void promoveazaGrad(const std::string& nouGrad);
    void adaugaSpecialitate(const std::string& specialitate);

    friend std::ostream& operator<<(std::ostream& os, const Bucatar& bucatar);
};

#endif // BUCATAR_H
