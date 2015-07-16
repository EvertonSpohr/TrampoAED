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

    Lista_Usuario *Users; ///LISTA ENCADEADA CONTENDO OS USUARIOS

    /**
    M�todo para inicializar a lista de usuarios

    Pr�-Cond: Lista de usuarios
    P�s-Cond: Lista de usuarios apontando para null
    */
    void Iniciliza_Usuario();

    /**
    M�todo para verificar se um usu�rio esta inserido na lista

    Pr�-Cond: email do usuario
    P�s-Cond: retorna true se o usuario esta na lista, caso nao retorna false
    */
    int Consulta_Usuario(char Email[]);

    /**
    M�todo para buscar um usuario

    Pr�-Cond: email do usuario
    P�s-Cond: retorna node com as informacoes do usuario
    */
    Lista_Usuario *Retorna_Usuario(char Email[]);

    /**
    M�todo para inserir usuario na lista

    Pr�-Cond: objeto usuario novo
    P�s-Cond: lista de usuarios contendo o novo usuario
    */
    int Insere_Usuario(Usuario U);

    /**
    M�todo para remover o usuario da lista

    Pr�-Cond: email do usuario
    P�s-Cond: lista de usuarios sem o usuario
    */
    int Remover_Usuario(char Email[]);

    /**
    M�todo para salvar os registros dos usuarios em um arquivo .csv

    Pr�-Cond: Lista de usuarios
    P�s-Cond: arquivo .csv com os registros dos usuarios
    */
    void salva_usuarios();

    /**
    M�todo para carregar os registros dos usuarios do arquivo .csv

    Pr�-Cond: arquivo .csv com os registros dos usuarios
    P�s-Cond: lista de usuarios contendo os registros do arquivo
    */
    void Carrega_Usuarios();



#endif // LISTA_USUARIOS_H_INCLUDED
