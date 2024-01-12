#ifndef TEMA_2_POO_PIZZERIE_ANGAJATEXCEPTIE_H
#define TEMA_2_POO_PIZZERIE_ANGAJATEXCEPTIE_H

#include "TrattoriaExceptie.h"

class AngajatExceptie : public TrattoriaExceptie {
public:
    explicit AngajatExceptie(const std::string& msg) : TrattoriaExceptie(msg) {}
};


#endif //TEMA_2_POO_PIZZERIE_ANGAJATEXCEPTIE_H
