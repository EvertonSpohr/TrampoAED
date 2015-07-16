#include <stdio.h>
#include <conio.h>
#include "Telas_Config.h"
#include "Telas_Principal.h"

#include "../Model/ModelConfig.h"


void Menu_Principal_Config()
{
    char OPC;
    clrscr();

    tela_principal("Configuracoes");

    gotoxy(14,5);
    printf("Valor da Multa: %f", Valor_Multa);

    gotoxy(14,7);
    printf("Alterar valor da multa?   (S/N)");

    fflush(stdin);
    gotoxy(38,7);
    scanf("%c", &OPC);

    if(OPC == 's' || OPC == 'S')
    {
        clrscr();
        tela_principal("Configuracoes");

        gotoxy(14,5);
        printf("Novo valor para multa: ");

        fflush(stdin);
        gotoxy(37,5);
        scanf("%f", &Valor_Multa);

        Salvar_Config();

        gotoxy(14,8);
        printf("Valor alterado! Tecle para retornar ao menu principal");
        getch();
        tela_menu_principal();
    }
    else
    {
        gotoxy(14,10);
        printf("Operacao cancelada! Tecle para retornar ao menu principal");
        getch();
        tela_menu_principal();
    }
}
