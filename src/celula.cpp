#include "celula.hpp"

TipoCelula::TipoCelula()
// Descricao: cria uma celula
// Entrada: nenhuma
// Saida: celula
{
    prox = NULL;
    ant = NULL;
};

void TipoCelula::Imprime()
// Descricao: imprime a palavra e sua quantidade que reside na celula
// Entrada: nehuma
// Saida: impressao na saida padrao (stdout)
{
    palavra.Imprime();
}
