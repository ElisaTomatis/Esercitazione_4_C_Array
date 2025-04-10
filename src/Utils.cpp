#include "Utils.hpp"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <iostream>  


using namespace std;

string ArrayToString(const size_t& n,
                     const double* const v,
                     int precision)
{
    ostringstream toString;
    toString << fixed << setprecision(precision);
    toString << "[ ";
    for (size_t i = 0; i < n; ++i)
        toString << v[i] << " ";
    toString << "]";
    return toString.str();
}

bool ExportPortfolioResult(const string& outputFilePath,
                           double S,
                           double V,
                           double R,
                           const size_t n,
                           const double* const w,
                           const double* const r)
{
    ofstream file(outputFilePath);
    if (!file.is_open()) {
        cerr << "Errore apertura file di output." << endl;
        return false;
    }

    file << fixed << setprecision(2);
    file << "S = " << S << ", n = " << n << endl;
    file << "w = " << ArrayToString(n, w, 2) << endl;
    file << "r = " << ArrayToString(n, r, 2) << endl;

    file << fixed << setprecision(4);
    file << "Rate of return of the portfolio: " << R << endl;

    file << fixed << setprecision(2);
    file << "V: " << V << endl;

    file.close();
    return true;
}