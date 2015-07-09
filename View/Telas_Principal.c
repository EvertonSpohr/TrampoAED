
#include "Telas_Principal.h"
#include "../Controler/Controler_Menu.h"
#include "../Model/Lista_Usuarios.h"
#include <stdio.h>

void tela_principal(char *Titulo){

    SetConsoleTitle(" BIBLIOTECA COMPUTARIA "); // Define nome da console

    system("mode 81, 25"); // define tamanha da tela

    TableBorder(0,0,79,24,2,15,1,1); // cria a borda

    gotoxy(0,1); TituloSimples(Titulo, 7,9); // adiciona o titulo ao sistema

    gotoxy(8, 23); printf("Data: "); gotoxy(16,23); system ( "date/t " ); // adiciona a data no rodapé
    gotoxy(30,23); printf("Hora: "); gotoxy(38,23); system ("time /t "); // adiciona hora no rodapé
    gotoxy(50,23); printf("Versao: 1.0"); // adiciona a versao no rodapé

}

void tela_menu_principal(Lista_Usuario *LU)
{
    int OPC;

    do
    {
        tela_principal("Menu Principal");

        gotoxy(33,4); printf("SELECIONE UMA OPCAO");

        TableBorder(28,8,55,14,2,15,0,0);  // cria a borda
        gotoxy(31,9);  printf("[1] USUARIOS");
        gotoxy(31,10); printf("[2] ACERVO");
        gotoxy(31,11); printf("[3] CONSULTAS");
        gotoxy(31,12); printf("[4] EMPRESTIMOS");
        gotoxy(31,13); printf("[5] SALVAR E SAIR");

        TableBorder(28,15,48,17,1,15,0,0);
        gotoxy(29,16); printf("OPCAO: ");
        TableBorder(48,15,55,17,1,15,0,0);

        gotoxy(50,16); scanf("%d", &OPC);
        seleciona_menu(OPC);

    }
    while(OPC < 1 || OPC > 5);


}
