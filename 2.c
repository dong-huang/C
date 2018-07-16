#include "stdio.h"
#include "string.h"

int main()
{
    //1
    char a[100], b[100];
    scanf("%s %s", a, b);
    //2
    int maxm = 0, lefta = 0, righta = 0, leftb = 0, rightb = 0;
    for (int i = 0; i < strlen(a);i++)
    {
        lefta = i;
        righta = i + 1;
        for (int j = 0; j < strlen(b);j++)
            if(b[j]==a[i])
            {
                int max = 0;
                leftb = j;
                rightb = j + 1;
                while(lefta>=0&&leftb>=0)
                {
                    if(a[lefta--]==b[leftb--])
                        max++;
                    else
                        break;
                }
                while(righta<strlen(a)&&rightb<strlen(b))
                {
                    if(a[righta++]==b[rightb++])
                        max++;
                        else
                            break;
                }
                if(maxm<max)
                    maxm = max;
            }
    }
    printf("%d", maxm);
    return 0;
}