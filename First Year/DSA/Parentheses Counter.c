#include <stdio.h>

int main()
{
    char arr1[5];
    int i, c, sum1=0, sum2=0, sum3;
    printf("Enter an expression containing parentheses= ");  
    scanf("%s",arr1);
    for(i=0;i<15;i+=1)
    {
        if(arr1[i]=='(' || arr1[i]=='{' || arr1[i]=='[')  
        {  
            sum1+=1;      
        }  
         
        if(arr1[i]==')' || arr1[i]=='}' || arr1[i]==']')  
        {  
            sum2+=1;    
        }
    }
    printf("Number of opening parentheses=%d and number of closing parentheses=%d",sum1,sum2);
    sum3=sum1+sum2;
    if(sum3%2==0)
    {
        printf("\nThis expression is valid! (or you put brackets wrong)");
    }
    else
    {
        printf("\nDo it again now!!");
    }
}
