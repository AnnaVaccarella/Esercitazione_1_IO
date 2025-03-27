#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Funzione per mappare un valore da [1,5] a [-1,2]
double mapValue(double x) {
    return -1 + (x - 1) * (2 - (-1)) / (5 - 1);
}

int main() {   
    ifstream inputFile("data.txt");
    ofstream outputFile("result.txt");
    
    if (!inputFile.is_open()) {
        cout << "Errore nell'apertura del file" << endl;
        return 1;
    }
    
    vector<double> values;
    double val;
    
    // Per leggere i valori dal file
    while (inputFile >> val) {
        values.push_back(val);
    }
    // Chiudo il file di input
    inputFile.close();

    // Vettore per memorizzare i valori mappati
    vector<double> mappedValues;
    double sum = 0.0;
    
    // Scrivi l'intestazione nel file di output
    outputFile << "# i Mean" << endl;
    
    // Mappa i valori e calcola la media cumulativa
    for (int i = 0; i < values.size(); ++i) {
        double mappedVal = mapValue(values[i]);  // Passa il valore corretto
        mappedValues.push_back(mappedVal);

        // Calcola la somma cumulativa dei primi i+1 valori
        sum += mappedVal;
        double mean = sum / (i + 1);

        // Scrivi l'indice e la media nel file di output
        outputFile << i + 1 << " " << mean << endl;
    }
    
    // Chiudi il file di output
    outputFile.close();
    return 0;
}
