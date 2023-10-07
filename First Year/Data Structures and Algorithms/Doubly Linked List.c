#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next; 
};
struct node *start=NULL;
struct node *create_11(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_given(struct node *);
int main() 
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1:  Create a list");
        printf("\n 2:  Display the list");
        printf("\n 3:  Insert at beginning");
        printf("\n 4:  Insert at ending");
        printf("\n 5:  Insert after node");
        printf("\n 6:  Insert before node");
        printf("\n 7:  Delete at beginning");
        printf("\n 8:  Delete at ending");
        printf("\n 9:  Delete at given node");
        printf("\n 10:  Exit");
        printf("\n\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1 : start=create_11(start);
                     break;
                     
            case 2 : start=display(start);
                     break;
                     
            case 3 : start=insert_beg(start);
                     break;  
                     
            case 4 : start=insert_end(start);
                     break;
            
            case 5 : start=insert_after(start);
                     break;
                     
            case 6 : start=insert_before(start);
                     break;  
            case 7 : start=delete_beg(start);
                     break; 
                     
            case 8 : start=delete_end(start);
                     break;    
            case 9 : start=delete_given(start);
                     break;                  
        }
    }while(option!=10);   
    return 0;
}
struct node *create_11(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data :");
    scanf("%d",&num);
    while(num!=-1)
    {
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node -> data=num;
        if(start==NULL)
        {
            new_node->next=NULL;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
            ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
        }
        return start;
}
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\nEnter the data :");
    scanf("%d",&num);
        new_node=(struct node *)malloc(sizeof(struct node));
        new_node -> data=num;
        new_node->next=start;
        start->prev=new_node;
        start=new_node;
        return start;
}
struct node *insert_end(struct node *start)
{
    struct node *new_node,*ptr;
    int num;
    printf("\nEnter the data :");
    scanf("%d",&num);
        new_node=(struct node *)malloc(sizeof(struct node));
        ptr=start;
        while(ptr->next!=NULL)
        {
        ptr=ptr->next;
        }
        ptr->next=new_node;
        new_node->prev=ptr;
        new_node -> data=num;
        new_node->next=NULL;
        return start;
}
struct node *insert_after(struct node *start)
{
    struct node *new_node,*ptr,*preptr;
    int num,x;
    printf("\nEnter the data :");
    scanf("%d",&num);
    printf("\nEnter the number after which it is to be added :");
    scanf("%d",&x);
        new_node=(struct node *)malloc(sizeof(struct node));
        ptr=start;
        while(preptr->data!=x)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->prev=preptr;
        new_node -> data=num;
        new_node->next=ptr;
        return start;
}
struct node *insert_before(struct node *start)
{
    struct node *new_node,*ptr,*preptr;
    int num,x;
    printf("\nEnter the data :");
    scanf("%d",&num);
    printf("\nEnter the number before which it is to be added :");
    scanf("%d",&x);
        new_node=(struct node *)malloc(sizeof(struct node));
        ptr=start;
        while(ptr->data!=x)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=new_node;
        new_node->prev=preptr;
        new_node -> data=num;
        new_node->next=ptr;
        return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
        start=start->next;
        ptr=start;
        return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr,*preptr;
        ptr=start;
        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=NULL;
        return start;
}
struct node *delete_given(struct node *start)
{
    struct node *ptr,*preptr;
    int num;
    printf("\nEnter the value to delete :");
    scanf("%d",&num);
    ptr=start;
        while(ptr->data!=num)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        ptr->next->prev=preptr;
        ptr->next=ptr;
        return start;
}
