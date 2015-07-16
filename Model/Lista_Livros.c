#include "Lista_Livros.h"
#include <string.h>
#include <conio.h>
#include "../libs/biblioteca.h"
#include "../View/Telas_Relatorios.h"

    void Iniciliza_Acervo()
    {
        Acervo = NULL;
    }


    int Consulta_Acervo(char titulo[])
    {

        Lista_Acervo *P;
        P = Acervo;

        while(P != NULL)
        {
            if(strcmp(Acervo->livro.Titulo, titulo) == 0)
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


    Lista_Acervo *Busca_Livro_Titulo(char titulo[])
    {
        int achou = 0;

        while((Acervo != NULL) && (achou == 0))
        {
          if(strcmp(Acervo->livro.Titulo, titulo) == 0)
             achou = 1;
          else
             Acervo = Acervo->Prox;
        }
        return (Acervo);
    }

    int Insere_Acervo(Livro L)
    {
        Lista_Acervo *New;

        if(!Consulta_Acervo(L.Titulo))
        {
              New = ((Lista_Acervo*)malloc(sizeof(Lista_Acervo)));
              New->livro = L;
              New->Ant = NULL;
              New->Prox = Acervo;
              if ((Acervo) != NULL)
              {
                 (Acervo)->Ant = New;
              }
              Acervo = New;
              return(1);
       }
       else
          return (0);
    }


    int Remover_Livro(char titulo[])
    {
       Lista_Acervo *P;
       int achou = 0;

       P = Busca_Livro_Titulo(titulo);

       if(P != NULL)
       {
          if(P->Prox != NULL)
             P->Prox->Ant = P->Ant;
          if(P->Ant != NULL)
             P->Ant->Prox = P->Prox;
          else
             (Acervo) = P->Prox;
          free(P);
          achou = 1;
       }

       if(achou == 1)
       {
          return(1);
       }
       else
       {
          return(0);
       }
    }

 void Salva_Livros()
    {
        FILE *Arquivo;
        Arquivo = fopen("Arquivos/acervo.csv","w");   /* Arquivo ASCII, para escrita */


        if(!Arquivo)
        {
           printf( "Erro na abertura do arquivo");
        }
         else
         {
               if(Acervo == NULL)
               {
                   printf("Lista de livros vazia!");
               }
               else
               {

                while(Acervo)
                {
                    fprintf(Arquivo, "%s;%s;%d;%s;%s\n",Acervo->livro.Titulo, Acervo->livro.Ano, Acervo->livro.Num_Exemp, Acervo->livro.Area, Acervo->livro.Autores);

                    Acervo = Acervo->Prox;
                  }

                  fclose(Arquivo);
               }
         }
    }

void Carrega_Livros()
{
	FILE *Arquivo;
    Arquivo = fopen("Arquivos/acervo.csv","r");

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
            int cont = 1;

            char Autores[255] = "";

            while (p != NULL)
            {
                if(cont == 4)
                {
                    strcat(Autores, p);

                    p = strtok (NULL, ";");
                    if(p == NULL)
                    {
                        break;
                    }
                    else
                        strcat(Autores, ";");
                }
                else
                {
                    array[i++] = p;
                    p = strtok (NULL, ";");
                    cont++;
                }
            }

            Livro L;

            strcpy(L.Titulo, array[0]);
            strcpy(L.Ano, array[1]);
            L.Num_Exemp = atoi(array[2]);
            strcpy(L.Area, array[3]);
            strcpy(L.Autores, Autores);

            Insere_Acervo(L);

        }
    }
	fclose(Arquivo);
}
