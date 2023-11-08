#include<stdio.h>
#include<ctype.h>
#include<string.h>

char grammar[20][20], followset[20], finalfirst[20];
int k=0, i;
void Follow(char, int);

void First(char, int);

int main() 
{
    char s;
    int count;
    
    printf("Enter number of productions: ");
    scanf("%d", &count);
    printf("Productions are entered separately as A=BC.\n\n");
    int i;
    for(i = 0; i<count; i+=1)
    {
        printf("Enter Production %d : ", i+1);
        scanf("%s", grammar[i]);
    }
    int j;
    printf("\nFollow Sets for the given grammar:\n");
    for(i = 0; i < count; i++) 
    {
        s = grammar[i][0];
        Follow(s, count);
        printf("Follow(%c) = { ", s);
        
        for(j = 0; j < k; j++) 
        {
            printf("%c ", followset[j]);
            if(j == k-1)
            {
                break;
            }
            else
            {
                printf(", ");
            }
        }
        printf("}\n");
        k = 0;
    }

    printf("\nFinal First Sets for the given grammar:\n");
    for(i = 0; i < count; i++) 
    {
        s = grammar[i][0];
        finalfirst[0] = '\0'; // Reset finalfirst for each non-terminal
        First(s, count);
        printf("First(%c) = { %s }\n", s, finalfirst);
    }
    return 0;
}

void First(char c, int count) 
{
    if(isupper(c) == 0) 
    {
        followset[k++] = c;
        finalfirst[strlen(finalfirst)] = c;
        finalfirst[strlen(finalfirst)+1] = '\0';
    }
    int j;
    for(j = 0; j < count; j++) 
    {
        if(grammar[j][0] == c) 
        {
            if(grammar[j][2] == '$') 
            {
                Follow(grammar[i][0], count);
            } 
            else if(islower(grammar[j][2])) 
            {
                followset[k++] = grammar[j][2];
                finalfirst[strlen(finalfirst)] = grammar[j][2];
                finalfirst[strlen(finalfirst)+1] = '\0';
            } 
            else 
            {
                First(grammar[j][2], count);
            }
        }
    }
}

void Follow(char c, int count)
{

    if(grammar[0][0]==c)
    {
        followset[k++]='$';
    }
    int j;
    for(i = 0; i < count; i+=1)
    {
        for(j = 2; j < strlen(grammar[i]); j++)
        {
            if(grammar[i][j] == c)
            {
                if(grammar[i][j+1]!='\0')
                {
                    First(grammar[i][j+1], count);
                }
                if(grammar[i][j+1]=='\0' && c != grammar[i][0])
                {
                    Follow(grammar[i][0], count);
                }
            }
        }
    }
}
