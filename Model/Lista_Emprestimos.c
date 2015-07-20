#include "Lista_Livros.h"
#include "Lista_Emprestimos.h"
#include <string.h>

    void Iniciliza_Emprestimos()
    {
        Emprestimos = NULL;
    }


    int Consulta_Emprestimo( char Email[])
    {

        Lista_Emprestimo *P;
        P = Emprestimos;
        while(P != NULL)
        {
            //printf("%s---%s",Email,P->Emp.Email_Usuario);
            if( (strcmp(Email, P->Emp.Email_Usuario) == 0))
            {
                return(1);
            }
            else
            {
                P = P->Prox;
            }
        }
        return (0);
    }

int Consulta_Emprestimo_Livro( char Email[], char Livro[])
    {

        Lista_Emprestimo *P;
        P = Emprestimos;
        while(P != NULL)
        {
            //printf("%s---%s",Email,P->Emp.Email_Usuario);
            if( (strcmp(Email, P->Emp.Email_Usuario) == 0)&&(strcmp(Livro, P->Emp.Titulo) == 0))
            {
                return(1);
            }
            else
            {
                P = P->Prox;
            }
        }
        return (0);
    }

    Lista_Emprestimo *Retorna_Emprestimo(char Email[], char Titulo[])
    {
        int achou = 0;
        Lista_Emprestimo *LE = Emprestimos;
        while((LE != NULL) && (achou<1))
        {
          if((strcmp(Email, LE->Emp.Email_Usuario) == 0)&&(strcmp(Titulo, LE->Emp.Titulo) == 0)){
             achou = 1;
             }
          else
             LE = LE->Prox;
        }
        return (LE);
    }

    Lista_Emprestimo *EmprestimosByEmail(char Email[]){

        if(Consulta_Emprestimo(Email)==1){
            Lista_Emprestimo *emprestimoByEmail;
            Lista_Emprestimo *New;
            Lista_Emprestimo *E = Emprestimos;


            emprestimoByEmail=NULL;
            int counter =0;

            while((E!=NULL)){

                if((strncmp(Email,E->Emp.Email_Usuario,10)==0)){
                    New = ((Lista_Emprestimo*)malloc(sizeof(Lista_Emprestimo)));
                    New->Emp=E->Emp;
                    New->Ant= NULL;
                    New->Prox=emprestimoByEmail;

                    if(emprestimoByEmail!=NULL){
                        emprestimoByEmail->Ant = New;
                    }
                    emprestimoByEmail = New;
                    E=E->Prox;
                    counter++;

                }else
                    E=E->Prox;
            }
            return emprestimoByEmail;
        }else{
        return NULL;
        }
    }
    int Insere_Emprestimo( Emprestimo E)
    {
        Lista_Emprestimo *New;

        if(!Consulta_Emprestimo_Livro( E.Email_Usuario,E.Titulo))
        {
              New = ((Lista_Emprestimo*)malloc(sizeof(Lista_Emprestimo)));
              New->Emp = E;
              New->Ant = NULL;
              New->Prox = Emprestimos;
              if ((Emprestimos) != NULL)
              {
                 Emprestimos->Ant = New;
              }
              Emprestimos = New;
              return(1);
       }
       else
          return (0);
    }


    int Remover_Emprestimo(char Email[], char Titulo[])
    {
       Lista_Emprestimo *P;
       int achou = 0;

       P = Retorna_Emprestimo(Email,Titulo);

       if(P != NULL)
       {

          if(P->Prox != NULL)
             P->Prox->Ant = P->Ant;
          if(P->Ant != NULL)
             P->Ant->Prox = P->Prox;
          else
             (Emprestimos) = P->Prox;
          free(P);
          achou = 1;
       }

       if(achou)
       {
          return(1);
       }
       else
       {
          return(0);
       }
    }

     void Salva_Emprestimos()
    {
        FILE *Arquivo;
        Arquivo = fopen("Arquivos/emprestimos.csv","w");   /* Arquivo ASCII, para escrita */


        if(!Arquivo)
        {
           printf( "Erro na abertura do arquivo");
        }
         else
         {
               if(Emprestimos == NULL)
               {
                   printf("Lista de emprestimos vazia!");
               }
               else
               {

                while(Emprestimos)
                {
                    fprintf(Arquivo, "%s;%s;%s;%s\n",Emprestimos->Emp.Email_Usuario, Emprestimos->Emp.Titulo, Emprestimos->Emp.Data_Emprestimo, Emprestimos->Emp.Status);
                    Emprestimos = Emprestimos->Prox;
                  }

                  fclose(Arquivo);
               }
         }
    }

void Carrega_Emprestimos()
{
	FILE *Arquivo;
    Arquivo = fopen("Arquivos/emprestimos.csv","r");

    char Linha[255];

	if(Arquivo == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
	else
    {
        while( !feof(Arquivo) )
        {
            fscanf(Arquivo,"%s", &Linha);

            int i;
            char *p;
            char *array[5];
            i = 0;
            p = strtok (Linha,";");

            while (p != NULL)
            {
                array[i++] = p;
                p = strtok (NULL, ";");
            }

            Emprestimo E;

            strcpy(E.Email_Usuario, array[0]);
            strcpy(E.Titulo, array[1]);
            strcpy(E.Data_Emprestimo, array[2]);
            strcpy(E.Status, array[3]);

            Insere_Emprestimo(E);

        }


    }
	fclose(Arquivo);
}
