#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct playerinfo
{
    int finalscore;
    char playername[20];
}edit[50];           //structure declare and type is array

int score,top=-1;

void getname()
{
    top+=1;
    printf("\n\n\t\tBut First enter your name=");
    scanf("%s",edit[top].playername);                    //gets playername
    printf("\n\t\tCreating new game file.......");
    printf("\n\t\tGame file created successfully!!\n");
}

int cool() 
{
	int k;
	srand(time(NULL));          //ensures time is elapsed and number generates different sequences
	k=rand() % 17;              //generate a random number. 
	return k;
}

void scored(int a)
{
    if(a==1)
    {
        score+=2;
    }
    else if(a==2)
    {
        score-=1;
    }
}

void scoreboard()
{
    for(int i=0;i<=top;i+=1)
    {
        printf("\n\nNAME: %s",edit[i].playername);
        printf("\nSCORE: %d",edit[i].finalscore);
    }
    printf("\n%s needs %d more points to win",edit[top].playername,10-edit[top].finalscore);
}

void help()
{
    printf("\t\t+-------------------------------------------------------------------------------------------------------+");
    printf("\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|This is just a simple guessing game. You can play with different names.\t\t\t\t\t\t\t\t\t|");
    printf("\n\t\t|You will be given hints and the length of the word and you will have to guess the right word.\t\t|");
    printf("\n\t\t|You can answer it letter by letter for a better experience.\t\t\t\t\t\t|");
    printf("\n\t\t|You will get +2 points for right answer. If you fail to answer within 5 turns then negative 1 points\t|");
    printf("\n\t\t|To win you need 10 points. Beware, your points can also fall in the negative zone.\t\t\t|");
    printf("\n\t\t|GOOD LUCK!!!!\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t+-------------------------------------------------------------------------------------------------------+\n");
    
}

const char *x[] = {              //x is a string literal (a pointer to const memory which cannot be modified). Its better practice to declare it as const to show this
	"Bag", "Demon", "Hell",
	"Robot", "Factory", "Doraemon",
	"Cyborg", "Zombie", "Claustrophobia",
	"Burger", "Pizza", "Satire",
	"Samurai", "Cummerbund", "Cashmere", "Cyclops", "Sudoku"};
	
int hints(char ans[]){
    printf("\n\nHint - ");         //because strcmp gives integer value 0 when strings same and different number otherwise
    if(strcmp(ans,x[0])==0)
    printf("Something we carry");
	if(strcmp(ans,x[1])==0)
	printf("Evil entity");
	if(strcmp(ans,x[2])==0)
	printf("Sinners perish in ?");  
	if(strcmp(ans,x[3])==0)
	printf("Remote controlled machine");
	if(strcmp(ans,x[4])==0)
	printf("A workshop with machines");
	if(strcmp(ans,x[5])==0)
	printf("Blue Robo Cat");
	if(strcmp(ans,x[6])==0)
	printf("Person with Boimetric body parts");
	if(strcmp(ans,x[7])==0)
	printf("Brain eater");
	if(strcmp(ans,x[8])==0)
	printf("Irrational fear of confined spaces");
	if(strcmp(ans,x[9])==0)
	printf("Joker fast food");
	if(strcmp(ans,x[10])==0)
	printf("Popular italian snack");
	if(strcmp(ans,x[11])==0)
	printf("Criticizing humorously");
	if(strcmp(ans,x[12])==0)
	printf("Japanese Warriors");
	if(strcmp(ans,x[13])==0)
	printf("A waist sash");
	if(strcmp(ans,x[14])==0)
	printf("Kashmiri shawl");
	if(strcmp(ans,x[15])==0)
	printf("An one-eyed monster");
	if(strcmp(ans,x[16])==0)
	printf("A grid combinatorial puzzle");
}
 
