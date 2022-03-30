#include "321go.h"
#include "requisites for game.h"
#include "player.h"

void game(char *name)
{
    int maptut[8][8];
    int i, j, k, lives, moves, top, pi, pj, flag;
    char firstlet=name[0];

    STARTOVER:
    lives=0;
    moves=0;
    top=-1;
    pi=0;
    pj=0;
    flag=0;
    readysetgo();
    mapget(maptut,++top,&pi,&pj);
    while(!qfull(lives)&&!overflow(top))
    {
        system("cls");
        printf("Lives: %d\t\t\t\tMoves: %d",3-lives ,moves);
        printf("\n\n\n\n\n\n\t\t");
        for(i=0; i<=9; i++)
        {
            printf("--");
        }
        printf("\n\t\t");
        for(i=0; i<8; i++)
        {
            for(k=0; k<2; k++)
            {
                printf("| ");
                for(j=0; j<8; j++)
                {
                    if(maptut[i][j]==0)
                        printf("%c%c",176,176);
                    else if(maptut[i][j]==1)
                        printf("  ");
                    else if(maptut[i][j]==2)
                        printf("%c%c",207,207);
                    else if(maptut[i][j]==3)
                    {
                        if(k==0&&!flag)
                            printf("%c ",firstlet);
                        else
                            printf("  ");
                    }
                    else if(maptut[i][j]==4)
                    {
                        if(!flag)
                        {
                            if(k==0)
                                printf("XO");
                            else
                                printf("OX");
                        }
                        else
                            printf("%c%c",firstlet,firstlet);
                    }
                }
                printf(" |");
                printf("\n\t\t");
            }
        }
        for(i=0; i<=9; i++)
        {
            printf("--");
        }
        if(flag&&!overflow(++top))
        {
            nextlevel(top);
            pi=0;
            pj=0;
            flag=0;
            mapget(maptut,top,&pi,&pj);
        }
        else if(overflow(top))
        {
            printf("\n\n\t\tCongrats you won with %d lives and %d moves\n\n",3-lives,moves);
            system("pause");
        }
        char dir=getch();
        switch(dir)
        {
            case 'W':
            case 'w':
                if(bordch(pi-1,pj)&&(maptut[pi-1][pj]==1||maptut[pi-1][pj]==2||maptut[pi-1][pj]==4))
                {
                    moves++;
                    if(maptut[pi-1][pj]!=4&&maptut[pi-1][pj]!=2)
                    {
                        maptut[pi][pj]=1;
                        pi-=1;
                        maptut[pi][pj]=3;
                    }
                    else if(maptut[pi-1][pj]==4)
                    {
                        flag++;
                    }
                    else
                        enq(&lives);
                }
                break;
            case 'A':
            case 'a':
                if(bordch(pi,pj-1)&&(maptut[pi][pj-1]==1||maptut[pi][pj-1]==2||maptut[pi][pj-1]==4))
                {
                    moves++;
                    if(maptut[pi][pj-1]!=4&&maptut[pi][pj-1]!=2)
                    {
                        maptut[pi][pj]=1;
                        pj-=1;
                        maptut[pi][pj]=3;
                    }
                    else if(maptut[pi][pj-1]==4)
                    {flag++;}
                    else
                        enq(&lives);
                }
                break;
            case 'S':
            case 's':
                if(bordch(pi+1,pj)&&(maptut[pi+1][pj]==1||maptut[pi+1][pj]==2||maptut[pi+1][pj]==4))
                {
                    moves++;
                    if(maptut[pi+1][pj]!=4&&maptut[pi+1][pj]!=2)
                    {
                        maptut[pi][pj]=1;
                        pi+=1;
                        maptut[pi][pj]=3;
                    }
                    else if(maptut[pi+1][pj]==4)
                    {flag++;}
                    else
                        enq(&lives);
                }
                break;
            case 'D':
            case 'd':
                if(bordch(pi,pj+1)&&(maptut[pi][pj+1]==1||maptut[pi][pj+1]==2||maptut[pi][pj+1]==4))
                {
                    moves++;
                    if(maptut[pi][pj+1]!=4&&maptut[pi][pj+1]!=2)
                    {
                        maptut[pi][pj]=1;
                        pj+=1;
                        maptut[pi][pj]=3;
                    }
                    else if(maptut[pi][pj+1]==4)
                    {flag++;}
                    else
                        enq(&lives);
                }
                break;
        }
    }
    if(qfull(lives))
    {
        if(lostrepeat())
            goto STARTOVER;
    }
    filewrite(name, 3-moves, lives);
}
