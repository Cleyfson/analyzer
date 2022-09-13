

///////////////////////////////// PROTOTIPO DE LISTA //////////////////////////////////////
#ifndef LISTA_HPP
#define LISTA_HPP

#include "celula.hpp"

class Lista {
public:
    Lista() { tamanho = 0; };
    int GetTamanho() { return tamanho; };
    bool Vazia() { return tamanho == 0; };
    virtual void InsereInicio(TipoPalavra item) = 0;
    virtual void Imprime() = 0;
    virtual void Limpa() = 0;

protected:
    int tamanho;
};

///////////////////////////////// LISTA //////////////////////////////////////

class ListaEncadeada : public Lista {
public:
    ListaEncadeada();
    ~ListaEncadeada();
    void InsereInicio(TipoPalavra _palavra);
    bool PesquisaPalavra(std::string _palavra);
    void Imprime();
    int getSize(TipoCelula* l, TipoCelula* h);
    void Limpa();
    TipoCelula* partition(TipoCelula* l, TipoCelula* h);
    void _quickSort(TipoCelula* l, TipoCelula* h);
    void quickSort();
    void quickSort(TipoCelula* prim, TipoCelula* ult);
    void SalvarArq(std::string saidanome);
    TipoCelula* acharPivo(TipoCelula* l);
    TipoCelula* acharUltimo(TipoCelula* h);
    void Selecao(TipoCelula* prim, TipoCelula* ult);

private:
    TipoCelula* primeiro;
    TipoCelula* ultimo;
};

#endif