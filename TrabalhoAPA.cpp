#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;
using namespace std::chrono;

const int INDICE = 25;

int FibonacciR(int indiceFib)
{ 
    if (indiceFib == 0)
        return 0;

    else if (indiceFib == 1 || indiceFib == 2)
        return 1;

    else
        return FibonacciR(indiceFib - 1) + FibonacciR(indiceFib - 2);
}

int FibonacciB(int indiceFib)
{
    int aux1 = 0, aux2 = 1, prox = 1;

    for (int i = 0; i < indiceFib - 1; ++i)
    {
        prox = aux1 + aux2;
        aux1 = aux2;
        aux2 = prox;
    }
    return prox;
}

int main()
{
    auto inicioRecursivo = std::chrono::high_resolution_clock::now();
    cout << "Fatorial recursivo: " << FibonacciR(INDICE) << endl;
    auto finalRecursivo = std::chrono::high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(finalRecursivo - inicioRecursivo);
    cout << "Tempo de execucao da forma recursiva: "
        << duration1.count() << " microsegundos" << endl << endl;


    auto inicioForcabruta = std::chrono::high_resolution_clock::now();
    cout << "Fatorial forca bruta: " << FibonacciB(INDICE) << endl;
    auto finalForcaBruta = std::chrono::high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(finalForcaBruta - inicioForcabruta);
    cout << "Tempo de execucao da forma usando forca bruta: "
        << duration.count() << " microsegundos" << endl;
}
