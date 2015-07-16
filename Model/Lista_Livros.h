#ifndef LISTA_LIVROS_H_INCLUDED
#define LISTA_LIVROS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

    typedef struct Livro
    {
        int Codigo;
        char Titulo[255];
        char Autores[255];
        char Ano[25];
        int Num_Exemp;
        char Area[255];

    }Livro;

    typedef struct Lista_Acervo
    {
        Livro livro;
        struct Lista_Acervo *Prox;
        struct Lista_Acervo *Ant;

    }Lista_Acervo;

    Lista_Acervo *Acervo;

    void Iniciliza_Acervo();
    int Consulta_Acervo(char titulo[]);
    int Insere_Acervo(Livro L);
    int Remover_Livro(char titulo[]);
    void Imprime_Acervo();
    Lista_Acervo *Busca_Livro_Titulo(char titulo[]);
    void Salva_Livros();
    void Carrega_Livros();



#endif // LISTA_LIVROS_H_INCLUDED
