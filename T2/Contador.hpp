#ifndef Contador_
#define Contador_
#include "Ocorrencia.hpp"
#include <iostream>

using namespace std;

class Contador
{
private:
    Ocorrencia *head;
    Ocorrencia *tail;

public:
    Contador();
    void add(int pag);
    bool ProcuraNodo(int pag, Ocorrencia *&aux);
    void print(int cond);
    void ImprimePaginas();
    void ImprimeOcorrencias();
    void ImprimeOcorrenciaPag(int pag);
};

#endif