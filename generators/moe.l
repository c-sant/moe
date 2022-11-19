%{
    #include "moe.tab.h"
    int lineno = 0;    
%}

%option yylineno

%%

";"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_SEMICOLON; }
"("                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_LPAREN; }
")"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_RPAREN; }
"{"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_LBRACE; }
"}"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_RBRACE; }
"<="                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_LESSER_EQUAL; }
">="                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_GREATER_EQUAL; }
"<"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_LESSER; }
">"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_GREATER; }
"!="                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_BANG_EQUAL; }
"=="                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_EQUAL_EQUAL; }
"="                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_EQUAL; }
"&&"                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_AND; }
"||"                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_OR; }
"+"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_PLUS; }
"-"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_MINUS; }
"*"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_STAR; }
"/"                         { strcpy(yylval.nd_obj.name, (yytext)); return TK_SLASH; }
"true"                      { strcpy(yylval.nd_obj.name, (yytext)); return TK_TRUE; }
"false"                     { strcpy(yylval.nd_obj.name, (yytext)); return TK_FALSE; }
"print"                     { strcpy(yylval.nd_obj.name, (yytext)); return TK_PRINT; }
"int"                       { strcpy(yylval.nd_obj.name, (yytext)); return TK_INT; }
"string"                    { strcpy(yylval.nd_obj.name, (yytext)); return TK_STRING; }
"position"                  { strcpy(yylval.nd_obj.name, (yytext)); return TK_POSITION; }
"program"                   { strcpy(yylval.nd_obj.name, (yytext)); return TK_PROGRAM; }
"if"                        { strcpy(yylval.nd_obj.name, (yytext)); return TK_IF; }
"else"                      { strcpy(yylval.nd_obj.name, (yytext)); return TK_ELSE; }
[0-9]+                      { strcpy(yylval.nd_obj.name, (yytext)); return TK_NUMBER; }
[a-zA-Z_]([a-zA-Z0-9_])*    { strcpy(yylval.nd_obj.name, (yytext)); return TK_IDENTIFIER; }
["'].*["']                  { strcpy(yylval.nd_obj.name, (yytext)); return TK_STRING_LITERAL; }
\n                          { lineno++; }
[ \t\r]                     { ; }
.                           { printf("unexpected token: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}