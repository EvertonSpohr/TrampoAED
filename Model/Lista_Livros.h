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
    int Consulta_Acervo(int Codigo);
    Lista_Acervo *Retorna_Elemento(int Codigo);
    int Insere_Acervo(Livro L);
    int Remover_Livro(int Codigo);
    void Imprime_Acervo();




#endif // LISTA_LIVROS_H_INCLUDED
