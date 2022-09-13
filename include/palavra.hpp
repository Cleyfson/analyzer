///////////////////////////////// CLASSE TIPO PALAVRA //////////////////////////////////////

#ifndef PALAVRA_HPP
#define PALAVRA_HPP

#include <iostream>

class TipoPalavra {
private:
    std::string chave;
    int quant;

public:
    TipoPalavra(/* args */);
    TipoPalavra(std::string _word, int _quant = 1);
    void removerSimbolos();
    void letraMinuscula();
    void tratarPalavra();
    int letraValor(char letra);
    int menorTam(TipoPalavra b);
    bool palavraMaior(TipoPalavra b);
    std::string getPalavra();
    void setQuant();
    int getQuant();
    void Imprime();
};

#endif