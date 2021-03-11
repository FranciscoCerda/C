/*To make this code, I needed the help of Ángel Soria and Ángel Chávez, 
who helped me to understand how to develop it and make it works.*/

#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int main()
{
  int c, n = FALSE, p = FALSE, q = FALSE;
  while ((c = getchar()) != EOF)
    {
      switch(c)
      {
          case '(':
              p = TRUE;
              putchar(c);
              break;

          case ')':
              p = FALSE;
              putchar(c);
              break;

          case '{':
              p = TRUE;
              putchar(c);
              break;

          case '}':
              p = FALSE;
              putchar(c);
              break;

          case '[':
              p = TRUE;
              putchar(c);
              break;

          case ']':
              p = FALSE;
              putchar(c);
              break;

          case '<':
              p = TRUE;
              putchar(c);
              break;

          case '>':
              p = FALSE;
              putchar(c);
              break;

          case '\"':
              putchar(c);
              ++q;
              break;

           case '\'':
              putchar(c);
              ++q;
              break;

          default:
            if(c != '.' && c!= ':' && c != '\?' && c != '!' && c != '-' && c != ';' && c != '_')
                {
                if (p == TRUE || q == TRUE)
                    {
                    putchar(c);
                    }
                    else
                    {
                        if (q == 2)
                        {
                            q = 0;
                        }
                        if (c >= '0' && c <= '9')
                        {
                            ++n;
                        }
                        else
                        {
                            n = 0;
                        }
                        if (n == 1)
                        {
                            putchar('X');
                        }
                        if (n == 0)
                        {
                            putchar(c);
                        }
                    }
                }

        }
    }

    return 0;
}
