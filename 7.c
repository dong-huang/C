#include "stdio.h"
#include "stdlib.h"

struct Node{
    int val;
    struct Node* next;
};

typedef struct Node list_t;

struct List{
    list_t** listlist;
    int size;
};

typedef struct List listlist_t;

list_t* pushnode(list_t* head, int val){
    
    list_t* newNode = (list_t *)malloc(sizeof(list_t));
    list_t* trav = head;
    
    newNode->val = val;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        return head;
    }
    
    trav = head;
    while(trav->next){
        trav = trav->next;
    }
    
    trav->next = newNode;
    
    return head;
}

list_t* popnode(list_t* head){
    
    list_t* toDel = NULL;
    list_t** indirect = &head; 
    
    if(head == NULL){
        return NULL;
    }
    
    while((*indirect)->next){
        indirect = &(*indirect)->next;
    }
    
    toDel = *indirect;
    (*indirect) = (*indirect)->next;
    free(toDel);
    
    return head;
}

void pushback(listlist_t* listArr, list_t* temp){

    list_t* newNode = NULL;
    list_t* trav = temp;
    const int size = listArr->size;
    
    listArr->listlist = (list_t **)realloc(listArr->listlist, sizeof(list_t *) * (size + 1));
    listArr->listlist[size] = NULL;
    
    while(trav){
        listArr->listlist[size] = pushnode(listArr->listlist[size], trav->val);
        trav = trav->next;
    }
    
    trav = temp;
    
    listArr->size = listArr->size + 1;
}

void permute(int *nums, int numsSize, listlist_t *pResult, list_t* temp, int begin){
    
    pushback(pResult, temp);
    
    for(int i = begin; i < numsSize; i++){
        if(i > begin && nums[i] == nums[i - 1]) continue;
        temp = pushnode(temp, nums[i]);
        permute(nums, numsSize, pResult, temp, i + 1);
        temp = popnode(temp);
    }
}

int getListSize(list_t* head){
    
    list_t* trav = head;
    int size = 0;
    
    while(trav){
        trav = trav->next;
        size++;
    }
    
    return size;
}

void copyList(int** ppArr, list_t* head){
    
    int size = getListSize(head);
    int i = 0;
    list_t* trav = head;
    
    *ppArr = NULL;
    
    if(size != 0){
        *ppArr = (int *)malloc(sizeof(int) * size);
        while(trav){
            (*ppArr)[i] = trav->val;
            trav = trav->next;
            i++;
        }
    }
    
    return;
}

int compare(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int** subsetsWithDup(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    
    listlist_t result;
    list_t* temp = NULL;
    int row;
    int col;
    int** resultArr = NULL;
    int begin = 0;
    
    result.listlist = NULL;
    result.size = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    permute(nums, numsSize, &result, temp, begin);
    
    row = 0;
    col = 0;
    *returnSize = result.size;
    resultArr = (int **)malloc(sizeof(int *) * result.size);
    *columnSizes = (int *)malloc(sizeof(int) * result.size);
    
    for(row = 0; row < result.size; row++){
        
        (*columnSizes)[row] = getListSize(result.listlist[row]);
        copyList(&resultArr[row], result.listlist[row]); 
    }
    
    return resultArr;
}
int main(){
    int nums[10];
    char g;
    int q, r = 0;
    while((g=getchar())!=']'){
        scanf("%d", &q);
        nums[r++] = q;
    }
    int *columnSizes=0;
    int returnSize=0;
    int** result=subsetsWithDup(nums, r, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize;i++){
        putchar('[');
        for (int j = 0; j < columnSizes[i];j++){
            printf("%d,", result[i][j]);
        }
        printf("]\n");
    }
    return 0;
}