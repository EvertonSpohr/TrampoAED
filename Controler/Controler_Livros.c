#include "Controler_Livros.h"
#include "../View/Telas_Livros.h"
#include "../View/Telas_Principal.h"

void seleciona_menu_livros(int OPC)
    {
        clrscr();

            switch (OPC)
            {
            case 1:
                Tela_Cadastrar_Livros();
                break;

            case 2:
                Tela_Alterar_Livros();
                break;

            case 3:
                Tela_Remover_Livros();
                break;

            case 4:
                Tela_Pesquisar_Livros();
                break;

            case 5:
                tela_menu_principal();
                break;

            }
     }
