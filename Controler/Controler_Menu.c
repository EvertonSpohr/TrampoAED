#include "Controler_Menu.h"
#include "../View/Telas_Usuario.h"
#include "../View/Telas_Livros.h"
#include "../View/Telas_Relatorios.h"
#include "../libs/biblioteca.h"
#include "../Model/Lista_Usuarios.h"

    void seleciona_menu(int OPC)
    {
        clrscr();

            switch (OPC)
            {
            case 1:
                Menu_Principal_Usuario();
                break;

            case 2:
                Menu_Principal_Livros();
                break;

            case 3:
                Menu_Principal_Relatorios();
                break;

            case 4:
                break;

            case 5:
                //exit(1);
                break;

            }
     }
