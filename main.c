#include <stdio.h>
#include <stdlib.h>

#include "Model/Lista_Livros.h"
#include "Model/Lista_Usuarios.h"
#include "libs/biblioteca.h"
#include "View/Telas_Principal.h"
#include <windows.h>

int main()
{

    Iniciliza_Usuario();
    Iniciliza_Acervo();
    Iniciliza_Emprestimos();

    Carrega_Usuarios();
    Carrega_Livros();
    Ler_Config();
    Carrega_Emprestimos();

    tela_menu_principal();
    getchar();

    return 0;
}
