%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include "moe.lex.c"
    
    #define TOTAL_KEYWORDS 22

    void yyerror(const char *s);
    int yylex();
    int yywrap();

    void insert_type();
    void set_global();
    void unset_global();

    int search(char *type);
    void add_symbol(char symbol_type, char *data_type);

    struct symbol {
        char *id_name;
        char *data_type;
        char *symbol_type;
        int line_no;
        bool is_global;
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
    bool is_global = false;
    extern int lineno;

    int sem_errors = 0;
    char errors[10][100];

    char reserved[TOTAL_KEYWORDS][10] = {
        "var", "program", "print", "if", "else", "int", "position", "string",
        "pos", "parameter", "param", "par", "open", "close", "jaw", "delay",
        "global", "move", "await", "for", "between", "bool"
    };

    void check_declaration(char *c);
    void validate_types(char *type1, char *type2, char *msg);
    char *get_type(char *id_name);
%}

%union {
    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;
}
%start program
%token <nd_obj> TK_PROGRAM
%token <nd_obj> TK_OPEN TK_JAW TK_CLOSE TK_DELAY TK_GLOBAL
%token <nd_obj> TK_MOVE TK_AWAIT
%token <nd_obj> TK_STRING_LITERAL TK_NUMBER TK_IDENTIFIER TK_TRUE TK_FALSE 
%token <nd_obj> TK_STRING TK_INT TK_POSITION TK_PARAMETER TK_BOOL
%token <nd_obj> TK_PRINT
%token <nd_obj> TK_IF TK_ELSE TK_FOR TK_BETWEEN
%left <nd_obj> TK_AND TK_OR
%left <nd_obj> TK_EQUAL TK_BANG_EQUAL TK_EQUAL_EQUAL
%left <nd_obj> TK_LESSER_EQUAL TK_GREATER_EQUAL TK_LESSER TK_GREATER
%left <nd_obj> TK_PLUS TK_MINUS
%left <nd_obj> TK_STAR TK_SLASH
%token <nd_obj> TK_LPAREN TK_RPAREN
%token <nd_obj> TK_LBRACE TK_RBRACE
%token <nd_obj> TK_SEMICOLON TK_COMMA

%type <nd_obj> program body declarations declaration var_declaration statement
%type <nd_obj> print_statement if_statement else_statement open_statement
%type <nd_obj> jaw_statement two_arguments close_statement optional_argument
%type <nd_obj> delay_statement move_statement moved_statement loop_statement 
%type <nd_obj> expression assignment logic equality comparison term factor unary  
%type <nd_obj> primary var_init access_modifier numeric_variable 
%type <nd_obj> expression_statement

%%

program             : TK_PROGRAM TK_IDENTIFIER { add_symbol('V', "string"); } 
                      TK_LBRACE body TK_RBRACE                                  { 
                                                                                    $$.nd = mknode($5.nd, NULL, "program");
                                                                                    head = $$.nd;
                                                                                }
                    ;
                        
body                : declarations                                              { $$.nd = mknode($1.nd, NULL, "body"); }
                    ;

// declarations

declarations        :                                                           { $$.nd = NULL; }
                    | declarations declaration                                  { $$.nd = mknode($1.nd, $2.nd, "declarations"); }
                    ;

declaration         : var_declaration                                           { $$.nd = mknode($1.nd, NULL, "declaration"); }
                    | statement                                                 { $$.nd = mknode($1.nd, NULL, "declaration"); }
                    ;

var_declaration     : access_modifier data_type TK_IDENTIFIER
                      { add_symbol('V', type); } var_init                       {
                                                                                    validate_types(
                                                                                        get_type($3.name),
                                                                                        get_type($5.name),
                                                                                        "Line %d: Incorrectly initialized value (expected %s, got %s).\n"
                                                                                    );
                                                                                    $3.nd = mknode(NULL, NULL, $3.name); 
                                                                                    $$.nd = mknode($3.nd, $5.nd, "var_declaration");
                                                                                }
                    ;

var_init            : TK_SEMICOLON                                              { $$.nd = mknode(NULL, NULL, "var_init"); }
                    | TK_EQUAL statement                                        { strcpy($$.name, $2.name); $$.nd = mknode($2.nd, NULL, "var_init"); }
                    ;

