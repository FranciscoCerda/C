#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() //"MAIN" FUNCTION
{
    system("color 0A"); //HACKER MODE
    char word[60];
    options();
	return 0;
}

void options() //"OPTIONS" FUNCTION, SHOWS THE MENU THAT ALLOWS ACCESS TO THE GAME MODES
{
    system("cls"); //FOR CLEAR SCREEN
	int option;
	do
    {
		printf("\n\t\t\t\tTHE HANGMAN GAME\n\n");
		printf(" How do you like to play?\n\n");
		printf(" 1. Random Word\n");
		printf(" 2. Write a Word\n\n");
		printf(" Choose an Option: ");
		scanf("%i",&option);
		fflush(stdin);
    }
	while(option<1 || option>2);

	if (option==1) startGame1(); // If choose option 1, open gamemode 1 (HARDMODE)
	if (option==2) startGame2(); // If choose option 2, open gamemode 2

}

void startGame1 () //GAME VARIATION #1 FOR A RANDOM WORD
{
    system("cls"); //FOR CLEAR SCREEN

    /* MODIFIABLE LIST OF WORDS */
    char *chain[] = {"DOG", "PUPPY", "TURTLE", "RABBIT", "PARROT", "CAT", "DUCK", "MOUSE", "FISH", "HAMSTER",
                    "GERMANY", "FINLAND", "FRANCE", "MEXICO", "ITALY", "SPAIN", "CANADA", "JAPAN", "SWITZERLAND", "SWEDEN",
                    "AVOCADO", "WATERMELON", "BANANA", "CHERRY", "LEMON", "APPLE", "PINEAPPLE", "COCONUT", "STRAWBERRY", "GRAPE",
                    "RESTROOM", "KITCHEN", "MARKET", "REFRIGERATOR", "TRAVEL", "SUNFLOWER", "CLOTHES", "TRUCK", "TACOS", "GLASS",
                    "SUN", "BEACH", "HEADPHONES", "MONITOR", "SHOES", "TREE", "ROCK", "WATCH", "KEYS", "KNIFE"};
    char rep[100], temporal[100];
    char pal;
    int lg, i, j, strt, crrct = 0, temp = 0, chances = 7; //DEFINING THE VARIABLES TO USE AND THE NUMBER OF TRIES
    int repetido = 0, win = 0;
    srand(time(NULL));
    int num = rand();
    num = rand()%50; //A RANDOM NUMBER IS GENERATED BETWEEN 1 AND 50

    lg = 0;
    strt = 0;
    j = 0;

    rep[0] = ' ';
    rep[1] = '\0';


    do
    {
        system("cls");
        temp=0;
        hang(chances);

            if(strt == 0)
         {
             for(i=0;i<strlen(chain[num]);i++)
                {
                  if(chain[num][i] == ' ')
                    {
                        temporal[i] = ' ';
                        lg++;
                    }
                     else
                    {
                        temporal[i] = '_';
                        lg++;
                    }
                 }
          }

      strt = 1;
      temporal[lg] = '\0';

        for(i = 0; i < strlen(rep); i++)
            {
               if(rep[i] == pal)
               {
                repetido = 1;
                break;
                }
                 else
                {
                repetido = 0;
                }
             }

        if(repetido == 0)
            {
                for(i=0;i<strlen(chain[num]);i++)
                {
                if(chain[num][i] == pal)
                    {
                      temporal[i] = pal;
                      crrct++;
                      temp=1;
                    }
                }
            }

        if(repetido == 0)
            {
                if(temp == 0)
                     {
                       chances = chances - 1;
                     }
            }

        printf("\n");

        for(i=0;i<strlen(temporal);i++)
            {
             printf(" %c ",temporal[i]);
            }

        printf("\n");

        if(strcmp(chain[num],temporal) == 0)
            {
                win = 1;
                break;
            }

        printf("\nAccepted Letters: %d\n",crrct);
        printf("\nRemaining Chances: %d\n",chances);


        rep[j] = pal;
        j++;

        if (chances==0)
            {
               break;
            }

        printf("\nWrite a letter: ");
        scanf("\n%c",&pal);

    }

    while(chances != 0);

    if(win)
        {
        printf("\n\nCONGRATULATIONS!!\n");
        printf("\nYOU WIN!!!\n");
        }
    else
        {
        printf("\n\nGAME OVER :(\n\n");
        printf("The word was: %s\n", chain[num]);
        }
    printf("\n\nPress Enter to play again...");
    getch();
    options();

    printf("\n\n");
    system("PAUSE");
}

