#include "stdio.h"
#include "stdlib.h"
typedef struct List{
    int val;
    struct List *next;
} list;
int list2num(list* head);
list *getlist();
list *num2list(int a);
list *reverse(list *head);
int main(){
    list *x, *y;
    x = getlist();
    y = getlist();
    x = reverse(x);
    y = reverse(y);
    int sum = list2num(x) + list2num(y);
    list *head = num2list(sum);
    list *trav = head;
    while(trav->next){
        printf("%d->", trav->val);
        trav = trav->next;
    }
    printf("%d", trav->val);
    return 0;
}
int list2num(list* head){
    int r = 0;
    list *trav = head;
    while(trav){
        r = r * 10 + trav->val;
        trav = trav->next;
    }
    return r;
}
list* num2list(int a){
    list *head = (list *)malloc(sizeof(list));
    head->val = a % 10;
    head->next = NULL;
    a = a / 10;
    list *trav = head;
    while(a){
        trav->next = (list *)malloc(sizeof(list));
        trav->next->val = a % 10;
        trav->next->next = NULL;
        trav = trav->next;
        a = a / 10;
    }
    return head;
}
list *getlist(){
    int in;
    list *head = (list *)malloc(sizeof(list));
    scanf("%d", &in);
    head->val = in;
    head->next = NULL;
    list *trav = head;
    while(getchar()=='-'&&getchar()=='>'){
        scanf("%d", &in);
        trav->next = (list *)malloc(sizeof(list));
        trav->next->val = in;
        trav->next->next = NULL;
        trav = trav->next;
    }
    return head;
}
list *reverse(list *head){
    if(head==NULL)
        return NULL;
    list *head2 = (list *)malloc(sizeof(list));
    head2->val = head->val;
    head2->next = NULL;
    list *trav2 = head2, *trav = head->next;
    while(trav){
        list *t = (list *)malloc(sizeof(list));
        t->next = trav2;
        t->val = trav->val;
        trav2 = t;
        trav = trav->next;
    }
    return trav2;
}