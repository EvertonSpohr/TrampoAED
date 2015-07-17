#include "Lista_Livros.h"
#include "Lista_Emprestimos.h"
#include <string.h>

    void Iniciliza_Emprestimos()
    {
        Emprestimos = NULL;
    }


    int Consulta_Emprestimo( char *Email)
    {

        Lista_Emprestimo *P;
        P = Emprestimos;

        while(P != NULL)
        {
            if( (strcmp(Email, P->Emp.Email_Usuario) == 1))
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

    Lista_Emprestimo *Retorna_Emprestimo(char *Email)
    {
        int achou = 0;
        while((Emprestimos != NULL)&& (!achou))
        {
          if((strcmp(Email, Emprestimos->Emp.Email_Usuario) == 1))
             achou = 1;
          else
             Emprestimos = Emprestimos->Prox;
        }
        return (Emprestimos);
    }

    /*Emprestimo[] Get_Emprestimos(char *Email){
        Emprestimo emprestimoByEmail[100];
        Emprestimos;
        emprestimoByEmail = ((Lista_Emprestimo*)malloc(sizeof(Lista_Emprestimo)));
        emprestimoByEmail->Ant=NULL;
        int count =0;
        while((Emprestimos!=NULL)){
            if((strcmp(Email,Emprestimos->Emp.Email_Usuario)==1)){
                emprestimoByEmail->Emp=E->Emp;
                emprestimoByEmail = emprestimoByEmail->Prox;
                Emprestimos=Emprestimos->Prox;
            }else
                E=E->Prox;
        }
        return emprestimoByEmail;
    }
    */
    int Insere_Emprestimo( Emprestimo E)
    {
        Lista_Emprestimo *New;

        if(!Consulta_Emprestimo( E.Email_Usuario))
        {
              New = ((Lista_Emprestimo*)malloc(sizeof(Lista_Emprestimo)));
              New->Emp = E;
              New->Ant = NULL;
              New->Prox = Emprestimos;
              if ((Emprestimos) != NULL)
              {
                 (Emprestimos)->Ant = New;
              }
              Emprestimos = New;
              return(1);
       }
       else
          return (0);
    }


    int Remover_Emprestimo(char Email[])
    {
       Lista_Emprestimo *P;
       int achou = 0;

       P = Retorna_Emprestimo(Email);

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
