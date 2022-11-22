/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./generators/moe.y"

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

    int cstep;

#line 136 "./src/moe.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "moe.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PROGRAM = 3,                 /* TK_PROGRAM  */
  YYSYMBOL_TK_OPEN = 4,                    /* TK_OPEN  */
  YYSYMBOL_TK_JAW = 5,                     /* TK_JAW  */
  YYSYMBOL_TK_CLOSE = 6,                   /* TK_CLOSE  */
  YYSYMBOL_TK_DELAY = 7,                   /* TK_DELAY  */
  YYSYMBOL_TK_GLOBAL = 8,                  /* TK_GLOBAL  */
  YYSYMBOL_TK_MOVE = 9,                    /* TK_MOVE  */
  YYSYMBOL_TK_AWAIT = 10,                  /* TK_AWAIT  */
  YYSYMBOL_TK_STRING_LITERAL = 11,         /* TK_STRING_LITERAL  */
  YYSYMBOL_TK_NUMBER = 12,                 /* TK_NUMBER  */
  YYSYMBOL_TK_IDENTIFIER = 13,             /* TK_IDENTIFIER  */
  YYSYMBOL_TK_TRUE = 14,                   /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 15,                  /* TK_FALSE  */
  YYSYMBOL_TK_STRING = 16,                 /* TK_STRING  */
  YYSYMBOL_TK_INT = 17,                    /* TK_INT  */
  YYSYMBOL_TK_POSITION = 18,               /* TK_POSITION  */
  YYSYMBOL_TK_PARAMETER = 19,              /* TK_PARAMETER  */
  YYSYMBOL_TK_BOOL = 20,                   /* TK_BOOL  */
  YYSYMBOL_TK_PRINT = 21,                  /* TK_PRINT  */
  YYSYMBOL_TK_IF = 22,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 23,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 24,                    /* TK_FOR  */
  YYSYMBOL_TK_BETWEEN = 25,                /* TK_BETWEEN  */
  YYSYMBOL_TK_AND = 26,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 27,                     /* TK_OR  */
  YYSYMBOL_TK_EQUAL = 28,                  /* TK_EQUAL  */
  YYSYMBOL_TK_BANG_EQUAL = 29,             /* TK_BANG_EQUAL  */
  YYSYMBOL_TK_EQUAL_EQUAL = 30,            /* TK_EQUAL_EQUAL  */
  YYSYMBOL_TK_LESSER_EQUAL = 31,           /* TK_LESSER_EQUAL  */
  YYSYMBOL_TK_GREATER_EQUAL = 32,          /* TK_GREATER_EQUAL  */
  YYSYMBOL_TK_LESSER = 33,                 /* TK_LESSER  */
  YYSYMBOL_TK_GREATER = 34,                /* TK_GREATER  */
  YYSYMBOL_TK_PLUS = 35,                   /* TK_PLUS  */
  YYSYMBOL_TK_MINUS = 36,                  /* TK_MINUS  */
  YYSYMBOL_TK_STAR = 37,                   /* TK_STAR  */
  YYSYMBOL_TK_SLASH = 38,                  /* TK_SLASH  */
  YYSYMBOL_TK_LPAREN = 39,                 /* TK_LPAREN  */
  YYSYMBOL_TK_RPAREN = 40,                 /* TK_RPAREN  */
  YYSYMBOL_TK_LBRACE = 41,                 /* TK_LBRACE  */
  YYSYMBOL_TK_RBRACE = 42,                 /* TK_RBRACE  */
  YYSYMBOL_TK_SEMICOLON = 43,              /* TK_SEMICOLON  */
  YYSYMBOL_TK_COMMA = 44,                  /* TK_COMMA  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_47_1 = 47,                      /* $@1  */
  YYSYMBOL_body = 48,                      /* body  */
  YYSYMBOL_declarations = 49,              /* declarations  */
  YYSYMBOL_declaration = 50,               /* declaration  */
  YYSYMBOL_var_declaration = 51,           /* var_declaration  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_var_init = 53,                  /* var_init  */
  YYSYMBOL_data_type = 54,                 /* data_type  */
  YYSYMBOL_access_modifier = 55,           /* access_modifier  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_expression_statement = 57,      /* expression_statement  */
  YYSYMBOL_print_statement = 58,           /* print_statement  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_if_statement = 60,              /* if_statement  */
  YYSYMBOL_else_statement = 61,            /* else_statement  */
  YYSYMBOL_loop_statement = 62,            /* loop_statement  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_open_statement = 64,            /* open_statement  */
  YYSYMBOL_close_statement = 65,           /* close_statement  */
  YYSYMBOL_optional_argument = 66,         /* optional_argument  */
  YYSYMBOL_jaw_statement = 67,             /* jaw_statement  */
  YYSYMBOL_move_statement = 68,            /* move_statement  */
  YYSYMBOL_moved_statement = 69,           /* moved_statement  */
  YYSYMBOL_two_numbers = 70,               /* two_numbers  */
  YYSYMBOL_delay_statement = 71,           /* delay_statement  */
  YYSYMBOL_expression = 72,                /* expression  */
  YYSYMBOL_assignment = 73,                /* assignment  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_logic = 75,                     /* logic  */
  YYSYMBOL_equality = 76,                  /* equality  */
  YYSYMBOL_comparison = 77,                /* comparison  */
  YYSYMBOL_term = 78,                      /* term  */
  YYSYMBOL_factor = 79,                    /* factor  */
  YYSYMBOL_unary = 80,                     /* unary  */
  YYSYMBOL_primary = 81,                   /* primary  */
  YYSYMBOL_numeric_variable = 82,          /* numeric_variable  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_comparison_operator = 84        /* comparison_operator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  148

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   106,   116,   121,   122,   125,   126,   130,
     129,   155,   156,   159,   160,   161,   162,   163,   166,   167,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     184,   188,   187,   191,   198,   199,   200,   204,   203,   221,
     224,   228,   229,   232,   235,   238,   241,   242,   245,   250,
     259,   259,   275,   293,   312,   331,   350,   369,   388,   406,
     429,   447,   466,   485,   503,   533,   564,   582,   603,   621,
     627,   633,   639,   644,   649,   652,   653,   653,   656,   657,
     658,   659
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PROGRAM",
  "TK_OPEN", "TK_JAW", "TK_CLOSE", "TK_DELAY", "TK_GLOBAL", "TK_MOVE",
  "TK_AWAIT", "TK_STRING_LITERAL", "TK_NUMBER", "TK_IDENTIFIER", "TK_TRUE",
  "TK_FALSE", "TK_STRING", "TK_INT", "TK_POSITION", "TK_PARAMETER",
  "TK_BOOL", "TK_PRINT", "TK_IF", "TK_ELSE", "TK_FOR", "TK_BETWEEN",
  "TK_AND", "TK_OR", "TK_EQUAL", "TK_BANG_EQUAL", "TK_EQUAL_EQUAL",
  "TK_LESSER_EQUAL", "TK_GREATER_EQUAL", "TK_LESSER", "TK_GREATER",
  "TK_PLUS", "TK_MINUS", "TK_STAR", "TK_SLASH", "TK_LPAREN", "TK_RPAREN",
  "TK_LBRACE", "TK_RBRACE", "TK_SEMICOLON", "TK_COMMA", "$accept",
  "program", "$@1", "body", "declarations", "declaration",
  "var_declaration", "$@2", "var_init", "data_type", "access_modifier",
  "statement", "expression_statement", "print_statement", "$@3",
  "if_statement", "else_statement", "loop_statement", "$@4",
  "open_statement", "close_statement", "optional_argument",
  "jaw_statement", "move_statement", "moved_statement", "two_numbers",
  "delay_statement", "expression", "assignment", "$@5", "logic",
  "equality", "comparison", "term", "factor", "unary", "primary",
  "numeric_variable", "$@6", "comparison_operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      12,     4,    53,  -111,  -111,    -4,  -111,    13,    -3,  -111,
      21,    33,    57,    60,  -111,    66,   102,  -111,  -111,   107,
    -111,  -111,    99,   105,   106,    56,    95,  -111,  -111,    46,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,   103,  -111,    48,    64,    70,    42,    79,  -111,  -111,
      56,   101,    56,    56,   101,  -111,   119,   137,    56,   136,
    -111,  -111,   110,  -111,  -111,  -111,  -111,  -111,   139,  -111,
      56,    56,    56,    56,  -111,  -111,  -111,  -111,    56,    56,
      56,    56,    56,   113,    42,  -111,  -111,   116,   111,   122,
     -13,   130,    95,  -111,    -2,  -111,  -111,  -111,    64,    64,
      70,    70,    42,    79,    79,  -111,  -111,   128,  -111,   129,
     101,   131,   134,   138,  -111,   133,   141,   155,    -8,  -111,
    -111,  -111,  -111,  -111,  -111,   140,  -111,   101,   154,  -111,
    -111,  -111,    37,   135,  -111,   161,   101,    -9,  -111,   145,
    -111,  -111,   146,    76,  -111,  -111,   115,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     0,    19,     3,
       0,     0,     0,     0,    18,     0,     0,    72,    71,    73,
      69,    70,     0,     0,     0,     0,     0,     6,     7,     0,
       8,    20,    21,    22,    23,    24,    26,    25,    28,    29,
      27,     0,    49,    52,    55,    58,    60,    63,    66,    68,
      41,     0,    41,     0,     0,    45,     0,     0,     0,     0,
      73,    67,     0,    13,    14,    16,    17,    15,     0,    30,
       0,     0,     0,     0,    81,    80,    79,    78,     0,     0,
       0,     0,     0,     0,    42,    75,    76,     0,    46,     0,
       0,     0,     0,    31,     0,    37,    74,     9,    54,    53,
      57,    56,    59,    61,    62,    64,    65,     0,    77,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,    39,
      43,    47,    40,    48,    44,     0,     5,     0,     0,    11,
      10,    32,    19,     0,    12,    34,     0,     0,    33,     0,
       5,    35,     0,    19,     5,    36,    19,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,  -111,  -110,  -111,  -111,  -111,  -111,  -111,
    -111,    58,  -111,  -111,  -111,    51,  -111,  -111,  -111,  -111,
    -111,   142,  -111,   173,  -111,   143,  -111,   165,   100,  -111,
     144,    62,    68,   -24,    63,   -25,  -111,   -96,  -111,  -111
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     7,     8,    27,    28,   118,   130,    68,
      29,    30,    31,    32,   115,    33,   138,    34,   117,    35,
      36,    83,    37,    38,    39,    87,    40,    41,    42,    56,
      43,    44,    45,    46,    47,    48,    49,    88,   108,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    23,   121,     1,   132,     3,    22,    23,
     128,    24,    79,    80,    70,    71,    84,   112,    84,    90,
     143,   133,   140,    25,   146,   129,    26,     6,   116,    -4,
     139,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,     4,   102,     9,   105,   106,    22,    23,
      50,    24,    63,    64,    65,    66,    67,    17,    18,    60,
      20,    21,    51,    25,    70,    71,    26,    79,    80,   135,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    25,    72,    73,    26,    52,    22,    23,    53,
      24,    74,    75,    76,    77,    54,    17,    18,    19,    20,
      21,    15,    25,    85,    86,    26,    81,    82,   145,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    25,    98,    99,    26,   -50,    22,    23,    57,    24,
     100,   101,   103,   104,    58,    59,    69,    92,    93,    95,
      96,    25,    97,   107,    26,   110,   109,   147,    10,    11,
      12,    13,   111,    15,    16,    17,    18,    19,    20,    21,
     113,   119,   120,   125,   122,    22,    23,   123,    24,   136,
     127,   124,   126,   131,   137,   142,   134,   144,   141,    55,
      25,    62,   114,    26,    89,     0,     0,    91,     0,     0,
       0,     0,    94
};

static const yytype_int16 yycheck[] =
{
      25,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    22,   110,     3,   126,    13,    21,    22,
      28,    24,    35,    36,    26,    27,    50,    40,    52,    53,
     140,   127,    41,    36,   144,    43,    39,    41,    40,    42,
     136,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     0,    78,    42,    81,    82,    21,    22,
      39,    24,    16,    17,    18,    19,    20,    11,    12,    13,
      14,    15,    39,    36,    26,    27,    39,    35,    36,    42,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    36,    29,    30,    39,    39,    21,    22,    39,
      24,    31,    32,    33,    34,    39,    11,    12,    13,    14,
      15,     9,    36,    12,    13,    39,    37,    38,    42,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    36,    70,    71,    39,    28,    21,    22,    39,    24,
      72,    73,    79,    80,    39,    39,    43,    28,    11,    13,
      40,    36,    13,    40,    39,    44,    40,    42,     4,     5,
       6,     7,    40,     9,    10,    11,    12,    13,    14,    15,
      40,    43,    43,    40,    43,    21,    22,    43,    24,    44,
      25,    43,    41,    43,    23,    40,   128,    41,   137,    16,
      36,    26,    92,    39,    52,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,    13,     0,    47,    41,    48,    49,    42,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    21,    22,    24,    36,    39,    50,    51,    55,
      56,    57,    58,    60,    62,    64,    65,    67,    68,    69,
      71,    72,    73,    75,    76,    77,    78,    79,    80,    81,
      39,    39,    39,    39,    39,    68,    74,    39,    39,    39,
      13,    80,    72,    16,    17,    18,    19,    20,    54,    43,
      26,    27,    29,    30,    31,    32,    33,    34,    84,    35,
      36,    37,    38,    66,    78,    12,    13,    70,    82,    66,
      78,    70,    28,    11,    75,    13,    40,    13,    76,    76,
      77,    77,    78,    79,    79,    80,    80,    40,    83,    40,
      44,    40,    40,    40,    73,    59,    40,    63,    52,    43,
      43,    82,    43,    43,    43,    40,    41,    25,    28,    43,
      53,    43,    49,    82,    56,    42,    44,    23,    61,    82,
      41,    60,    40,    49,    41,    42,    49,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    47,    46,    48,    49,    49,    50,    50,    52,
      51,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    59,    58,    60,    61,    61,    61,    63,    62,    64,
      65,    66,    66,    67,    68,    69,    70,    70,    71,    72,
      74,    73,    73,    75,    75,    75,    76,    76,    76,    77,
      77,    78,    78,    78,    79,    79,    79,    80,    80,    81,
      81,    81,    81,    81,    81,    82,    83,    82,    84,    84,
      84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     1,     0,     2,     1,     1,     0,
       5,     1,     2,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     0,     6,     8,     0,     2,     4,     0,    12,     5,
       5,     0,     1,     5,     5,     2,     1,     3,     5,     1,
       0,     4,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     2,     1,     1,
       1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* $@1: %empty  */
