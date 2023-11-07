%{
#include <stdio.h>
int count=0;
%}

%%
// counting 
([a-z0-9A-Z])* {count ++;}
"\n" {printf("Total number of words=%d\n", count); count=0; }
// For Keywords
if|else|while|for|int|float|char    { printf("Keywords: %s\n", yytext); }

// Special symbols
[+\-*/=;(){}]                      { printf("Special Symbols: %c\n", yytext[0]); }

// Ignore whitespace and newline characters
[ \t\n] ;

// Identifiers
[a-zA-Z_][a-zA-Z0-9_]*             { printf("Identifiers: %s\n", yytext); }

// Comment detection
"/*"                             { printf("Start of Comment: %s\n", yytext); }
"*/"                             { printf("End of Comment: %s\n", yytext); }

// #include and libraries
^#include.*               { printf("Library: %s\n", yytext); }

// Catch-all rule for unrecognized characters
.                                  { printf("String is none: %s\n", yytext); }

%%

int main() {
    printf("Enter your Text: ");
    yylex();
    return 0;
}
