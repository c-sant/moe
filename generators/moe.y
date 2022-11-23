/* ABC */

%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <stdbool.h>
    #include "moe.lex.c"
    
    #define TOTAL_KEYWORDS 22
    #define OUTPUT_FILE_PATH "a.txt"

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

    FILE *output_file;

    int cstep = 0;
    int stepdebug;

    void presolved_to_expr(struct var_name *obj);
    void write_to_file(char *src);
%}

%union {
    // name: name of the symbol
    // node: node structure of the symbol (links to other symbols)
    // presolved: the result of solving this symbol
    // symbol_type: 'C' for constant; 'E' for expression
    struct var_name {
        char name[100];
        struct node *nd;
        int presolved;
        int is_presolved;
        char expr[256];
    } nd_obj;
}
%start program
%token <nd_obj> TK_PROGRAM
%token <nd_obj> TK_OPEN TK_JAW TK_CLOSE TK_DELAY TK_GLOBAL
%token <nd_obj> TK_MOVE TK_AWAIT
%token <nd_obj> TK_STRING_LITERAL TK_NUMBER TK_IDENTIFIER TK_TRUE TK_FALSE 
%token <nd_obj> TK_STRING TK_INT TK_POSITION TK_PARAMETER
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
%type <nd_obj> jaw_statement two_numbers close_statement optional_argument
%type <nd_obj> delay_statement move_statement moved_statement loop_statement 
%type <nd_obj> expression assignment logic equality comparison term factor unary  
%type <nd_obj> primary var_init access_modifier numeric_variable if_condition
%type <nd_obj> expression_statement comparison_operator if_valid_operator

%%

program             : TK_PROGRAM TK_IDENTIFIER { add_symbol('V', "string"); } 
                      TK_LBRACE body TK_RBRACE                                  { 
                                                                                    $$.nd = mknode($5.nd, NULL, "program");
                                                                                    head = $$.nd;

                                                                                    write_to_file($5.expr);
                                                                                }
                    ;
                        
body                : declarations                                              { 
                                                                                    $$.nd = mknode($1.nd, NULL, "body"); 
                                                                                    
                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                }
                    ;

// declarations

declarations        :                                                           { 
                                                                                    $$.nd = NULL; 
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "");
                                                                                }
                    | declarations declaration                                  { 
                                                                                    $$.nd = mknode($1.nd, $2.nd, "declarations");

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                    if ($2.is_presolved) presolved_to_expr(&$2);

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n%s", $1.expr, $2.expr);
                                                                                }
                    ;

declaration         : var_declaration                                           { 
                                                                                    $$.nd = mknode($1.nd, NULL, "declaration"); 
                                                                                    
                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                }
                    | statement                                                 { 
                                                                                    $$.nd = mknode($1.nd, NULL, "declaration"); 
                                                                                    
                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                }
                    ;

var_declaration     : access_modifier data_type TK_IDENTIFIER
                      { add_symbol('V', type); } var_init                       {
                                                                                    char *globality = is_global ? "GLOBAL" : "DEFINE";
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s %s\n", globality, $3.name);

                                                                                    if ($5.nd != NULL)
                                                                                    {

                                                                                        // validate_types(
                                                                                        //     get_type($3.name),
                                                                                        //     get_type($5.name),
                                                                                        //     "Line %d: Incorrectly initialized value (expected %s, got %s).\n"
                                                                                        // );
                                                                                        snprintf($$.expr, sizeof($$.expr), "%sSET %s = %s\n", $$.expr, $3.name, $5.name);
                                                                                    }

                                                                                    $3.nd = mknode(NULL, NULL, $3.name); 
                                                                                    $$.nd = mknode($3.nd, $5.nd, "var_declaration");
                                                                                }
                    ;

var_init            : TK_SEMICOLON                                              { $$.nd = NULL; }
                    | TK_EQUAL expression_statement                             {
                                                                                    if ($2.is_presolved) presolved_to_expr(&$2);
                                                                                    
                                                                                    snprintf($$.name, sizeof($$.name), "%s", $2.expr);
                                                                                    
                                                                                    $$.nd = mknode($2.nd, NULL, "var_init"); 
                                                                                }
                    ;