#line 106 "./generators/moe.y"
                                               { add_symbol('V', "string"); }
#line 1325 "./src/moe.tab.c"
    break;

  case 3: /* program: TK_PROGRAM TK_IDENTIFIER $@1 TK_LBRACE body TK_RBRACE  */
#line 107 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "program");
                                                                                    head = (yyval.nd_obj).nd;


                                                                                    printf("%d: consumed program %s\n", ++cstep, (yyvsp[-4].nd_obj).name);
                                                                                }
#line 1337 "./src/moe.tab.c"
    break;

  case 4: /* body: declarations  */
#line 116 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "body"); }
#line 1343 "./src/moe.tab.c"
    break;

  case 5: /* declarations: %empty  */
#line 121 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = NULL; }
#line 1349 "./src/moe.tab.c"
    break;

  case 6: /* declarations: declarations declaration  */
#line 122 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declarations"); }
#line 1355 "./src/moe.tab.c"
    break;

  case 7: /* declaration: var_declaration  */
#line 125 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declaration"); }
#line 1361 "./src/moe.tab.c"
    break;

  case 8: /* declaration: statement  */
#line 126 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declaration"); }
#line 1367 "./src/moe.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 130 "./generators/moe.y"
                      { add_symbol('V', type); }
#line 1373 "./src/moe.tab.c"
    break;

  case 10: /* var_declaration: access_modifier data_type TK_IDENTIFIER $@2 var_init  */