data_type           : TK_STRING                                                 { insert_type(); }
                    | TK_INT                                                    { insert_type(); }
                    | TK_BOOL                                                   { insert_type(); }
                    | TK_POSITION                                               { insert_type(); }
                    | TK_PARAMETER                                              { insert_type(); }
                    ;

access_modifier     : TK_GLOBAL                                                 { set_global(); $$.nd = NULL; }
                    |                                                           { unset_global(); $$.nd = NULL; }
                    ;

// statements

statement           : expression_statement                                      { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | print_statement                                           { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | if_statement                                              { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | loop_statement                                            { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | open_statement                                            { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | jaw_statement                                             { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | close_statement                                           { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | delay_statement                                           { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | move_statement                                            { $$.nd = mknode($1.nd, NULL, "statement"); }
                    | moved_statement                                           { $$.nd = mknode($1.nd, NULL, "statement"); }
                    ;

expression_statement: expression TK_SEMICOLON                                   { $$.nd = mknode($1.nd, NULL, $1.name); }
                    ;

print_statement     : TK_PRINT TK_LPAREN TK_STRING_LITERAL 
                      { add_symbol('C', "string"); } TK_RPAREN TK_SEMICOLON     { $$.nd = mknode(NULL, NULL, "print"); }
                    ;

if_statement        : TK_IF TK_LPAREN logic TK_RPAREN TK_LBRACE declarations 
                      TK_RBRACE else_statement                                  { 
                                                                                    struct node *if_node = mknode($3.nd, $6.nd, "if");
                                                                                    $$.nd = mknode(if_node, $8.nd, "if-else"); 
                                                                                }
                    ;

else_statement      :                                                           { $$.nd = NULL; }
                    | TK_ELSE if_statement                                      { $$.nd = mknode($2.nd, NULL, "else-if"); }
                    | TK_ELSE TK_LBRACE declarations TK_RBRACE                  { $$.nd = mknode($3.nd, NULL, "else"); }
                    ;

loop_statement      : TK_FOR TK_LPAREN TK_IDENTIFIER 
                      { add_symbol('V', "int"); } TK_BETWEEN numeric_variable 
                      TK_COMMA numeric_variable TK_RPAREN TK_LBRACE declarations 
                      TK_RBRACE                                                 {
                                                                                    validate_types(
                                                                                        "int",
                                                                                        get_type($6.name),
                                                                                        "Line %d: lower bound of loop must be %s (got %s)."
                                                                                    ); 
                                                                                    validate_types(
                                                                                        "int",
                                                                                        get_type($8.name),
                                                                                        "Line %d: upper bound of loop must be %s (got %s)."
                                                                                    ); 
                                                                                    $$.nd = mknode($11.nd, NULL, "for-loop");
                                                                                }
                    ;

open_statement      : TK_OPEN TK_LPAREN optional_argument TK_RPAREN TK_SEMICOLON{ $$.nd = mknode($4.nd, NULL, "open"); }
                    ;

close_statement     : TK_CLOSE TK_LPAREN optional_argument TK_RPAREN 
                      TK_SEMICOLON                                              { $$.nd = mknode($4.nd, NULL, "close"); }
                    ;

optional_argument   :                                                           { $$.nd = NULL; }
                    | term                                                      { $$.nd = $1.nd; }
                    ;

jaw_statement       : TK_JAW TK_LPAREN two_arguments TK_RPAREN TK_SEMICOLON     { $$.nd = mknode($4.nd, NULL, "jaw"); }
                    ;

move_statement      : TK_MOVE TK_LPAREN two_arguments TK_RPAREN TK_SEMICOLON    { $$.nd = mknode($4.nd, NULL, "move"); }
                    ;

moved_statement     : TK_AWAIT move_statement                                   { $$.nd = mknode($1.nd, NULL, "moved"); }
                    ;

two_arguments       : term                                                      { $$.nd = $1.nd; }                                          
                    | term TK_COMMA term                                        { $$.nd = mknode($1.nd, $3.nd, "two_arguments"); }
                    ;

delay_statement     : TK_DELAY TK_LPAREN term TK_RPAREN TK_SEMICOLON            { $$.nd = mknode($4.nd, NULL, "delay"); }
                    ;

// expressions

expression          : assignment                                                { $$.nd = mknode($1.nd, NULL, "expression"); }
                    ;

assignment          : TK_IDENTIFIER { check_declaration($1.name); } TK_EQUAL 
                      assignment                                                { 
                                                                                    validate_types(
                                                                                        get_type($1.name), 
                                                                                        get_type($4.name), 
                                                                                        "Line %d: Incorrectly assigned value (expected %s, got %s).\n"
                                                                                    ); 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "assignment"); 
                                                                                }
                    | logic                                                     { $$.nd = mknode($1.nd, NULL, "assignment"); }
                    ;

logic               : logic TK_OR equality                                      { $$.nd = mknode($1.nd, $3.nd, "logic"); }
                    | logic TK_AND equality                                     { $$.nd = mknode($1.nd, $3.nd, "logic"); }
                    | equality                                                  { $$.nd = mknode($1.nd, NULL, "logic"); }
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

primary             : TK_TRUE                                                   { add_symbol('C', "bool"); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_FALSE                                                  { add_symbol('C', "bool"); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_NUMBER                                                 { add_symbol('C', "int"); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_STRING_LITERAL                                         { add_symbol('C', "string"); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_IDENTIFIER { check_declaration($1.name); }             { $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_LPAREN expression TK_RPAREN
                    ;

numeric_variable    : TK_NUMBER                                                 { add_symbol('C', "int"); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_IDENTIFIER { check_declaration($1.name); }             { $$.nd = mknode(NULL, NULL, $1.name); }
                    ;

/* text_variable       : TK_STRING_LITERAL                                         { add_symbol('C'); $$.nd = mknode(NULL, NULL, $1.name); }
                    | TK_IDENTIFIER { check_declaration($1.name); }             { $$.nd = mknode(NULL, NULL, $1.name); }
                    ; */

comparison_operator : TK_GREATER
                    | TK_LESSER
                    | TK_GREATER_EQUAL
                    | TK_LESSER_EQUAL
                    ;

%%

int main(int argc, char **argv) {
    yydebug = 0;
    yyparse();

    printf("\n\n");
	printf("\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER    GLOBAL \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t%d\n", 
                symbol_table[i].id_name, 
                symbol_table[i].data_type, 
                symbol_table[i].symbol_type, 
                symbol_table[i].line_no, 
                symbol_table[i].is_global
        );
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].data_type);
	}
	printf("\n\n");

	printf("\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	print_tree(head); 
	printf("\n\n");

    printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
	if(sem_errors > 0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
}

void insert_type() {
    strcpy(type, yytext);
}

void set_global() {
    is_global = true;
}

void unset_global() {
    is_global = false;
}

int search(char *id_name) {
    int i;
    for (i = count - 1; i >= 0; i--) {
        if (strcmp(symbol_table[i].id_name, id_name) == 0) {
            return -1;
            break;
        }
    }

    return 0;
}

void add_symbol(char symbol_type, char *data_type) {
    // symbol type can be either V for variables or C for constants
    q = search(yytext);

    if (symbol_type == 'V') {
        // checks if variable name is equals to keyword

        for (int i = 0; i < TOTAL_KEYWORDS; i++) {
            if (!strcmp(reserved[i], strdup(yytext))) {
                sprintf(errors[sem_errors], "Line %d: \"%s\" is a reserved keyword name and can't be used as variable.\n", lineno + 1, yytext);
                sem_errors++;
                return;
            }
        }
    }

    if(!q) {
        symbol_table[count].id_name = strdup(yytext);
        symbol_table[count].data_type = strdup(data_type);
        symbol_table[count].line_no = lineno;
        symbol_table[count].is_global = is_global;

        if (symbol_type == 'V') {
            symbol_table[count].symbol_type = "Variable";
        }
        else if (symbol_type == 'C') {
            symbol_table[count].symbol_type = "Constant";
        }

        count++;
    }
    else if (symbol_type == 'V') {
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

void validate_types(char *type1, char *type2, char *msg)
{
  // type1 must match type2

  if (strcmp(type1, type2))
  {
    sprintf(errors[sem_errors], msg, lineno + 1, type1, type2);
    sem_errors++;
  }
}

char *get_type(char *id_name) {
    for (int i = 0; i < count; i++)
    {
        if(!strcmp(symbol_table[i].id_name, id_name)) {
            return symbol_table[i].data_type;
        }
    }
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}