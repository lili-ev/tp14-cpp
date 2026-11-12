
#include <iostream>
#include <stdexcept>
using namespace std;

// Fonction diviser
double diviser(int a, int b) {
    if (b == 0) {
        throw runtime_error("Erreur : division par zero impossible !");
    }

    return (double)a / b;
}

int main() {

    // Premier test
    try {
        cout << "10 / 2 = " << diviser(10, 2) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Deuxieme test
    try {
        cout << "20 / 4 = " << diviser(20, 4) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    // Troisieme test : division par zero
    try {
        cout << "15 / 0 = " << diviser(15, 0) << endl;
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
