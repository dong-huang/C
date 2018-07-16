#include "stdio.h"
#include "string.h"
void reverse(char a[], int b, int c);
int main()
{
    char input[100];
    int cntin = 0;
    char in;
    for (;(in=getchar())!='\n';cntin++)
    {
        input[cntin] = in;
    }
    input[cntin] = '\0';
    reverse(input, 0, strlen(input)-1);
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] != '\n' && input[i] != ' ')
        {
            int j = i;
            while (input[j] != '\n' && input[j] != ' '&&j<strlen(input))
                j++;
            j--;
            reverse(input, i, j);
            i = j + 1;
        }
    }
    printf("%s",input);
        return 0;
 }
 void reverse(char a[],int b,int c)
 {
     int i = b, j = c;
     for (; i < j;i++,j--)
     {
         char ch = a[i];
         a[i] = a[j];
         a[j] = ch;
     }
 }
