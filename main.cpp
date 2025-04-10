#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "Utils.hpp" 

using namespace std;

int main() {
    ifstream inputFile("data.txt");

    if (inputFile.fail()) {
        cerr << "Errore nell'apertura di data.txt" << endl;
        return 1;
    }

    double S;
    int n;
    string line;

    // Lettura del valore iniziale S
    getline(inputFile, line);
    S = stod(line.substr(line.find(";") + 1));

    // Lettura del numero di elementi n
    getline(inputFile, line);
    n = stoi(line.substr(line.find(";") + 1));

    // Lettura dell'intestazione "w;r"
    getline(inputFile, line);

    // Allocazione dinamica degli array C-style per w e r
    double* w = new double[n];
    double* r = new double[n];

    double R = 0.0; // rate of return totale
    int i = 0;
    while (getline(inputFile, line) && i < n) {
        stringstream ss(line);
        string w_str, r_str;

        getline(ss, w_str, ';');
        getline(ss, r_str, ';');

        double wi = stod(w_str);
        double ri = stod(r_str);

        w[i] = wi;
        r[i] = ri;

        R += wi * ri;
        i++;
    }

    inputFile.close();

    // Calcolo del valore finale del portafoglio
    double V = S * (1 + R);

    // Scrittura su file usando funzione Utils
    if (!ExportPortfolioResult("result.txt", S, V, R, n, w, r)) {
        cerr << "Errore nella scrittura su result.txt" << endl;
        return 1;
    }

    // Deallocazione della memoria dinamica
    delete[] w;
    delete[] r;

    return 0;
}