#line 130 "./generators/moe.y"
                                                                                {
                                                                                    if (is_global)
                                                                                    {
                                                                                        printf("GLOBAL %s\n", (yyvsp[-2].nd_obj).name);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("DEFINE %s\n", (yyvsp[-2].nd_obj).name);
                                                                                    }
                                                                                    if ((yyvsp[0].nd_obj).nd != NULL)
                                                                                    {
                                                                                        validate_types(
                                                                                            get_type((yyvsp[-2].nd_obj).name),
                                                                                            get_type((yyvsp[0].nd_obj).name),
                                                                                            "Line %d: Incorrectly initialized value (expected %s, got %s).\n"
                                                                                        );

                                                                                        printf("SET %s = %s\n", (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj).name);
                                                                                    }

                                                                                    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "var_declaration");
                                                                                }
#line 1401 "./src/moe.tab.c"
    break;

  case 11: /* var_init: TK_SEMICOLON  */
#line 155 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = NULL; }
#line 1407 "./src/moe.tab.c"
    break;

  case 12: /* var_init: TK_EQUAL statement  */
#line 156 "./generators/moe.y"
                                                                                { strcpy((yyval.nd_obj).name, (yyvsp[0].nd_obj).name); (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "var_init"); }
#line 1413 "./src/moe.tab.c"
    break;

  case 13: /* data_type: TK_STRING  */
