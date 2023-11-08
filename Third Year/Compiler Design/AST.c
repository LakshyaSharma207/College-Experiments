#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define AST Node structure
typedef struct AstNode {
    char type[20];
    char data;
    struct AstNode* left;
    struct AstNode* right;
}AstNode;

// Function to create a variable node
AstNode* createNode(char i) 
{
    if(strcmp(symbolTable[i].type, "Constant") == 0)
    {
        AstNode* node = malloc(sizeof(AstNode));
        strcpy(node->type, symbolTable[i].type);
        node->data = symbolTable[i].name;
        node->left = node->right = NULL;
        return node;
    }
    else if(strcmp(symbolTable[i].type, "Identifier") == 0)
    {
        AstNode* node = malloc(sizeof(AstNode));
        strcpy(node->type, symbolTable[i].type);
        node->data = symbolTable[i].name;
        node->left = node->right = NULL;
        return node;
    }
    else if(strcmp(symbolTable[i].type, "Operator") == 0) 
    {
        AstNode* node = malloc(sizeof(AstNode));
        strcpy(node->type, symbolTable[i].type);
        node->data = symbolTable[i].name;
        node->left = createNode(i-1);
        node->right = createNode(i+1);
        return node;
    }
}

// Function to print the AST
void printAst(AstNode* node) 
{
    if (node == NULL) return;

    if(strcmp(node->type, "Constant") == 0 || strcmp(node->type, "Identifier") == 0) 
    {
        printf("%c", node->data);
    } 
    if(strcmp(node->type, "Operator") == 0) 
    {
        printf("%c", node->data);
        printf("(");
        printAst(node->left);
        printf(", ");
        printAst(node->right);
        printf(")");
    }
}

int main() 
{
    AstNode* multiplyNode = createOperatorNode(createOperatorNode('*'), createVariableNode('b'), createVariableNode('c'));
    AstNode* addNode = createOperatorNode(createOperatorNode('+'), createVariableNode('a'), multiplyNode);

    printAst(addNode);

    free(a);
    free(b);
    free(c);
    free(multiplyNode);
    free(addNode);
    return 0;
}

