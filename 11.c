#include "stdio.h"
#include "stdlib.h"
typedef struct List{
    int val;
    struct List *next;
} list;
void insert(list **phead, int inser);
int times(int i, int j, int k, int p1, int p2, int p3);
int listsize(list *head);
int locval(list *head, int cnt);
int main(){
    int k;
    scanf("%d", &k);
    list *head = (list *)malloc(sizeof(list));
    head = NULL;
    for (int i = 1; i <= k; i++){
        for (int m1 = 0; m1 <= i; m1++){
            for (int m2 = 0; m2 <= i - m1; m2++)
            {
                int inser = times(3, 5, 7, m1, m2, i - m1 - m2);
                insert(&head, inser);
            }
        }
        if(listsize(head)>=k){
            printf("%d", locval(head, k));
            return 0;
        }
    }
    getchar();
    return 0;
}
void insert(list **phead, int inser){
    if(*phead==NULL){
        *phead = (list *)malloc(sizeof(list));
        (*phead)->val = inser;
        (*phead)->next = NULL;
        return;
    }
    list *prev = *phead, *trav = (*phead)->next;
    if (prev == *phead && prev->val > inser){
        *phead = (list *)malloc(sizeof(list));
        (*phead)->val = inser;
        (*phead)->next = prev;
        return;
    }
    if(prev == *phead && prev->val == inser){
        return;
    }
    if(trav==NULL){
        prev->next = (list *)malloc(sizeof(list));
        prev->next->val = inser;
        prev->next->next = NULL;
        return;
    }
    while (trav->val < inser && trav->next != NULL)
    {
        prev = prev->next;
        trav = trav->next;
    }
    if (trav->val < inser){
        trav->next = (list *)malloc(sizeof(list));
        trav->next->val = inser;
        trav->next->next = NULL;
        return;
    }
    if (prev->val == inser)
    {
        return;
    }
    prev->next = (list *)malloc(sizeof(list));
    prev->next->val = inser;
    prev->next->next = trav;
    return;
}
int times(int i, int j, int k, int p1, int p2, int p3){
    int i1 = 1, j1 = 1, k1 = 1;
    while(p1){
        i1 *= i;
        p1--;
    }
    while(p2){
        j1 *= j;
        p2--;
    }
    while(p3){
        k1 *= k;
        p3--;
    }
    return i1 * j1 * k1;
}
int listsize(list *head){
    int cnt = 0;
    list *trav = head;
    while(trav){
        cnt++;
        trav = trav->next;
    }
    return cnt;
}
int locval(list *head, int cnt){
    list *trav = head;
    cnt--;
    while(cnt){
        trav = trav->next;
        cnt--;
    }
    return trav->val;
}