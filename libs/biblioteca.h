
#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

typedef struct STR{
    char text[255];
}str;

//const char ChRest[] = "abcdefghijklmnopqrstuvwzyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";


//CABECALHOS ==============================================================================

void gotoxy(int x, int y);
/**
    Posiciona o cursor nas cordenadas xy;
    @param x cordenada de X na tela
    @param y cordenada de Y na tela
*/
void clrscr();
/**
    Limpa a tela
*/
void textcolor(int iColor);
/**
    Adiciona cor a letra
    @param iColor numero para a cor desejada
*/
void backcolor (int iColor);
/**
    Adiciona cor ao fundo
    @param iColor numero da cor desejada
*/
void line();
/**
    desenha uma linha tracejada na tela
*/
void center(char *msg, int coluna);
/**
    Centraliza uma mesagem na tela
    @param msg string contendo a mensagem a ser centralizada
    @param coluna - coluna onde sera escrita a msg;
*/
void clreol();
/**
    limpa uma linha
*/
void printchrxy(short x, short y, const char chr);
/**
    une o printf com o gotoxy mas para imprimir um char
    @param x - cordenada de X
    @param y - cordenada de Y
    @param chr - char a ser impresso
*/
void TableBorder(int sx, int sy, int ex, int ey, int b, int tColor, int cabecalho, int rodape);
/**
    Desenha uma caixa(borda) na tela
    @param sx - posicao inicial de X
    @param sy - posicao inicial de Y
    @param ex - posicao final de X
    @param ey - posicao final de Y
    @param b - tipo de borda // 1 simples // 2 dupla
    @param tColor - cor da borda
    @param cabecalho - se deseja inserir cabecalho a caixa //1 sim 0 nao
    @param rodape - se deseja inserir rodepe a caixa // 1 sim 0 nao
*/
void cBar(short sx, short ex, short y, short Color);
/**
    cria barra colorida na tela
    @param sx - posiciao inicial de x
    @param ex - posicao final de x
    @param y - posicao de y
    @param Color - cor da barra
*/
void TituloSimples(const char Titulo[], short bColor, short tColor);
/**
    Adiciona uma msg e centraliza ela na tela
    @param Titulo[] - string com a msg
    @param bColor - cor do fundo
    @param tColor -  cor da letra
*/
int compchar(char c, const char string[]);
/**
    Compara um caracter com outro
    @param c - caracter a ser comparado
    @param string - string a ser comparada
*/
int pegastring(int x, int y, int tam, str *string, const char ch[]);
/**
    Le uma string da tela e faz as restricoes de tamanha e de caracteres
    @param x - posiciona cursor em c
    @param y - posiciona cursor em y
    @param tamanho - restringe o tamanho da string
    @param str* string - ponteiro para string que esta contida na struct str que tem o elem char text[]
    @param ch - define o conjunto de elementos que e posivel ler
*/

//FIM ======================================================================================

#endif
