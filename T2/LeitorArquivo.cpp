// Iaçanã Ianiski Weber - 09/2023
#include <iostream>
#include "LeitorArquivo.hpp"
using namespace std;

bool LeitorArquivo::isSpecialChar(char c){
    return !std::isalpha(c);
}

LeitorArquivo::LeitorArquivo(string nome):file(nome){
    if(!file){
        throw std::runtime_error("Could not open file: " + nome);
    }
}

string LeitorArquivo::proximaPalavra(){
    std::string word = "";
    // read characters until a space is found
    for (char c; file.get(c); ) {
        if (std::isspace(c)) {
            if (!word.empty()) {
                // end of a word, return it
                return word;
            }
        } else if (!isSpecialChar(c)) {
            // not a special character, add it to the word
            word += c;
        }
    }
    // end of file or error, return what has been read
    return word;
}