#ifndef LOCAL_H  // Include guard pentru a preveni includerea multiplă
#define LOCAL_H

#include <string>
#include <vector>
#include "Review.h"
#include "Angajat.h"
class Local {
    std::string nume;
    std::string adresa;
    std::string contact;
    std::vector<Review> reviewuri;
    std::vector<Angajat> staff;

public:
    Local(const std::string& nume, const std::string& adresa, const std::string& contact);
    Local(const Local& other);
    Local& operator=(const Local& other);
    ~Local();

    void acordaReview(const Review& review);
    void adaugaAngajat(const Angajat& angajat);
    void schimbaAdresa(const std::string& nouaAdresa);

    friend std::ostream& operator<<(std::ostream& os, const Local& local);
};

#endif
