#include "stdio.h"
#include "string.h"

int main()
{
    char input[100];
    int ii = 0;
    while((input[ii++]=getchar())!='\n')
        ;
    int chn = 0, won = 0, max = 0;
    int chara[52];
    for (int i = 0; i < 52;i++)
        chara[i] = 0;
        for (int i = 0; input[i] != '\n'; i++)
        {
            if (input[i] >= 'a' && input[i] <= 'z')
                chara[input[i] - 'a']++;
                else if(input[i]>='A'&&input[i]<='Z')
                    chara[input[i] - 'A' + 'z' - 'a' + 1]++;
        }
        for (int i = 0; i < 52;i++)
        if(max<chara[i])
            max = chara[i];
        printf("most times %d\nmost character ", max);
        for (int i = 0; i < 52;i++)
        if(chara[i]==max)
            printf("%c ", i <= 25 ? 'a' + i : 'A' + i - 26);
        printf("\nnumber of character ");
        for (int i = 0; i < 52;i++)
            chn += chara[i];
        printf("%d\n", chn);
        for (int i = 0, cnt = 0; input[i] != '\0';i++)
        {
            if(input[i]!=' '&&input[i]!='\n')
                cnt++;
                else if(cnt)
                    {
                        cnt = 0;
                        won++;
                    }
        }
        printf("number of words %d", won);
        getchar();
        return 0;
}