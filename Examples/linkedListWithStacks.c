#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;  //instead of link
};

struct Node* top=NULL;  //instead of head
void push(int x);    //instead of insert
void pop();
void reverse();
void reverseLinkedList(struct Node** head);

int main()
{
    push(1);
    push(2);
    push(3);

    printf("Original Stack: ");
    struct Node* originalHead = top;
    reverse();
    reverseLinkedList(&originalHead);
    printf("\n");

    return 0;
}

void push(int x)
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->link=top;
    top=temp;
}

void pop()
{
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node*));
    if(top==NULL)   return;
    temp=top;
    top=temp->link;
    free(temp);
}

void reverse()
{
   struct Node* temp=top;
   if(temp==NULL)   return;
   while(temp!=NULL){
    push(temp->data);
    temp=temp->link;
   }
   while(top!=NULL){
    printf("%d", top->data);
    pop();
   }
}

void reverseLinkedList(struct Node** head)
{
    struct Node* temp = top;
    if(temp==NULL)  return;
    *head=temp;
    pop();

    while(!top){
        temp->link=top;
        pop();
        temp=temp->link;
    }
    temp->link;

}
