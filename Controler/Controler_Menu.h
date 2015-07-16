#ifndef CONTROLER_MENU_H_INCLUDED
#define CONTROLER_MENU_H_INCLUDED

#include "../Model/Lista_Usuarios.h"

#include <stdio.h>
#include <stdlib.h>

    /**
    Método para selecionar qual a opção do usuario para as operaçoes
    referentes ao menu principal.

    Pré-Cond: Opção do usuario (1 - 6)
    Pós-Cond: Chama o método referente a opção
    */
    void seleciona_menu(int OPC);

    /**
    Método para chamar as funções de salvar as listas encadeadas

    Pré-Cond: Listas encadeadas
    Pós-Cond: Arquivo salvo
    */
    void Salvar();


#endif // CONTROLER_MENU_H_INCLUDED
