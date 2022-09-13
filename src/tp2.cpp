#include "msgassert.hpp"
#include <fstream>
#include <getopt.h>
#include <iostream>
#include <lista.hpp>
#include <string.h>

// variaveis globais
char dicionario[26];
char lognome[100];
char arqnome[100];
char saidanome[100];
int regmem;

// varias usadas no arquivo lista.cpp como varias externas
int mediana;
int particao;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
    fprintf(stderr, "tp2\n");
    fprintf(stderr, "\t-i ou -I <arq>\t(arquivo de entrada(input))\n");
    fprintf(stderr, "\t-o ou -O <arq>\t(arquivo de saida(output))\n");
    fprintf(stderr, "\t-m ou -M \t(tamanho da particao usada na otimização da mediana)\n");
    fprintf(stderr, "\t-s ou -S \t(tamanho da particao usada na otimização da selecao)\n");
    fprintf(stderr, "\t-p <arq>\t(arquivo de registro de acesso)\n");
    fprintf(stderr, "\t-l \t(registrar acessos a memoria)\n");
}

void parse_args(int argc, char** argv)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc e argv
// Saida: optescolhida, regmem, lognome, m1nome, m2nome, m3nome
{
    // variaveis externas do getopt
    extern char* optarg;

    // variavel auxiliar
    int c;

    // inicializacao variaveis globais para opcoes
    regmem = 0;
    mediana = 1;
    particao = 0;
    lognome[0] = 0;
    arqnome[0] = 0;
    saidanome[0] = 0;

    // getopt - letra indica a opcao, : junto a letra indica parametro
    // no caso de escolher mais de uma operacao, vale a ultima
    while ((c = getopt(argc, argv, "i:I:m:M:s:S:o:O:p:l")) != EOF) {
        if (c == 'i' || c == 'I') {
            strcpy(arqnome, optarg);
        } else if (c == 'm' || c == 'M') {
            mediana = std::stoi(optarg);
        } else if (c == 's' || c == 'S') {
            particao = std::stoi(optarg);
        } else if (c == 'o' || c == 'O') {
            strcpy(saidanome, optarg);
        } else if (c == 'p') {
            strcpy(lognome, optarg);
        } else if (c == 'l') {
            regmem = 1;
        } else {
            uso();
            exit(1);
        }
    }
    // verificacao da consistencia das opcoes
    avisoAssert(strlen(saidanome) > 0, "tp2 - nome de arquivo de saida não foi definido");
    erroAssert(strlen(arqnome) > 0, "tp2 - nome de arquivo de entrada precisa ser definido");
    erroAssert(mediana >= 1, "tp2 - valor da flag mediana/-m|-M precisa ser maior que 1");
    erroAssert(particao >= 0, "tp2 - valor da flag particao/-s|-M nao pode ser negativa");
}

int main(int argc, char** argv)
// Descricao: programa principal para execucao de operacoes de leitura e ordenacao
// Entrada: argc e argv
// Saida: arquivo texto com palavras e suas quantidades, ordenadas de acordo com a ordem lexografica apresentada
{
    // variaveis usadas no processo de leitura do arquivo de entrada
    bool read = false;
    ListaEncadeada Lista;

    // avaliar linha de comando
    parse_args(argc, argv);

    // inicia processo de leitura do arquivo de entrada
    std::ifstream entrada;
    std::string palavra;
    entrada.open(arqnome);
    erroAssert(entrada, "tp2 - erro na abertura do arquivo de entrada");

    // processado o arquvo texto de entrada palavra por palavra
    while (entrada >> palavra) {

        // dependendo da palavra lida "#TEXTO" ou "#ORDEM" o vetor com a ordem lexografica será lido
        // ou as palavras de texto serão lidas
        if (palavra == "#TEXTO") {
            entrada >> palavra;
            read = true;
        } else if (palavra == "#ORDEM") {
            for (int i = 0; i < 26; i++)
                entrada >> dicionario[i];
            read = false;
        }

        // Cria tipo palavra baseada na palavra lido do arquivo
        TipoPalavra nova(palavra);

        // a palavra criada recebe tratatamento (removacao de sinais e simbolos e adequação para formato minusculo)
        nova.tratarPalavra();

        // se o estado de leitura estiver ativo a palavra será inserida na lista de palavras
        if (read)
            Lista.InsereInicio(nova);
    }

    // lista de palavras e ordenada usando quicksort
    Lista.quickSort();

    // dados da lista são registrados no arquivo de texto de saida indicado
    Lista.SalvarArq(saidanome);

    // arquivo fechado
    entrada.close();
    return 0;
}
