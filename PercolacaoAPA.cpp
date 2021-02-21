#include <iostream>
#include <time.h>
#include <vector>
#include "Caminho.h"

const int TAMANHO = 20;

using namespace std;

bool CaminhoAux(double matrizOriginal[TAMANHO][TAMANHO], double matrizAux[TAMANHO][TAMANHO], int i, int j, int size)
{
	//Vefirica se o elemento está na matriz e se já foi verificado
	if (i < 0 || j < 0 || i >= size || j >= size || matrizAux[i][j] >= 0)
		return false;

	//Seta a verificação do elemento
	matrizAux[i][j] = 0;

	//Se o elemento for 0, já indica que não pode ser do caminho e retorna falso
	if (matrizOriginal[i][j] == 0)
		return false;

	//Parte recursiva que verifica se o caminho chegou à ultima coluna, indicando que o caminho existe ou verifica os vizinhos do elemento analisado
	if (j == size - 1 ||
		CaminhoAux(matrizOriginal, matrizAux, i + 1, j, TAMANHO) ||
		CaminhoAux(matrizOriginal, matrizAux, i - 1, j, TAMANHO) ||
		CaminhoAux(matrizOriginal, matrizAux, i, j + 1, TAMANHO) ||
		CaminhoAux(matrizOriginal, matrizAux, i, j - 1, TAMANHO)
		) matrizAux[i][j] = 1;

	//retorna verdadeiro para caso o último elemento do caminho seja de fato 1
	return matrizAux[i][j] == 1;
}

bool CaminhoExiste(double matrizOriginal[TAMANHO][TAMANHO], double matrizAux[TAMANHO][TAMANHO])
{
	for (int i = 0; i < TAMANHO; i++)
		if (CaminhoAux(matrizOriginal, matrizAux, i, 0, TAMANHO))
			return true;

	return false;
}

int main()
{
	srand(time(NULL));

	//Definição da matriz inicial, aleatória com números 0 ou 1
	double matrizOriginal[TAMANHO][TAMANHO];

	for (int i = 0; i < TAMANHO; i++)
	{
		for (int j = 0; j < TAMANHO; j++)
		{
			double numEntreZeroEUm = ((double)rand() / (RAND_MAX));

			if (numEntreZeroEUm <= 0.59274621)
				matrizOriginal[i][j] = 1;
			else
				matrizOriginal[i][j] = 0;
		}
	}

	//Definição da matriz auxiliar
	double matrizAux[TAMANHO][TAMANHO];
	for (int i = 0; i < TAMANHO; i++)
		for (int j = 0; j < TAMANHO; j++)
			matrizAux[i][j] = -1;

	bool result1 = CaminhoExiste(matrizOriginal, matrizAux);

	if (result1)
		cout << "Sim" << endl;
	else
		cout << "Nao" << endl;
}