#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void quicksort(int array[], int begin, int end);
void swap(int *a, int *b);
int next_permutation(int ip[], int len);
void reverse(int ip[], int begin, int end);
int main(){
    int ip[20], len;
    for (int i = 0;; i++){
        scanf("%d", &ip[i]);
        if(getchar()=='\n'){
            ip[i + 1] = '\0';
            len = i + 1;
            break;
        }
    }
    quicksort(ip, 0, len - 1);
    do{
        for (int i = 0; i < len;i++)
            printf("%d ", ip[i]);
        putchar('\n');
    } while (next_permutation(ip, len));
    return 0;
}
void quicksort(int array[], int begin, int end)
{
    int i, j;
    if(begin < end)
    {
        i = begin + 1;
        j = end;
        while(i < j)
        {
            if(array[i] > array[begin])  
            {
                swap(&array[i], &array[j]);  
                j--;
            }
            else
            {
                i++;  
            }
        }
        if(array[i] >= array[begin])  
        {
            i--;
        }
        swap(&array[begin], &array[i]);
        
        quicksort(array, begin, i);
        quicksort(array, j, end);
    }
}
void swap(int *a, int *b)  
{
    int temp;
 
    temp = *a;
    *a = *b;
    *b = temp;
 
    return ;
}
int next_permutation(int ip[], int len){
    if(len==0||len==1)
        return 0;
    int flag = 0;
    int ini = len - 1;
    while(ini>0&&ip[ini-1]>=ip[ini]){
        ini--;
    }
    if(ini)
        ini--;
    int k = len;
    while(k--){
        if(ip[k]>ip[ini]){
            int t = ip[k];
            ip[k] = ip[ini];
            ip[ini] = t;
            flag = 1;
            break;
        }
    }
    reverse(ip, ini + 1, len - 1);
    return flag;
}
void reverse(int ip[],int begin, int end){
    for (; begin < end;begin++,end--){
        int t = ip[begin];
        ip[begin] = ip[end];
        ip[end] = t;
    }
    return;
}