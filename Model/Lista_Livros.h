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

    Lista_Acervo *Acervo; ///LISTA ENCADEADO CONTENDO OS LIVROS

    /**
    M�todo para inicializar a lista de livros

    Pr�-Cond: Lista de livros
    P�s-Cond: Lista de livros apontando para null
    */
    void Iniciliza_Acervo();

    /**
    M�todo para Consultar se o livro esta contido na lista

    Pr�-Cond: Titulo do livro
    P�s-Cond: Retorna o true caso encontrado, senao retorna false
    */
    int Consulta_Acervo(char titulo[]);

    /**
    M�todo para inserir um livro novo na lista

    Pr�-Cond: Novo Livro
    P�s-Cond: Lista de livros com o novo livro inserido
    */
    int Insere_Acervo(Livro L);

    /**
    M�todo para remover um livro da lista

    Pr�-Cond: Titulo do livro para remover
    P�s-Cond: Lista de livros sem o livro
    */
    int Remover_Livro(char titulo[]);

    /**
    M�todo buscar o livro pelo titulo

    Pr�-Cond: titulo do livro
    P�s-Cond: N� contendo o livro
    */
    Lista_Acervo *Busca_Livro_Titulo(char titulo[]);

    /**
    M�todo para salvar o acervo em um arquivo .csv

    Pr�-Cond: Lista de livros
    P�s-Cond: Arquivo .csv com os registros dos livros
    */
    void Salva_Livros();

    /**
    M�todo para carregar os registros que estao no arquivo e adicionalos na lista

    Pr�-Cond: Arquivo .csv com os registros dos livtos
    P�s-Cond: Lista contendo todos os livros
    */
    void Carrega_Livros();



#endif // LISTA_LIVROS_H_INCLUDED
