#include <stdio.h>

int main()
{
    int i, j, arr1[5],arr2[5],arr3[10];
    printf("Enter elements for the first array=");
    for(i=0;i<5;i+=1)
    {
        scanf("%d",&arr1[i]);
    }
    printf("Enter elements for the second array=");
    for(i=0;i<5;i+=1)
    {
        scanf("%d",&arr2[i]);
    }
    for(i=0;i<5;i+=1)
    {
        arr3[i]=arr1[i];
    }
    for(i=0,j=5;i<5 && j<10;i+=1,j+=1)
    {
        arr3[j]=arr2[i];
    }
    printf("The merged array is=");
    for(i=0;i<10;i+=1)
    {
        printf("%d, ",arr3[i]);
    }
}
