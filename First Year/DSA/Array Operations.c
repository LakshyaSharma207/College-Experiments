#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declaring array and size as global
int n, arr[20];

void insert_array();
void delete_array();
void search_array();
void print_array();

int main()
{
    int i;
    
    printf("Enter size of array = ");
    scanf("%d", &n);
    //generating random array elements
    srand(time(0));
    for(i=0; i<n; i+=1)
    {
        arr[i] = rand() % 100;
    }
    printf("The generated array: [");
    for(i=0; i<n; i+=1)
    {
        printf("%d",arr[i]);
        if(i == n-1)
        {
            printf("]");
            break;
        }
        else
        {
            printf(", ");
        }
    }
    
    int op;
    printf("\nEnter numeric option\n");
    
    while(1)
    {
        printf("Which operation to perform?\n\n1. Print array\n2. Search element\n3. Insert Element\n4. Delete Element\n5. Exit");
        printf("\nEnter option = ");
        scanf(" %d", &op);
        if(op == 1)
        {
            print_array();
        }
        else if(op == 2)
        {
            search_array();
        }
        else if(op == 3)
        {
            insert_array();
        }
        else if(op == 4)
        {
            delete_array();
        }
        else if(op == 5)
        {
            break;
        }
        else
        {
            printf("Enter correct option!!\n");
        }
        op = 0;
    }
    printf("\nExiting Program......\n");
}

void insert_array()
{
    int i, x, pos; 
    
    printf("Enter the element to insert = ");
    scanf("%d",&x);
    printf("Enter the position to be inserted = ");
    scanf("%d",&pos);
    for(i=n; i>=pos; i-=1)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = x;
    n+=1;
    print_array();
}

void delete_array()
{
    int i, x, k;
    printf("Enter the element to delete = ");
    scanf("%d",&x);
    
    for(i=0; i<n; i+=1)
    {
        if(arr[i]==x)
        {
            k = i;;
        }
    }
    for(i=k; i<n; i+=1)
    {
        arr[i]=arr[i+1];
    }
    n-=1;
    printf("Element Deleted!");
    print_array();
}

void search_array()
{
    int i, x, flag = 0;
    
    printf("Enter element to search=");
    scanf("%d",&x);
    for(i=0; i<n; i+=1)
    {
       if(arr[i]==x)
       {
           printf("\nElement %d was found at index %d.\n\n", x ,i);
           flag=1;
       }
    }
    if(flag == 0)
    {
        printf("\nElement was not found.\n\n");
    }
}

void print_array()
{
    int i;
    printf("\nPrinting the array....\nArray: [");
    for(i=0; i<n; i+=1)
    {
        printf("%d",arr[i]);
        if(i == n-1)
        {
            printf("]");
            break;
        }
        else
        {
            printf(", ");
        }
    }
    printf("\n\n");
}

