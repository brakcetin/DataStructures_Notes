/*******************************************************************
Name    : Burak                 Lecture     : Data Structures
Surname : Çetin                 Department  : Computer Engineering
Student Number: 22118080032     Homework    : Assignment 2
*******************************************************************/

#include<stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 20
#define TRUE 1
#define FALSE 0

typedef struct{
    int value;
}element;

int isFull(char queue[], int rear); //checking if the queue is full
int isEmpty(char queue[]);          //checking if the queue is empty
void addCircularQ(char queue[], element item);  //adding new item
void delCircularQ(char queue[]);                //deleting last item
void display(); //printing selected queue

element cirQueue[MAX_QUEUE_SIZE];   //defining circular queue
int front1=0, rear1=0, size1=0;     //initializing front, rear and size for the FIRST queue
int front2=10, rear2=10, size2=0;   //initializing front, rear and size for the SECOND queue

int main()
{
    FILE *inputFile = fopen("input.txt", "r");  //opens input.txt file read-only ("r")
    if(inputFile == NULL){
        printf("***ERROR: File not found!***"); //if file does not exist
        return -1;
    }
    char order[10]; //order: ENQUEUE, DEQUEUE OR PRINT
    char queue[10]; //queue: FIRST or SECOND
    element item;    //creating a new object from element struct

    while(fscanf(inputFile, "%s", order) != EOF){   //EOF: End of File, the while loop will work until it reaches the end of the file
        if(strcmp(order, "ENQUEUE") == 0){  //comparing with strcmp. If it says ENQUEUE in the file...
            fscanf(inputFile, "%s%d", queue, &item.value);
            addCircularQ(queue, item);
        }
        else if(strcmp(order, "DEQUEUE") == 0){ //If it says DEQUEUE in the file...
            fscanf(inputFile, "%s", queue);
            delCircularQ(queue);
        }
        else if(strcmp(order, "PRINT") == 0){   //If it says PRINT in the file...
            fscanf(inputFile, "%s", queue);
            display(queue);
        }
    }

    fclose(inputFile);  //closing the input.txt file
    return 0;
}

int isFull(char queue[], int rear)
{
    int* front = (strcmp(queue, "FIRST") == 0) ? &front1 : &front2;
    //if the value written in QUEUE is FIRST in the input.txt file, it assigns front1 to *front
    //if it is not FIRST (it is SECOND) it assigns front2 to *front

    if(*front == rear || rear1 == front2){  //queue is full
        return TRUE;                        //in the same queue, if front and (rear+1) are equal, then the queue is full
    }                                       //NOTE!:  in this function it says "rear", but in the addCircularQ function that it takes as reference,
    else                                    //        it is sent to the parameter as (rear+1)
        return FALSE;                       //Because there are 2 queues side by side in a single 1D array,
                                            //if the "rear" of the FIRST queue conflicts with the "front" of the SECOND queue,
                                            //then the FIRST queue is full
}

int isEmpty(char queue[])
{
    int* front = (strcmp(queue, "FIRST") == 0) ? &front1 : &front2;
    int* rear = (strcmp(queue, "FIRST") == 0) ? &rear1 : &rear2;
    //if the value written in QUEUE is FIRST in the input.txt file, it assigns front1 to *front and rear1 to *rear
    //if it is not FIRST (it is SECOND) it assigns front2 to *front and rear2 to *rear

    if(*front == *rear)   ////queue is empty
        return TRUE;
    else
        return FALSE;
}

void addCircularQ(char queue[], element item)
{
        int* front = (strcmp(queue, "FIRST") == 0) ? &front1 : &front2;
        int* rear = (strcmp(queue, "FIRST") == 0) ? &rear1 : &rear2;
        int* size = (strcmp(queue, "FIRST") == 0) ? &size1 : &size2;
        //if the value written in QUEUE is FIRST in the input.txt file, it assigns front1 to *front, rear1 to *rear and size1 to *size
        //if it is not FIRST (it is SECOND) it assigns front2 to *front, rear2 to *rear and size2 to *size

        *rear = (*rear + 1) % MAX_QUEUE_SIZE;   //since it is a circular queue, we take the mode of rear for index using the size of the queue.
                                                //rear's index increased by 1 because we added a new element
        if(isFull(queue, *rear)){    //if queue is full...
            printf("Queue\t%s\tis full\n", queue);
            --(*rear);  //rear was increased by 1 to check if the queue was full, but the queue was full and could not be added, so it was restored
            return;
        }

        (*size)++;  //size increased
        cirQueue[*rear]=item;   //new item added to next index
        printf("%d\tis inserted to queue\t%s\n", item.value, queue);
}

void delCircularQ(char queue[])
{
    int* front = (strcmp(queue, "FIRST") == 0) ? &front1 : &front2;
    int* rear = (strcmp(queue, "FIRST") == 0) ? &rear1 : &rear2;
    int* size = (strcmp(queue, "FIRST") == 0) ? &size1 : &size2;
    //if the value written in QUEUE is FIRST in the input.txt file, it assigns front1 to *front, rear1 to *rear and size1 to *size
    //if it is not FIRST (it is SECOND) it assigns front2 to *front, rear2 to *rear and size2 to *size

    if(isEmpty(queue)){ //if queue is empty...
         printf("Queue\t%s\tis empty\n", queue);
        return;
    }

    int value = cirQueue[*front + 1].value;
    printf("%d\tis deleted from queue\t%s\n", value, queue);
    (*front) = (*front + 1) % MAX_QUEUE_SIZE;   //"front" increased by 1 after deleting one item
    (*size)--;  //size decreased
}



void display(char queue[])
{
    int* front = (strcmp(queue, "FIRST") == 0) ? &front1 : &front2;
    int* rear = (strcmp(queue, "FIRST") == 0) ? &rear1 : &rear2;
    int* size = (strcmp(queue, "FIRST") == 0) ? &size1 : &size2;
    //if the value written in QUEUE is FIRST in the input.txt file, it assigns front1 to *front, rear1 to *rear and size1 to *size
    //if it is not FIRST (it is SECOND) it assigns front2 to *front, rear2 to *rear and size2 to *size

    printf("QUEUE:%s\tFRONT:%d\tREAR:%d\tSIZE:%d\n", queue, *front, *rear, *size);
    int i = *front + 1;  //i: first index of items, first index of queue is empty because of "front"

    if((*size) > 0){    //if the size of the queue is bigger than 0, so the queue is not empty...
        do
        {
            printf("%d\t", cirQueue[i].value);
            i = (i+1) % MAX_QUEUE_SIZE; //next element
        }while(i != (*rear + 1) % MAX_QUEUE_SIZE); //it will continue until the front reaches itself
    }
    else
        printf("NO_CONTENT");   //the queue is empty
    printf("\n");
}
