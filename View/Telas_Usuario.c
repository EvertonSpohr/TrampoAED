#include <stdio.h>
#include <conio.h>
#include "Telas_Usuario.h"
#include "Telas_Principal.h"
#include "../Controler/Controler_Usuario.h"
#include "../Model/Lista_Usuarios.h"

void Menu_Principal_Usuario()
{
    int OPC;
    clrscr();

    do
    {
        tela_principal("Menu de Controle de Usuarios");

        gotoxy(33,4);
        printf("SELECIONE UMA OPCAO");

        TableBorder(28,8,55,14,2,15,0,0);  // cria a borda
        gotoxy(31,9);
        printf("[1] CADASTRAR");
        gotoxy(31,10);
        printf("[2] ALTERAR");
        gotoxy(31,11);
        printf("[3] EXCLUIR");
        gotoxy(31,12);
        printf("[4] PESQUISAR");
        gotoxy(31,13);
        printf("[5] MENU PRINCIPAL");

        TableBorder(28,15,48,17,1,15,0,0);
        gotoxy(29,16);
        printf("OPCAO: ");
        TableBorder(48,15,55,17,1,15,0,0);

        gotoxy(50,16);
        scanf("%d", &OPC);
        seleciona_menu_usuario(OPC);

    }
    while(OPC < 1 || OPC > 5);

}

void Tela_Cadastrar_Usuario()
{
    tela_principal("Cadastrar Usuario");

    gotoxy(7,9);
    printf("Nome: ");
    gotoxy(7,10);
    printf("E-Mail: ");
    gotoxy(7,11);
    printf("Data de Nascimento: ");
    gotoxy(7,12);
    printf("Area: ");

    Usuario U;

    fflush(stdin);
    gotoxy(14,9);
    gets(U.Nome);

    fflush(stdin);
    gotoxy(16,10);
    gets(U.Email);

    fflush(stdin);
    gotoxy(28,11);
    gets(U.Data_Nasc);

    fflush(stdin);
    gotoxy(14,12);
    gets(U.Area);

    fflush(stdin);
    char OPC;

    gotoxy(7,14);
    printf("Salvar Usuario:     (S/N)");
    gotoxy(23,14);
    scanf("%c", &OPC);

    fflush(stdin);

    if(OPC == 'S' || OPC == 's')
    {
        if(Insere_Usuario(U) == 1)
        {
        gotoxy(7,16);
        printf("Usuario salvo com sucesso!");
        getchar();
        Menu_Principal_Usuario();
        }
        else
        {
            gotoxy(7,16);
            printf("Falha ao inserir usuario! E-mail ja cadastrado!");
            getchar();
            Menu_Principal_Usuario();
        }
    }
    else
    {
        Menu_Principal_Usuario();
    }

}

void Tela_Pesquisar_Usuario()
{
    char Email[255] = "";

    tela_principal("Pesquisar Usuario");

    gotoxy(7,7);
    printf("E-Mail: ");
    fflush(stdin);
    gotoxy(15,7);
    gets(Email);

    Lista_Usuario *LU = Retorna_Usuario(Email);

    gotoxy(7,7); printf("                                                                        ");

    if(LU != NULL)
    {
        gotoxy(7,7); printf("Usuario encontrado!");

        gotoxy(7,9);
        printf("Nome: ");
        gotoxy(7,10);
        printf("E-Mail: ");
        gotoxy(7,11);
        printf("Data de Nascimento: ");
        gotoxy(7,12);
        printf("Area: ");

        fflush(stdin);
        gotoxy(14,9);
        puts(LU->Users.Nome);

        fflush(stdin);
        gotoxy(16,10);
        puts(LU->Users.Email);

        fflush(stdin);
        gotoxy(28,11);
        puts(LU->Users.Data_Nasc);

        fflush(stdin);
        gotoxy(14,12);
        puts(LU->Users.Area);

        gotoxy(7,18);
        printf("Tecle <ENTER> para voltar ao menu do usuario");

        getchar();
        Menu_Principal_Usuario();

    }
    else
    {
        gotoxy(7,18);
        printf("Usuario nao encontrado!");
        getchar();
        Menu_Principal_Usuario();
    }

}

