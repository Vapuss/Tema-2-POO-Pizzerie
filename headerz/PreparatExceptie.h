#ifndef TEMA_2_POO_PIZZERIE_PREPARATEXCEPTIE_H
#define TEMA_2_POO_PIZZERIE_PREPARATEXCEPTIE_H

#include "TrattoriaExceptie.h"

class PreparatExceptie : public TrattoriaExceptie {
public:
    explicit PreparatExceptie(const std::string& msg) : TrattoriaExceptie(msg) {}
};



#endif //TEMA_2_POO_PIZZERIE_PREPARATEXCEPTIE_H
