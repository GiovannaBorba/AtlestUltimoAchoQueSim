#include "menu.hpp"
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

string corAleatoria() {
    int cor = rand() % 7 + 31; // Escolhe uma cor entre 31 e 37 (cores de texto)
    std::stringstream ss;
    ss << "\x1B[" << cor << "m";
    return ss.str();
}
void encerrando(){
    cout << "------------------------------" << endl;
    cout << "Encerrando..." << endl;
    system("sleep 2");
    system("clear");
}

string str(){
     stringstream ss;
     srand(static_cast<unsigned int>(std::time(nullptr)));
     string cor = corAleatoria();
     ss << "------------------------------" << "\x1B[0m" << endl;
     ss << "\x1B[4m" << "MENU DO USUARIO:" << "\x1B[0m" << endl << endl;
     ss << "\x1B[31m" << "[1. Exibir todo o indice remissivo (em ordem alfabetica)]" << "\x1B[0m" << endl; //Vermelho
     ss << "\x1B[33m" << "[2. Exibir todo o indice remissivo (em ordem decrescente)]" << "\x1B[0m" << endl; //Amarelo
     ss << "\x1B[32m" << "[3. Exibir informacoes sobre a catalogacao]" << "\x1B[0m" << endl; //Verde
     ss << "\x1B[36m" << "[4. Exibir a palavra com o maior numero de ocorrencia]" << "\x1B[0m" << endl; //Azul claro
     ss << "\x1B[34m" << "[5. Exibir as paginas de ocorrencia de uma palavra]" << "\x1B[0m" << endl; //Azul escuro
     ss << "\x1B[35m" << "[6. Exibir ocorrencia de uma palavra em uma determinada pagina]" << "\x1B[0m" << endl; //Roxo
     ss << "\x1B[31m" << "[7. Encerrar o programa]" << "\x1B[0m" << endl;
     ss << endl;
     ss << "\x1B[4m" << "Digite o número da função que deseja executar:" << "\x1B[0m" << " ";
     return ss.str();
}

int saida(){
    int menu; 
    cout << endl << "[0. Retornar ao menu]" << endl << "[7. Encerrar o programa]" << endl << endl;
    cout << "Digite o número da função que deseja executar: ";
    cin >> menu;
    //cout << endl;
    return menu;
}

int FuncaoTres(){
    int tres; 
    cout << endl << "[0. Retornar ao menu]" << endl;
    cout << "[7. Encerrar o programa]" << endl;
    cout << "Digite o número da função que deseja executar: ";
    cin >> tres;
    cout << endl;
    return tres;
}
