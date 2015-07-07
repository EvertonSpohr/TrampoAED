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

    void Iniciliza_Emprestimos(Lista_Emprestimo **Emprestimos);
    int Consulta_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email, int codigo);
    Lista_Emprestimo *Retorna_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email, int codigo);
    int Insere_Emprestimo(Lista_Emprestimo **Emprestimos, Emprestimo E);
    int Remover_Emprestimo(Lista_Emprestimo **Emprestimos, char *Email, int codigo);
    void Imprime_Emprestimos(Lista_Emprestimo *Emprestimos);


#endif // LISTA_EMPRESTIMOS_H_INCLUDED
