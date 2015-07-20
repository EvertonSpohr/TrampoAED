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
        tela_principal("MENU DE CONTROLE DE EMPRESTIMOS");

        gotoxy(33,4);
        printf("SELECIONE UMA OPCAO");

        TableBorder(28,8,55,14,2,15,0,0);  // cria a borda
        gotoxy(31,9);
        printf("[1] CADASTRAR");
        gotoxy(31,10);
        printf("[2] PESQUISAR");
        gotoxy(31,11);
        printf("[3] DEVOLUCAO");
        gotoxy(31,12);
        printf("[4] MENU PRINCIPAL");
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
    tela_principal("CADASTRAR EMPRESTIMO");

    //Usuario existe?
    char OPC;
    char* user_email = Get_User();
    //Livro exixte?
    getchar();
    fflush(stdin);


    if(user_email!='0'){
        char* livro = Get_Livro();
        if(livro!='0'){
            gotoxy(7,16);
            printf("Continuar com o cadastro de Emprestimo?:     (S/N)");
            gotoxy(7,17);
            fflush(stdin);
            scanf("%c", &OPC);

            fflush(stdin);

            if(OPC == 'S' || OPC == 's'){
                if(Empresta_Livros(livro)){
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
                        clrscr();
                        Menu_Principal_Emprestimo();
                        }
                        else
                        {
                            gotoxy(7,16);
                            printf("Falha ao cadastrar Emprestimo!");
                            getchar();
                            clrscr();
                            Menu_Principal_Emprestimo();
                        }
                }else{
                    getchar();
                    clrscr();
                    Menu_Principal_Emprestimo();
                }
            }else{
                clrscr();
                Menu_Principal_Emprestimo();
            }
        }else{
            clrscr();
            Menu_Principal_Emprestimo();
        }
    }else{
        getchar();
        clrscr();
        Menu_Principal_Emprestimo();
    }
}
char* Get_Livro(){
    char Titulo[255] = "";
    clrscr();
    tela_principal("PESQUISAR LIVRO");

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

        if(LA->livro.Num_Exemp==0){
            gotoxy(7,17);
            printf("Não Há exemplares disponíveis deste livro!");
            return 0;
        }else{
            //L.Num_Exemp = L.Num_Exemp-1;

            fflush(stdin);
            LA->livro.Num_Exemp=LA->livro.Num_Exemp-1;

            gotoxy(7,17);
            printf("Agora Existem %i disponiveis",LA->livro.Num_Exemp);
            return 1;
        }
    }
}

char* Get_User(){
    char Email[255] = "";

    tela_principal("PESQUISAR USUARIO");

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

    tela_principal("PESQUISAR EMPRESTIMO");

    gotoxy(7,7);
    printf("Email: ");
    gotoxy(15,7);
    fflush(stdin);
    gets(Email);
    //printf("disods");
    Lista_Emprestimo *LE = EmprestimosByEmail(Email);
    //Consulta_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email, int codigo);
    //printf("-------");

    if(LE != NULL)
    {
        gotoxy(7,7); printf("Emprestimos encontrados!");
        gotoxy(7,7); clreol();
        int Y = 5;
        int X = 4;
        int cont = 1;

          while(LE)
          {
                gotoxy(X, ++Y); printf("%d ----------------------------------------------------- ", cont);
                Y++;
                gotoxy(X, ++Y); printf("Data de emprestimo: %s", LE->Emp.Data_Emprestimo);
                gotoxy(X, ++Y); printf("Email: %s", LE->Emp.Email_Usuario);
                Y++;
                gotoxy(X, ++Y); printf("Titulo: %s", LE->Emp.Titulo);
                gotoxy(X, ++Y); printf("Status: %s", LE->Emp.Status);
                Y++; cont++;

                LE = LE->Prox;
          }
    getchar();
    Menu_Principal_Emprestimo();
    }
}
void Tela_Devolucao_Emprestimo(){
    char Email[255] = "";

    tela_principal("DEVOLUCAO DE LIVRO");

    gotoxy(7,7);
    printf("Email: ");
    gotoxy(15,7);
    fflush(stdin);
    gets(Email);
    clrscr();

    char Livro[255] = "";
    tela_principal("DEVOLUCAO DE LIVRO");
    gotoxy(7,7);
    printf("Titulo do Livro: ");
    gotoxy(25,7);
    fflush(stdin);
    gets(Livro);

    if(Remover_Emprestimo(Email,Livro)!=1){
        clrscr();
        gotoxy(7,7);
        printf("EMPRESTIMO NAO ENCONTRADO!");
    }else{

        Lista_Acervo *LA = Busca_Livro_Titulo(Livro);
        if(LA!=NULL){
            LA->livro.Num_Exemp++;
            gotoxy(7,16);
            printf("LIVRO DEVOLVIDO COM SUCESSO!");
        }else{
            gotoxy(7,16);
            printf("LIVRO NAO EXISTE NO CADASTRO POR FAVOR VERIFIQUE!");
        }

    }
    getchar();
    clrscr();
    Menu_Principal_Emprestimo();
}
