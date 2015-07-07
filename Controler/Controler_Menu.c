#include "Controler_Menu.h"
#include "../View/Telas_Usuario.h"
#include "../libs/biblioteca.h"
#include "../Model/Lista_Usuarios.h"

    void seleciona_menu(int OPC, Lista_Usuario *LU)
    {
        clrscr();

            switch (OPC)
            {
            case 1:
                Menu_Principal_Usuario(&LU);
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                //exit(1);
                break;

            }
     }
