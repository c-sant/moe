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

    struct node {
        struct node *left;
        struct node *right;
        char *token;
    };

    struct node *head;
    struct node *mknode(struct node *left, struct node *right, char *token);
    void print_inorder(struct node *tree); 
    void print_tree(struct node* tree);

    int count = 0;
    int q;
    char type[10];
    extern int lineno;

    int sem_errors = 0;

    void check_declaration(char *c);
%}

%union {
    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;
}
%start program
%token <nd_obj> TK_PROGRAM
%token <nd_obj> TK_VAR TK_NUMBER TK_IDENTIFIER TK_STRING
%token <nd_obj> TK_TRUE TK_FALSE
%token <nd_obj> TK_PRINT
%left <nd_obj> TK_AND TK_OR
%left <nd_obj> TK_EQUAL TK_BANG_EQUAL TK_EQUAL_EQUAL
%left <nd_obj> TK_LESSER_EQUAL TK_GREATER_EQUAL TK_LESSER TK_GREATER
%left <nd_obj> TK_PLUS TK_MINUS
%left <nd_obj> TK_STAR TK_SLASH
%token <nd_obj> TK_LPAREN TK_RPAREN
%token <nd_obj> TK_LBRACE TK_RBRACE
%token <nd_obj> TK_SEMICOLON

%type <nd_obj> program body declarations declaration var_declaration statement
%type <nd_obj> expression assignment logic_or logic_and equality comparison term
%type <nd_obj> factor unary primary var_init

%%

program             : TK_PROGRAM { add_symbol('K'); } TK_IDENTIFIER 
                      { add_symbol('V'); } TK_LBRACE body TK_RBRACE             { 
                                                                                    $$.nd = mknode($6.nd, NULL, "program");
                                                                                    head = $$.nd;
                                                                                }
                    ;
                        
body                : declarations                                              { $$.nd = mknode($1.nd, NULL, "body"); }
                    ;

// statements

declarations        :                                                           { $$.nd = NULL; }
                    | declarations declaration                                  { $$.nd = mknode($1.nd, $2.nd, "declarations"); }
                    ;

declaration         : var_declaration                                           { $$.nd = mknode($1.nd, NULL, "declaration"); }
                    | statement                                                 { $$.nd = mknode($1.nd, NULL, "declaration"); }
                    ;

var_declaration     : TK_VAR { insert_type(); } TK_IDENTIFIER
                      { add_symbol('V'); } var_init                             { 
                                                                                    $3.nd = mknode(NULL, NULL, $3.name); 
                                                                                    $$.nd = mknode($3.nd, $5.nd, "var_declaration");
                                                                                }
                    ;

var_init            : TK_SEMICOLON                                              { $$.nd = mknode(NULL, NULL, "var_init"); }
                    | TK_EQUAL statement                                        { $$.nd = mknode($2.nd, NULL, "var_init"); }
                    ;

statement           : expression TK_SEMICOLON                                   { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | TK_PRINT { add_symbol('K'); } TK_LPAREN TK_STRING 
                      { add_symbol('C'); } TK_RPAREN TK_SEMICOLON               { $$.nd = mknode(NULL, NULL, "print"); }
                    ;

// expressions

expression          : assignment                                                { $$.nd = mknode($1.nd, NULL, "expression"); }
                    ;

assignment          : TK_IDENTIFIER TK_EQUAL assignment                         { $$.nd = mknode($1.nd, $3.nd, "assignment"); }
                    | logic_or                                                  { $$.nd = mknode($1.nd, NULL, "assignment"); }
                    ;

logic_or            : logic_and TK_OR logic_and                                 { $$.nd = mknode($1.nd, $3.nd, "logic_or"); }
                    | logic_and                                                 { $$.nd = mknode($1.nd, NULL, "logic_or"); }
                    ;

logic_and           : equality TK_AND equality                                  { $$.nd = mknode($1.nd, $3.nd, "logic_and"); }
                    | equality                                                  { $$.nd = mknode($1.nd, NULL, "logic_and"); }
                    ;

equality            : comparison TK_EQUAL_EQUAL comparison                      { $$.nd = mknode($1.nd, $3.nd, "equality"); }
                    | comparison TK_BANG_EQUAL comparison                       { $$.nd = mknode($1.nd, $3.nd, "equality"); }
                    | comparison                                                { $$.nd = mknode($1.nd, NULL, "equality"); }
                    ;

comparison          : term comparison_operator term                             { $$.nd = mknode($1.nd, $3.nd, "comparison"); }
                    | term                                                      { $$.nd = mknode($1.nd, NULL, "comparison"); }
                    ;

term                : factor TK_PLUS factor                                     { $$.nd = mknode($1.nd, $3.nd, "term"); }
                    | factor TK_MINUS factor                                    { $$.nd = mknode($1.nd, $3.nd, "term"); }
                    | factor                                                    { $$.nd = mknode($1.nd, NULL, "term"); }
                    ;

factor              : unary TK_STAR unary                                       { $$.nd = mknode($1.nd, $3.nd, "factor"); }
                    | unary TK_SLASH unary                                      { $$.nd = mknode($1.nd, $3.nd, "factor"); }
                    | unary                                                     { $$.nd = mknode($1.nd, NULL, "factor"); }
                    ;

unary               : TK_MINUS primary                                          { $$.nd = mknode($2.nd, NULL, "unary"); }
                    | primary                                                   { $$.nd = mknode($1.nd, NULL, "unary"); }
                    ;

primary             : TK_TRUE                                                   { add_symbol('C'); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_FALSE                                                  { add_symbol('C'); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_NUMBER                                                 { add_symbol('C'); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_STRING                                                 { add_symbol('C'); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_IDENTIFIER                                             { $$.nd = mknode(NULL, NULL, $1.name); }
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
	printf("\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
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

	printf("\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	print_tree(head); 
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

    if (c == 'V') {
        for (int i = 0; i < 10; i++) {
            if (!strcmp(reserved[i], strdup(yytext))) {
                sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword.\n", lineno + 1, yytext);
                sem_errors++;
                return;
            }
        }
    }

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
    else if (c == 'V') {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed.\n", lineno + 1, yytext);
        sem_errors++;
    }
}

struct node *mknode(struct node *left, struct node *right, char *token) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    char *newstr = (char *)malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;

    return newnode;
}

void print_tree(struct node* tree) {
	printf("\n\n Inorder traversal of the Parse Tree: \n\n");
	print_inorder(tree);
	printf("\n\n");
}

void print_inorder(struct node *tree) {
    int i; 
    if (tree->left) {
        print_inorder(tree->left); 
    } 
    printf("%s, ", tree->token); 
    if (tree->right) {  
        print_inorder(tree->right); 
    }
}

void check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Undeclared variable \"%s\".\n", lineno + 1, c);
        sem_errors++;
    }
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}