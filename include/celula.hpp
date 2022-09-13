///////////////////////////////// CLASSE TIPO CELULA //////////////////////////////////////
#ifndef CELULA_HPP
#define CELULA_HPP

#include "palavra.hpp"

class TipoCelula {
public:
    TipoCelula();
    void Imprime();

private:
    TipoPalavra palavra;
    TipoCelula* prox;
    TipoCelula* ant;
    friend class ListaEncadeada;
};

#endif