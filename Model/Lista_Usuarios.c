#include "Lista_Usuarios.h"
#include <string.h>

    void Iniciliza_Usuario()
    {
        Users = NULL;
    }


    int Consulta_Usuario(char Email[])
    {
        Lista_Usuario *P;
        P = Users;

        while(P != NULL)
        {
            if( strcmp(P->Users.Email, Email) == 0)
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

    Lista_Usuario *Retorna_Usuario(char Email[])
    {
    int achou = 0;

    Lista_Usuario *LAux = Users;

    while((LAux != NULL) && (achou != 1))
    {
      if(strcmp(LAux->Users.Email, Email) == 0)
      {
          achou = 1;
      }
      else
      {
          LAux = LAux->Prox;
      }
    }
    return (LAux);
}

    int Insere_Usuario(Usuario U)
    {
        Lista_Usuario *New;

        if(!Consulta_Usuario(U.Email))
        {
              New = ((Lista_Usuario*)malloc(sizeof(Lista_Usuario)));
              New->Users = U;
              New->Ant = NULL;
              New->Prox = Users;
              if (Users != NULL)
              {
                 Users->Ant = New;
              }
              Users = New;
              return(1);
       }
       else
          return (0);
    }


    int Remover_Usuario(char Email[])
    {
       Lista_Usuario *P;
       int achou = 0;

       P = Retorna_Usuario(Email);

       if(P != NULL)
       {
          if(P->Prox != NULL)
             P->Prox->Ant = P->Ant;
          if(P->Ant != NULL)
             P->Ant->Prox = P->Prox;
          else
             Users = P->Prox;
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

    void Imprime_Usuarios()
    {
       if(Users == NULL)
          printf("Lista de Usuarios vazia!");
       else
       {
          while(Users)
          {
            printf("\nNome: %s, Data Nasc: %s, Area: %s, Email: %s \n", Users->Users.Nome, Users->Users.Data_Nasc, Users->Users.Area, Users->Users.Email);

            Users = Users->Prox;
          }
       }
       getchar();
    }
