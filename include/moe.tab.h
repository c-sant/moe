/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_MOE_TAB_H_INCLUDED
# define YY_YY_INCLUDE_MOE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_PROGRAM = 258,              /* TK_PROGRAM  */
    TK_OPEN = 259,                 /* TK_OPEN  */
    TK_JAW = 260,                  /* TK_JAW  */
    TK_CLOSE = 261,                /* TK_CLOSE  */
    TK_DELAY = 262,                /* TK_DELAY  */
    TK_GLOBAL = 263,               /* TK_GLOBAL  */
    TK_MOVE = 264,                 /* TK_MOVE  */
    TK_AWAIT = 265,                /* TK_AWAIT  */
    TK_STRING_LITERAL = 266,       /* TK_STRING_LITERAL  */
    TK_NUMBER = 267,               /* TK_NUMBER  */
    TK_IDENTIFIER = 268,           /* TK_IDENTIFIER  */
    TK_STRING = 269,               /* TK_STRING  */
    TK_INT = 270,                  /* TK_INT  */
    TK_POSITION = 271,             /* TK_POSITION  */
    TK_PARAMETER = 272,            /* TK_PARAMETER  */
    TK_TRUE = 273,                 /* TK_TRUE  */
    TK_FALSE = 274,                /* TK_FALSE  */
    TK_PRINT = 275,                /* TK_PRINT  */
    TK_IF = 276,                   /* TK_IF  */
    TK_ELSE = 277,                 /* TK_ELSE  */
    TK_AND = 278,                  /* TK_AND  */
    TK_OR = 279,                   /* TK_OR  */
    TK_EQUAL = 280,                /* TK_EQUAL  */
    TK_BANG_EQUAL = 281,           /* TK_BANG_EQUAL  */
    TK_EQUAL_EQUAL = 282,          /* TK_EQUAL_EQUAL  */
    TK_LESSER_EQUAL = 283,         /* TK_LESSER_EQUAL  */
    TK_GREATER_EQUAL = 284,        /* TK_GREATER_EQUAL  */
    TK_LESSER = 285,               /* TK_LESSER  */
    TK_GREATER = 286,              /* TK_GREATER  */
    TK_PLUS = 287,                 /* TK_PLUS  */
    TK_MINUS = 288,                /* TK_MINUS  */
    TK_STAR = 289,                 /* TK_STAR  */
    TK_SLASH = 290,                /* TK_SLASH  */
    TK_LPAREN = 291,               /* TK_LPAREN  */
    TK_RPAREN = 292,               /* TK_RPAREN  */
    TK_LBRACE = 293,               /* TK_LBRACE  */
    TK_RBRACE = 294,               /* TK_RBRACE  */
    TK_SEMICOLON = 295,            /* TK_SEMICOLON  */
    TK_COMMA = 296                 /* TK_COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 57 "./generators/moe.y"

    struct var_name {
        char name[100];
        struct node *nd;
    } nd_obj;

#line 112 "./include/moe.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_MOE_TAB_H_INCLUDED  */
