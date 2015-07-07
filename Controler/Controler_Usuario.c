#include "Controler_Usuario.h"
#include "../View/Telas_Usuario.h"
#include "../View/Telas_Principal.h"
#include "../libs/biblioteca.h"

    void seleciona_menu_usuario(int OPC)
    {
        clrscr();

            switch (OPC)
            {
            case 1:
                Tela_Cadastrar_Usuario();
                break;

            case 2:
                Tela_Alterar_Usuario();
                break;

            case 3:
                Tela_Remover_Usuario();
                break;

            case 4:
                Tela_Pesquisar_Usuario();
                break;

            case 5:
                tela_menu_principal();
                break;

            }
     }


