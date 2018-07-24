#include "stdio.h"
#include "stdlib.h"
void dfs(int begin, int sum, int len, int backpack, int nums[], int *max);
int main(){
    int backpack, max = 0, nums[100], i;
    scanf("%d", &backpack);
    getchar();
    for ( i = 0;;i++)
    {
        scanf("%d", &nums[i]);
        if(getchar()=='\n')
            break;
    }
    nums[i + 1] = '\0';
    dfs(0, 0, i+1, backpack, nums, &max);
    printf("%d", max);
    getchar();
    return 0;
}
void dfs(int begin, int sum, int len, int backpack, int nums[], int *max){
    if (sum > (*max))
        *max = sum;
    for (int i = begin; i < len; i++)
    {
        if (i > begin && nums[i] == nums[i - 1])
        {
            continue;
        }
        if (sum + nums[i] > backpack)
            return;
        dfs(i + 1, sum + nums[i], len, backpack, nums, max);
    }
    return;
}