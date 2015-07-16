#include "ModelConfig.h"
#include <stdio.h>


    void Salvar_Config()
    {
        FILE *Arquivo;
        Arquivo = fopen("config.cfg","w");   /* Arquivo ASCII, para escrita */

        if(!Arquivo)
        {
           printf( "Erro na abertura do arquivo");
        }
        else
        {
             fprintf(Arquivo, "%f", Valor_Multa);
        }
        fclose(Arquivo);
    }

void Ler_Config()
{
	FILE *Arquivo;
    Arquivo = fopen("config.cfg","r");

	if(Arquivo == NULL)
    {
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
	else
    {
        while( !feof(Arquivo) )
        {
            fscanf(Arquivo,"%f", &Valor_Multa);
        }
    }
	fclose(Arquivo);
}
