#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int x, y;
int M, N;
float diff;
int total_mines = 0;
int mines = 0;
int minefield[30][30];
int blank_minefield[30][30];
int final_minefield[30][30];

int main()
{
    printf("\t\t\t\tMINESWEEPER\n");
    printf("\n");
    difficulty();
    return 0;
}


void difficulty( void )
{
    M = 10; //columna
    N = 10; // fila
    total_mines = k;
    minefield_generator();
    guess();
}



void minefield_generator( void )
{
    int i = 0, j = 0;


    while( j < N )
    {
        while( i < M)
        {
            minefield[i][j] = '#';
            blank_minefield[i][j] = minefield[i][j];
            final_minefield[i][j] = minefield[i][j];
            i++;
        }
        i = 0;
        j++;
    }
    mines = 0;
    while( mines < total_mines )
    {
        i = rand()%(M);
        j = rand()%(N);
        if( minefield[i][j] != '1')
        {
            minefield[i][j] = '1';
            final_minefield[i][j] = minefield[i][j];
            mines++;
        }
    }
    i = 0;
    j = 0;

    while( j < N )
    {
        while( i < M)
        {
            if( minefield[i][j] != '1')
            {
                minefield[i][j] = 0;
            }
            if((minefield[i-1][j-1] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j-1] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i-1][j+1] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j-1] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i][j+1] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            if((minefield[i+1][j+1] == '1') && (minefield[i][j] != '1'))
            {
                minefield[i][j]++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    i = 0;
    j = 0;
}

void print_minefield(void)
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            if( blank_minefield[i][j] == '#')
            {
                printf("|%c|\t", blank_minefield[i][j]);

            }
            else if( minefield[i][j] == 0 )
            {
                blank_minefield[i][j] = ' ';
                printf("|%c|\t", blank_minefield[i][j]);
            }
            else
            {
                printf("|%d|\t", blank_minefield[i][j]);

            }
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}


void guess( void )
{
    int q = 0, i=0, j=0, match=0;
    print_minefield();
    while( j < N )
    {
        while( i < M )
        {
            if(minefield[i][j] == blank_minefield[i][j])
            {
                match++;
            }
            i++;
        }
        i = 0;
        j++;
    }
    if( match == (( M * N ) - total_mines))
    {
        win();
    }
    printf("\nEnter the column value, then a space and the row value: ");
    scanf("%d %d", &x, &y);
    printf("\n");
    FLUSH;
    if( (x >= M) || (x < 0) || (y < 0) || (y >= N) )
    {
        printf("\nPlease enter a value inside the grid\n");
        printf("\n");
        guess();
    }
    if( minefield[x][y] == '1' )
    {
        boom();
    }
    if( blank_minefield[x][y] != '#' )
    {
        printf("\nPlease, try with another value. Duplicated positions are not allowed\n");
        printf("\n");
        guess();
    }

    else
    {
        blank_minefield[x][y] = minefield[x][y];
        if( minefield[x][y] == 0 )
        {
            if( minefield[x-1][y-1] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x-1][y] == 0 )
            {
                blank_minefield[x-1][y] = minefield[x-1][y];
            }
            if( minefield[x][y-1] == 0 )
            {
                blank_minefield[x][y-1] = minefield[x][y-1];
            }
            if( minefield[x-1][y+1] == 0 )
            {
                blank_minefield[x-1][y+1] = minefield[x-1][y+1];
            }
            if( minefield[x+1][y-1] == 0 )
            {
                blank_minefield[x+1][y-1] = minefield[x+1][y-1];
            }
            if( minefield[x+1][y] == 0 )
            {
                blank_minefield[x+1][y] = minefield[x+1][y];
            }
            if( minefield[x][y+1] == 0 )
            {
                blank_minefield[x][y+1] = minefield[x][y+1];
            }
            if( minefield[x+1][y+1] == 0 )
            {
                blank_minefield[x+1][y+1] = minefield[x+1][y+1];
            }
        }
        guess();
    }
}

void boom( void )
{
    print_final_minefield();
    printf("\n\t\tYou hit a mine at %d,%d\n\t\tBOOOOM!", x, y);
    printf("\n");
    play_again();
}

void print_final_minefield( void )
{
    int i = 0, j = 0, z = 0;
    while( z < M )
    {
        if( z == 0 )
        {
            printf("\t");
        }
        printf("|%d|\t", z);
        z++;
    }
    printf("\n\n");

    while( j < N )
    {
        printf("|%d|\t", j);
        while( i < M)
        {
            printf("|%c|\t", final_minefield[i][j]);
            i++;
        }
        printf("\n");
        i = 0;
        j++;
    }
}

void win( void )
{
    printf("\n\n\n\t\t\tYOU WIN!!!!!\n\n\n");
    printf("\n");
    play_again();
}

void play_again( void )
{
    char option[2];
    printf("\n\t\tWanna play again(Y/N)?:");
    printf("\n");
    scanf("%c", &option[0]);
    FLUSH;
    if((option[0] == 'Y') || (option[0] == 'y'))
    {
        difficulty();
    }
    else if( (option[0] == 'N') || (option[0] == 'n'))
    {
        game_over();
    }
    else
    {
        printf("\n\t\tPlease enter either Y or N");
        printf("\n");
        play_again();
    }
}

void game_over( void )
{
    printf("\n\n\t\tGame Over");
    exit(1);
}
