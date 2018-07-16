//Write a removeDuplicates() function which takes a list and deletes
//any duplicate nodes from the list. The list is not sorted.
//
//For example if the linked list is 12->11->12->21->41->43->21,
//then removeDuplicates() should convert the list to 12->11->21->41->43.
//
//Challenge
//O(n) time
//12 11 12 21 41 43 21
#include "stdlib.h"
#include "stdio.h"

struct node{
    int a;
    struct node *next;
};
int main(){
    struct node *head = NULL, *cur;
    int a;
    if(scanf("%d",&a)!=EOF){
        head = (struct node *)malloc(sizeof(struct node));
        head->a = a;
        cur = head;
        while(scanf("%d",&a)!=EOF){
            cur->next = (struct node *)malloc(sizeof(struct node));
            cur = cur->next;
            cur->a = a;
        }
        cur->next = NULL;
    }
    cur = head;
    while(cur!=NULL)
    {
        struct node *curr = (struct node *)malloc(sizeof(struct node));
        struct node *prev = (struct node *)malloc(sizeof(struct node));
        curr = head;
        prev->next = curr;
        while(curr!=NULL)
        if(curr->a==cur->a&&curr!=cur)
        {
            prev->next = prev->next->next;
            curr = curr->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
        cur = cur->next;
    }
    cur = head;
    while(cur!=0)
    {
        printf("%d ", cur->a);
        cur = cur->next;
    }
    return 0;
}