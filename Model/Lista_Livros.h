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
    Método para inicializar a lista de livros

    Pré-Cond: Lista de livros
    Pós-Cond: Lista de livros apontando para null
    */
    void Iniciliza_Acervo();

    /**
    Método para Consultar se o livro esta contido na lista

    Pré-Cond: Titulo do livro
    Pós-Cond: Retorna o true caso encontrado, senao retorna false
    */
    int Consulta_Acervo(char titulo[]);

    /**
    Método para inserir um livro novo na lista

    Pré-Cond: Novo Livro
    Pós-Cond: Lista de livros com o novo livro inserido
    */
    int Insere_Acervo(Livro L);

    /**
    Método para remover um livro da lista

    Pré-Cond: Titulo do livro para remover
    Pós-Cond: Lista de livros sem o livro
    */
    int Remover_Livro(char titulo[]);

    /**
    Método buscar o livro pelo titulo

    Pré-Cond: titulo do livro
    Pós-Cond: Nó contendo o livro
    */
    Lista_Acervo *Busca_Livro_Titulo(char titulo[]);

    /**
    Método para salvar o acervo em um arquivo .csv

    Pré-Cond: Lista de livros
    Pós-Cond: Arquivo .csv com os registros dos livros
    */
    void Salva_Livros();

    /**
    Método para carregar os registros que estao no arquivo e adicionalos na lista

    Pré-Cond: Arquivo .csv com os registros dos livtos
    Pós-Cond: Lista contendo todos os livros
    */
    void Carrega_Livros();



#endif // LISTA_LIVROS_H_INCLUDED
