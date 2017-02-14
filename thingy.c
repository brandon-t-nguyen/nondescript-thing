#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// lol am lazy
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

char shiftLeft(char c)
{
    char low;
    char hi;
    if( 'a' <= c && c <= 'z' )
    {
        low = 'a';
        hi = 'z';
    }
    else if( 'A' <= c && c <= 'Z' )
    {
        low = 'A';
        hi = 'Z';
    }
    else
    {
        return c;
    }

    char out = c - 1;
    if(c <= low )
    {
        out = hi;
    }
    return out;

}

#define TERM_WIDTH 80
int main(int argc, char * argv[])
{
    printf(MAGENTA);
    for(int i = 0; i < TERM_WIDTH; i++)
    {
        putchar('=');
    }
    putchar('\n');
    // perform decipher
    char c;
    int count = 0;

    putchar('|');
    putchar(' ');
    count = 2;
    while(scanf("%c",&c) != EOF)
    {
        if(c == '\n')
        {
            while(count < TERM_WIDTH-1)
            {
                putchar(' ');
                count++;
            }
            printf(MAGENTA);
            putchar('|');
            putchar(c);
            putchar('|');
            putchar(' ');
            count = 2;
        }
        else
        {
            printf(CYAN);
            putchar(shiftLeft(c));
            count++;
        }
    }
    while(count < TERM_WIDTH-1)
    {
        putchar(' ');
        count++;
    }
    printf(MAGENTA);
    putchar('|');
    putchar('\n');
    for(int i = 0; i < TERM_WIDTH; i++)
    {
        putchar('=');
    }
    putchar('\n');


    printf(RESET);
}
