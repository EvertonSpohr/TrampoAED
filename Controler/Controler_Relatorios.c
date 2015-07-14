#include "Controler_Relatorios.h"
#include "../View/Telas_Relatorios.h"
#include "../View/Telas_Principal.h"
#include "../libs/biblioteca.h"

    void seleciona_menu_relatorios(int OPC)
    {
        clrscr();

            switch (OPC)
            {
            case 1:
                Tela_Lista_Emprestimos();
                break;

            case 2:
                Tela_Lista_Acervo();
                break;

            case 3:
                Tela_Lista_Usuarios();
                break;

            case 4:
                tela_menu_principal();
                break;

            }
     }