#line 159 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1419 "./src/moe.tab.c"
    break;

  case 14: /* data_type: TK_INT  */
#line 160 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1425 "./src/moe.tab.c"
    break;

  case 15: /* data_type: TK_BOOL  */
#line 161 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1431 "./src/moe.tab.c"
    break;

  case 16: /* data_type: TK_POSITION  */
#line 162 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1437 "./src/moe.tab.c"
    break;

  case 17: /* data_type: TK_PARAMETER  */
#line 163 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1443 "./src/moe.tab.c"
    break;

  case 18: /* access_modifier: TK_GLOBAL  */
#line 166 "./generators/moe.y"
                                                                                { set_global(); (yyval.nd_obj).nd = NULL; }
#line 1449 "./src/moe.tab.c"
    break;

  case 19: /* access_modifier: %empty  */
#line 167 "./generators/moe.y"
                                                                                { unset_global(); (yyval.nd_obj).nd = NULL; }
#line 1455 "./src/moe.tab.c"
    break;

  case 20: /* statement: expression_statement  */
#line 172 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1461 "./src/moe.tab.c"
    break;

  case 21: /* statement: print_statement  */
#line 173 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1467 "./src/moe.tab.c"
    break;

  case 22: /* statement: if_statement  */
#line 174 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1473 "./src/moe.tab.c"
    break;

  case 23: /* statement: loop_statement  */