data_type           : TK_STRING                                                 { insert_type(); }
                    | TK_INT                                                    { insert_type(); }
                    | TK_POSITION                                               { insert_type(); }
                    | TK_PARAMETER                                              { insert_type(); }
                    ;

access_modifier     : TK_GLOBAL                                                 { set_global(); $$.nd = NULL; }
                    |                                                           { unset_global(); $$.nd = NULL; }
                    ;

// statements

statement           : expression_statement                                      { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | print_statement                                           { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | if_statement                                              { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | loop_statement                                            { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | open_statement                                            { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | jaw_statement                                             { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | close_statement                                           { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | delay_statement                                           { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | move_statement                                            { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    | moved_statement                                           { 
                                                                                    $$.nd = mknode($1.nd, NULL, "statement");

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s\n", $1.expr); 
                                                                                }
                    ;

expression_statement: expression TK_SEMICOLON                                   { 
                                                                                    $$.nd = mknode($1.nd, NULL, $1.name); 

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);    
                                                                                }
                    ;

print_statement     : TK_PRINT TK_LPAREN TK_STRING_LITERAL 
                      { add_symbol('C', "string"); } TK_RPAREN TK_SEMICOLON     { 
                                                                                    $$.nd = mknode(NULL, NULL, "print"); 

                                                                                    snprintf($$.expr, sizeof($$.expr), "PRINT %s", $3.name);
                                                                                }
                    ;

if_statement        : TK_IF TK_LPAREN if_condition TK_RPAREN TK_LBRACE 
                      declarations TK_RBRACE else_statement                     { 
                                                                                    struct node *if_node = mknode($3.nd, $6.nd, "if");
                                                                                    $$.nd = mknode(if_node, $8.nd, "if-else");

                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);
                                                                                    if ($6.is_presolved) presolved_to_expr(&$6);
                                                                                    if ($8.is_presolved) presolved_to_expr(&$8);
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "IF %s\n%s\n%s\nENDIF", $3.expr, $6.expr, $8.expr);
                                                                                }
                    ;

else_statement      :                                                           { 
                                                                                    $$.nd = NULL; 
                                                                                
                                                                                    snprintf($$.expr, sizeof($$.expr), "");
                                                                                }
                    | TK_ELSE if_statement                                      { 
                                                                                    $$.nd = mknode($2.nd, NULL, "else-if"); 

                                                                                    if ($2.is_presolved) presolved_to_expr(&$2);
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "ELSE\n%s", $2.expr);
                                                                                }
                    | TK_ELSE TK_LBRACE declarations TK_RBRACE                  { 
                                                                                    $$.nd = mknode($3.nd, NULL, "else"); 
                                                                                    
                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                    snprintf($$.expr, sizeof($$.expr), "ELSE\n%s", $3.expr);
                                                                                }
                    ;

if_condition        : if_condition if_valid_operator term                       {
                                                                                    $$.nd = mknode($1.nd, $3.nd, "if_condition");

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s %s %s", $1.expr, $2.expr, $3.expr);
                                                                                    $$.is_presolved = 0;
                                                                                }
                    | if_condition TK_OR if_condition                           {
                                                                                    $$.nd = mknode($1.nd, $3.nd, "if_condition");

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s ORIF %s\n", $1.expr, $3.expr);                                                                                    
                                                                                    $$.is_presolved = 0;
                                                                                }
                    | if_condition TK_AND if_condition                          {
                                                                                    $$.nd = mknode($1.nd, $3.nd, "if_condition");

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s ANDIF %s\n", $1.expr, $3.expr);                                                                                    
                                                                                    $$.is_presolved = 0;
                                                                                }
                    | term                                                      {
                                                                                    $$.nd = mknode($1.nd, NULL, "if-condition");

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                    $$.is_presolved = 0;
                                                                                }
                    ;

if_valid_operator   : comparison_operator                                       { snprintf($$.expr, sizeof($$.expr), "%s", $1.expr); }
                    | TK_EQUAL_EQUAL                                            { snprintf($$.expr, sizeof($$.expr), "="); }
                    | TK_BANG_EQUAL                                             { snprintf($$.expr, sizeof($$.expr), "<>"); }
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

open_statement      : TK_OPEN TK_LPAREN optional_argument TK_RPAREN TK_SEMICOLON{ 
                                                                                    $$.nd = mknode($4.nd, NULL, "open"); 
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "OPEN %s", $3.expr);
                                                                                }
                    ;

close_statement     : TK_CLOSE TK_LPAREN optional_argument TK_RPAREN 
                      TK_SEMICOLON                                              { 
                                                                                    $$.nd = mknode($4.nd, NULL, "close"); 
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "CLOSE %s", $3.expr);
                                                                                }
                    ;

optional_argument   :                                                           { 
                                                                                    $$.nd = NULL; 
                                                                                
                                                                                    snprintf($$.expr, sizeof($$.expr), "");
                                                                                }
                    | term                                                      { 
                                                                                    $$.nd = $1.nd; 
                                                                                
                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);    
                                                                                
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                }
                    ;

jaw_statement       : TK_JAW TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON       { 
                                                                                    $$.nd = mknode($3.nd, NULL, "jaw"); 
                                                                                
                                                                                    snprintf($$.expr, sizeof($$.expr), "JAW %s", $3.expr);
                                                                                }
                    ;

move_statement      : TK_MOVE TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON      { 
                                                                                    $$.nd = mknode($3.nd, NULL, "move"); 
                                                                                
                                                                                    snprintf($$.expr, sizeof($$.expr), "MOVE %s", $3.expr);
                                                                                }
                    ;

moved_statement     : TK_AWAIT TK_MOVE TK_LPAREN two_numbers TK_RPAREN 
                      TK_SEMICOLON                                              { 
                                                                                    $$.nd = mknode($4.nd, NULL, "moved"); 

                                                                                    snprintf($$.expr, sizeof($$.expr), "MOVED %s", $4.expr);
                                                                                }
                    ;

two_numbers         : numeric_variable                                          { 
                                                                                    $$.nd = $1.nd; 

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);    
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                }                                          
                    | numeric_variable TK_COMMA numeric_variable                { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "two_numbers"); 

                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);    
                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);    

                                                                                    snprintf($$.expr, sizeof($$.expr), "%s %s", $1.expr, $3.expr);
                                                                                }
                    ;

