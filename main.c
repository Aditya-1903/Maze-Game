#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Name.h"
#include "map printing.h"
#include "Regulation.h"
#include "hscore.h"

void leaderboard();

int main()
{
    int choice;

    MENU:
    system("cls");
    printf("\n\n\n*****************************************************************\n PACMAN \n*****************************************************************\n\n\n");
    printf("\n\n MENU\n\n");
    printf("\n 1. ABOUT PACMAN\n");
    printf("\n 2. RULES\n");
    printf("\n 3. PLAY!\n");
    printf("\n 4. VIEW LEADERBOARD\n");
    printf("\n 5. EXIT\n");

    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            about();
            break;
        case 2:
            rules();
            break;
        case 3:
            {
                char name[20];
                nameIP(name);
                game(name);
            }
            break;
        case 4:
            leaderboard();
            break;
        case 5:
            exit(0);
        default: system("cls");
            printf("\n\n\n\t Sorry wrong option\n\n");
            system("pause");
    }
    goto MENU;
    return 0;
}
