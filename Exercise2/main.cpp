#include <iostream>
#include <fstream>
#include <iomanip>

// Funzione per mappare un valore da [1,5] a [-1,2]
double map_value(double x) {
    return -1.0 + (x - 1.0) * (2.0 - (-1.0)) / (5.0 - 1.0);
}

int main() 
{
    std::ifstream inputFile("data.txt");
    std::ofstream outputFile("result.txt");

    if (inputFile.fail()) {
        std::cerr << "Errore nell'apertura del file di input" << std::endl;
        return 1;
    }

    if (outputFile.fail()) {
        std::cerr << "Errore nell'apertura del file di output" << std::endl;
        return 1;
    }

    double value, cumulativeSum = 0.0;
    int count = 0;

    // Scriviamo l'header nel file di output
    outputFile << "# N Mean" << std::endl;

    while (inputFile >> value) {
        double mapped = map_value(value); // Mappiamo il valore
        cumulativeSum += mapped;           // Somma 

        double mean = cumulativeSum / (count + 1); // Media cumulata

        // Scriviamo il risultato nel file con la precisione richiesta
        outputFile << (count + 1) << " " 
                   << std::scientific << std::setprecision(16) << mean 
                   << std::endl;

        count++;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

