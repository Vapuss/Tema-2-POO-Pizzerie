#ifndef TEMA_2_POO_PIZZERIE_TRATTORIAEXCEPTIE_H
#define TEMA_2_POO_PIZZERIE_TRATTORIAEXCEPTIE_H

#include <exception>
#include <string>

class TrattoriaExceptie : public std::exception {
protected:
    std::string message;

public:
    explicit TrattoriaExceptie(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};


#endif //TEMA_2_POO_PIZZERIE_TRATTORIAEXCEPTIE_H
