#ifndef LISTA_EMPRESTIMOS_H_INCLUDED
#define LISTA_EMPRESTIMOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "Lista_Usuarios.h"
#include "Lista_Livros.h"

    typedef struct Emprestimo
    {
        char Data_Emprestimo[255];
        char Email_Usuario[255];
        char Status[255];
        char Titulo[255];

    }Emprestimo;

    typedef struct Lista_Emprestimo
    {
        Emprestimo Emp;
        struct Lista_Emprestimo *Prox;
        struct Lista_Emprestimo *Ant;

    }Lista_Emprestimo;

    Lista_Emprestimo *Emprestimos;

    void Iniciliza_Emprestimos();
    int Consulta_Emprestimo(char Email[]);
    Lista_Emprestimo *EmprestimosByEmail( char Email[]);
    Lista_Emprestimo *Retorna_Emprestimo(char Email[],char Titulo[]);
    int Insere_Emprestimo(Emprestimo E);
    void Salva_Emprestimos();
    int Remover_Emprestimo(char Email[], char Titulo[]);


#endif // LISTA_EMPRESTIMOS_H_INCLUDED
