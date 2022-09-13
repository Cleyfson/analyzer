#include "lista.hpp"
#include <fstream>

// variaveis auxiliares que residem no main, usadas para auxiliar na otimizações aplicadas no quicksort
extern int mediana;
extern int particao;

ListaEncadeada::ListaEncadeada()
    // Descricao: cria uma lista
    // Entrada: nenhuma
    // Saida: Lista com um TipoCelula primeiro e ultimo
    : Lista()
{
    primeiro = new TipoCelula();
    ultimo = primeiro;
};

ListaEncadeada::~ListaEncadeada()
// Descricao: Destrutor da Lista
// Entrada: nenhuma
// Saida: Lista limpa e memora desalocada
{
    Limpa();
    delete primeiro;
};

void ListaEncadeada::InsereInicio(TipoPalavra _palavra)
// Descricao: Insere um TipoCelula na Lista
// Entrada: _palavra
// Saida: nenhuma
{
    if (!PesquisaPalavra(_palavra.getPalavra())) {
        TipoCelula* nova = new TipoCelula();
        nova->palavra = _palavra;

        if (primeiro->prox == NULL) {
            nova->prox = primeiro->prox;
            nova->ant = primeiro;
            primeiro->prox = nova;
            tamanho++;
        } else {
            nova->prox = primeiro->prox;
            primeiro->prox->ant = nova;
            primeiro->prox = nova;
            nova->ant = primeiro;
            tamanho++;
        }

        if (nova->prox == NULL)
            ultimo = nova;
    }
};

bool ListaEncadeada::PesquisaPalavra(std::string palavra)
// Descricao: percorre a lista de palavra e se retorna se a palvra em questão ja esta na lista
// Entrada: palavra
// Saida: true or false
{
    TipoCelula* p = primeiro->prox;
    while (p != NULL) {
        if (p->palavra.getPalavra() == palavra) {
            p->palavra.setQuant();
            return true;
        }
        p = p->prox;
    }

    return false;
};

void ListaEncadeada::Imprime()
// Descricao: percorre a lista imprimindo o conteúdo de cada uma das celulas
// Entrada: nenhuma
// Saida: impressao na saida padrao (stdout)
{
    TipoCelula* p;
    p = primeiro->prox;
    while (p != NULL) {
        p->palavra.Imprime();
        p = p->prox;
    }
    printf("#FIM\n");
};

int ListaEncadeada::getSize(TipoCelula* l, TipoCelula* h)
// Descricao: percorre a lista no intervelado entre o TipoCelula l e h com objetivo de sabr o tamanho da particao
// Entrada: *l e *h
// Saida: tamanho
{
    int tamanho = 1;
    while (l != h) {
        l = l->prox;
        tamanho++;
    }
    return tamanho;
};

void ListaEncadeada::Limpa()
// Descricao: percorre a lista desalocando a memoria de cada uma das celulas
// Entrada: nenhuma
// Saida: nenhuma
{
    TipoCelula* p;
    p = primeiro->prox;
    while (p != NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
};

void ListaEncadeada::SalvarArq(std::string saidanome)
// Descricao: percorre a lista salvando no arquivo de texto saida o conteudo de cada uma das celulas
// Entrada: saidanome
// Saida: arquivo texto prenchido com dados da lista
{
    std::ofstream saida;
    saida.open(saidanome);

    TipoCelula* p = primeiro->prox;
    while (p != NULL) {
        saida << p->palavra.getPalavra() << " " << p->palavra.getQuant() << std::endl;
        p = p->prox;
    }
    saida << "#FIM\n";
    saida.close();
};

TipoCelula* ListaEncadeada::acharUltimo(TipoCelula* h)
// Descricao: percorre a lista a partir da celula h até uma particao de tamanho definido pela variavel mediana
// Entrada: *h
// Saida: p
{
    TipoCelula* p = h;
    for (int i = 1; i < mediana; i++) {
        p = p->ant;
    }
    return p;
}

TipoCelula* ListaEncadeada::acharPivo(TipoCelula* l)
// Descricao: percorre a lista a partir da celula h até uma particao de tamanho definido pela variavel mediana/2, usada na otimização do quicksort
// Entrada: *l
// Saida: p
{
    TipoCelula* h = acharUltimo(l);
    quickSort(h, l);
    TipoCelula* p = l;
    for (int i = 0; i < mediana / 2; i++) {
        p = p->ant;
    }
    return p;
};

void swap(TipoPalavra* a, TipoPalavra* b)
// Descricao: Troca o conteudo entre dois TiposPalavras
// Entrada: *a, *b
// Saida: nenhuma
{
    TipoPalavra t = *a;
    *a = *b;
    *b = t;
};

TipoCelula* ListaEncadeada::partition(TipoCelula* l, TipoCelula* h)
// Descricao: função auxiliar do quicksort
// Entrada: *l, *h
// Saida: i
{
    TipoCelula* x;
    if (getSize(l, h) > mediana) {
        x = acharPivo(h);
    } else
        x = h;

    TipoCelula* i = l->ant;

    for (TipoCelula* j = l; j != x; j = j->prox) {
        if (j->palavra.palavraMaior(x->palavra)) {
            i = (i == NULL) ? l : i->prox;
            swap(&(i->palavra), &(j->palavra));
        }
    }
    i = (i == NULL) ? l : i->prox;
    swap(&(i->palavra), &(x->palavra));
    return i;
};

void ListaEncadeada::_quickSort(TipoCelula* l, TipoCelula* h)
// Descricao: chamada recursiva do quicksort
// Entrada: *l, *h
// Saida: nenhuma
{
    if (h != NULL && l != h && l != h->prox) {
        if (particao > 2) {
            if (getSize(l, h) <= particao) {
                Selecao(l, h);
            } else {
                TipoCelula* p = partition(l, h);
                _quickSort(l, p->ant);
                _quickSort(p->prox, h);
            }
        } else {
            TipoCelula* p = partition(l, h);
            _quickSort(l, p->ant);
            _quickSort(p->prox, h);
        }
    }
};

void ListaEncadeada::quickSort()
// Descricao: quicksort
// Entrada: nenhuma
// Saida: lista ordenanda
{
    TipoCelula* h = ultimo;
    _quickSort(primeiro->prox, h);
};

void ListaEncadeada::quickSort(TipoCelula* prim, TipoCelula* ult)
{
    // Descricao: chamada auxiliar do quicksort, usada pela função acharPivo usada na otimização do quicksort
    // Entrada: *prim, *ult
    // Saida: particao da lista ordenada
    _quickSort(prim, ult);
};

void ListaEncadeada::Selecao(TipoCelula* prim, TipoCelula* ult)
// Descricao: algoritmo de ordenação por selecao, usado na otimização do quicksort
// Entrada: *prim, *ult
// Saida: particação da lista ordenada
{
    TipoCelula* aux = ult;
    while (aux != prim) {
        TipoCelula* menor = prim;
        TipoCelula* i = prim;
        while (1) {
            if (!(i->palavra.palavraMaior(menor->palavra)))
                menor = i;
            if (i == aux)
                break;
            i = i->prox;
        }
        swap(&(menor->palavra), &(aux->palavra));
        aux = aux->ant;
    }
};