void Tela_Alterar_Usuario()
{
    char Email[255] = "";

    tela_principal("Alterar Usuario");

    gotoxy(7,7);
    printf("E-Mail: ");
    fflush(stdin);
    gotoxy(15,7);
    gets(Email);

    Lista_Usuario *LU = Retorna_Usuario(Email);

    gotoxy(7,7); printf("                                                                        ");

    if(LU != NULL)
    {
        gotoxy(7,7); printf("Usuario encontrado!");

        gotoxy(7,9);
        printf("Nome: ");
        gotoxy(7,10);
        printf("E-Mail: ");
        gotoxy(7,11);
        printf("Data de Nascimento: ");
        gotoxy(7,12);
        printf("Area: ");

        fflush(stdin);
        gotoxy(14,9);
        puts(LU->Users.Nome);

        fflush(stdin);
        gotoxy(16,10);
        puts(LU->Users.Email);

        fflush(stdin);
        gotoxy(28,11);
        puts(LU->Users.Data_Nasc);

        fflush(stdin);
        gotoxy(14,12);
        puts(LU->Users.Area);

        fflush(stdin);
        char OPC;

        char Email_Original[255] = "";
        strcpy(Email_Original, LU->Users.Email);// Email_Original = LU->Users.Email;

        gotoxy(7,14);
        printf("Alterar:     (S/N)");
        gotoxy(17,14);
        scanf("%c", &OPC);

        fflush(stdin);

        if(OPC == 'S' || OPC == 's')
        {
            clrscr();
            tela_principal("Alterar Usuario");

            gotoxy(7,9);
            printf("Nome: ");
            gotoxy(7,10);
            printf("E-Mail: ");
            gotoxy(7,11);
            printf("Data de Nascimento: ");
            gotoxy(7,12);
            printf("Area: ");

            Usuario U;

            fflush(stdin);
            gotoxy(14,9);
            gets(U.Nome);

            fflush(stdin);
            gotoxy(16,10);
            gets(U.Email);

            fflush(stdin);
            gotoxy(28,11);
            gets(U.Data_Nasc);

            fflush(stdin);
            gotoxy(14,12);
            gets(U.Area);

            char OPCS;

            gotoxy(7,14);
            printf("Salvar Usuario:     (S/N)");
            gotoxy(23,14);
            scanf("%c", &OPCS);

            fflush(stdin);

            if(OPCS == 'S' || OPCS == 's')
            {
                if(Remover_Usuario(Email_Original) == 1)
                {
                    if(Insere_Usuario(U) == 1)
                    {
                    gotoxy(7,16);
                    printf("Usuario salvo com sucesso!");
                    getchar();
                    Menu_Principal_Usuario();
                    }
                    else
                    {
                        gotoxy(7,16);
                        printf("Falha ao alterar usuario! E-mail ja cadastrado!");
                        getchar();
                        Menu_Principal_Usuario();
                    }
                }
                else
                {
                gotoxy(7,16);
                printf("Falha ao alterar usuario!");
                getchar();
                Menu_Principal_Usuario();
            }

            }
            else
            {
                Menu_Principal_Usuario();
            }

        }
        else
        {
            Menu_Principal_Usuario();
        }

    }
    else
    {
        gotoxy(7,18);
        printf("Usuario nao encontrado!");
        getchar();
        Menu_Principal_Usuario();
    }

}


void Tela_Remover_Usuario()
{
    char Email[255] = "";

    tela_principal("Remover Usuario");

    gotoxy(7,7);
    printf("E-Mail: ");
    fflush(stdin);
    gotoxy(15,7);
    gets(Email);

    Lista_Usuario *LU = Retorna_Usuario(Email);

    gotoxy(7,7); clreol();

    if(LU != NULL)
    {
        gotoxy(7,7); printf("Usuario encontrado!");

        gotoxy(7,9);
        printf("Nome: ");
        gotoxy(7,10);
        printf("E-Mail: ");
        gotoxy(7,11);
        printf("Data de Nascimento: ");
        gotoxy(7,12);
        printf("Area: ");

        fflush(stdin);
        gotoxy(14,9);
        puts(LU->Users.Nome);

        fflush(stdin);
        gotoxy(16,10);
        puts(LU->Users.Email);

        fflush(stdin);
        gotoxy(28,11);
        puts(LU->Users.Data_Nasc);

        fflush(stdin);
        gotoxy(14,12);
        puts(LU->Users.Area);

        fflush(stdin);
        char OPC;

        gotoxy(7,14);
        printf("Remover Usuario:     (S/N)");
        gotoxy(24,14);
        scanf("%c", &OPC);

        fflush(stdin);

        if(OPC == 'S' || OPC == 's')
        {
            if(Remover_Usuario(LU->Users.Email) == 1)
            {

                    gotoxy(7,16);
                    printf("Usuario removido com sucesso!");
                    getchar();
                    Menu_Principal_Usuario();

            }
            else
            {
                gotoxy(7,16);
                printf("Falha ao remover usuario!");
                getchar();
                Menu_Principal_Usuario();
            }
        }
        else
        {
            Menu_Principal_Usuario();
        }
    }
    else
    {
        gotoxy(7,18);
        printf("Usuario nao encontrado!");
        getchar();
        Menu_Principal_Usuario();
    }

}