#line 175 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1479 "./src/moe.tab.c"
    break;

  case 24: /* statement: open_statement  */
#line 176 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1485 "./src/moe.tab.c"
    break;

  case 25: /* statement: jaw_statement  */
#line 177 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1491 "./src/moe.tab.c"
    break;

  case 26: /* statement: close_statement  */
#line 178 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1497 "./src/moe.tab.c"
    break;

  case 27: /* statement: delay_statement  */
#line 179 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1503 "./src/moe.tab.c"
    break;

  case 28: /* statement: move_statement  */
#line 180 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1509 "./src/moe.tab.c"
    break;

  case 29: /* statement: moved_statement  */
#line 181 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement"); }
#line 1515 "./src/moe.tab.c"
    break;

  case 30: /* expression_statement: expression TK_SEMICOLON  */
#line 184 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, (yyvsp[-1].nd_obj).name); }
#line 1521 "./src/moe.tab.c"
    break;

  case 31: /* $@3: %empty  */
#line 188 "./generators/moe.y"
                      { add_symbol('C', "string"); }
#line 1527 "./src/moe.tab.c"
    break;

  case 32: /* print_statement: TK_PRINT TK_LPAREN TK_STRING_LITERAL $@3 TK_RPAREN TK_SEMICOLON  */
#line 188 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode(NULL, NULL, "print"); }
#line 1533 "./src/moe.tab.c"
    break;

  case 33: /* if_statement: TK_IF TK_LPAREN logic TK_RPAREN TK_LBRACE declarations TK_RBRACE else_statement  */
#line 192 "./generators/moe.y"
                                                                                { 
                                                                                    struct node *if_node = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "if");
                                                                                    (yyval.nd_obj).nd = mknode(if_node, (yyvsp[0].nd_obj).nd, "if-else"); 
                                                                                }
