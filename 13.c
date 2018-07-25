#include "stdio.h"
#include "stdlib.h"
typedef struct List{
    int val;
    struct List *next;
} list;
list *getlist();
list *find(list *head, int v);
int main(){
    list *head = getlist();
    list *slow = head, *fast = head;
    while(fast->next!=NULL&&fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast->next == NULL || fast->next->next == NULL){
        printf("false");
        return 0;
    }
    slow = head;
    for (;;){
        if(slow==fast){
            printf("%d", slow->val);
            return 0;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return 0;
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
        list *temp = find(head, in);
        if (temp == NULL)
        {
            trav->next = (list *)malloc(sizeof(list));
            trav->next->val = in;
            trav->next->next = NULL;
            trav = trav->next;
        }
        else{
            trav->next = temp;
        }
    }
    return head;
}
list *find(list *head, int v){
    list *trav = head;
    while(trav!=NULL&&trav->val!=v){
        trav = trav->next;
    }
    return trav;
}