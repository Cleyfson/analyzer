#include "palavra.hpp"
#include <algorithm>

// variavel auxiliar que reside no main, usada para auxiliar na categorização dos valores das strings
extern char dicionario[26];

TipoPalavra::TipoPalavra(/* args */)
// Descricao: cria uma palavra
// Entrada: nenhuma
// Saida: palavra com chave '-' e quantidade 0
{
    this->chave = '-';
    this->quant = 0;
};

TipoPalavra::TipoPalavra(std::string _word, int _quant)
// Descricao: cria uma palavra
// Entrada: _word, _quant
// Saida: palavra com chave = _word, quantidade = _quant
{
    this->chave = _word;
    this->quant = _quant;
};

std::string TipoPalavra::getPalavra()
// Descricao: retorna o elemento chave do TipoPalavra
// Entrada: nenhuma
// Saida: chave
{
    return chave;
};

void TipoPalavra::setQuant()
// Descricao: aumento em uma unidade a quantidade da palavra designada
// Entrada: nenhuma
// Saida: quantidade + 1
{
    quant++;
};

int TipoPalavra::getQuant()
// Descricao: retorna o elemento quantidade do TipoPalavra
// Entrada: nenhuma
// Saida: quantidade
{
    return quant;
};

void TipoPalavra::removerSimbolos()
// Descricao: percorre a string do elemento chave do TipoPalavra removendo simbolos da string
// Entrada: nenhuma
// Saida: string sem os simbolos designados
{
    // Simbolos designados para retirada
    std::string chars = ",.!?:;_";

    for (char c : chars) {
        chave.erase(std::remove(chave.begin(), chave.end(), c), chave.end());
    }
};

void TipoPalavra::letraMinuscula()
// Descricao: percorre a string do elemento chave do TipoPalavra transformando seu caracteres para forma minuscula
// Entrada: nenhuma
// Saida: string no formato minusculo
{
    std::for_each(chave.begin(), chave.end(), [](char& c) {
        c = ::tolower(c);
    });
};

void TipoPalavra::tratarPalavra()
// Descricao: trata da remoção e formatação da string chave do TipoPalavra
// Entrada: nenhuma
// Saida: string completamente formatada
{
    this->letraMinuscula();
    this->removerSimbolos();
};

void TipoPalavra::Imprime()
// Descricao: imprime a palavra e sua quantidade
// Entrada: nehuma
// Saida: impressao na saida padrao (stdout)
{
    std::cout << chave << " " << quant << std::endl;
};

int TipoPalavra::letraValor(char letra)
// Descricao: percorre o vetor dicionario e retorna em qual posicao o char se encontra nesse vetor
// Entrada: letra
// Saida: posicao da letra dado o vetor dicionario, ou seu valor na tabela ASCII
{
    for (int i = 0; i < 26; i++) {
        if (letra == ::tolower(dicionario[i])) {
            return i + 97;
        }
    }

    return int(letra);
};

int TipoPalavra::menorTam(TipoPalavra b)
// Descricao: compara e discerne entre 2 TipoPalavra, qual tem maior tamanho
// Entrada: b
// Saida: retorna o tamanho da menor string entre da comparação entre duas
{
    if (this->chave.size() > b.chave.size()) {
        return b.chave.size();
    }
    return this->chave.size();
};

bool TipoPalavra::palavraMaior(TipoPalavra b)
// Descricao: compara e discerne entre 2 TipoPalavra, qual tem maior maior valor, dado uma ordem lexografica especifica
// Entrada: b
// Saida: retorna verdadeira se o TipoPalavra chamando a função for maior que o TipoPalavra b
{
    for (int i = 0; i < menorTam(b); i++) {
        if (letraValor(this->chave[i]) < letraValor(b.chave[i]))
            return true;
        else if (letraValor(this->chave[i]) > letraValor(b.chave[i]))
            return false;
    }
    return (this->chave.size() < b.chave.size());
};