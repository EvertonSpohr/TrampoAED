#include "Controler_Livros.h"
#include "../View/Telas_Emprestimo.h"
#include "../View/Telas_Principal.h"

void seleciona_menu_Emprestimo(int OPC)
    {
        clrscr();

            switch (OPC)
            {
            case 1:
                Tela_Cadastrar_Emprestimo();
                break;

            case 2:
                Tela_Alterar_Emprestimo();
                break;

            case 3:
                Tela_Remover_Emprestimo();
                break;

            case 4:
                Tela_Pesquisar_Emprestimo();
                break;

            case 5:
                tela_menu_principal();
                break;

            }
     }
