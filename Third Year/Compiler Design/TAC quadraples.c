#include <stdio.h>
#include <string.h>
#include <ctype.h>

void generateQuad(char pos, char op, char operand1, char operand2) 
{
    if(isdigit(operand1))
    {
        printf("(%c)\t%c\tT%c\t%c\tT%c\n", pos, op, operand1, operand2, pos);
    }
    else if(isdigit(operand2))
    {
        printf("(%c)\t%c\t%c\tT%c\tT%c\n", pos, op, operand1, operand2, pos);
    }
    else
    {
        printf("(%c)\t%c\t%c\t%c\tT%c\n", pos, op, operand1, operand2, pos);
    }
}

int main() 
{
    char arr[20];
    printf("Enter the expression = ");
    scanf("%s", arr);

    printf("Intermediate code -\n");
    printf("\topr\targ1\targ2\tresult\n");

    char pos = '0';
    for (int i = 0; i < strlen(arr); i++) 
    {
        if (arr[i] == '/' || arr[i] == '*' || arr[i] == '%') 
        {
            pos++;
            generateQuad(pos, arr[i], arr[i - 1], arr[i + 1]);

            arr[i - 1] = pos;
            for (int j = i; j < strlen(arr); j++) 
            {
                arr[j] = arr[j + 2];
            }
            i = -1; 
        }
    }

    for (int i = 0; i < strlen(arr); i++) 
    {
        if (arr[i] == '+' || arr[i] == '-') 
        {
            pos++;
            generateQuad(pos, arr[i], arr[i - 1], arr[i + 1]);

            arr[i - 1] = pos;
            for (int j = i; j < strlen(arr); j++) 
            {
                arr[j] = arr[j + 2];
            }
            i = -1; 
        }
    }
    for (int i = 0; i < strlen(arr); i++) 
    {
        if (arr[i] == '=') 
        {
            pos++;
            printf("(%c)\t= \tT%c\t  \t%c\n", pos, arr[i + 1], arr[i - 1]);
            break;
        }
    }
    return 0;
}
