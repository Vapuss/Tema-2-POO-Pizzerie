#include "../headerz/Review.h"

Review::Review(const std::string& nume, int rating, const std::string& continut)
        : numeOaspete(nume), rating(rating), continut(continut) {}

// Constructor de copiere
Review::Review(const Review& other)
        : numeOaspete(other.numeOaspete), rating(other.rating), continut(other.continut) {}

// Operator de atribuire
Review& Review::operator=(const Review& other) {
    if (this != &other) {
        numeOaspete = other.numeOaspete;
        rating = other.rating;
        continut = other.continut;
    }
    return *this;
}

// Destructor
Review::~Review() {}

// Operator <<
std::ostream& operator<<(std::ostream& os, const Review& review) {
    os << "Review de la " << review.numeOaspete
       << " - Rating: " << review.rating
       << " - " << review.continut;
    return os;
}