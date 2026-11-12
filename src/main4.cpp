
#include <iostream>
#include <exception>
using namespace std;

// Premiere exception : montant invalide
class MontantInvalideException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : le montant doit etre positif !";
    }
};

// Deuxieme exception : solde insuffisant
class SoldeInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : solde insuffisant pour effectuer le retrait !";
    }
};

// Classe Compte
class Compte {
private:
    int solde;

public:
    Compte(int s) {
        solde = s;
    }

    void deposer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException();
        }

        solde += montant;
        cout << "Depot effectue : " << montant << " DH" << endl;
        cout << "Solde actuel : " << solde << " DH" << endl;
    }

    void retirer(int montant) {
        if (montant <= 0) {
            throw MontantInvalideException();
        }

        if (montant > solde) {
            throw SoldeInsuffisantException();
        }

        solde -= montant;
        cout << "Retrait effectue : " << montant << " DH" << endl;
        cout << "Solde actuel : " << solde << " DH" << endl;
    }
};

int main() {
    Compte c(1000);

    cout << "Solde initial : 1000 DH" << endl;

    // Test 1 : depot normal
    try {
        c.deposer(500);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    // Test 2 : depot negatif
    try {
        c.deposer(-200);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }

    // Test 3 : retrait normal
    try {
        c.retirer(300);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    // Test 4 : retrait superieur au solde
    try {
        c.retirer(2000);
    }
    catch (const MontantInvalideException& e) {
        cout << e.what() << endl;
    }
    catch (const SoldeInsuffisantException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
