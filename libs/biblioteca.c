/*  biblioteca generica para todos os tipos de funçoes de auxilio

    Arquivo .c Para implementaçao das funcoes

    Programador: Everton Rogerio Spohr.
    Ano: 2012.
    Compilador: MinGW.

    Funcao da Biblioteca: Generica(varias funcoes).


*/
// INCLUDES =======================================================================================


#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

const char ChRest[] = "abcdefghijklmnopqrstuvwzyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

typedef struct STR{

    char text[255];
}str;

// TIPOS ENUMERADOS ================================================================================

enum DOS_COLORS{
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
    LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
    LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE };



// IMPLEMENTACAO DAS FUNCOES =======================================================================


// Funcao para posicionamento na tela.
void gotoxy(int x, int y)
{

HANDLE hOut;
COORD Position;

hOut = GetStdHandle(STD_OUTPUT_HANDLE);

Position.X = x;
Position.Y = y;
SetConsoleCursorPosition(hOut,Position);
}
//===========================================================================================

void clrscr()
{
    system("cls");  // limpa a tela
}

//==========================================================================================

void textcolor(int iColor)  // altera a cor do texto
{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

//============================================================================================

void backcolor (int iColor) // altera a cor do fundo

{
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x000F;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

//==========================================================================================

void center(char *msg, int coluna){ // centraliza uma msg na tela

    int tam;

    tam = 40 -(strlen(msg) / 2);

    gotoxy(tam, coluna); puts(msg);

}

//=====================================================================================

void clreol(){ // limpa uma linha

    printf("                                                      ");

}


//--<-PRINT-C-XY->--------------------------------------------------------------------------------
    void printchrxy(short x, short y, const char chr)
    {
      gotoxy(x,y); printf("%c",chr);
    }
  //------------------------------------------------------------------------------------------------


  //--<-TABLE-BORDER->------------------------------------------------------------------------------
    void TableBorder(int sx, int sy, int ex, int ey, int b, int tColor, int cabecalho, int rodape)
    {
      //setBKcolor(black,tColor);
        textcolor(tColor);
        backcolor(0);
    unsigned short i,j;

      char bd[7];
      switch (b)
      {
        case 1:bd[1] = 218; bd[2] = 191; bd[3] = 192; bd[4] = 217; bd[5] = 196; bd[6] = 179; break;
        case 2:bd[1] = 201; bd[2] = 187; bd[3] = 200; bd[4] = 188; bd[5] = 205; bd[6] = 186; break;
      }
      printchrxy(sx,sy,bd[1]); printchrxy(ex,sy,bd[2]);
      for(i = sx+1; i < ex; i++, printchrxy(i-1,sy,bd[5]), printchrxy(i-1,ey,bd[5]));
      for(j = sy+1; j < ey; j++, printchrxy(sx,j-1,bd[6]), printchrxy(ex,j-1,bd[6]));
      printchrxy(sx,ey,bd[3]); printchrxy(ex,ey,bd[4]);
      if(cabecalho)
      {
        printchrxy(sx,sy+2,204);   printchrxy(ex,sy+2,185);
        for(i = sx; i < ex-1; i++, printchrxy(i,sy+2,205));
      }
      if(rodape)
      {
        printchrxy(sx,ey-2,204);   printchrxy(ex,ey-2,185);
        for( i = sx; i < ex-1; i++, printchrxy(i,ey-2,205));
      }

    gotoxy(0,0);

    }

//--<-CBAR->--------------------------------------------------------------------------------------
    void cBar(short sx, short ex, short y, short Color)
    {
     unsigned short i;
      backcolor(Color);
      for(i = sx; i <= ex; i++ ,gotoxy(i-1,y), printf("%c",32));
      backcolor(1);
    }
  //------------------------------------------------------------------------------------------------

//--<-Titulo-Simples->----------------------------------------------------------------------------
    void TituloSimples(const char Titulo[], short bColor, short tColor)
    {
      cBar(1,78,1,bColor);
      backcolor(bColor);
      textcolor(tColor);
      gotoxy(((80-strlen(Titulo)+1)/2), 1); printf("%s",Titulo);
      backcolor(0);
      textcolor(15);
    }

int compchar(char c, const char string[]){

    int x = 0;
    int i;
    for(i = 0; i < strlen(string); i++){
        if(c == string[i]){
            x = 1;
            break;
        }
    }
    return x;
}


int pegastring(int x, int y, int tam, str *string, const char ch[]){

// x e y sao cordenadas do gotoxy, tam é o tamanho pra restringir
// const char ch é os caracteres que poderao ser iseridos :D

    string->text[0] = '\0';
    int k,pos = 0;

    do{
        gotoxy(x,y); printf("%s ", string->text);
        gotoxy(x+pos, y);
        k = getch();
        if(k == 224 || k == 0){
            k = getch();

        }else{
            if(k == 8 && pos != 0){
                string->text[strlen(string->text) - 1] = '\0';
                pos--;

            }else{
                if(pos != tam && compchar((char)k, ch)){
                    string->text[pos] = (char)k;
                    pos++;
                    string->text[pos] = '\0';
                }
            }
        }


    }while((k != 13)&&( k != 27));

    return k;
}

