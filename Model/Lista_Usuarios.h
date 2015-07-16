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
    Método para inicializar a lista de usuarios

    Pré-Cond: Lista de usuarios
    Pós-Cond: Lista de usuarios apontando para null
    */
    void Iniciliza_Usuario();

    /**
    Método para verificar se um usuário esta inserido na lista

    Pré-Cond: email do usuario
    Pós-Cond: retorna true se o usuario esta na lista, caso nao retorna false
    */
    int Consulta_Usuario(char Email[]);

    /**
    Método para buscar um usuario

    Pré-Cond: email do usuario
    Pós-Cond: retorna node com as informacoes do usuario
    */
    Lista_Usuario *Retorna_Usuario(char Email[]);

    /**
    Método para inserir usuario na lista

    Pré-Cond: objeto usuario novo
    Pós-Cond: lista de usuarios contendo o novo usuario
    */
    int Insere_Usuario(Usuario U);

    /**
    Método para remover o usuario da lista

    Pré-Cond: email do usuario
    Pós-Cond: lista de usuarios sem o usuario
    */
    int Remover_Usuario(char Email[]);

    /**
    Método para salvar os registros dos usuarios em um arquivo .csv

    Pré-Cond: Lista de usuarios
    Pós-Cond: arquivo .csv com os registros dos usuarios
    */
    void salva_usuarios();

    /**
    Método para carregar os registros dos usuarios do arquivo .csv

    Pré-Cond: arquivo .csv com os registros dos usuarios
    Pós-Cond: lista de usuarios contendo os registros do arquivo
    */
    void Carrega_Usuarios();



#endif // LISTA_USUARIOS_H_INCLUDED
