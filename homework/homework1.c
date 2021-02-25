#include <stdio.h>

int main() 
{
    int c;
    int i = 0;
    char strong[13]={"strong/strong"};
    char script[13]={"script/script"};
    printf("\tCode cleaner\n");
    printf(" Introduce your HTML code below:\n");

    while ((c = getchar()) != EOF)
    {
        if (c == '<')
        {
            while ((c = getchar()) == strong[i]) 
            {
                ++i;
            }
            if (c==script[1]) 
            {
                c = getchar();
                if(c==script[2]) 
                {
                    c=getchar();
                    if (c==script[3]) 
                    {
                    while ((c=getchar())!='>') 
                    {
                        ;
                    }
                    while ((c=getchar())!='>') 
                    {
                        ;
                    }
                }
            }
        }
        if(i == 13) 
        {
            i = 0;
        }
        while(c != EOF && c != '>') 
        {
            c=getchar();
        }
    }
    else if (i == 6 && i < 13) 
    {
            if(c == ' ') 
            {
                printf("_");
                c = getchar();
            }
        putchar(c);
        }
        if ((i != 6 && c != '<' && c != '>') || c == '\n') 
        {
            putchar (c);
            i = 0;
        }
    }
}


