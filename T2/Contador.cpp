#include "Contador.hpp"
#include "Palavra.hpp"

Contador::Contador() : head(nullptr), tail(nullptr) {}

void Contador::add(int pag) {
    Ocorrencia *n = new Ocorrencia(1, pag);
    Ocorrencia *aux = nullptr;
    
    if (ProcuraNodo(pag, aux)) {
        aux->contagem++;
    } else {
        if (!head || pag < head->pag) {
            n->next = head;
            head = n;
            if (!tail) {
                tail = n;
            }
        } else {
            Ocorrencia *ptr = head;
            while (ptr->next && ptr->next->pag < pag) {
                ptr = ptr->next;
            }
            n->next = ptr->next;
            ptr->next = n;

            if (!n->next) {
                tail = n;
            }
        }
    }
}

bool Contador::ProcuraNodo(int pag, Ocorrencia *&aux) {
    for (Ocorrencia *ptr = head; ptr; ptr = ptr->next) {
        if (ptr->pag == pag) {
            aux = ptr;
            return true;
        }
    }
    return false;
}

void Contador::ImprimePaginas() {
    Ocorrencia *ptr = head;
    while (ptr != nullptr) {
        cout << ptr->pag;
        if (ptr->next) {
            cout << " | ";
        }
        ptr = ptr->next;
    }
     cout << " | ";
}

void Contador::ImprimeOcorrencias() {
    Ocorrencia *ptr = head;
    ptr = head;
    while (ptr != nullptr) {
        cout << endl << ptr->toString();
        ptr = ptr->next;
    }
    cout << endl;
}

void Contador::ImprimeOcorrenciaPag(int pag) {
    Ocorrencia *ptr = head;
    bool encontrou = false;

    while (ptr != nullptr) {
        if (ptr->pag == pag) {
            cout << ptr->toString();
            encontrou = true;
        }
        ptr = ptr->next;
    }
}