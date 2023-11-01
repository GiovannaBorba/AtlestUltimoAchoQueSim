#ifndef LISTA_ORDENADA_DE_PALAVRAS_HPP
#define LISTA_ORDENADA_DE_PALAVRAS_HPP

#include "Palavra.hpp"
using namespace std;

class ListaOrdenadaDePalavras {
private:
    Palavra* primeiro;
    string palavra;
    bool flag;
    Palavra *head;
    Palavra *tail;
    Palavra *middle;
    Palavra **vet;
    int count;
public:
    ListaOrdenadaDePalavras();
    ~ListaOrdenadaDePalavras();

    bool ProcuraNodo(string palavra, Palavra *&aux);
    void add(string palavra, int pag);
    void ImprimeLista();
    int size();
    string lowercase(string palavra);
    int get(int index);
    int pagina(int total, string palavra);
    int CountStopwords(int StopWordsTotal);
    bool StopWords(string palavra);
    void Percentual(int countTotal, int countPalavras, int StopWordsTotal);
    void PesquisaPagina(const string& palavra, int pag);
    void exibirLista() const;
    void TotalCatalogadas(int countPalavras);
    void TotalStopWords(int StopWordsTotal);
    Palavra* buscaPalavra(const string& palavra);
    void PalavraComMaiorOcorrencia();
    void exibirIndiceRemissivo();


};

#endif 