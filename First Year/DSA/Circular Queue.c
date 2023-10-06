#include <stdio.h>
#define MAX 5
int A[MAX];
int front=-1,rear=-1;
int main()
{
    int opt,val;
    printf("\n\t\t\tMENU DRIVEN");
    do
    {
    printf("\n\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit");
    printf("\n\nEnter an option no. to proceed : ");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1 : printf("Enter an element to insert : ");
                 scanf("%d",&val);
                 if(front==0&&rear==MAX-1)
                 {
                     printf("Queue Overflow");
                 }
                 else if(front==-1&&rear==-1)
                 {
                     front=rear=0;
                 }
                 else if(rear==MAX-1&&front!=0)
                 {
                     rear=0;
                 }
                 else
                 {
                     rear++;
                 }
                 A[rear]=val;
                 break;
        case 2 : if(front==-1||front>rear)
                 {
                     printf("Queue Underflow");
                 }  
                 else if(front==rear)
                 {
                     front=rear=-1;
                 }
                 else if(front==MAX-1)
                 {
                     front=0;
                 }
                 else
                 {
                     val=A[front];
                     front++;
                 }
                 printf("\nThe deleted item is %d",val);
                 break;
                 
                 
        case 3 : if(front==-1||rear==-1)
                 {
                     printf("Queue Underflow");
                 }
                 else if(front<rear)
                 {
                 for(int i=front;i<=rear;i++)
                 {
                     printf("\n%d",A[i]);
                 }
                 }
                 else
                 {
                    for(int i=0;i<MAX;i++)
                 {
                     printf("\n%d",A[i]);
                 }
                    for(int i=0;i<=rear;i++)
                 {
                     printf("\n%d",A[i]);
                 }
                 }
               break;     
    }
    }while(opt!=4); 
}
