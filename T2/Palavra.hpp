#ifndef PALAVRA_HPP
#define PALAVRA_HPP
#include "Contador.hpp"

using namespace std;

#include <string>

class Palavra
{
public:
    Palavra *next;
    int quant;
    string palavra;
    Contador *indices;
    int primeiraOcorrencia;

    Palavra();
    Palavra(string palavra);

    string getPalavra();
    bool operator>(Palavra &novo)const;
    int PrimeiraOcorrencia(int total);
};

#endif