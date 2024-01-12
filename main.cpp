#include <iostream>
#include <string>
#include <vector>

#include "headerz/Angajat.h"
#include "headerz/Bauturi.h"
#include "headerz/Bucatar.h"
#include "headerz/Desert.h"
#include "headerz/Local.h"
#include "headerz/Meniu.h"
#include "headerz/Preparat.h"
#include "headerz/Paste.h"
#include "headerz/Pizza.h"
#include "headerz/Review.h"
#include "headerz/TrattoriaExceptie.h"
#include "headerz/PreparatExceptie.h"
#include "headerz/AngajatExceptie.h"
        int main() {


            try {
                // Testarea excepției pentru Preparat
                std::vector<std::string> ingredienteVeg = {"brânză", "ciuperci"};
                Pizza pizzaVeg("Pizza Vegetariană", ingredienteVeg, 30.0, 350, true, 32, "Neapolitan");

            } catch (const PreparatExceptie& e) {
                std::cerr << "Eroare la crearea preparatului: " << e.what() << std::endl;
            } catch (const AngajatExceptie& e) {
                std::cerr << "Eroare la crearea angajatului: " << e.what() << std::endl;
            }

            Angajat angajat("Alex Popescu", 30, 12, "0123456789", 3000.0, "Ospatar", 24, "Ospatarie");
            std::cout << "Informatii angajat initial:\n" << angajat << "\n";


            angajat.maresteSalariu(10.0); // Majoram salariul cu 10%
            std::cout << "Informatii angajat dupa majorare salariu:\n" << angajat << "\n";


            Bucatar bucatar("Maria Ionescu", 35, 24, "0987654321", 4000.0, "Ajutor de bucatar", 36, "Bucatarie", "Ajutor bucatar");
            std::cout << "Informatii bucatar initial:\n" << bucatar << "\n";

            // Modificarea unor atribute ale bucatarului
            bucatar.promoveazaGrad("Sous Chef");
            bucatar.adaugaSpecialitate("Pizzaiolo");
            bucatar.adaugaSpecialitate("Cofetar");
            std::cout << "Informatii bucatar dupa promovare si adaugare specialitati:\n" << bucatar << "\n";





            Local trattoria("Trattoria Da Marco", "Strada Principala 123", "0123456789");


            Review review1("Mihai", 5, "Pizza excelentă!");
            trattoria.acordaReview(review1);


            Angajat angajat1("Maria", 30, 12, "9876543210", 3000, "Chef", 24, "Bucătărie");
            trattoria.adaugaAngajat(angajat1);


            trattoria.schimbaAdresa("Bulevardul Unirii 45");
            std::cout << trattoria;




            std::vector<std::string> ingrediente = {"sos de rosii", "mozzarella", "busuioc"};
            Pizza pizzaM("Pizza Margherita", ingrediente, 35.0, 400, false, 32, "Neapolitan");


            pizzaM.adaugaIngredient("masline");
            pizzaM.scoateIngredient("busuioc");

            std::cout << pizzaM;



            std::vector<std::string> ingredienteTagRagu = {"faina", "oua", "sare"};
            Paste tagliatelle("Tagliatelle al Ragù", ingredienteTagRagu, 45.0, 300, false, "Taglierini", "Normal");

            std::cout << tagliatelle;



            std::vector<std::string> ingredienteLimo = {"apa", "lamaie", "zahar"};
            Bauturi limonada("Limonada", ingredienteLimo, false, 15.0, 500);

            std::cout << limonada;




            Meniu meniu1;
            meniu1.adaugaPizza(Pizza("Margherita", {"sos de roșii", "mozzarella"}, 30.0, 400, false, 32, "Neapolitan"));
            meniu1.adaugaPaste(Paste("Carbonara", {"paste", "ouă", "parmezan", "pancetta"}, 45.0, 300, false, "Spaghetti", "Normal"));
            meniu1.adaugaBautura(Bauturi("Limonada", {"apă", "lamaie", "zahăr"}, false, 15.0, 500));
            meniu1.adaugaDesert(Desert("Tiramisu", {"cafea", "mascarpone", "piscoturi", "cacao"}, 35.0, 250, false, true, true));


            std::cout << meniu1;




            Meniu meniu2;

            // Crearea unei pizze
            std::shared_ptr<Preparat> pizza = std::make_shared<Pizza>("Margherita", std::vector<std::string>{"sos de rosii", "mozzarella"}, 30.0, 400, false, 32, "Neapolitan");
            pizza->creeazaPreparat(); // Afișează detaliile pizzei

            // Crearea unui preparat de paste
            std::shared_ptr<Preparat> paste = std::make_shared<Paste>("Carbonara", std::vector<std::string>{"paste", "ouă", "parmezan", "pancetta"}, 45.0, 300, false, "Spaghetti", "Normal");
            paste->creeazaPreparat(); // Afișează detaliile pastelor

            // Crearea unui desert
            std::shared_ptr<Preparat> desert = std::make_shared<Desert>("Tiramisu", std::vector<std::string>{"cafea", "mascarpone", "piscoturi", "cacao"}, 35.0, 250, false, true, true);
            desert->creeazaPreparat(); // Afișează detaliile desertului

            // Adăugarea preparatelor în meniu
            meniu2.adaugaPreparat(pizza);
            meniu2.adaugaPreparat(paste);
            meniu2.adaugaPreparat(desert);

            // Afișarea întregului meniu
            std::cout << "Meniul complet:\n";
            meniu2.afiseazaMeniu();




            std::vector<std::string> comandaClient = {"Margherita", "Carbonara", "Tiramisu"};

            // Calculul și afișarea bonului pentru comanda clientului
            std::cout << "Costul total pentru comanda selectată: "
                      << meniu2.calculeazaBonul(comandaClient) << " lei" << std::endl<<"\n";



            std::vector<std::string> ingredienteTaraneasca = {"sos de roșii", "mozzarella", "ciuperci", "ceapă", "bacon"};
            std::unique_ptr<Preparat> pizzaTaraneasca = std::make_unique<Pizza>("Țărănească", ingredienteTaraneasca, 40.0, 450, false, 32, "Clasic");

            // Clonarea pizzei "Țărănească"
            std::unique_ptr<Preparat> pizzaTaraneascaClona = pizzaTaraneasca->clone();

            // Afișarea detaliilor pentru pizza "Țărănească" (originală și clonă);
            pizzaTaraneasca->creeazaPreparat();
            pizzaTaraneascaClona->creeazaPreparat();

            return 0;
        }