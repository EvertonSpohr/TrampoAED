#ifndef CONTROLER_MENU_H_INCLUDED
#define CONTROLER_MENU_H_INCLUDED

#include "../Model/Lista_Usuarios.h"

#include <stdio.h>
#include <stdlib.h>

    /**
    M�todo para selecionar qual a op��o do usuario para as opera�oes
    referentes ao menu principal.

    Pr�-Cond: Op��o do usuario (1 - 6)
    P�s-Cond: Chama o m�todo referente a op��o
    */
    void seleciona_menu(int OPC);

    /**
    M�todo para chamar as fun��es de salvar as listas encadeadas

    Pr�-Cond: Listas encadeadas
    P�s-Cond: Arquivo salvo
    */
    void Salvar();


#endif // CONTROLER_MENU_H_INCLUDED
