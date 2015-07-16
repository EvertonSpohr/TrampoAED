#include "Telas_Emprestimo.h"
#include <stdio.h>
#include <conio.h>
#include "Telas_Principal.h"
#include "../Controler/Controler_Emprestimo.h"
#include "../Model/Lista_Emprestimos.h"
#include "../Model/Lista_Usuarios.h"
#include "../Model/Lista_Livros.h"
#include <time.h>


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
        printf("[3] MENU PRINCIPAL");
        gotoxy(31,12);
        TableBorder(28,15,48,17,1,15,0,0);
        gotoxy(29,16);
        printf("OPCAO: ");
        TableBorder(48,15,55,17,1,15,0,0);

        gotoxy(50,16);
        scanf("%d", &OPC);
        seleciona_menu_Emprestimo(OPC);

    }
    while(OPC < 1 || OPC > 3);
}

void Tela_Cadastrar_Emprestimo()
{
    tela_principal("Cadastrar Emprestimo");

    //Usuario existe?
    char OPC;
    char* user_email = Get_User();
    //Livro exixte?
    getchar();
    fflush(stdin);
    char* livro = Get_Livro();

    if(user_email!='0' && livro!='0'){
        gotoxy(7,16);
        printf("Continuar com o cadastro de Emprestimo?:     (S/N)");
        gotoxy(7,17);
        scanf("%c", &OPC);

        fflush(stdin);

        if(OPC == 'S' || OPC == 's'){
            Empresta_Livros(livro);
            clrscr();
            tela_principal("Menu de Controle de Emprestimos");
            gotoxy(7,9);
            //printf("Data: ");

            Emprestimo Emp;

            char text[100];
            time_t now = time(NULL);
            struct tm *t = localtime(&now);

            strftime(text, sizeof(text)-1, "%d/%m/%Y", t);

            strcpy(Emp.Data_Emprestimo,text);
            strcpy(Emp.Titulo,livro);
            strcpy(Emp.Email_Usuario,user_email);
            strcpy(Emp.Status,"livre");


            //printf("%c",time);
            if(Insere_Emprestimo(Emp)==1){

                gotoxy(7,16);
                printf("Emprestimo salvo com sucesso!");
                getchar();
                Menu_Principal_Emprestimo();
                }
                else
                {
                    gotoxy(7,16);
                    printf("Falha ao cadastrar Emprestimo!");
                    getchar();
                    Menu_Principal_Emprestimo();
                }
        }
    }else{
        getchar();
        Menu_Principal_Emprestimo();
    }
}
char* Get_Livro(){
    char Titulo[255] = "";
    clrscr();
    tela_principal("Pesquisar Livro");

    gotoxy(7,7);
    printf("Titulo: ");
    fflush(stdin);
    gotoxy(15,7);
    gets(Titulo);

    Lista_Acervo *LA = Busca_Livro_Titulo(Titulo);

    gotoxy(7,7); clreol();

    if(LA != NULL)
    {
        gotoxy(7,7); printf("Livro encontrado!");

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

        getchar();
        return LA->livro.Titulo;

    }
    else
    {
        gotoxy(7,18);
        printf("Livro nao encontrado!");
        getchar();
        return '0';
    }
}

int Empresta_Livros(char *Titulo)
{


    Lista_Acervo *LA = Busca_Livro_Titulo(Titulo);

    if(LA != NULL)
    {

        Livro L = LA->livro;
        if(L.Num_Exemp==0){
            gotoxy(7,17);
            printf("Não Há exemplares disponíveis deste livro!");
            return 0;
        }else{

            fflush(stdin);
            if(Remover_Livro(L.Titulo) == 1)
            {
                if(Insere_Acervo(L) == 1)
                {
                    L.Num_Exemp = L.Num_Exemp-1;
                    gotoxy(7,17);
                    printf("Existem %d exemplares deste livro",L.Num_Exemp);
                    getchar();
                }
                else
                {
                    gotoxy(7,17);
                    printf("Falha ao emprestar este livro");
                    getchar();
                }
            }
            else
            {
                gotoxy(7,17);
                printf("Falha ao emprestar este livro!");
                getchar();
            }
        }
    }
    return 1;
}

char* Get_User(){
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
        return LU->Users.Email;
    }
    else
    {
        gotoxy(7,18);
        printf("Usuario nao encontrado!");
        return '0';
    }

}

void Tela_Pesquisar_Emprestimo()
{
    char Email[255] = "";

    tela_principal("Pesquisar Emprestimo");

    /*gotoxy(7,7);
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

    }*/
    getchar();
    Menu_Principal_Emprestimo();
}

