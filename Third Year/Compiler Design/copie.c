#include<stdio.h>
#include<string.h>
#include<ctype.h>

int buffer1[32];
int buffer2[17];
char buffer3[10][100];

int main(){
	char lst1[][20] = {"auto","double","int","struct","break","else","long","switch","case","enum","register","typedef","char","extern","return","union","const","float","short","unsigned","continue","for","signed","void","default","goto","sizeof","voltile","do","if","static","while"};
	char lst2[][20] = {"=","==","/","%","*","+","-","^","!",">","<","]","[","{","}","(",")","."};
	char string[5][100];

    int o = -1;
	printf("\nEnter strings =");
	do{
        i+= 1;
        scanf("%s", string[o]);
    }while(strcmp(string[o], "$"));

	
	int flag[5] = {0,0,0,0,0};
    int k=0, m=0, n=0;
	for(int i = 0; i < 32; i += 1){
        for(int j = 0; j < o; j+=1){
            if(flag[j] == 0){
                if(strcmp(string[j], lst1[i]) == 0){
                    buffer1[k] = i;
                    flag[j] = 1;
                    k+=1;
                }
                if(strcmp(string[j], lst2[i]) == 0){
                    buffer2[m] = i;
                    flag[j] = 1;
                    m+=1;
                }
            }
        }
    }
    for(int j = 0; j < o; j+=1){
        if(flag[j] == 0){
            if(isalpha(string[j][0])){
                strcpy(buffer3[n], string[j]);
                flag[j] = 1;
                n+=1;
            } else if(string[j][0] == '_'){
                printf("\n%s is an identifier with _.", string[j]);
                flag[j] = 1;
            } else {
                printf("\n%s is none.", string[j]);
                flag[j] = 1;
            } 
        }
    }
	if(k!=0){
	    printf("\nKeywords:");
	    for(int i = 0; i<k; i+=1){
	        printf("%s", lst1[buffer1[i]]);
	        printf(", ");
	    }
	}
	if(m!=0){
	    printf("\nSpecial Characters:");
	    for(int i = 0; i<m; i+=1){
	        printf("%s", lst2[buffer2[i]]);
	        printf(", ");
	    }
	}
	if(n!=0){
	    printf("\nIdentifiers:");
	    for(int i = 0; i<n; i+=1){
	        printf("%s", buffer3[i]);
	        printf(", ");
	    }
	}
}


