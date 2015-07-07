/*
    Biblioteca para validaçoes!

    Esta biblioteca contem as validacoes de telefone, nome ....

    Autor: Everton R. Spohr

*/

#ifndef VALIDACAO_H_INCLUDED
#define VALIDACAO_H_INCLUDED

#include <stdio.h>
#include <windows.h>

int verifica_nome(char *nome);
/**
    verifica se o nome nao contem numeros ou caracteres especiais
    @param nome - nome a ser verificado
*/
int verifica_telefone(char fone[30]);
/**
    verifica se o telefone nao contem letras ou caracteres especiais
    @param fone a ser verificado
*/
int verifica_email(char Testar[100]);
/**
    verifica se o email contem o @
    @param Testar - email a ser verificado
*/
int verifica_aniversario(char niver[15]);
/**
    verifica se a data esta no formato dd/mm/aaaa, tendo que conter a barra
    @param niver - data a ser testada
*/
int pega_senha(char *pass, int x);
/**
    recebe uma senha e esconde, aparecendo uma carrinha no lugar
    @param pass - string que ira receber a senha
    @param x - tamanho da senha
*/
// x é o tamanho da senha e passa a string que ira receber a senha.
int pega_cod(char *pass);
/**
    recebe o codigo no formato xxx-x adicionando o - no cod. só aceita numeros
    @param pass - string que recebera o codigo
*/
int pega_cod_ger(char *pass);
/**
    recebe o codigo no formato xxxx só acc numeros
    @param pass - string que recebera o codigo
*/
//FIM ==========================================================================
#endif

