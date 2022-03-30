void filewrite(char *name, int moves, int lives)
{
    struct player P;
    strcpy(P.name,name);
    P.moves=moves;
    P.life=lives;
    FILE *fo;
    fo = fopen ("hscore.txt", "a");
    if (fo == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        system("pause");
        exit(0);
    }
    fwrite(&P, sizeof(struct player), 1, fo);
    fclose(fo);
}

void leaderboard()
{
    system("cls");
    FILE *inf;
    int i, j, N=0;
    struct player inp[50];

    inf = fopen ("hscore.txt", "r");

    if (inf == NULL)
    {
       fprintf(stderr, "\nError to open the file\n");
       exit (0);
    }

    while(fread(&inp[i], sizeof(struct player), 1, inf))
        N++;

    struct player temp;

    for (i=0; i<N-1; i++)
    {
        for (j=0; j<N-i-1; j++)
        {
            if ( inp[j].life<inp[j+1].life || inp[j].life<inp[j+1].life && inp[j].moves<inp[j+1].moves )
            {
                temp = inp[j];
                inp[j] = inp[j + 1];
                inp[j + 1] = temp;
            }
        }
    }
    printf("\t\tLEADERBOARD\n\t\t-----------\n\n\n\tS.NO          Player name   Lives   Moves");
    for(i=0; i<N; i++)
        printf("\n\n\t%4d %20s %7d %7d",i+1,inp[i].name,inp[i].life,inp[i].moves);
    fclose(inf);
    printf("\n\n\n");
    system("pause");
}
