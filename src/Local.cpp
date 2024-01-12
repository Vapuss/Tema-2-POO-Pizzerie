#include "../headerz/Local.h"
#include "../headerz/AngajatExceptie.h"
Local::Local(const std::string& nume, const std::string& adresa, const std::string& contact)
        : nume(nume), adresa(adresa), contact(contact) {}

Local::Local(const Local& other)
        : nume(other.nume), adresa(other.adresa), contact(other.contact),
          reviewuri(other.reviewuri), staff(other.staff) {}

Local& Local::operator=(const Local& other) {
    if (this != &other) {
        nume = other.nume;
        adresa = other.adresa;
        contact = other.contact;
        reviewuri = other.reviewuri;
        staff = other.staff;
    }
    return *this;
}

Local::~Local() {}

void Local::acordaReview(const Review& review) {
    reviewuri.push_back(review);
}

void Local::adaugaAngajat(const Angajat& angajat) {

        if (angajat.getSalariu() < 2400) {
            throw AngajatExceptie("Salariul angajatului este sub minimul legal.");
        }
        staff.push_back(angajat);

}

void Local::schimbaAdresa(const std::string& nouaAdresa) {
    adresa = nouaAdresa;
}




std::ostream& operator<<(std::ostream& os, const Local& local) {
    os << "Local: " << local.nume << "\nAdresa: " << local.adresa << "\nContact: " << local.contact << "\n";
    return os;
}
