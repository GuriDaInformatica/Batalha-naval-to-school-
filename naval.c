#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#include <commctrl.h>
#include <stdbool.h>


//matrizes 💀
int mapa1[7][7]=
{
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
int mapa2[7][7]=
{
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
int matriz1[7][7] =
{
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};
int matriz2[7][7] =
{
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0}
};

//pontos para finalizar o jogo
int pontosDoJogador1=0, pontosDoJogador2=0;

//muda o valor da matriz int para char
char converterNumeroDaMatriz(int numero) 
{
    switch (numero)
    {
        case 0 : return '~';//agua
            break;
        case 4 : return '#';//barco4
            break;
        case 3 : return '@';//barco3
            break;
        case 2 : return '$';//barco2
            break;
        case 1 : return '%';//barco1
            break;
        case 5 : return 'X';//acertou
            break;
        case 6 : return 'O';//errou
            break;
    }
    return 0;
}

//imprime o tabuleiro na tela
void tabuleiroMatrizes(int tabela[7][7])
{   
    //system("cls");
    printf("\t  | A | B | C | D | E | F | G |\n");
    printf("\t-------------------------------\n");
    for(int i=0;i<7;i++)
    {

        printf("\t%d | ", i+1);
        
        for(int j=0;j<7;j++)
        {
            printf("%c", converterNumeroDaMatriz(tabela[i][j]));
            printf(" | ");
            if(j==6)
            printf("\n");
        }
        printf("\t-------------------------------\n");
    }
}
//funções para definir
int switchCaseX(char navio[3])
{
    int x;

    switch(navio[0])
    {
        case '1' : x=0;
            break;
        case '2' : x=1;
            break;
        case '3' : x=2;
            break;
        case '4' : x=3;
            break;
        case '5' : x=4;
            break;
        case '6' : x=5;
            break;
        case '7' : x=6;
            break;
        default:printf("\ninvalido");
    }


    return x;
}
int switchCaseY(char navio[3])
{   
    int y;

    switch(navio[1])
    {
        case 'A' : y=0;
            break;
        case 'B' : y=1;
            break;
        case 'C' : y=2;
            break;
        case 'D' : y=3;
            break;
        case 'E' : y=4;
            break;
        case 'F' : y=5;
            break;
        case 'G' : y=6;
            break;
        case 'a' : y=0;
            break;
        case 'b' : y=1;
            break;
        case 'c' : y=2;
            break;
        case 'd' : y=3;
            break;
        case 'e' : y=4;
            break;
        case 'f' : y=5;
            break;
        case 'g' : y=6;
            break;
        
        default:printf("\ninvalido");
    }

    return y;
}

//altera a matriz para saber se acertou ou errou
bool jogar(int rodada)
{
    char posicao[3];
    int x,y;

    if (rodada%2==0)
    {
        printf("digite uma coordenada: ");
        scanf("%2s", posicao);

        x = switchCaseX(posicao);
        y = switchCaseY(posicao);

        if(mapa2[x][y]==5 || mapa2[x][y]==6)
        {
            printf("essa coordenada ja foi escolhida\n");
            system("pause");
            return FALSE;
        }
        else
        {
            for(int a=0;a<7;a++)
            {
                if((0<a)&&(a<5))
                {
                    if(matriz2[x][y]==a)
                        {
                            mapa2[x][y]=5;
                            pontosDoJogador1= pontosDoJogador1+1;
                            printf("ACERTOU!! joga dnv\n");
                            system("pause");
                            return FALSE;
                        }
                }
                if(4<a)
                {
                    if(matriz2[x][y]==a)
                        {
                            mapa2[x][y]=6;                    
                        }
                }
                    if(a==0)
                    {
                        if(matriz2[x][y]==a)
                        {
                            mapa2[x][y]=6;
                        }
                }
            }
        }
  


    }
    else
    {
        printf("digite uma coordenada: ");
        scanf("%2s", posicao);

        x = switchCaseX(posicao);
        y = switchCaseY(posicao);

        if(mapa1[x][y]==5||mapa1[x][y]==6)
        {
            printf("essa coordenada ja foi escolhida\n");
            system("pause");
            return FALSE;
        }
        else
        {
            for(int a=0;a<7;a++)
            {        
                if((0<a)&&(a<5))
                {
                    if(matriz1[x][y]==a)
                    {
                        mapa1[x][y]=5;
                        pontosDoJogador2= pontosDoJogador2+1;
                        printf("ACERTOU!! joga dnv\n");
                        system("pause");
                        return FALSE;
                    }
                }
                if(4<a)
                {
                    if(matriz1[x][y]==a)
                    {
                        mapa1[x][y]=6;
                    }
                }
                if(a==0)
                {
                    if(matriz1[x][y]==a)
                    {
                        mapa1[x][y]=6;
                    }
                }   
            } 
        }
    }
    return TRUE;
}
//funções para colocar os navios na matriz
void botaPortaAvioes(int jogador[7][7])
{
    char portaAvioes[3];
    int direcao;
    
    printf("posicione o porta-avioes (4x1)\n");
    scanf("%2s", portaAvioes);

    int x = switchCaseX(portaAvioes);
    int y = switchCaseY(portaAvioes);
    
    printf("vc quer o barco de lado ou em pe\n1-pe\n2-deitado\n");
    scanf("%d", &direcao);
    
    if(direcao==1)
    {
        for(int i=0;i<4;i++)
            jogador[x+i][y]= 4;
    }
    else
    {
        for(int i=0;i<4;i++)
            jogador[x][y+i]= 4;
    }

}
void botaCruzador(int jogador[7][7])
{
    char cruzador[3];
    int direcao;
    
    printf("posicione o cruzador (3x1)\n");
    scanf("%2s", cruzador);

    int x = switchCaseX(cruzador);
    int y = switchCaseY(cruzador);
    
    printf("vc quer o barco de lado ou em pe\n1-pe\n2-deitado\n");
    scanf("%d", &direcao);
    
    if(direcao==1)
    {
        for(int i=0;i<3;i++)
            jogador[x+i][y]= 3;
    }
    else
    {
        for(int i=0;i<3;i++)
            jogador[x][y+i]= 3;
    }
}
void botaSubmarino(int jogador[7][7])
{
    char submarino[3];
    int direcao;
    
    printf("posicione o submarino (2x1)\n");
    scanf("%2s", submarino);

    int x = switchCaseX(submarino);
    int y = switchCaseY(submarino);
    
    printf("vc quer o barco de lado ou em pe\n1-pe\n2-deitado\n");
    scanf("%d", &direcao);
    
    if(direcao==1)
    {
        for(int i=0;i<2;i++)
            jogador[x+i][y]= 2;
    }
    else
    {
        for(int i=0;i<2;i++)
            jogador[x][y+i]= 2;
    }
}
void botaBote(int jogador[7][7])
{
    char bote[3];
    
    printf("posicione o bote (1x1)\n");
    scanf("%2s", bote);

    int x = switchCaseX(bote);
    int y = switchCaseY(bote);
    
    jogador[x][y]= 1;

}

//verifica se ha vencedor
bool acabouOjogo()
{
    system("cls");
    if(pontosDoJogador1 == 13)
    {
        printf("fim de jogo\n");
        printf("jogador 1 ganhou\n");
        return FALSE;
    }
    if(pontosDoJogador2 == 13)
    {
        printf("fim de jogo\n");
        printf("jogador 2 ganhou\n");
        return FALSE;
    }
    return TRUE;
}

//int main
int main()
{   

    for(int i=0; i<6;i++)
    {
        printf("jogador 1, posicione os barcos:\n");
        if(i==0){tabuleiroMatrizes(matriz1); botaPortaAvioes(matriz1);system("cls");}
        if(i==1){tabuleiroMatrizes(matriz1); botaCruzador(matriz1);system("cls");}
        if(i==2){tabuleiroMatrizes(matriz1); botaSubmarino(matriz1);system("cls");}
        if(i==3){tabuleiroMatrizes(matriz1); botaSubmarino(matriz1);system("cls");}
        if(i==4){tabuleiroMatrizes(matriz1); botaBote(matriz1);system("cls");}
        if(i==5){tabuleiroMatrizes(matriz1); botaBote(matriz1);system("cls");}
    }
    
    for(int i=0; i<6;i++)
    {
        printf("jogador 2, posicione os barcos:\n");
        if(i==0){tabuleiroMatrizes(matriz2); botaPortaAvioes(matriz2);system("cls");}
        if(i==1){tabuleiroMatrizes(matriz2); botaCruzador(matriz2);system("cls");}
        if(i==2){tabuleiroMatrizes(matriz2); botaSubmarino(matriz2);system("cls");}
        if(i==3){tabuleiroMatrizes(matriz2); botaSubmarino(matriz2);system("cls");}
        if(i==4){tabuleiroMatrizes(matriz2); botaBote(matriz2);system("cls");}
        if(i==5){tabuleiroMatrizes(matriz2); botaBote(matriz2);system("cls");}
    }

    for(int rodada=0; rodada<100;rodada++)
    {    
        if(rodada%2==0)
        {
            system("cls");
            printf("jogador 1, faca sua jogada\n");
            tabuleiroMatrizes(mapa1);
            printf("\n");
            tabuleiroMatrizes(mapa2);
            printf("jogador 1, acertos: %d\njogador 2, acertos: %d\n\n",pontosDoJogador1, pontosDoJogador2);
            if(!jogar(rodada))
            {
                rodada--;
            }
            if(!acabouOjogo())
            {
                printf("\tBarcos do vencedor:\n");
                tabuleiroMatrizes(matriz1);
                break;
            }
            
        }
        else
        {   
            system("cls");
            
            printf("jogador 2, faca sua jogada\n");
            tabuleiroMatrizes(mapa1);
            printf("\n");
            tabuleiroMatrizes(mapa2);
            printf("jogador 1, acertos: %d\njogador 2, acertos: %d\n\n",pontosDoJogador1, pontosDoJogador2);

            if(!jogar(rodada))
            {
                rodada--;
            }
            if(!acabouOjogo())
            {
            
                printf("\tBarcos do vencedor:\n");
                tabuleiroMatrizes(matriz2);
                break;
            }
        }
    }
    return 0;
}