#line 1542 "./src/moe.tab.c"
    break;

  case 34: /* else_statement: %empty  */
#line 198 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = NULL; }
#line 1548 "./src/moe.tab.c"
    break;

  case 35: /* else_statement: TK_ELSE if_statement  */
#line 199 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "else-if"); }
#line 1554 "./src/moe.tab.c"
    break;

  case 36: /* else_statement: TK_ELSE TK_LBRACE declarations TK_RBRACE  */
#line 200 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "else"); }
#line 1560 "./src/moe.tab.c"
    break;

  case 37: /* $@4: %empty  */
#line 204 "./generators/moe.y"
                      { add_symbol('V', "int"); }
#line 1566 "./src/moe.tab.c"
    break;

  case 38: /* loop_statement: TK_FOR TK_LPAREN TK_IDENTIFIER $@4 TK_BETWEEN numeric_variable TK_COMMA numeric_variable TK_RPAREN TK_LBRACE declarations TK_RBRACE  */
#line 206 "./generators/moe.y"
                                                                                {
                                                                                    validate_types(
                                                                                        "int",
                                                                                        get_type((yyvsp[-6].nd_obj).name),
                                                                                        "Line %d: lower bound of loop must be %s (got %s)."
                                                                                    ); 
                                                                                    validate_types(
                                                                                        "int",
                                                                                        get_type((yyvsp[-4].nd_obj).name),
                                                                                        "Line %d: upper bound of loop must be %s (got %s)."
                                                                                    ); 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "for-loop");
                                                                                }
#line 1584 "./src/moe.tab.c"
    break;

  case 39: /* open_statement: TK_OPEN TK_LPAREN optional_argument TK_RPAREN TK_SEMICOLON  */
#line 221 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "open"); }
#line 1590 "./src/moe.tab.c"
    break;

  case 40: /* close_statement: TK_CLOSE TK_LPAREN optional_argument TK_RPAREN TK_SEMICOLON  */
#line 225 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "close"); }
#line 1596 "./src/moe.tab.c"
    break;

  case 41: /* optional_argument: %empty  */
#line 228 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = NULL; }
#line 1602 "./src/moe.tab.c"
    break;

  case 42: /* optional_argument: term  */
#line 229 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd; }
#line 1608 "./src/moe.tab.c"
    break;

  case 43: /* jaw_statement: TK_JAW TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON  */
#line 232 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "jaw"); }
#line 1614 "./src/moe.tab.c"
    break;

  case 44: /* move_statement: TK_MOVE TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON  */
#line 235 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "move"); }
#line 1620 "./src/moe.tab.c"
    break;

  case 45: /* moved_statement: TK_AWAIT move_statement  */
#line 238 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "moved"); }
#line 1626 "./src/moe.tab.c"
    break;

  case 46: /* two_numbers: numeric_variable  */
#line 241 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd; }
#line 1632 "./src/moe.tab.c"
    break;

  case 47: /* two_numbers: numeric_variable TK_COMMA numeric_variable  */
#line 242 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "two_numbers"); }
#line 1638 "./src/moe.tab.c"
    break;

  case 48: /* delay_statement: TK_DELAY TK_LPAREN term TK_RPAREN TK_SEMICOLON  */
#line 245 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "delay"); }
#line 1644 "./src/moe.tab.c"
    break;

  case 49: /* expression: assignment  */
