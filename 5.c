//1.Given an integer array, find a subarray with sum closest to zero.
//Return the indexes of the first number and last number.
//
//Example
//Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4]
//
//Challenge
//O(nlogn) time
//-3 1 1 -3 5
#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct Pair{
    int sum, id;
} pair;

int getnum(int in[]);
int mini(int a, int b);
int maxi(int a, int b);
void swap(pair *a, pair *b);

int getnum(int in[]){
    int n, i;
    for (i = 0; scanf("%d", &n) != EOF; i++)
    {
        in[i] = n;
    }
    return i;
}
int mini(int a,int b){
    return a < b ? a : b;
}
int maxi(int a,int b){
    return a < b ? b : a;
}
void swap(pair *a, pair *b)  
{
    pair temp;
 
    temp = *a;
    *a = *b;
    *b = temp;
 
    return ;
}
void quicksort(pair array[], int begin, int end)
{
    int i, j;
    if(begin < end)
    {
        i = begin + 1;
        j = end;
        while(i < j)
        {
            if(array[i].sum > array[begin].sum)  
            {
                swap(&array[i], &array[j]);  
                j--;
            }
            else
            {
                i++;  
            }
        }
        if(array[i].sum >= array[begin].sum)  
        {
            i--;
        }
        swap(&array[begin], &array[i]);
        
        quicksort(array, begin, i);
        quicksort(array, j, end);
    }
}
int main(){
    int num[100];
    int len = getnum(num), min = INT_MAX, cnt = 0;
    pair suid[len+1], ans[len+1];
    suid[0].sum = 0;
    suid[0].id = 0;
    for (int i = 1; i <= len; i++){
        suid[i].sum = suid[i - 1].sum + num[i-1];
        suid[i].id = i;
    }
    quicksort(suid, 0, len);
    for (int i = 1; i <= len;i++){
        if(min>suid[i].sum-suid[i-1].sum){
            min = suid[i].sum - suid[i - 1].sum;
        }
    }
    for (int i = 1; i <= len;i++){
        if(suid[i].sum - suid[i - 1].sum==min){
            ans[cnt].sum = mini(suid[i].id, suid[i - 1].id);
            ans[cnt].id = maxi(suid[i].id-1, suid[i - 1].id-1);
            cnt++;
        }
    }
    for (int i = 0; i < cnt;i++){
        printf("[%d,%d]\n", ans[i].sum, ans[i].id);
    }
    return 0;
}