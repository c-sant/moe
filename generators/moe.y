%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "moe.lex.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();

    void insert_type();
    int search(char *type);
    void add_symbol(char c);

    struct datatype {
        char *id_name;
        char *data_type;
        char *type;
        int line_no;
    } symbol_table[255];

    int count = 0;
    int q;
    char type[10];
    extern int lineno;
%}

%start program
%token TK_PROGRAM
%token TK_VAR TK_NUMBER TK_IDENTIFIER TK_STRING
%token TK_TRUE TK_FALSE
%token TK_PRINT
%left TK_AND TK_OR
%left TK_EQUAL TK_BANG_EQUAL TK_EQUAL_EQUAL
%left TK_LESSER_EQUAL TK_GREATER_EQUAL TK_LESSER TK_GREATER
%left TK_PLUS TK_MINUS
%left TK_STAR TK_SLASH
%token TK_LPAREN TK_RPAREN
%token TK_LBRACE TK_RBRACE
%token TK_SEMICOLON

%%

program             : TK_PROGRAM { add_symbol('K'); } TK_IDENTIFIER { add_symbol('V'); } TK_LBRACE body TK_RBRACE
                    ;
                        
body                : declarations
                    ;

// statements

declarations        : 
                    | declarations declaration
                    ;

declaration         : var_declaration 
                    | statement
                    ;

var_declaration     : TK_VAR { insert_type(); } TK_IDENTIFIER { add_symbol('V'); } var_init
                    ;

var_init            : TK_SEMICOLON
                    | TK_EQUAL statement
                    ;

statement           : expression TK_SEMICOLON
                    | TK_PRINT { add_symbol('K'); } TK_LPAREN TK_STRING { add_symbol('C'); } TK_RPAREN TK_SEMICOLON 
                    ;

// expressions

expression          : assignment
                    ;

assignment          : TK_IDENTIFIER TK_EQUAL assignment
                    | logic_or
                    ;

logic_or            : logic_and TK_OR logic_and
                    | logic_and
                    ;

logic_and           : equality TK_AND equality
                    | equality
                    ;

equality            : comparison TK_EQUAL_EQUAL comparison
                    | comparison TK_BANG_EQUAL comparison
                    | comparison
                    ;

comparison          : term comparison_operator term
                    | term
                    ;

term                : factor TK_PLUS factor
                    | factor TK_MINUS factor
                    | factor
                    ;

factor              : unary TK_STAR unary
                    | unary TK_SLASH unary
                    | unary
                    ;

unary               : TK_MINUS primary
                    | primary
                    ;

primary             : TK_TRUE { add_symbol('C'); }
                    | TK_FALSE { add_symbol('C'); }
                    | TK_NUMBER { add_symbol('C'); }
                    | TK_STRING { add_symbol('C'); }
                    | TK_IDENTIFIER
                    | TK_LPAREN expression TK_RPAREN
                    ;

comparison_operator : TK_GREATER
                    | TK_LESSER
                    | TK_GREATER_EQUAL
                    | TK_LESSER_EQUAL
                    ;

%%

int main() {
    yydebug = 0;
    yyparse();

    printf("\n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
}

void insert_type() {
    strcpy(type, yytext);
}

int search(char *type) {
    int i;
    for (i = count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, type) == 0) {
            return -1;
            break;
        }
    }

    return 0;
}

void add_symbol(char c) {
    q = search(yytext);

    if(!q) {
        if (c == 'K') {
            symbol_table[count].id_name = strdup(yytext);
            symbol_table[count].data_type = strdup("N/A");
            symbol_table[count].line_no = lineno;
            symbol_table[count].type = strdup("Keyword\t");
            count++;
        }
        else if (c == 'V') {
            symbol_table[count].id_name = strdup(yytext);
            symbol_table[count].data_type = strdup(type);
            symbol_table[count].line_no = lineno;
            symbol_table[count].type = strdup("Variable");
            count++;
        }
        else if (c == 'C') {
            symbol_table[count].id_name = strdup(yytext);
            symbol_table[count].data_type = strdup("CONST");
            symbol_table[count].line_no = lineno;
            symbol_table[count].type = strdup("Constant");
            count++;
        }
    }
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}