#line 250 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "expression"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);
                                                                                    
                                                                                    printf("%s\n", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1656 "./src/moe.tab.c"
    break;

  case 50: /* $@5: %empty  */
#line 259 "./generators/moe.y"
                                    { check_declaration((yyvsp[0].nd_obj).name); }
#line 1662 "./src/moe.tab.c"
    break;

  case 51: /* assignment: TK_IDENTIFIER $@5 TK_EQUAL assignment  */
#line 260 "./generators/moe.y"
                                                                                {
                                                                                    validate_types(
                                                                                        get_type((yyvsp[-3].nd_obj).name), 
                                                                                        get_type((yyvsp[0].nd_obj).name), 
                                                                                        "Line %d: Incorrectly assigned value (expected %s, got %s).\n"
                                                                                    ); 
                                                                                    
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "assignment");
                                                                                    

                                                                                    if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);
             
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "SET %s = %s\n", (yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj).expr);
                                                                                    printf("%d: solved assignment: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                }
#line 1682 "./src/moe.tab.c"
    break;

  case 52: /* assignment: logic  */
#line 275 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "assignment"); 

                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved assignment: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved assignment: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1703 "./src/moe.tab.c"
    break;

  case 53: /* logic: logic TK_OR equality  */
#line 293 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "logic"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved || (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved OR logic: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s || %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved OR logic: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1727 "./src/moe.tab.c"
    break;

  case 54: /* logic: logic TK_AND equality  */
#line 312 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "logic"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved && (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved AND logic: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s && %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved AND logic: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1751 "./src/moe.tab.c"
    break;

  case 55: /* logic: equality  */
#line 331 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "logic"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved logic: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved logic: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1772 "./src/moe.tab.c"
    break;

  case 56: /* equality: equality TK_EQUAL_EQUAL comparison  */
#line 350 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "equality"); 
                                                                                
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved == (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved equality: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s = %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved equality: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1796 "./src/moe.tab.c"
    break;

  case 57: /* equality: equality TK_BANG_EQUAL comparison  */
#line 369 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "equality"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved != (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved inequality: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s != %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved inequality: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1820 "./src/moe.tab.c"
    break;

  case 58: /* equality: comparison  */
#line 388 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "equality"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved equality: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved equality: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1841 "./src/moe.tab.c"
    break;

  case 59: /* comparison: comparison comparison_operator term  */
#line 406 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "comparison"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        if (!strcmp((yyvsp[-1].nd_obj).name, ">=")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved >= (yyvsp[0].nd_obj).presolved;
                                                                                        else if (!strcmp((yyvsp[-1].nd_obj).name, ">")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved > (yyvsp[0].nd_obj).presolved;
                                                                                        else if (!strcmp((yyvsp[-1].nd_obj).name, "<")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved < (yyvsp[0].nd_obj).presolved;
                                                                                        else if (!strcmp((yyvsp[-1].nd_obj).name, "<=")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved <= (yyvsp[0].nd_obj).presolved;
                                                                                    
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved comparison: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s %s %s", (yyvsp[-2].nd_obj).expr, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved comparison: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1869 "./src/moe.tab.c"
    break;

  case 60: /* comparison: term  */
#line 429 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "comparison"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved comparison: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved comparison: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1890 "./src/moe.tab.c"
    break;

  case 61: /* term: term TK_PLUS factor  */
#line 447 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "term"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved + (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved term: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s + %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved term: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1914 "./src/moe.tab.c"
    break;

  case 62: /* term: term TK_MINUS factor  */
#line 466 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "term"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved - (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved term: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s - %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved term: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1938 "./src/moe.tab.c"
    break;

  case 63: /* term: factor  */
#line 485 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "term"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved term: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved term: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1959 "./src/moe.tab.c"
    break;

  case 64: /* factor: factor TK_STAR unary  */
#line 503 "./generators/moe.y"
                                                                                { 
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type((yyvsp[-2].nd_obj).name), 
                                                                                        "Line %d: Multiplication's left term should be %s (got %s).\n"
                                                                                    );
                                                                                    
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type((yyvsp[0].nd_obj).name), 
                                                                                        "Line %d: Multiplication's right term should be %s (got %s).\n"
                                                                                    );
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "factor"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved) 
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved * (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved factor: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s * %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved factor: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1994 "./src/moe.tab.c"
    break;

  case 65: /* factor: factor TK_SLASH unary  */
#line 533 "./generators/moe.y"
                                                                                {
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type((yyvsp[-2].nd_obj).name), 
                                                                                        "Line %d: Division's left term should be %s (got %s).\n"
                                                                                    );
                                                                                    
                                                                                    validate_types(
                                                                                        "int", 
                                                                                        get_type((yyvsp[0].nd_obj).name), 
                                                                                        "Line %d: Division's right term should be %s (got %s).\n"
                                                                                    );

                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "factor"); 
                                                                                
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved) 
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved / (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved factor: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) snprintf((yyvsp[-2].nd_obj).expr, sizeof((yyvsp[-2].nd_obj).expr), "%d", (yyvsp[-2].nd_obj).presolved);
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) snprintf((yyvsp[0].nd_obj).expr, sizeof((yyvsp[0].nd_obj).expr), "%d", (yyvsp[0].nd_obj).presolved);

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s / %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved factor: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2030 "./src/moe.tab.c"
    break;

  case 66: /* factor: unary  */
#line 564 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "factor");

                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved factor: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved factor: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    } 
                                                                                }
