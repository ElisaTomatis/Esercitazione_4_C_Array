#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    
	ifstream inputFile("data.txt");
    ofstream outputFile("result.txt");

    if (inputFile.fail()) {
        cerr << "Errore nell'apertura di data.txt" << endl;
        return 1;
    }
	
	if (outputFile.fail())
	{
		std::cerr << "Non è stato possibile creare il file result.txt" << std::endl;
		return 1;
	}

    double S;
    int n;
    string line;

    // Lettura di S
    getline(inputFile, line);
    S = stod(line.substr(line.find(";") + 1));

    // Lettura di n
    getline(inputFile, line);
    n = stoi(line.substr(line.find(";") + 1));

    // Lettura dell'intestazione w;r
    getline(inputFile, line);

    vector<double> w;
	vector<double> r;
    double R = 0.0; // inizializzazione del rate of return totale


    while (getline(inputFile, line)) {
        stringstream ss(line);
        string w_str, r_str;

        getline(ss, w_str, ';');
        getline(ss, r_str, ';');

        double wi = stod(w_str);
        double ri = stod(r_str);

        w.push_back(wi);
        r.push_back(ri);

        R += wi * ri; // calcolo diretto durante la lettura
    }

    inputFile.close();

    // Calcolo del valore finale del portafoglio
    double V = S * (1 + R);

    // Scrittura su file
    outputFile << fixed << setprecision(2);
    outputFile << "S = " << S << ", n = " << n << endl;
    outputFile << "w = [ ";
    for (double val : w) outputFile << val << " ";
    outputFile << "]" << endl;

    outputFile << "r = [ ";
    for (double val : r) outputFile << val << " ";
    outputFile << "]" << endl;

    outputFile << fixed << setprecision(4);
    outputFile << "Rate of return of the portfolio: " << R << endl;

    outputFile << fixed << setprecision(2);
    outputFile << "V: " << V << endl;

    outputFile.close();

    return 0;
}

