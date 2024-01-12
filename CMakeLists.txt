cmake_minimum_required(VERSION 3.26)
project(Tema_2_POO_Pizzerie)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tema_2_POO_Pizzerie main.cpp
        src/Angajat.cpp
        src/Bauturi.cpp
        src/Bucatar.cpp
        src/Desert.cpp
        src/Local.cpp
        src/Meniu.cpp
        src/Paste.cpp
        src/Pizza.cpp
        src/Preparat.cpp
        src/Review.cpp
        headerz/TrattoriaExceptie.h
        headerz/PreparatExceptie.h
        headerz/AngajatExceptie.h)