void startGame2 () //GAME VARIATION #2 FOR A WORD OR PHRASE INTRODUCED BY A USER
{
    system("cls");
    char rep[100], temporal[100], word [60], chances = 7; //DEFINING THE VARIABLES TO USE AND THE NUMBER OF TRIES
    char pal;
    int lg, i, j, strt, crrct = 0, temp = 0;
    int repetido = 0, win = 0;

    printf("\nIntroduce your word: \n");
    gets(word); // TAKES THE WORD INTRODUCED BY THE USER


    system("cls");

    lg = 0;
    strt = 0;
    j = 0;

    rep[0] = ' ';
    rep[1] = '\0';


    do
    {
            system("cls");
            temp=0;
            hang(chances);

            if(strt == 0)
            {
             for(i=0;i<strlen(word);i++)
                {
                 if(word[i] == ' ')
                    {
                        temporal[i] = ' ';
                        lg++;
                    }
                     else
                    {
                        temporal[i] = '_';
                        lg++;
                    }
                }
             }

            strt = 1;
            temporal[lg] = '\0';

            for(i = 0; i < strlen(rep); i++)
            {
               if(rep[i] == pal)
                {
                repetido = 1;
                break;
                }
                 else
                {
                repetido = 0;
                }
             }

            if(repetido == 0)
            {
                for(i=0;i<strlen(word);i++)
                {
                if(word[i] == pal)
                     {
                        temporal[i] = pal;
                        crrct++;
                        temp=1;
                     }
                }
            }

        if(repetido == 0)
            {
             if(temp == 0)
                 {
                   chances = chances - 1;
                 }
            }

         printf("\n");

         for(i = 0; i<strlen(temporal); i++)
            {
             printf(" %c ",temporal[i]);
            }

        printf("\n");

        if(strcmp(word,temporal) == 0)
        {
            win = 1;
            break;
        }

        printf("\nAccepted Letters: %d\n",crrct);
        printf("\nRemaining Chances: %d\n",chances);


        rep[j] = pal;
        j++;

        if (chances==0)
        {
           break;
        }

        printf("\nWrite a letter: ");
        scanf("\n%c",&pal);

    }
    while(chances != 0);


    if(win)
        {
        printf("\n\nCONGRATULATIONS!!\n");
        printf("\nYOU WIN!!!\n");
        }
    else
        {
        printf("\n\nGAME OVER :(\n\n");
        printf("The word was: %s\n", word);
        }
    printf("\n\nPress Enter to play again...");
    getch();
    options();

    printf("\n\n");
    system("PAUSE");
}
void hang (int chances) //FUNCTION TO PRINT THE GALLOWS AND THE HANGMAN, ACCORDING TO THE NUMBER OF REMAINING TRIES
{
if (chances==8 || chances==7)
    {
    printf("\n     _______\n    |/      |\n    |\n    |\n    |\n    |\n    |\n ----------");
    }

if (chances==6)
    {
			printf("\n     _______\n    |/      |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
    }

if (chances==5)
    {
			printf("\n     _______\n    |/      |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
    }

if (chances==4)
    {
			printf("\n     _______\n    |/      |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");

    }

if (chances==3)
    {
			printf("\n     _______\n    |/      |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n    |\n ----------");

    }

if (chances==2)
    {
			printf("\n     _______\n    |/      |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      /\n    |\n    |\n ----------");

    }

if (chances==1)
    {
			printf("\n     _______\n    |/      |\n    |       0\n    |      /|");
			printf("\\");
			printf("\n");
			printf("    |      / ");
			printf("\\");
			printf("\n");
			printf("    |\n    |\n ----------");

    }

}


/* I consulted some videos and pages to get references of how to make my code. 
References: dcastillob on GitHub.
OpenWebinars on Youtube.
https://www.usna.edu/Users/cs/roche/courses/f20ic210/notes/06/files.php?f=hangman.c */


