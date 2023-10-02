#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<stdlib.h>

struct Symbol{
    char name[20];
    int index;
    char type[20];
};

int main()
{
    int i = -1, j = 0, k=0, n;
    char arr[20][20];
    char lst1[][20] = {"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","voltile","do","if","static","while"};
	char lst2[][20] = {"=","==","/","%","*","+","-","^","!",">","<","]","[","{","}","(",")","."};
    
    struct Symbol symbolTable[50];

    printf("Enter the expression seperated by space and end it with $ = ");
    do{
        i+= 1;
        scanf("%s", arr[i]);
    }while(strcmp(arr[i], "$"));

    n = i;
    printf("Given Expression:");
    for (i = 0; i < n; i += 1) 
    {
        printf("%s", arr[i]);
    }

    int flag[n];
    for(i=0; i<n; i+=1)
    {
        flag[i] = 0;
    }
    for (i = 0; i < n; i+=1) 
    {
        for(j=0; j<32; j+=1)
        {
            if(flag[i] == 0)
            {
                if(strcmp(arr[i], lst1[j]) == 0)
                {
                    strcpy(symbolTable[k].name, arr[i]);
                    symbolTable[k].index = i;
                    strcpy(symbolTable[k].type, "Keyword");
                    k++; 
                    flag[i]=1;
                    break;
                }
            }
        }
        for(j=0; j<18; j+=1)
        {
            if(flag[i] == 0)
            {
                if(strcmp(arr[i], lst2[j]) == 0)
                {
                    strcpy(symbolTable[k].name, arr[i]);
                    symbolTable[k].index = i;
                    strcpy(symbolTable[k].type, "Operator");
                    k++; 
                    flag[i] = 1;
                    break;
                }
            }
        }
        if(flag[i] == 0)
        {
            if(isdigit(arr[i][0])){
                strcpy(symbolTable[k].name, arr[i]);
                symbolTable[k].index = i;
                strcpy(symbolTable[k].type, "Constant");
                k++;
                flag[i] = 1;
            }
            else
            {
                strcpy(symbolTable[k].name, arr[i]);
                symbolTable[k].index = i;
                strcpy(symbolTable[k].type, "Identifier");
                k++;
                flag[i] = 1;
            }
        }
    }
    
    printf("\n\nSymbol Table - \n");
    printf("Name\t Type\n");
    for(i = 0; i < k; i++) 
    {
        printf("%s\t %s\n", symbolTable[i].name, symbolTable[i].type);
    }
    
    char lookup[20];
    int found;
    while(1)
    {
        printf("\nEnter a symbol to search ($ to exit) = ");
        scanf(" %s", lookup);
        if(strcmp(lookup, "$") == 0)
        {
            break;
        }
        else
        {
            found=0;
            for(i=0; i<k; i+=1)
            {
                if(strcmp(symbolTable[i].name, lookup) == 0)
                {
                    printf("Symbol %s is found at index %d.", symbolTable[i].name, symbolTable[i].index);
                    found=1;
                    break;
                }
            }
            if(found == 0)
            {
                printf("\nSymbol not found in Symbol Table.");
            }
        }
    }
    
    return 0;
}