delay_statement     : TK_DELAY TK_LPAREN term TK_RPAREN TK_SEMICOLON            { 
                                                                                    $$.nd = mknode($4.nd, NULL, "delay");

                                                                                    if ($3.is_presolved) presolved_to_expr(&$3);
                                                                                    snprintf($$.expr, sizeof($$.expr), "DELAY %s", $3.expr); 
                                                                                }
                    ;

// expressions

expression          : assignment                                                {
                                                                                    $$.nd = mknode($1.nd, NULL, "expression"); 
                                                                                    
                                                                                    if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                }
                    ;

assignment          : TK_IDENTIFIER { check_declaration($1.name); } TK_EQUAL 
                      assignment                                                {
                                                                                    validate_types(
                                                                                        get_type($1.name), 
                                                                                        get_type($4.name), 
                                                                                        "Line %d: Incorrectly assigned value (expected %s, got %s).\n"
                                                                                    ); 
                                                                                    
                                                                                    $$.nd = mknode($1.nd, $3.nd, "assignment");
                                                                                    
                                                                                    if ($4.is_presolved) presolved_to_expr(&$4);
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "SET %s = %s", $1.name, $4.expr);
                                                                                    $$.is_presolved = 0;
                                                                                    
                                                                                    if (stepdebug) printf("%d: solved assignment at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                }
                    | logic                                                     { 
                                                                                    $$.nd = mknode($1.nd, NULL, "assignment"); 
                                                                                    if ($1.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved assignment at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved assignment at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    ;

logic               : logic TK_OR equality                                      { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "logic"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved || $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved OR logic at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s || %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved OR logic at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | logic TK_AND equality                                     { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "logic"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved && $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved AND logic at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s && %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved AND logic at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | equality                                                  { 
                                                                                    $$.nd = mknode($1.nd, NULL, "logic"); 
                                                                                    
                                                                                    if ($1.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved logic at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved logic at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    ;


equality            : equality TK_EQUAL_EQUAL comparison                        { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "equality"); 
                                                                                
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved == $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s = %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | equality TK_BANG_EQUAL comparison                         { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "equality"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved != $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved inequality at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s <> %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved inequality at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | comparison                                                { 
                                                                                    $$.nd = mknode($1.nd, NULL, "equality"); 
                                                                                    
                                                                                    if ($1.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    ;

comparison          : comparison comparison_operator term                       { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "comparison"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        if (!strcmp($2.name, ">=")) $$.presolved = $1.presolved >= $3.presolved;
                                                                                        else if (!strcmp($2.name, ">")) $$.presolved = $1.presolved > $3.presolved;
                                                                                        else if (!strcmp($2.name, "<")) $$.presolved = $1.presolved < $3.presolved;
                                                                                        else if (!strcmp($2.name, "<=")) $$.presolved = $1.presolved <= $3.presolved;
                                                                                    
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s %s %s", $1.expr, $2.name, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | term                                                      { 
                                                                                    $$.nd = mknode($1.nd, NULL, "comparison"); 
                                                                                    
                                                                                    if ($1.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                        $$.is_presolved = 0;

                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    ;

term                : term TK_PLUS factor                                       { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "term"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved + $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s + %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved term at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | term TK_MINUS factor                                      { 
                                                                                    $$.nd = mknode($1.nd, $3.nd, "term"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved - $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s - %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | factor                                                    { 
                                                                                    $$.nd = mknode($1.nd, NULL, "term"); 
                                                                                    
                                                                                    if ($1.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved term at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    ;

factor              : factor TK_STAR unary                                      { 
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type($1.name), 
                                                                                        "Line %d: Multiplication's left term should be %s (got %s).\n"
                                                                                    );
                                                                                    
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type($3.name), 
                                                                                        "Line %d: Multiplication's right term should be %s (got %s).\n"
                                                                                    );
                                                                                    $$.nd = mknode($1.nd, $3.nd, "factor"); 
                                                                                    
                                                                                    if ($1.is_presolved && $3.is_presolved) 
                                                                                    {
                                                                                        $$.presolved = $1.presolved * $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s * %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | factor TK_SLASH unary                                     {
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type($1.name), 
                                                                                        "Line %d: Division's left term should be %s (got %s).\n"
                                                                                    );
                                                                                    
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type($3.name), 
                                                                                        "Line %d: Division's right term should be %s (got %s).\n"
                                                                                    );

                                                                                    $$.nd = mknode($1.nd, $3.nd, "factor"); 
                                                                                
                                                                                    if ($1.is_presolved && $3.is_presolved) 
                                                                                    {
                                                                                        $$.presolved = $1.presolved / $3.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ($1.is_presolved) presolved_to_expr(&$1);
                                                                                        if ($3.is_presolved) presolved_to_expr(&$3);

                                                                                        snprintf($$.expr, sizeof($$.expr), "%s / %s", $1.expr, $3.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    | unary                                                     { 
                                                                                    $$.nd = mknode($1.nd, NULL, "factor");

                                                                                    if ($1.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    } 
                                                                                }
                    ;

unary               : TK_MINUS unary                                            {
                                                                                    $$.nd = mknode($2.nd, $1.nd, "unary"); 
                                                                                    snprintf($$.name, sizeof($$.name), "%s", $2.name);

                                                                                    if ($2.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $2.presolved;

                                                                                        if (!strcmp($1.name, "-")) 
                                                                                            $$.presolved = -$$.presolved;

                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else 
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s%s", $1.name, $2.expr);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    } 
                                                                                }
                    | primary                                                   { 
                                                                                    $$.nd = mknode($1.nd, NULL, "unary"); 

                                                                                    if ($1.is_presolved) 
                                                                                    {
                                                                                        $$.presolved = $1.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $1.name);
                                                                                        $$.is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    } 
                                                                                }
                    ;

primary             : TK_TRUE                                                   { 
                                                                                    add_symbol('C', "int"); 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                    $$.presolved = 1;
                                                                                    $$.is_presolved = 1; 
                                                                                }
                    | TK_FALSE                                                  { 
                                                                                    add_symbol('C', "int"); 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                    $$.presolved = 1;
                                                                                    $$.is_presolved = 1;
                                                                                }
                    | TK_NUMBER                                                 { 
                                                                                    add_symbol('C', "int"); 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                    $$.presolved = atoi($1.name);
                                                                                    $$.is_presolved = 1;
                                                                                }
                    | TK_STRING_LITERAL                                         { 
                                                                                    add_symbol('C', "string");
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.name);
                                                                                }
                    | TK_IDENTIFIER                                             { 
                                                                                    check_declaration($1.name);
                                                                                    $$.nd = mknode(NULL, NULL, $1.name);
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.name);
                                                                                }
                    | TK_LPAREN logic TK_RPAREN                                 {
                                                                                    snprintf($$.name, sizeof($$.name), "%s", $2.name);
                                                                                    if ($2.is_presolved)
                                                                                    {
                                                                                        $$.presolved = $2.presolved;
                                                                                        $$.is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved grouped primary at line %d: %d\n", ++cstep, lineno + 1, $$.presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf($$.expr, sizeof($$.expr), "%s", $2.expr);
                                                                                        $$.is_presolved = 0;

                                                                                        if (stepdebug) printf("%d: solved grouped primary at line %d: %s\n", ++cstep, lineno + 1, $$.expr);
                                                                                    }
                                                                                }
                    ;

numeric_variable    : TK_NUMBER                                                 { 
                                                                                    add_symbol('C', "int"); 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name);
                                                                                    $$.presolved = atoi($1.name);
                                                                                    $$.is_presolved = 1;
                                                                                }
                    | TK_IDENTIFIER                                             { 
                                                                                    check_declaration($1.name);
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "%s", $1.name);
                                                                                    $$.is_presolved = 0;
                                                                                }
                    ;

comparison_operator : TK_GREATER                                                { 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                
                                                                                    snprintf($$.expr, sizeof($$.expr), ">");
                                                                                }
                    | TK_LESSER                                                 { 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 

                                                                                    snprintf($$.expr, sizeof($$.expr), "<");
                                                                                }
                    | TK_GREATER_EQUAL                                          { 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 

                                                                                    snprintf($$.expr, sizeof($$.expr), ">=");
                                                                                }
                    | TK_LESSER_EQUAL                                           { 
                                                                                    $$.nd = mknode(NULL, NULL, $1.name); 
                                                                                    
                                                                                    snprintf($$.expr, sizeof($$.expr), "<=");
                                                                                }
                    ;

%%

int main() {
    yydebug = 0;
    stepdebug = 1;
    cstep = 0;

    /* output_file = fopen(OUTPUT_FILE_PATH, "w"); */

    yyparse();

    printf("\n\n");
	/* printf("\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n"); */
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
/* 
	printf("\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	print_tree(head); 
	printf("\n\n");

    printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n"); */
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
    snprintf(type, sizeof(type), "%s", yytext);
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
    snprintf(newstr, sizeof(newstr), "%s", token);
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

void presolved_to_expr(struct var_name *obj)
{
    if(obj->is_presolved != 0 && obj->is_presolved != 1)
    {
        printf("IS_PRESOLVED AT LINE %d IS NEITHER 0 NOR 1, BUT %d\n", lineno + 1, obj->is_presolved);
        return;
    }
    snprintf(obj->expr, sizeof(obj->expr), "%d", obj->presolved);
    obj->is_presolved = 0;
}

void write_to_file(char *src)
{
    output_file = fopen(OUTPUT_FILE_PATH, "w");

    if (output_file == NULL)
    {
        printf("WARNING: couldn't write output program.");
    }

    fprintf(output_file, "%s", src);
}

void yyerror(const char *msg) {
    fprintf(stderr, "%s\n", msg);
}
