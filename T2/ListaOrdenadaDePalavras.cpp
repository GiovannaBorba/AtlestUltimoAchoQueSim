#include <iostream>
#include <sstream>
using namespace std;

#include "ListaOrdenadaDePalavras.hpp"
#include "Palavra.hpp"
#include "LeitorArquivo.hpp"
#include "Ocorrencia.hpp"
#include "Contador.hpp"

ListaOrdenadaDePalavras::ListaOrdenadaDePalavras() : head(nullptr), tail(nullptr), middle(nullptr), count(0), flag(false) {
}

ListaOrdenadaDePalavras::~ListaOrdenadaDePalavras() {
    Palavra* atual = head;
    while (atual) {
        Palavra* next = atual->next;
        delete atual;
        atual = next;
    }
}

void ListaOrdenadaDePalavras::ImprimeLista() {
    Palavra* atual = head;
    while (atual) {
        cout << "   + " << atual->palavra << " --- | "; //<< atual->primeiraOcorrencia << " || ";
        atual->indices->ImprimePaginas();
        cout << endl;
        atual = atual->next;
    }
}

int ListaOrdenadaDePalavras::size() {
    return count;
}

void ListaOrdenadaDePalavras::add(string palavra, int pag) {
    Palavra* n = new Palavra(palavra);
    Palavra* aux = nullptr;

    if (ProcuraNodo(palavra, aux)) {
        aux->indices->add(pag);
        aux->quant++;
    } else {
        if (!head || palavra < head->palavra) {
            n->next = head;
            head = n;

            if (!tail) {
                tail = head;
            }

            count++;
            n->primeiraOcorrencia = n->PrimeiraOcorrencia(pag);
        } else {
            Palavra* ptr = head;
            while (ptr->next && ptr->next->palavra < palavra) {
                ptr = ptr->next;
            }

            n->next = ptr->next;
            ptr->next = n;

            if (!n->next) {
                tail = n;
            }
            count++;
            n->primeiraOcorrencia = n->PrimeiraOcorrencia(pag);
        }
        n->indices->add(pag);
    }
}

bool ListaOrdenadaDePalavras::ProcuraNodo(string palavra, Palavra*& aux) {
    for (Palavra* ptr = head; ptr != nullptr; ptr = ptr->next){
        if (ptr->palavra == palavra) {
            aux = ptr;
            return true;
        }
    }
    return false;
}

string ListaOrdenadaDePalavras::lowercase(string palavra) {
    for (char& c : palavra) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }
    return palavra;
}

int ListaOrdenadaDePalavras::pagina(int total, string palavra) {
    int caracter = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        caracter++;
    }
    total += caracter;
    return total;
}

bool ListaOrdenadaDePalavras::StopWords(string palavra) {
    for (char& c : palavra) {
        if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
        }
    }
    LeitorArquivo stop = LeitorArquivo("StopWords/stopwords-en.txt");
    while (1) {
        string a = stop.proximaPalavra();
        for (char& c : a) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a'; // Converte caracteres maiúsculos para minúsculos
            }
        }
        if (palavra == a) {
            return false;
        }
        count++;
        if (a.empty()) {
            return true;
        }
    }
}

int ListaOrdenadaDePalavras::CountStopwords(int StopWordsTotal) {
    StopWordsTotal++;
    return StopWordsTotal;
}

void ListaOrdenadaDePalavras::Percentual(int countTotal, int countPalavras, int StopWordsTotal) {
    cout << "=> Total de palavras no livro: " << countTotal << endl << "        ";
    
    double percentualP = static_cast<double>(countPalavras) / countTotal * 100.0;
    double percentualS = static_cast<double>(StopWordsTotal) / countTotal * 100.0;

    cout << "%" << percentualP << " PALAVRAS CATALOGADAS " << endl << "        ";
    cout << "%" << percentualS << " STOPWORDS DESCARTADAS " << endl;
}

void ListaOrdenadaDePalavras::PesquisaPagina(const string& palavra, int pag) {
    Palavra* atual = head;
    bool encontrou = false;

    while (atual) {
        if (atual->getPalavra() == palavra) {
            int primeiraOcorrencia = atual->primeiraOcorrencia;
            if (pag >= primeiraOcorrencia) {
                int ocorrencia = pag - primeiraOcorrencia + 1;
                atual->indices->ImprimeOcorrenciaPag(ocorrencia);
                encontrou = true;
                break;
            }
        }
        atual = atual->next;
    }
}

void ListaOrdenadaDePalavras::TotalStopWords(int StopWordsTotal) {
    cout << "=> Total de StopWords descartadas: " << StopWordsTotal << endl;
}

void ListaOrdenadaDePalavras::TotalCatalogadas(int countPalavras) {
    cout << "=> Total de Palavras catalogadas: " << countPalavras << endl;
}

Palavra* ListaOrdenadaDePalavras::buscaPalavra(const string& palavra) {
    Palavra* atual = head;

    while (atual) {
        if (atual->getPalavra() == palavra) {
            atual->indices->ImprimePaginas();
            return atual;
        }
        atual = atual->next;
    }

    return nullptr;
}

void ListaOrdenadaDePalavras::PalavraComMaiorOcorrencia() {
    Palavra* atual = head;
    int maxOcorrencias = 0;

    while (atual) {
        if (atual->quant > maxOcorrencias) {
            maxOcorrencias = atual->quant;
        }
        atual = atual->next;
    }

    atual = head;

    while (atual) {
        if (atual->quant == maxOcorrencias) {
            cout << "     + " << atual->getPalavra() << " [" << maxOcorrencias << " ocorrências]" << endl;
        }
        atual = atual->next;
    }
}

void ListaOrdenadaDePalavras::exibirIndiceRemissivo() {
    Palavra* atual = head;
    int maxOcorrencias = 0;

    while (atual) {
        if (atual->quant > maxOcorrencias) {
            maxOcorrencias = atual->quant;
        }
        atual = atual->next;
    }

    // Exiba as palavras com o número máximo de ocorrências em ordem alfabética
    for (int ocorrencias = maxOcorrencias; ocorrencias >= 0; ocorrencias--) {
        atual = head;

        while (atual) {
            if (atual->quant == ocorrencias) {
                cout << "     + " << atual->getPalavra() << " --- [" << ocorrencias << " ocorrências]" << endl;
            }
            atual = atual->next;
        }
    }
}