#line 2051 "./src/moe.tab.c"
    break;

  case 67: /* unary: TK_MINUS unary  */
#line 582 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "unary"); 
                                                                                    snprintf((yyval.nd_obj).name, sizeof((yyval.nd_obj).name), "%s", (yyvsp[0].nd_obj).name);

                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;

                                                                                        if (!strcmp((yyvsp[-1].nd_obj).name, "-")) 
                                                                                            (yyval.nd_obj).presolved = -(yyval.nd_obj).presolved;

                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved unary: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else 
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s%s", (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj).expr);
                                                                                        printf("%d: solved unary: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    } 
                                                                                }
#line 2077 "./src/moe.tab.c"
    break;

  case 68: /* unary: primary  */
#line 603 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "unary"); 

                                                                                    if ((yyvsp[0].nd_obj).is_presolved) 
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        printf("%d: solved unary: %d\n", ++cstep, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                        printf("%d: solved unary: %s\n", ++cstep, (yyval.nd_obj).expr);
                                                                                    } 
                                                                                }
#line 2098 "./src/moe.tab.c"
    break;

  case 69: /* primary: TK_TRUE  */
#line 621 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "bool"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    (yyval.nd_obj).presolved = 1;
                                                                                    (yyval.nd_obj).is_presolved = 1; 
                                                                                }
#line 2109 "./src/moe.tab.c"
    break;

  case 70: /* primary: TK_FALSE  */
#line 627 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "bool"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    (yyval.nd_obj).presolved = 1;
                                                                                    (yyval.nd_obj).is_presolved = 1;
                                                                                }
#line 2120 "./src/moe.tab.c"
    break;

  case 71: /* primary: TK_NUMBER  */
#line 633 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "int"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    (yyval.nd_obj).presolved = atoi((yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).is_presolved = 1;
                                                                                }
#line 2131 "./src/moe.tab.c"
    break;

  case 72: /* primary: TK_STRING_LITERAL  */
#line 639 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "string");
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                }
#line 2141 "./src/moe.tab.c"
    break;

  case 73: /* primary: TK_IDENTIFIER  */
#line 644 "./generators/moe.y"
                                                                                { 
                                                                                    check_declaration((yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                }
#line 2151 "./src/moe.tab.c"
    break;

  case 75: /* numeric_variable: TK_NUMBER  */
#line 652 "./generators/moe.y"
                                                                                { add_symbol('C', "int"); (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 2157 "./src/moe.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 653 "./generators/moe.y"
                                    { check_declaration((yyvsp[0].nd_obj).name); }
#line 2163 "./src/moe.tab.c"
    break;

  case 77: /* numeric_variable: TK_IDENTIFIER $@6  */
#line 653 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); }
#line 2169 "./src/moe.tab.c"
    break;

  case 78: /* comparison_operator: TK_GREATER  */
#line 656 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 2175 "./src/moe.tab.c"
    break;

  case 79: /* comparison_operator: TK_LESSER  */
#line 657 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 2181 "./src/moe.tab.c"
    break;

  case 80: /* comparison_operator: TK_GREATER_EQUAL  */
#line 658 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 2187 "./src/moe.tab.c"
    break;

  case 81: /* comparison_operator: TK_LESSER_EQUAL  */
#line 659 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 2193 "./src/moe.tab.c"
    break;


#line 2197 "./src/moe.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 662 "./generators/moe.y"


int main() {
    yydebug = 0;
    cstep = 0;

    /* output_file = fopen(OUTPUT_FILE_PATH, "w"); */

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
