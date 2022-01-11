#include <stdio.h>

int main()
{
    int c, isFirstSpace;
    isFirstSpace = 1;
    while((c = getchar()) != EOF)
    {
        if(isFirstSpace == 0 && c == ' ')
            continue;//跳过
        else
        {
            if(c == ' ') isFirstSpace = 0;  
            else isFirstSpace =  1;  
            putchar(c);
        }
    }
    return 0;
}