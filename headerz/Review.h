#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>
#include <vector>

class Review {
    std::string numeOaspete;
    int rating; // Rating de la 1 la 5
    std::string continut;

public:

    Review(const std::string& nume, int rating, const std::string& continut);
    Review(const Review& other);

    Review& operator=(const Review& other);
    ~Review();

    // Operator <<
    friend std::ostream& operator<<(std::ostream& os, const Review& review);

};

#endif