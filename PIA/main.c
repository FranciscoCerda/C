/* ***This isn't the complete code*** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char word[60],rep[100],temporal[100];
    char pal;
    int lg,i,j,strt,crrct=0,temp=0, chances=5;
    int repetido=0,win=0;

    printf("\n\t\t\t\tTHE HANDMAN GAME\n\n");
    printf("\n***Only use CAPITAL LETTERS***\n");
    printf("Introduce your word: ");
    gets(word);

    system("cls");

    lg = 0;
    strt = 0;
    j = 0;

    rep[0] = ' ';
    rep[1] = '\0';


    do {
                system("cls");
        temp=0;

        if(strt == 0) {
         for(i=0;i<strlen(word);i++) {
          if(word[i] == ' ') {
            temporal[i] = ' ';
             lg++;
          }
          else {
             temporal[i] = '_';
             lg++;
          }
         }
        }

        strt = 1;

        temporal[lg] = '\0';

        for(i=0;i<strlen(rep);i++) {
           if(rep[i] == pal) {
            repetido = 1;
            break;
          }
          else {
           repetido = 0;
         }
        }

        if(repetido == 0) {
         for(i=0;i<strlen(word);i++) {
                    if(word[i] == pal) {
             temporal[i] = pal;
              crrct++;
              temp=1;
            }
          }
        }

        if(repetido == 0) {
         if(temp == 0) {
           chances = chances - 1;
         }
        }
        else
        {
         printf("\nIntroduce another character, please\n\n");
        }

        printf("\n");

        for(i=0;i<strlen(temporal);i++)
        {
         printf(" %c ",temporal[i]);
        }

        printf("\n");

        if(strcmp(word,temporal) == 0)
        {
            win = 1;
            break;
        }

        printf("\nAccpeted Letters: %d\n",crrct);
        printf("\nRemaining Chances: %d\n",chances);


        rep[j] = pal;
        j++;

        if (chances==0)
        {
           break;
        }

        printf("\nWrite a letter: ");
        scanf("\n%c",&pal);

    }while(chances != 0);


    if(win)
        {
        printf("\n\nYOU WIN!!!\n");
        }
    else
        {
        printf("\n\nYOU LOSE :(\n");
        }

    printf("\n\n");
    system("PAUSE");
    return 0;

}

/* I used some videos and pages to obtain some
references to do this short project advance. This isn't
the final result but I think it is a great attempt to start.
References: dcastillob on GitHub.
OpenWebinars on Youtube.
https://www.usna.edu/Users/cs/roche/courses/f20ic210/notes/06/files.php?f=hangman.c */


