%{
    #include "moe.tab.h"
    int lineno = 0;    
%}

%option yylineno

%%

";"                         { return TK_SEMICOLON; }
"("                         { return TK_LPAREN; }
")"                         { return TK_RPAREN; }
"{"                         { return TK_LBRACE; }
"}"                         { return TK_RBRACE; }
"<="                        { return TK_LESSER_EQUAL; }
">="                        { return TK_GREATER_EQUAL; }
"<"                         { return TK_LESSER; }
">"                         { return TK_GREATER; }
"!="                        { return TK_BANG_EQUAL; }
"=="                        { return TK_EQUAL_EQUAL; }
"="                         { return TK_EQUAL; }
"&&"                        { return TK_AND; }
"||"                        { return TK_OR; }
"+"                         { return TK_PLUS; }
"-"                         { return TK_MINUS; }
"*"                         { return TK_STAR; }
"/"                         { return TK_SLASH; }
"true"                      { return TK_TRUE; }
"false"                     { return TK_FALSE; }
"print"                     { return TK_PRINT; }
"var"                       { return TK_VAR; }
"program"                   { return TK_PROGRAM; }
[0-9]+(\.[0-9]+)*           { return TK_NUMBER; }
[a-zA-Z_]([a-zA-Z0-9_])*    { return TK_IDENTIFIER; }
["'].*["']                  { return TK_STRING; }
\n                          { lineno++; }
[ \t\r]                     { ; }
.                           { printf("unexpected token: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}