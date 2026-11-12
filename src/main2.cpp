
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Exception personnalisee
class StockInsuffisantException : public exception {
public:
    const char* what() const noexcept override {
        return "Erreur : stock insuffisant pour effectuer la vente !";
    }
};

// Classe Produit
class Produit {
private:
    string nom;
    int stock;

public:
    Produit(string n, int s) {
        nom = n;
        stock = s;
    }

    void vendre(int quantite) {
        if (quantite > stock) {
            throw StockInsuffisantException();
        }

        stock -= quantite;
        cout << "Vente effectuee avec succes !" << endl;
        cout << "Stock restant : " << stock << endl;
    }
};

int main() {
    Produit p("Ordinateur", 10);

    try {
        p.vendre(3);   // Vente normale
        p.vendre(9);   // Stock insuffisant
    }
    catch (const StockInsuffisantException& e) {
        cout << e.what() << endl;
    }

    return 0;
}
