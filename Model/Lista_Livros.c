#include "Lista_Livros.h"

    void Iniciliza_Acervo()
    {
        Acervo = NULL;
    }


    int Consulta_Acervo(int Codigo)
    {

        Lista_Acervo *P;
        P = Acervo;

        while(P != NULL)
        {
            if(P->livro.Codigo == Codigo)
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

    Lista_Acervo *Retorna_Elemento(int Codigo)
    {
    int achou = 0;

    while((Acervo != NULL) && (achou == 0))
    {
      if(Acervo->livro.Codigo == Codigo)
         achou = 1;
      else
         Acervo = Acervo->Prox;
    }
    return (Acervo);
}

    int Insere_Acervo(Livro L)
    {
        Lista_Acervo *New;

        if(!Consulta_Acervo(L.Codigo))
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


    int Remover_Livro(int Codigo)
    {
       Lista_Acervo *P;
       int achou = 0;

       P = Retorna_Elemento(Codigo);

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

    void Imprime_Acervo()
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
