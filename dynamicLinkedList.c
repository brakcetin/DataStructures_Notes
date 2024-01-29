#include<stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head;
void insert(int x);
void print();
void insertNthPlace(int x, int n);
void deleteNthPlace(int n);
struct Node* reverse();
void reverseRecursion(struct Node* p);
void printRecursion(struct Node* p);
struct Node* insertWithLocalHead(struct Node* head, int x);
void reversePrint(struct Node* p);

int main()
{
    head = NULL; //empty list

    /**INSERTING HEAD OF THE LIST**/
/*  printf("how many numbers? ");
    int n,i,x;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("\nenter the number: ");
        scanf("%d", &x);
        insert(x);
        print();    */
        //if head was a local variable instead of global
        //struct Node* head = NULL;
        //head = insert(head, x);
        //print(head);

    /**INSERTING HEAD OF THE LIST WITH LOCAL HEAD**/
/*  struct Node* head = NULL;
    head = insertWithLocalHead(head,2);
    head = insertWithLocalHead(head,4);
    head = insertWithLocalHead(head,6);
    head = insertWithLocalHead(head,5);
    print(head);    */

    /**INSERTING Nth PLACE**/
/*  insertNthPlace(2,1); print();   //2
    insertNthPlace(3,2); print();   //2 3
    insertNthPlace(4,1); print();   //4 2 3
    insertNthPlace(5,2); print();   //4 5 2 3   */

    /**DELETING Nth PLACE**/
/*  insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    int n;
    printf("enter a position that you want to delete: ");
    scanf("%d", &n);
    deleteNthPlace(n);
    print();    */

    /**REVERSE LIST - ITERATIVE METHOD**/
/*  insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    reverse();
    print();    */

    /**REVERSE LIST - RECURSION METHOD**/
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    reverseRecursion(head);
    print();

  //  }
}

void insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next = head;
    head = temp;
}

struct Node* insertWithLocalHead(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)  head=temp;
    else{
        struct Node* temp1 = head;
        while(temp1->next!=NULL)    temp1=temp1->next;
        temp1->next=temp;
    }
    return head;
}

void print()
{
    struct Node* temp = head;
    printf("list is: ");
    while(temp!=NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertNthPlace(int x, int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data=x;
    temp1->next=NULL;

    if(n==1){
        temp1->next=head;
        head=temp1;
        return;
    }
    struct Node* temp2 = head;
    for(int i=0; i<n-2; i++)
        temp2 = temp2->next;
    //temp2 points to (n-1)th Node  temp2=(n-1)th node  temp2->next=nth node
    temp1->next = temp2->next;
    temp2->next = temp1;    //now, temp2=(n-1)th node, temp1=nth node
}

void deleteNthPlace(int n)
{
    struct Node* temp1 = head;
    if(n==1){
        head = temp1->next;
        free(temp1);
        return;
    }

    for(int i=0; i<n-2; i++)
        temp1 = temp1->next;
    //temp1 points to (n-1)th Node  temp1=(n-1)th node  temp1->next=nth node
    struct Node* temp2 = temp1->next;   //nth node
    temp1->next = temp2->next;  //(n+1)th node
    free(temp2);    //delete temp2  (nth node)
}

struct Node* reverse()
{
    struct Node *prev, *current, *next;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next = current->next;   //move forward to reverse next node
        current->next = prev;   //direction changed
        prev = current;         //move forward to reverse next node
        current = next;         //move forward to reverse next node
    }
    head=prev;                  //head changed
    return head;
}

void reverseRecursion(struct Node* p)
{
    if(p->next==NULL){
        head=p;
        return;
    }
    reverseRecursion(p->next);
    struct Node* q=p->next;
    q->next=p;
    p->next=NULL;
}

void printRecursion(struct Node* p)
{
/*  struct Node* temp=head;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp=temp->next;
    }*/
    if(p==NULL)  return;
    printf("%d", p->data);
    printRecursion(p->next);
}

void reversePrint(struct Node* p)
{
    if(p==NULL) return;
    reversePrint(p->next);
    printf("%d", p->data);
}

