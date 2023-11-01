#include "Ocorrencia.hpp"
#include <iostream>
#include <sstream>

Ocorrencia::Ocorrencia(int c, int p) : contagem(c), pag(p), next(nullptr) {}

string Ocorrencia::toString() {
    stringstream ss;
    ss << "     + Pagina: " << pag << " -> [" << contagem << " ocorrências]";
    return ss.str();
}