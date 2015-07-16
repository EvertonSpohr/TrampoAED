#include "Telas_Emprestimo.h"
#include <stdio.h>
#include <conio.h>
#include "Telas_Principal.h"
#include "../Controler/Controler_Emprestimo.h"
#include "../Model/Lista_Emprestimos.h"

/*
void Menu_Principal_Emprestimo()
{
    int OPC;
    clrscr();

    do
    {
        tela_principal("Menu de Controle de Emprestimos");

        gotoxy(33,4);
        printf("SELECIONE UMA OPCAO");

        TableBorder(28,8,55,14,2,15,0,0);  // cria a borda
        gotoxy(31,9);
        printf("[1] CADASTRAR");
        gotoxy(31,10);
        printf("[2] PESQUISAR");
        gotoxy(31,11);
        printf("[5] MENU PRINCIPAL");
        gotoxy(31,12);
        TableBorder(28,15,48,17,1,15,0,0);
        gotoxy(29,16);
        printf("OPCAO: ");
        TableBorder(48,15,55,17,1,15,0,0);

        gotoxy(50,16);
        scanf("%d", &OPC);
        seleciona_menu_Emprestimo(OPC);

    }
    while(OPC < 1 || OPC > 5);

}

void Tela_Cadastrar_Emprestimo()
{
    tela_principal("Cadastrar Emprestimo");

    //Usuario, Livro, Data?

    gotoxy(7,9);
    printf("Titulo: ");
    gotoxy(7,10);
    printf("Autor(es), separe-os por ';': ");
    gotoxy(7,12);
    printf("Ano: ");
    gotoxy(7,13);
    printf("Numero de exemplares: ");
    gotoxy(7,14);
    printf("Area: ");

    Livro L;

    fflush(stdin);
    gotoxy(15,9);
    gets(L.Titulo);

    fflush(stdin);
    gotoxy(37,10);
    gets(L.Autores);

    fflush(stdin);
    gotoxy(12,12);
    gets(L.Ano);

    fflush(stdin);
    gotoxy(29,13);
    scanf("%d", &L.Num_Exemp);

    fflush(stdin);
    gotoxy(14,14);
    gets(L.Area);

    fflush(stdin);
    char OPC;

    gotoxy(7,16);
    printf("Salvar livro:     (S/N)");
    gotoxy(22,16);
    scanf("%c", &OPC);

    fflush(stdin);

    if(OPC == 'S' || OPC == 's')
    {
        if(Insere_Acervo(L) == 1)
        {
        gotoxy(7,16);
        printf("Livro salvo com sucesso!");
        getchar();
        Menu_Principal_Emprestimo();
        }
        else
        {
            gotoxy(7,16);
            printf("Falha ao inserir livro! Livro ja cadastrado!");
            getchar();
            Menu_Principal_Emprestimo();
        }
    }
    else
    {
        Menu_Principal_Emprestimo();
    }

}

void Tela_Pesquisar_Emprestimo()
{
    char Email[255] = "";

    tela_principal("Pesquisar Emprestimo");

    gotoxy(7,7);
    printf("Email: ");
    fflush(stdin);
    gotoxy(15,7);
    gets(Email);

    Lista_Emprestimo *LA = Consulta_Emprestimo(Emprestimos,Email);
    //Consulta_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email, int codigo);

    gotoxy(7,7); clreol();

    if(LA != NULL)
    {
        gotoxy(7,7); printf("Emprestimos encontrados!");

        gotoxy(7,9);
        printf("Titulo: ");
        gotoxy(7,10);
        printf("Autor(es): ");
        gotoxy(7,12);
        printf("Ano: ");
        gotoxy(7,13);
        printf("Numero de exemplares: ");
        gotoxy(7,14);
        printf("Area: ");

        fflush(stdin);
        gotoxy(15,9);
        puts(LA->livro.Titulo);

        fflush(stdin);
        gotoxy(18,10);
        puts(LA->livro.Autores);

        fflush(stdin);
        gotoxy(12,12);
        puts(LA->livro.Ano);

        fflush(stdin);
        gotoxy(29,13);
        printf("%d", LA->livro.Num_Exemp);

        fflush(stdin);
        gotoxy(14,14);
        puts(LA->livro.Area);

        gotoxy(7,18);
        printf("Tecle <ENTER> para voltar ao menu do acervo");

        getchar();
        Menu_Principal_Emprestimo();

    }
    else
    {
        gotoxy(7,18);
        printf("Livro nao encontrado!");
        getchar();
        Menu_Principal_Emprestimo();

    }

}
*/
