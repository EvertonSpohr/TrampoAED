/*
    Biblioteca para validaçoes!

    Esta biblioteca contem as validacoes de telefone, nome ....

    Autor: Everton R. Spohr

*/
//==========================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

//=========================================================================================


int verifica_nome(char *nome){

    char num[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int i = 0, count;// num_numeros = 0; nao utilizado
    while( i != strlen(nome)){

        for (count = 0; count != strlen(nome); count++ )
        {
            if ( nome[i] == num[count])
            {
                return -1;
                break; // se houver um numero apenas jah nao eh valido o nome
            }
        }
        i++;
    }
    return 0;
}

//==============================================================================================

int verifica_telefone(char fone[30]){


    int Testar2;
    int i = 0;
    int cont = 0;

   for (i = 0; i < strlen(fone); i++)
    {
        Testar2 = (int)fone[i];
        if((Testar2 > 47) && (Testar2 < 58)){  // verifica se ah apenas numeros

        }else{
            cont++;
        }
    }
    if(cont != 0){
        return -1;
    }else{
        return 0;
    }

}

//=================================================================================================

int verifica_email(char Testar[100]){

    int cont = 0;
    int Testar2, i;

    for (i = 0; i < strlen(Testar); i++){
        Testar2 = (int)Testar[i];
        if(Testar2 == 64){ // verifica se contem o @
            cont++;
        }
    }
    if(cont != 1){
        return -1;
    }else{
        return 0;
    }
}
//=========================================================================================================

int verifica_aniversario(char niver[15]){

    if((strlen(niver) > 10)){
        return -1;
    }else if((strlen(niver) <= 9)){
        return -1;
    }

    if(((int)niver[2] != 47) || ((int)niver[5] != 47)){
        return -1;
    }else if( ((int)niver[0] < 48) && ((int)niver[1] > 57) && ((int)niver[3] < 48) && ((int)niver[4] > 57)){
        return -1;
    }else if(((int)niver[6] < 48) && ((int)niver[7] > 57) && ((int)niver[8] < 48) && ((int)niver[9] > 57)){
        return -1;
    }else{
        return 0;
    }
}

//=======================================================================================================

int pega_senha(char *pass, int x) // x = tamanha da senha
{
    char caracter; //pass[6];//Definido o tamanho da senha como 20.
    int count = 0;//Contador para posicoes na string pass.
    do{
        fflush(stdin);
        caracter = getch();//Recebe caracter por caracter
        if ((int)caracter == 13) //Enter
        {
            count++;
            break;
        }
        if((int)caracter != 13 && (int)caracter != 8)
        {
            pass[count] = caracter;
            printf("%c", 1);
            count++;
        }
        else if((int)caracter == 8) //Backspace
        {
            printf("\b \b");//Anda 1 posicao na tela e limpa o caracter digitado
            if (count > 0) count--;
        }
        if((int)caracter == 27){
            pass[0] = '\0';
            break;
        }
        if(count == x){ // para quando a senha tiver 5 caracteres
            break;
        }


    }while ((int)caracter != 13 || count <= x);

    getch();
    pass[x] = '\0';

    return 0;
}
//------------------------------------------------------------------------------
int pega_cod(char *pass) // x = tamanha da senha
{
    int x = 5;
    char caracter; //pass[6];//Definido o tamanho da senha como 20.
    int count = 0;//Contador para posicoes na string pass.
    do{
        fflush(stdin);
        caracter = getch( );//Recebe caracter por caracter
        if ((int)caracter == 13) //Enter
        {
            count++;
            break;
        }
        if((int)caracter != 13 && (int)caracter != 8)
        {
            if((int)caracter >= 48 && (int)caracter <= 57){

                if(count == 3){
                    pass[3] = '-';
                    printf("%c", '-');
                    count++;
                }

                pass[count] = caracter;
                printf("%c", caracter);
                count++;

            }
        }

        else if((int)caracter == 8) //Backspace
        {
            printf("\b \b");//Anda 1 posicao na tela e limpa o caracter digitado
            if (count > 0) count--;
        }
        if((int)caracter == 27){
            pass[0] = '\0';
            break;
        }
        if(count == x){ // para quando a senha tiver 5 caracteres
            break;
        }


    }while ((int)caracter != 13 || count <= x);

    getch();
    pass[x] = '\0';

    return 0;
}

//==============================================================================

int pega_cod_ger(char *pass) // x = tamanha da senha
{
    int x = 4;
    char caracter; //pass[6];//Definido o tamanho da senha como 20.
    int count = 0;//Contador para posicoes na string pass.
    do{
        fflush(stdin);
        caracter = getch( );//Recebe caracter por caracter
        if ((int)caracter == 13) //Enter
        {
            count++;
            break;
        }
        if((int)caracter != 13 && (int)caracter != 8)
        {
            if((int)caracter >= 48 && (int)caracter <= 57){

                pass[count] = caracter;
                printf("%c", caracter);
                count++;

            }
        }

        else if((int)caracter == 8) //Backspace
        {
            printf("\b \b");//Anda 1 posicao na tela e limpa o caracter digitado
            if (count > 0) count--;
        }
        if((int)caracter == 27){
            pass[0] = '\0';
            break;
        }
        if(count == x){ // para quando a senha tiver 5 caracteres
            break;
        }


    }while ((int)caracter != 13 || count <= x);

    getch();
    pass[x] = '\0';

    return 0;
}
