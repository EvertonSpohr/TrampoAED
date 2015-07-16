#include "Controler_Menu.h"
#include "../View/Telas_Usuario.h"
#include "../View/Telas_Livros.h"
#include "../View/Telas_Relatorios.h"
#include "../View/Telas_Config.h"
#include "../View/Telas_Emprestimo.h"
#include "../libs/biblioteca.h"


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
                Menu_Principal_Emprestimo();
                break;

            case 5:
                Menu_Principal_Config();
                break;

            case 6:
                Salvar();
                break;

            }
     }

     void Salvar()
     {
         salva_usuarios();
         Salva_Livros();
         exit(1);
     }
