#include "Palavra.hpp"
#include "Ocorrencia.hpp"
#include <iostream>

using namespace std;

Palavra::Palavra() : next(nullptr), palavra(""), indices(new Contador()), quant(1), primeiraOcorrencia(0) {}

Palavra::Palavra(string palavra) : next(nullptr), palavra(palavra), indices(new Contador()), quant(1) {}

bool Palavra::operator>(Palavra &novo) const {
    if (this->quant == novo.quant) {
        return (this->palavra > novo.palavra);
    }
    return (this->quant > novo.quant);
}

string Palavra::getPalavra() {
    return palavra;
}

int Palavra::PrimeiraOcorrencia(int total) {
    int pag = total / 2500 + 1;
    this->primeiraOcorrencia = pag;
    this->indices->add(pag);
    return primeiraOcorrencia;
}