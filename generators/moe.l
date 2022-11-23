%{
    #include "moe.tab.h"
    int lineno = 0;    
%}

%option yylineno

%%

";"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_SEMICOLON; }
","                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_COMMA; }
"("                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_LPAREN; }
")"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_RPAREN; }
"{"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_LBRACE; }
"}"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_RBRACE; }
"<="                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_LESSER_EQUAL; }
">="                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_GREATER_EQUAL; }
"<"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_LESSER; }
">"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_GREATER; }
"!="                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_BANG_EQUAL; }
"=="                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_EQUAL_EQUAL; }
"="                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_EQUAL; }
"&&"                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_AND; }
"||"                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_OR; }
"+"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_PLUS; }
"-"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_MINUS; }
"*"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_STAR; }
"/"                         { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_SLASH; }
"true"                      { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_TRUE; }
"false"                     { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_FALSE; }
"print"                     { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_PRINT; }
"int"                       { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_INT; }
"position"                  { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_POSITION; }
"parameter"                 { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_PARAMETER; }
"program"                   { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_PROGRAM; }
"if"                        { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_IF; }
"else"                      { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_ELSE; }
"for"                       { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_FOR; }
"between"                   { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_BETWEEN; }
"open"                      { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_OPEN; }
"close"                     { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_CLOSE; }
"jaw"                       { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_JAW; }
"delay"                     { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_DELAY; }
"move"                      { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_MOVE; }
"await"                     { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_AWAIT; }
"global"                    { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_GLOBAL; }
[0-9]+                      { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_NUMBER; }
[a-zA-Z_]([a-zA-Z0-9_])*    { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_IDENTIFIER; }
"["[ABC]"]"                 { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_POSITION_GROUP; }
\"([^\\\"]|\\.)*\"          { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_STRING_LITERAL; }
\'([^\\\"]|\\.)*\'          { snprintf(yylval.nd_obj.name, sizeof(yylval.nd_obj.name), (yytext)); return TK_STRING_LITERAL; }
\n                          { lineno++; }
[ \t\r]                     { ; }
.                           { printf("unexpected token: %s\n", yytext); }

%%

int yywrap() {
    return 1;
}