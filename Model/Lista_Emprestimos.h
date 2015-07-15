#ifndef LISTA_EMPRESTIMOS_H_INCLUDED
#define LISTA_EMPRESTIMOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "Lista_Usuarios.h"
#include "Lista_Livros.h"

    typedef struct Emprestimo
    {
        char *Data_Emprestimo;
        char *Email_Usuario;
        int Codigo_Livro;
        char *Status;

    }Emprestimo;

    typedef struct Lista_Emprestimo
    {
        Emprestimo Emp;
        struct Lista_Emprestimo *Prox;
        struct Lista_Emprestimo *Ant;

    }Lista_Emprestimo;

    Lista_Emprestimo *Emprestimos;

    void Iniciliza_Emprestimos();
    int Consulta_Emprestimo(Lista_Emprestimo *Emprestimos,char *Email);
    Lista_Emprestimo *Retorna_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email);
    Lista_Emprestimo *Get_Emprestimos(Lista_Emprestimo *Emprestimos, char *Email);
    int Insere_Emprestimo(Lista_Emprestimo **Emprestimos, Emprestimo E);
    void Imprime_Emprestimos(Lista_Emprestimo *Emprestimos);


#endif // LISTA_EMPRESTIMOS_H_INCLUDED
