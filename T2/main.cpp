// Iaçanã Ianiski Weber - 09/2023
#include <iostream>
#include <cstdlib>
#include <string>
#include "LeitorArquivo.hpp"
#include "menu.hpp"
#include "Palavra.hpp"
#include "ListaOrdenadaDePalavras.hpp"
#include "Ocorrencia.hpp"
#include "Contador.hpp"

using namespace std;

int main() {

    cout << "Digite o nome do arquivo (por exemplo, 'Livros/alice.txt'): ";
    string nomeArquivo;
    cin >> nomeArquivo;


    LeitorArquivo a = LeitorArquivo(nomeArquivo);
    ListaOrdenadaDePalavras teste;


    cout << "Carregando, aguarde..." << endl;

    int count = 0;
    int countPalavras = 0;
    int i = 0;
    int total = 0;
    int StopWordsTotal = 0;

    while(1){
        string b = a.proximaPalavra();
        total = teste.pagina(total, b); 
        if(!b.empty()) b = teste.lowercase(b);
        if(teste.StopWords(b)){
            int pag = total/2500 + 1;
            teste.add(b, pag);
            countPalavras++;
        } else {
            StopWordsTotal = teste.CountStopwords(StopWordsTotal);
        }

        count++;

        if(b.empty()){
            break;   
        }
        //i++;
    }

    cout << "Counter: " << count << endl;
    //cout << "StopWords: " << StopWordsTotal << endl;
    //cout << "Palavras: " << countPalavras << endl;
    //cout << "Caracteres: " << total << endl;

    //teste.ImprimeLista(0);
    //teste.exibirIndiceRemissivo();

    ////[Menu Do Usuario]///

    int menu = 0;
    int flag = 0;
    string palavraProcurada;
    int pag;

    while(flag != 1){
    cout << str();
    cin >> menu; 
    if(menu != 7){cout << "------------------------------" << endl;}


    switch (menu){
    ////////////////////////////////////////////////
    case 1:
        cout << "\x1B[31m" << "1. Indice remissimo em ordem alfabética:" << "\x1B[0m" << endl; 
            teste.ImprimeLista();
            cout << "------------------------------" << endl;

        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Volte sempre!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 2:
        cout << "\x1B[33m" << "2. Indice remissimo em ordem decrescente:" << "\x1B[0m" << endl; 
            teste.exibirIndiceRemissivo();
            cout << "------------------------------" << endl;

        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Até mais!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 3:
        int tres;
            cout << "\x1B[32m" << "3. Informações sobre a catalogação:" << "\x1B[0m" << endl << endl; 

            cout << "   + 3.1 Percentual de palavras catalogadas" << endl << "        ";
                    teste.Percentual(count, countPalavras, StopWordsTotal);
                    cout << endl;

            cout << "   + 3.2 Numero de palavras diferentes registradas no indice remissivo" << endl << "        ";
                    cout << "=> Total de Palavras: " << teste.size() << endl;
                    cout << endl;

            cout << "   + 3.3 Retornar Numero total de palavras registradas no indice remissivo" << endl << "        ";
                    teste.TotalCatalogadas(countPalavras);
                    cout << endl;

            cout << "   + 3.4 Retornar Numero total de stopwords descartados" << endl << "        ";
                    teste.TotalStopWords(StopWordsTotal);
                    cout << endl;
        cout << "------------------------------" << endl;
        
        tres = FuncaoTres();
        
        if(tres == 7){
            flag = 1;
            encerrando();
            cout << "Adios!" << endl;
        } 

        break;

    ////////////////////////////////////////////////
    case 4:
        cout << "\x1B[36m" << "4. Exibir a palavra com o maior numero de ocorrencia" << "\x1B[0m" << endl << endl; 
            teste.PalavraComMaiorOcorrencia();

        cout << endl << "------------------------------" << endl;

        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Tchau-Tchau!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 5:
        cout << "\x1B[34m" << "5. Exibir as paginas de ocorrencia de uma palavra" << "\x1B[0m" << endl; 
                    cout << "Palavra: ";
                    cin >> palavraProcurada; 
                    teste.buscaPalavra(palavraProcurada);
                    cout << endl << "------------------------------" << endl;

        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Até a próxima!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 6:
        cout << "\x1B[35m" << "6. Exibir ocorrencia de uma palavra em uma determinada pagina" << "\x1B[0m" << endl; 
                    cout << "Palavra: ";
                    cin >> palavraProcurada; 
                    cout << "Pagina: ";
                    cin >> pag;
                    teste.PesquisaPagina(palavraProcurada, pag);
                    
                    cout << endl;
        cout << "------------------------------" << endl;
    
        if(saida() == 7){
            flag = 1;
            encerrando();
            cout << "Arrivederci!" << endl;
            } 

        break;

    ////////////////////////////////////////////////
    case 7:
        flag = 1;
        encerrando();
        cout << "Até logo!" << endl;
        break;

    ////////////////////////////////////////////////
    default:
        break;
        }
    }

}