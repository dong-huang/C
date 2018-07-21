#include "stdio.h"
#include "stdlib.h"
typedef struct List{
    int val;
    struct List *next;
} list;
void addnode(list **head, int val);
void delete (list **head, list *todel);
int main(){
    list *head = NULL;
    int v, times = 0;
    while(scanf("%d",&v)){
        addnode(&head, v);
        times++;
        if(getchar()=='-'&&getchar()=='>')
            ;
            else{
                break;
            }
    }
    printf("x:");
    int x, cnt = 0;
    scanf("%d", &x);
    list *trav = head;
    while(trav){
        cnt++;
        if(trav->val>=x){
            int t = trav->val;
            delete (&head, trav);
            addnode(&head, t);
        }
        if(cnt==times)
            break;
        trav = trav->next;
    }
    trav = head;
    while(trav){
        printf("%d ", trav->val);
        trav = trav->next;
    }
    return 0;
}
void addnode(list **head, int val){
    list *trav = *head;
    if(*head==NULL){
        *head = (list *)malloc(sizeof(list));
        (*head)->val = val;
        (*head)->next = NULL;
        return;
    }
    while(trav->next){
        trav = trav->next;
    }
    trav->next = (list *)malloc(sizeof(list));
    trav = trav->next;
    trav->val = val;
    trav->next = NULL;
    return;
}
void delete (list **head, list *todel){
    if(*head==todel){
        *head = (*head)->next;
        return;
    }
    list *trav = (*head)->next, *pre = *head;
    while(trav!=todel){
        trav = trav->next;
        pre = pre->next;
    }
    pre->next = trav->next;
    return;
}