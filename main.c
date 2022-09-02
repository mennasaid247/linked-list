#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int data;
    struct node *next;
}node;
typedef struct{
    node *head;
    node *tail;
}linkedList;
linkedList* init()
{
    linkedList *l = malloc(sizeof(linkedList));
    l->head = NULL;
    l->tail = NULL;
    return l;
}
node* newNode (int x)
{
    node *n = malloc(sizeof(node));
    n->data = x;
    n->next = NULL;
    return n;
}
void insertBegin(linkedList *l, int x)
{
    node *n = newNode(x);
    if(l->head == NULL)
    //if(!l->head)
    {l->head = n;
     l->tail = n;}
    else
        {n->next = l->head;
        l->head = n;}
}
void insertEnd (linkedList *l, int x)
{
    node *n = newNode(x);
    if (l->head == NULL)
        l->head = l->tail = n;
    else{
        l->tail->next = n;
        l->tail = n;
    }
}
void display(linkedList *l)
{
   node *temp = l->head;
   while (temp != NULL)
   {
       printf("%d ", temp->data);
       temp = temp->next;
   }
   printf("\n");
}
int isempty(linkedList*l)
{
    if(l->head==NULL)
        return 1;
    return 0;
}
void atpos(int pos,linkedList*l)
{int i=1;
    node*n=newNode(4);
    node*temp=l->head;
    while(!isempty(l))
    {
        if(i==pos)
        {
            temp->next=n;
           temp=temp->next;
           n->next=temp;
           break;
        }
        i++;
    }
}
int main()
{
  linkedList *l = init();
    insertEnd(l, 5);
    insertEnd(l, 8);
    insertEnd(l, 13);
    display(l);
    printf("\n");
    atpos(2,l);
      display(l);
    return 0;
}
