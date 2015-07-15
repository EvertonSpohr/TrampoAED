#include "Lista_Livros.h"
#include "Lista_Emprestimos.h"
#include <string.h>

    void Iniciliza_Emprestimos()
    {
        Emprestimos = NULL;
    }


    int Consulta_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email, int codigo)
    {

        Lista_Emprestimo *P;
        P = Emprestimos;

        while(P != NULL)
        {
            if( (strcmp(Email, P->Emp.Email_Usuario) == 1) && (P->Emp.Codigo_Livro == codigo) )
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

    Lista_Emprestimo *Retorna_Emprestimo(Lista_Emprestimo *Emprestimos, char *Email, int codigo)
    {
    int achou = 0;

    while((Emprestimos != NULL) && (!achou))
    {
      if((strcmp(Email, Emprestimos->Emp.Email_Usuario) == 1) && (Emprestimos->Emp.Codigo_Livro == codigo))
         achou = 1;
      else
         Emprestimos = Emprestimos->Prox;
    }
    return (Emprestimos);
}

    int Insere_Emprestimo(Lista_Emprestimo **Emprestimos, Emprestimo E)
    {
        Lista_Emprestimo *New;

        if(!Consulta_Emprestimo(*Emprestimos, E.Email_Usuario, E.Codigo_Livro))
        {
              New = ((Lista_Emprestimo*)malloc(sizeof(Lista_Emprestimo)));
              New->Emp = E;
              New->Ant = NULL;
              New->Prox = *Emprestimos;
              if ((*Emprestimos) != NULL)
              {
                 (*Emprestimos)->Ant = New;
              }
              *Emprestimos = New;
              return(1);
       }
       else
          return (0);
    }


    int Remover_Emprestimo(Lista_Emprestimo **Emprestimos, char *Email, int codigo)
    {
       Lista_Emprestimo *P;
       int achou = 0;

       P = Retorna_Emprestimo(*Emprestimos, Email, codigo);

       if(P != NULL)
       {
          if(P->Prox != NULL)
             P->Prox->Ant = P->Ant;
          if(P->Ant != NULL)
             P->Ant->Prox = P->Prox;
          else
             (*Emprestimos) = P->Prox;
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

    /*
    void Imprime_Acervo(Lista_Acervo *Acervo)
    {
       if(Acervo == NULL)
          printf("Acervo de Livros vazio!");
       else
       {
          while(Acervo)
          {
            printf("\nCodigo: %d, Titulo: %s, Autores: %s, Ano: %s, Area: %s ,Nro Exemplares: %d  ", Acervo->livro.Codigo,
            Acervo->livro.Titulo, Acervo->livro.Autores, Acervo->livro.Ano, Acervo->livro.Area, Acervo->livro.Num_Exemp);

            Acervo = Acervo->Prox;
          }
       }
       getchar();
    }
    */
