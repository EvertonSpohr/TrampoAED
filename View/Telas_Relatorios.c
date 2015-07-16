#include <stdio.h>
#include <conio.h>
#include "Telas_Relatorios.h"
#include "Telas_Principal.h"
#include "../Controler/Controler_Relatorios.h"
#include "../Model/Lista_Usuarios.h"
#include "../Model/Lista_Livros.h"
#include "../Model/Lista_Emprestimos.h"

void Menu_Principal_Relatorios()
{
    int OPC;
    clrscr();

    do
    {
        tela_principal("Menu de Controle de Relatorios");

        gotoxy(33,4);
        printf("SELECIONE UMA OPCAO");

        TableBorder(28,8,55,14,2,15,0,0);  // cria a borda
        gotoxy(31,9);
        printf("[1] LISTA DE EMPRESTIMOS");
        gotoxy(31,10);
        printf("[2] LISTA DE ACERVO");
        gotoxy(31,11);
        printf("[3] LISTA DE USUARIOS");
        gotoxy(31,12);
        printf("[4] MENU PRINCIPAL");

        TableBorder(28,15,48,17,1,15,0,0);
        gotoxy(29,16);
        printf("OPCAO: ");
        TableBorder(48,15,55,17,1,15,0,0);

        gotoxy(50,16);
        scanf("%d", &OPC);
        seleciona_menu_relatorios(OPC);

    }
    while(OPC < 1 || OPC > 4);

}


void Tela_Lista_Emprestimos()
{
    clrscr();

    gotoxy(30,4);
    printf("LISTA DE EMPRESTIMOS");

    Imprime_Emprestimos_();
}


void Tela_Lista_Acervo()
{
    clrscr();

    gotoxy(30,4);
    printf("LISTA DE LIVROS DO ACERVO");

    Imprime_Acervo();


}

void Tela_Lista_Usuarios()
{
    clrscr();

    gotoxy(30,4);
    printf("LISTA DE USUARIOS");

    Imprime_Usuarios();
}


void Imprime_Usuarios()
    {
        Lista_Usuario *LAux = Users;


       if(LAux == NULL)
       {
           gotoxy(26,9);
           printf("Lista de usuarios vazia!");
       }
       else
       {
          int Y = 5;
          int X = 4;
          int cont = 1;

          while(LAux)
          {
                gotoxy(X, ++Y); printf("%d ----------------------------------------------------- ", cont);
                Y++;
                gotoxy(X, ++Y); printf("Nome: %s", LAux->Users.Nome);
                gotoxy(X, ++Y); printf("Data Nasc: %s", LAux->Users.Data_Nasc);
                gotoxy(X, ++Y); printf("Area: %s", LAux->Users.Area);
                gotoxy(X, ++Y); printf("E-Mail: %s", LAux->Users.Email);
                Y++; cont++;

                LAux = LAux->Prox;
          }
       }

         getch();
         Menu_Principal_Relatorios();
    }

 void Imprime_Emprestimos_()
 {

    Lista_Emprestimo *LAux = Emprestimos;

    if(LAux == NULL)
    {
        gotoxy(30,9);
        printf("Lista de emprestimos vazia!");
    }
       else
       {
          int Y = 5;
          int X = 4;
          int cont = 1;

          while(LAux)
          {
                gotoxy(X, ++Y); printf("%d ----------------------------------------------------- ", cont);
                Y++;
                gotoxy(X, ++Y); printf("Titulo: %s", LAux->Emp.Titulo);
                gotoxy(X, ++Y); printf("E-Mail Usuario: %s", LAux->Emp.Email_Usuario);
                gotoxy(X, ++Y); printf("Data de Emprestimo: %s", LAux->Emp.Data_Emprestimo);
                gotoxy(X, ++Y); printf("Status: %s", LAux->Emp.Status);
                Y++; cont++;

                LAux = LAux->Prox;
          }
       }

         getch();
         Menu_Principal_Relatorios();
 }

 void Imprime_Acervo()
    {

        Lista_Acervo *LAux = Acervo;


       if(LAux == NULL)
       {
           gotoxy(30,9);
           printf("Acervo de Livros vazio!");
       }
       else
       {
          int Y = 5;
          int X = 4;
          int cont = 1;

          while(LAux)
          {
                gotoxy(X, ++Y); printf("%d ----------------------------------------------------- ", cont);
                Y++;
                gotoxy(X, ++Y); printf("Titulo: %s", LAux->livro.Titulo);
                gotoxy(X, ++Y); printf("Autores: %s", LAux->livro.Autores);
                Y++;
                gotoxy(X, ++Y); printf("Ano: %s", LAux->livro.Ano);
                gotoxy(X, ++Y); printf("Area: %s", LAux->livro.Area);
                gotoxy(X, ++Y); printf("Nro Exemplares: %d", LAux->livro.Num_Exemp);
                Y++; cont++;

                LAux = LAux->Prox;
          }
       }

         getch();
         Menu_Principal_Relatorios();
    }