int main() 
{
    int i=0,j=0,k,p,n,q,tries,op;
    char temp,ask;          //char array type because it's not working otherwise :/
    char ans[20],deleteinfo[20];   
    beginning:
    score=0;
    printf("\n\t\t+----------------------------------------+\n\t\t|\tWelcome to the Guessing Game\t |\n");
    printf("\t\t|\t\t\t\t\t |\n\t\t|\t Made by Lakshya, Jessica\t |\n\t\t+----------------------------------------+");
    getname();
    while(1)
    {
        options:
        printf("\n\t\t");
        for(int i=0;i<=4;i+=1)
        {
            printf("+-----------------------");
        }
        printf("+\n\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n\t\t|");
        printf(" 1. START THE GAME\t| 2. QUIT THE GAME\t| 3. RULES OF THE GAME\t| 4. VIEW SCOREBOARD\t| 5. RESET SCORES\t|");
        printf("\n\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\t\t\t|\n\t\t");
        for(int i=0;i<=4;i+=1)
        {
            printf("+-----------------------");
        }
        printf("+\n\n\t\tYou are playing as %s",edit[top].playername);
        printf("\n\t\tEnter your option from menu=");
        scanf(" %d",&op);
        if(op==1)
        {
            start:
            printf("\nLoading the game.........");
            printf("\nSo let's start the game!");
            strcpy(ans,x[cool()]);        //copy the value aquired stored in the address of the two pointers
            n=strlen(ans);
	        printf("\n\nI have a word in my mind, it's %d letter word and only the first letter is capital",n); //length of the answer
	        hints(ans);
	        
	        int mask[n];
            for(p=0;p<n;p+=1) 
	        {
	            mask[p]=0;                   //using mask array is like playing with indexes.  
            }
            tries=5;
	        while(q!=n && tries!=0)
	        {
	            printf("\n\t\t\t");
            for(k=0;k<n;k+=1)
            {
                printf("====");
            }
            printf("\n\n\t\t\t   ");
                for(k=0;k<n;k+=1) 
                {
                    if (mask[k]==1) 
                    { 
                        printf(" %c ", ans[k]);     //if you get a letter right then it's index is saved for future
                    }
                    else 
                    {
                        printf("_ ");
                    }
                }
                printf("\n\n\t\t\t");
                for(k=0;k<n;k+=1)
                {
                    printf("====");
                }
                printf("\n");
                i=0;
	            printf("\n\n\t\tGuess one letter=");       //takes the guessing value from user
	            scanf(" %c",&temp); 
	            
	            for(k=0;k<n;k+=1) 
	            {
	                if(ans[k]==temp)             
	                {
	                    if(mask[k]==0)
	                    {
	                        mask[k]=1;                       //masks the correctly given answer
	                        i=1;
	                        break;
	                    }
	                }
	            }
	            
	            q=0;
	            for(k=0;k<n;k+=1) 
	            {
	                if(mask[k]==1) 
	                {
	                    q+=1;
	                }
	            }
	            
	            if(i==0)
	            {
	                tries-=1;
	                printf("\t\tWrong guess try again\n");
	                printf("\t\tYou have %d tries left\n",tries);
	            }
	        }
	        if(q==n)                //outside the loop
	        {
	                printf("\nYou got it right! It is '%s'.",ans);
	                printf("\nYour points were increased by 2 points");
	                j=1;
	                scored(j);
	        }
	        else if(q!=n)
	        {
	            printf("\nding dong! Your guesses were wrong.");
	            printf("\nThe correct word is '%s'.",ans);
	            printf("\nYour points were deducted by 1!!");
	            j=2;
	            scored(j);
	        }
	        if(score==10)
            {
                printf("\n\t\tYou have won the game!!");
                goto quit;
            }
	        while(1)
	        {
	            printf("\nDo you want to continue playing? Y/N:-");
	            scanf(" %c",&ask);
	            if(ask=='Y' || ask=='y')
	            {
	                printf("Your current score is %d",score);
	                goto start;
	            }
	            else if(ask=='N' || ask=='n')
	            {
	                edit[top].finalscore=score;
	                goto options;
	            }
	            else
	            {
	                printf("Enter a valid option!");
	            }
	        }
        }
        else if(op==3)
        {
            help();
        }
        else if(op==4)
        {
            scoreboard();
        }
        else if(op==2)
        {
            quit:
            printf("\n\t\t1. Do you want to quit the game? or 2. Start a new game?");
            printf("\n\t\tEnter option 1 or 2=");
            scanf("%d",&k);
            if(k==1)
            {
                printf("Your final score is %d",score);
                printf("\nCome back again to play!!");
                printf("\nQuitting the game.......");
                break;
            }
            else if(k==2)
            {
                printf("\n\t\tUpdating your score......");
                printf("\n\t\tYour final score is %d",score);
                goto beginning;
            }
            else
            {
printf("Enter valid option!!\n");
                goto quit;
            }
        }
        else if(op==5)
        {
            printf("\n\t\tWhose information you want to delete?=>");
            scanf("%s",deleteinfo);
            for(p=0;p<=top;p+=1)
            {
                if(strcmp(edit[p].playername,deleteinfo)==0)
                {
                    k=p;
                }
            }
            for(q=k;q<top;q+=1)
            {
                strcpy(edit[q].playername,edit[q+1].playername);
edit[q].finalscore=edit[q+1].finalscore;
            }
            top-=1;
            printf("\n\t\tPlayer information deleted!");
            if(top==-1)
            {
                printf("\n\n\t\tNo player game file found!!");
                goto beginning;
            }
            else
            {
                goto options;
            }
        }
       else
       {
           printf("\nEnter a valid option!\n");
       }
    }
    
    
}
