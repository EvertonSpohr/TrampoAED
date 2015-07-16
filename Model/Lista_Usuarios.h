#ifndef LISTA_USUARIOS_H_INCLUDED
#define LISTA_USUARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

    typedef struct Usuario
    {
        char Nome[255];
        char Data_Nasc[255];
        char Area[255];
        char Email[255];

    }Usuario;

    typedef struct Lista_Usuario
    {
        Usuario Users;
        struct Lista_Usuario *Prox;
        struct Lista_Usuario *Ant;

    }Lista_Usuario;

    Lista_Usuario *Users;

    void Iniciliza_Usuario();
    int Consulta_Usuario(char Email[]);
    Lista_Usuario *Retorna_Usuario(char Email[]);
    int Insere_Usuario(Usuario U);
    int Remover_Usuario(char *Email);
    void Imprime_Usuarios();
    void salva_usuarios();



#endif // LISTA_USUARIOS_H_INCLUDED
