#include <time.h>
#include "maps.h"

int overflow(int top)
{
    if(top==5)
        return 1;
    else
        return 0;
}

void pop(int *top)
{
    while(*top)
        (*top)--;
}

void deq(int f, int r)
{
    while(f==r)
    {
        f++;
        if(f==r)
        {
            f=0;
            r=0;
        }
    }
}

int qfull(int r)
{
    if(r==3)
        return 1;
    else
        return 0;
}

void enq(int *lives)
{
    printf("\n\n\n\t\tSorry you hit an enemy\n\t\tNo. of lives remaining: %d\n\n",3-*lives);
    (*lives)++;
    if(!qfull(*lives))
        system("pause");
    else
    {
        printf("You lost the game!!");
        getch();
    }
}

void nextlevel(int n)
{
    srand(time(0));
    int i;
    printf("\n\nYou completed level %d. \nMoving on to the next level",n);
    Sleep(1000);
    for(i=0; i<rand()%6; i++)
    {
        Sleep(500);
        printf(" .");
    }
}

int bordch(int X, int Y)
{
    if(X<0||Y<0||X>=8||Y>=8)
        return 0;
    else
        return 1;
}

void mapget(int mapset[8][8], int nth, int *pi, int *pj)
{
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            mapset[i][j]=maps[nth][i][j];
            if(maps[nth][i][j]==3)
            {
                *pi=i;
                *pj=j;
            }
        }
    }
}

int lostrepeat()
{
    system("cls");
    printf("\n\nIf you want to start over, press S/s");
    char repetition=getch();
    if(repetition=='S'||repetition=='s')
        return 1;
    else
        return 0;
}
