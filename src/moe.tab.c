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
#line 3 "./generators/moe.y"

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

#line 140 "./src/moe.tab.c"

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
  YYSYMBOL_TK_PRINT = 20,                  /* TK_PRINT  */
  YYSYMBOL_TK_IF = 21,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 22,                   /* TK_ELSE  */
  YYSYMBOL_TK_FOR = 23,                    /* TK_FOR  */
  YYSYMBOL_TK_BETWEEN = 24,                /* TK_BETWEEN  */
  YYSYMBOL_TK_AND = 25,                    /* TK_AND  */
  YYSYMBOL_TK_OR = 26,                     /* TK_OR  */
  YYSYMBOL_TK_EQUAL = 27,                  /* TK_EQUAL  */
  YYSYMBOL_TK_BANG_EQUAL = 28,             /* TK_BANG_EQUAL  */
  YYSYMBOL_TK_EQUAL_EQUAL = 29,            /* TK_EQUAL_EQUAL  */
  YYSYMBOL_TK_LESSER_EQUAL = 30,           /* TK_LESSER_EQUAL  */
  YYSYMBOL_TK_GREATER_EQUAL = 31,          /* TK_GREATER_EQUAL  */
  YYSYMBOL_TK_LESSER = 32,                 /* TK_LESSER  */
  YYSYMBOL_TK_GREATER = 33,                /* TK_GREATER  */
  YYSYMBOL_TK_PLUS = 34,                   /* TK_PLUS  */
  YYSYMBOL_TK_MINUS = 35,                  /* TK_MINUS  */
  YYSYMBOL_TK_STAR = 36,                   /* TK_STAR  */
  YYSYMBOL_TK_SLASH = 37,                  /* TK_SLASH  */
  YYSYMBOL_TK_LPAREN = 38,                 /* TK_LPAREN  */
  YYSYMBOL_TK_RPAREN = 39,                 /* TK_RPAREN  */
  YYSYMBOL_TK_LBRACE = 40,                 /* TK_LBRACE  */
  YYSYMBOL_TK_RBRACE = 41,                 /* TK_RBRACE  */
  YYSYMBOL_TK_SEMICOLON = 42,              /* TK_SEMICOLON  */
  YYSYMBOL_TK_COMMA = 43,                  /* TK_COMMA  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_body = 47,                      /* body  */
  YYSYMBOL_declarations = 48,              /* declarations  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_var_declaration = 50,           /* var_declaration  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_var_init = 52,                  /* var_init  */
  YYSYMBOL_data_type = 53,                 /* data_type  */
  YYSYMBOL_access_modifier = 54,           /* access_modifier  */
  YYSYMBOL_statement = 55,                 /* statement  */
  YYSYMBOL_expression_statement = 56,      /* expression_statement  */
  YYSYMBOL_print_statement = 57,           /* print_statement  */
  YYSYMBOL_58_3 = 58,                      /* $@3  */
  YYSYMBOL_if_statement = 59,              /* if_statement  */
  YYSYMBOL_else_statement = 60,            /* else_statement  */
  YYSYMBOL_if_condition = 61,              /* if_condition  */
  YYSYMBOL_if_valid_operator = 62,         /* if_valid_operator  */
  YYSYMBOL_loop_statement = 63,            /* loop_statement  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_open_statement = 65,            /* open_statement  */
  YYSYMBOL_close_statement = 66,           /* close_statement  */
  YYSYMBOL_optional_argument = 67,         /* optional_argument  */
  YYSYMBOL_jaw_statement = 68,             /* jaw_statement  */
  YYSYMBOL_move_statement = 69,            /* move_statement  */
  YYSYMBOL_moved_statement = 70,           /* moved_statement  */
  YYSYMBOL_two_numbers = 71,               /* two_numbers  */
  YYSYMBOL_delay_statement = 72,           /* delay_statement  */
  YYSYMBOL_expression = 73,                /* expression  */
  YYSYMBOL_assignment = 74,                /* assignment  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_logic = 76,                     /* logic  */
  YYSYMBOL_equality = 77,                  /* equality  */
  YYSYMBOL_comparison = 78,                /* comparison  */
  YYSYMBOL_term = 79,                      /* term  */
  YYSYMBOL_factor = 80,                    /* factor  */
  YYSYMBOL_unary = 81,                     /* unary  */
  YYSYMBOL_primary = 82,                   /* primary  */
  YYSYMBOL_numeric_variable = 83,          /* numeric_variable  */
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
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   112,   112,   112,   121,   132,   137,   147,   154,   164,
     163,   185,   186,   195,   196,   197,   198,   201,   202,   207,
     212,   217,   222,   227,   232,   237,   242,   247,   252,   259,
     267,   266,   274,   287,   292,   299,   308,   318,   327,   336,
     346,   347,   348,   352,   351,   369,   376,   384,   389,   398,
     405,   412,   420,   427,   437,   447,   456,   456,   473,   492,
     513,   534,   555,   576,   597,   617,   642,   662,   683,   704,
     724,   756,   789,   809,   832,   852,   858,   864,   870,   875,
     880,   899,   905,   914,   919,   924,   929
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
  "TK_PRINT", "TK_IF", "TK_ELSE", "TK_FOR", "TK_BETWEEN", "TK_AND",
  "TK_OR", "TK_EQUAL", "TK_BANG_EQUAL", "TK_EQUAL_EQUAL",
  "TK_LESSER_EQUAL", "TK_GREATER_EQUAL", "TK_LESSER", "TK_GREATER",
  "TK_PLUS", "TK_MINUS", "TK_STAR", "TK_SLASH", "TK_LPAREN", "TK_RPAREN",
  "TK_LBRACE", "TK_RBRACE", "TK_SEMICOLON", "TK_COMMA", "$accept",
  "program", "$@1", "body", "declarations", "declaration",
  "var_declaration", "$@2", "var_init", "data_type", "access_modifier",
  "statement", "expression_statement", "print_statement", "$@3",
  "if_statement", "else_statement", "if_condition", "if_valid_operator",
  "loop_statement", "$@4", "open_statement", "close_statement",
  "optional_argument", "jaw_statement", "move_statement",
  "moved_statement", "two_numbers", "delay_statement", "expression",
  "assignment", "$@5", "logic", "equality", "comparison", "term", "factor",
  "unary", "primary", "numeric_variable", "comparison_operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      27,    38,    42,  -106,  -106,     8,  -106,    12,    11,  -106,
      17,    20,    31,    33,  -106,    53,    56,  -106,  -106,   102,
    -106,  -106,    97,   105,   106,    24,    24,  -106,  -106,   153,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,   104,  -106,    35,   -16,    55,    29,    72,  -106,  -106,
      24,    93,    24,    24,    93,   129,   146,   163,    24,   162,
    -106,  -106,    15,  -106,  -106,  -106,  -106,   164,  -106,    24,
      24,    24,    24,  -106,  -106,  -106,  -106,    24,    24,    24,
      24,    24,   137,    29,  -106,  -106,   139,   136,   142,   -28,
     143,    93,    88,  -106,   108,    29,  -106,  -106,  -106,   -16,
     -16,    55,    55,    29,    72,    72,  -106,  -106,   147,   148,
      93,   149,   150,   151,   155,  -106,   156,    24,    24,  -106,
    -106,   144,    24,  -106,   161,   -13,  -106,  -106,  -106,  -106,
    -106,  -106,   154,   157,    65,    65,  -106,    29,    93,    88,
    -106,  -106,  -106,  -106,    69,   158,  -106,   165,    93,   -12,
    -106,   159,  -106,  -106,   160,   107,  -106,  -106,   145,  -106
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     5,     0,    18,     3,
       0,     0,     0,     0,    17,     0,     0,    78,    77,    79,
      75,    76,     0,     0,     0,     0,     0,     6,     7,     0,
       8,    19,    20,    21,    22,    23,    25,    24,    27,    28,
      26,     0,    55,    58,    61,    64,    66,    69,    72,    74,
      47,     0,    47,     0,     0,     0,     0,     0,     0,     0,
      79,    73,     0,    13,    14,    15,    16,     0,    29,     0,
       0,     0,     0,    86,    85,    84,    83,     0,     0,     0,
       0,     0,     0,    48,    81,    82,     0,    52,     0,     0,
       0,     0,     0,    30,     0,    39,    43,    80,     9,    60,
      59,    63,    62,    65,    67,    68,    70,    71,     0,     0,
       0,     0,     0,     0,     0,    57,     0,     0,     0,    42,
      41,     0,     0,    40,     0,     0,    45,    49,    53,    46,
      54,    50,     0,     0,    38,    37,     5,    36,     0,     0,
      11,    10,    51,    31,    18,     0,    12,    33,     0,     0,
      32,     0,     5,    34,     0,    18,     5,    35,    18,    44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -106,  -106,  -106,  -106,   -86,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,    49,  -106,  -106,    48,  -106,     7,  -106,  -106,
    -106,  -106,  -106,   152,  -106,  -106,  -106,   -44,  -106,  -106,
     110,  -106,   177,    62,    90,   -50,    85,   -24,  -106,  -105,
     -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     5,     7,     8,    27,    28,   125,   141,    67,
      29,    30,    31,    32,   116,    33,   150,    94,   122,    34,
     124,    35,    36,    82,    37,    38,    39,    86,    40,    41,
      42,    56,    43,    44,    45,    46,    47,    48,    49,    87,
      77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      83,    61,    83,    89,   123,   128,    78,    79,    95,    23,
      90,   112,    71,    72,   139,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   103,   152,   140,
       1,    22,    23,   145,    24,    17,    18,    60,    20,    21,
      69,    70,     4,   151,   123,   123,    25,   114,     6,    26,
     144,     3,    -4,     9,    97,    50,   106,   107,    51,    25,
      69,    70,    26,    78,    79,    55,   155,    95,    95,    52,
     158,    53,   137,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    73,    74,    75,    76,    22,
      23,    54,    24,   119,   120,    73,    74,    75,    76,    17,
      18,    19,    20,    21,    25,    84,    85,    26,    80,    81,
     147,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    25,   134,   135,    26,    22,    23,   -56,
      24,    99,   100,   117,   118,    57,   119,   120,    73,    74,
      75,    76,    25,    58,    59,    26,    68,   121,   157,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   101,   102,   104,   105,    22,    23,    91,    24,    63,
      64,    65,    66,    92,    93,    96,   108,    98,   109,   110,
      25,   111,   113,    26,   136,   138,   159,   149,   146,   126,
     127,   129,   130,   131,   132,   133,   142,   153,   154,   143,
     156,   148,   115,    62,    88
};

static const yytype_uint8 yycheck[] =
{
      50,    25,    52,    53,    94,   110,    34,    35,    58,    21,
      54,    39,    28,    29,    27,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    77,    40,    42,
       3,    20,    21,   138,    23,    11,    12,    13,    14,    15,
      25,    26,     0,   148,   134,   135,    35,    91,    40,    38,
     136,    13,    41,    41,    39,    38,    80,    81,    38,    35,
      25,    26,    38,    34,    35,     9,   152,   117,   118,    38,
     156,    38,   122,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    30,    31,    32,    33,    20,
      21,    38,    23,    28,    29,    30,    31,    32,    33,    11,
      12,    13,    14,    15,    35,    12,    13,    38,    36,    37,
      41,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    35,   117,   118,    38,    20,    21,    27,
      23,    69,    70,    25,    26,    38,    28,    29,    30,    31,
      32,    33,    35,    38,    38,    38,    42,    39,    41,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    71,    72,    78,    79,    20,    21,    38,    23,    16,
      17,    18,    19,    27,    11,    13,    39,    13,    39,    43,
      35,    39,    39,    38,    40,    24,    41,    22,   139,    42,
      42,    42,    42,    42,    39,    39,    42,   149,    39,    42,
      40,    43,    92,    26,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    45,    13,     0,    46,    40,    47,    48,    41,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    20,    21,    23,    35,    38,    49,    50,    54,
      55,    56,    57,    59,    63,    65,    66,    68,    69,    70,
      72,    73,    74,    76,    77,    78,    79,    80,    81,    82,
      38,    38,    38,    38,    38,     9,    75,    38,    38,    38,
      13,    81,    76,    16,    17,    18,    19,    53,    42,    25,
      26,    28,    29,    30,    31,    32,    33,    84,    34,    35,
      36,    37,    67,    79,    12,    13,    71,    83,    67,    79,
      71,    38,    27,    11,    61,    79,    13,    39,    13,    77,
      77,    78,    78,    79,    80,    80,    81,    81,    39,    39,
      43,    39,    39,    39,    71,    74,    58,    25,    26,    28,
      29,    39,    62,    84,    64,    51,    42,    42,    83,    42,
      42,    42,    39,    39,    61,    61,    40,    79,    24,    27,
      42,    52,    42,    42,    48,    83,    56,    41,    43,    22,
      60,    83,    40,    59,    39,    48,    40,    41,    48,    41
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    46,    45,    47,    48,    48,    49,    49,    51,
      50,    52,    52,    53,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    56,
      58,    57,    59,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    64,    63,    65,    66,    67,    67,    68,
      69,    70,    71,    71,    72,    73,    75,    74,    74,    76,
      76,    76,    77,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    83,    83,    84,    84,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     6,     1,     0,     2,     1,     1,     0,
       5,     1,     2,     1,     1,     1,     1,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     6,     8,     0,     2,     4,     3,     3,     3,     1,
       1,     1,     1,     0,    12,     5,     5,     0,     1,     5,
       5,     6,     1,     3,     5,     1,     0,     4,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     1,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1
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
#line 112 "./generators/moe.y"
                                               { add_symbol('V', "string"); }
#line 1334 "./src/moe.tab.c"
    break;

  case 3: /* program: TK_PROGRAM TK_IDENTIFIER $@1 TK_LBRACE body TK_RBRACE  */
#line 113 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "program");
                                                                                    head = (yyval.nd_obj).nd;

                                                                                    write_to_file((yyvsp[-1].nd_obj).expr);
                                                                                }
#line 1345 "./src/moe.tab.c"
    break;

  case 4: /* body: declarations  */
#line 121 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "body"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1357 "./src/moe.tab.c"
    break;

  case 5: /* declarations: %empty  */
#line 132 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = NULL; 
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "");
                                                                                }
#line 1367 "./src/moe.tab.c"
    break;

  case 6: /* declarations: declarations declaration  */
#line 137 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "declarations");

                                                                                    if ((yyvsp[-1].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-1].nd_obj));
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n%s", (yyvsp[-1].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1380 "./src/moe.tab.c"
    break;

  case 7: /* declaration: var_declaration  */
#line 147 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declaration"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1392 "./src/moe.tab.c"
    break;

  case 8: /* declaration: statement  */
#line 154 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "declaration"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1404 "./src/moe.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 164 "./generators/moe.y"
                      { add_symbol('V', type); }
#line 1410 "./src/moe.tab.c"
    break;

  case 10: /* var_declaration: access_modifier data_type TK_IDENTIFIER $@2 var_init  */
#line 164 "./generators/moe.y"
                                                                                {
                                                                                    char *globality = is_global ? "GLOBAL" : "DEFINE";
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s %s\n", globality, (yyvsp[-2].nd_obj).name);

                                                                                    if ((yyvsp[0].nd_obj).nd != NULL)
                                                                                    {

                                                                                        // validate_types(
                                                                                        //     get_type($3.name),
                                                                                        //     get_type($5.name),
                                                                                        //     "Line %d: Incorrectly initialized value (expected %s, got %s).\n"
                                                                                        // );
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%sSET %s = %s\n", (yyval.nd_obj).expr, (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj).name);
                                                                                    }

                                                                                    (yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "var_declaration");
                                                                                }
#line 1434 "./src/moe.tab.c"
    break;

  case 11: /* var_init: TK_SEMICOLON  */
#line 185 "./generators/moe.y"
                                                                                { (yyval.nd_obj).nd = NULL; }
#line 1440 "./src/moe.tab.c"
    break;

  case 12: /* var_init: TK_EQUAL expression_statement  */
#line 186 "./generators/moe.y"
                                                                                {
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));
                                                                                    
                                                                                    snprintf((yyval.nd_obj).name, sizeof((yyval.nd_obj).name), "%s", (yyvsp[0].nd_obj).expr);
                                                                                    
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "var_init"); 
                                                                                }
#line 1452 "./src/moe.tab.c"
    break;

  case 13: /* data_type: TK_STRING  */
#line 195 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1458 "./src/moe.tab.c"
    break;

  case 14: /* data_type: TK_INT  */
#line 196 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1464 "./src/moe.tab.c"
    break;

  case 15: /* data_type: TK_POSITION  */
#line 197 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1470 "./src/moe.tab.c"
    break;

  case 16: /* data_type: TK_PARAMETER  */
#line 198 "./generators/moe.y"
                                                                                { insert_type(); }
#line 1476 "./src/moe.tab.c"
    break;

  case 17: /* access_modifier: TK_GLOBAL  */
#line 201 "./generators/moe.y"
                                                                                { set_global(); (yyval.nd_obj).nd = NULL; }
#line 1482 "./src/moe.tab.c"
    break;

  case 18: /* access_modifier: %empty  */
#line 202 "./generators/moe.y"
                                                                                { unset_global(); (yyval.nd_obj).nd = NULL; }
#line 1488 "./src/moe.tab.c"
    break;

  case 19: /* statement: expression_statement  */
#line 207 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1498 "./src/moe.tab.c"
    break;

  case 20: /* statement: print_statement  */
#line 212 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1508 "./src/moe.tab.c"
    break;

  case 21: /* statement: if_statement  */
#line 217 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1518 "./src/moe.tab.c"
    break;

  case 22: /* statement: loop_statement  */
#line 222 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1528 "./src/moe.tab.c"
    break;

  case 23: /* statement: open_statement  */
#line 227 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1538 "./src/moe.tab.c"
    break;

  case 24: /* statement: jaw_statement  */
#line 232 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1548 "./src/moe.tab.c"
    break;

  case 25: /* statement: close_statement  */
#line 237 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1558 "./src/moe.tab.c"
    break;

  case 26: /* statement: delay_statement  */
#line 242 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1568 "./src/moe.tab.c"
    break;

  case 27: /* statement: move_statement  */
#line 247 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1578 "./src/moe.tab.c"
    break;

  case 28: /* statement: moved_statement  */
#line 252 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "statement");

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s\n", (yyvsp[0].nd_obj).expr); 
                                                                                }
#line 1588 "./src/moe.tab.c"
    break;

  case 29: /* expression_statement: expression TK_SEMICOLON  */
#line 259 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, (yyvsp[-1].nd_obj).name); 

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[-1].nd_obj).expr);    
                                                                                }
#line 1598 "./src/moe.tab.c"
    break;

  case 30: /* $@3: %empty  */
#line 267 "./generators/moe.y"
                      { add_symbol('C', "string"); }
#line 1604 "./src/moe.tab.c"
    break;

  case 31: /* print_statement: TK_PRINT TK_LPAREN TK_STRING_LITERAL $@3 TK_RPAREN TK_SEMICOLON  */
#line 267 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, "print"); 

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "PRINT %s", (yyvsp[-3].nd_obj).name);
                                                                                }
#line 1614 "./src/moe.tab.c"
    break;

  case 32: /* if_statement: TK_IF TK_LPAREN if_condition TK_RPAREN TK_LBRACE declarations TK_RBRACE else_statement  */
#line 275 "./generators/moe.y"
                                                                                { 
                                                                                    struct node *if_node = mknode((yyvsp[-5].nd_obj).nd, (yyvsp[-2].nd_obj).nd, "if");
                                                                                    (yyval.nd_obj).nd = mknode(if_node, (yyvsp[0].nd_obj).nd, "if-else");

                                                                                    if ((yyvsp[-5].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-5].nd_obj));
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "IF %s\n%s\n%s\nENDIF", (yyvsp[-5].nd_obj).expr, (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1629 "./src/moe.tab.c"
    break;

  case 33: /* else_statement: %empty  */
#line 287 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = NULL; 
                                                                                
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "");
                                                                                }
#line 1639 "./src/moe.tab.c"
    break;

  case 34: /* else_statement: TK_ELSE if_statement  */
#line 292 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "else-if"); 

                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "ELSE\n%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1651 "./src/moe.tab.c"
    break;

  case 35: /* else_statement: TK_ELSE TK_LBRACE declarations TK_RBRACE  */
#line 299 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "else"); 
                                                                                    
                                                                                    if ((yyvsp[-1].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-1].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "ELSE\n%s", (yyvsp[-1].nd_obj).expr);
                                                                                }
#line 1663 "./src/moe.tab.c"
    break;

  case 36: /* if_condition: if_condition if_valid_operator term  */
#line 308 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "if_condition");

                                                                                    if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s %s %s", (yyvsp[-2].nd_obj).expr, (yyvsp[-1].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                    (yyval.nd_obj).is_presolved = 0;
                                                                                }
#line 1678 "./src/moe.tab.c"
    break;

  case 37: /* if_condition: if_condition TK_OR if_condition  */
#line 318 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "if_condition");

                                                                                    if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s ORIF %s\n", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);                                                                                    
                                                                                    (yyval.nd_obj).is_presolved = 0;
                                                                                }
#line 1692 "./src/moe.tab.c"
    break;

  case 38: /* if_condition: if_condition TK_AND if_condition  */
#line 327 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "if_condition");

                                                                                    if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s ANDIF %s\n", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);                                                                                    
                                                                                    (yyval.nd_obj).is_presolved = 0;
                                                                                }
#line 1706 "./src/moe.tab.c"
    break;

  case 39: /* if_condition: term  */
#line 336 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "if-condition");

                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                    (yyval.nd_obj).is_presolved = 0;
                                                                                }
#line 1719 "./src/moe.tab.c"
    break;

  case 40: /* if_valid_operator: comparison_operator  */
#line 346 "./generators/moe.y"
                                                                                { snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr); }
#line 1725 "./src/moe.tab.c"
    break;

  case 41: /* if_valid_operator: TK_EQUAL_EQUAL  */
#line 347 "./generators/moe.y"
                                                                                { snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "="); }
#line 1731 "./src/moe.tab.c"
    break;

  case 42: /* if_valid_operator: TK_BANG_EQUAL  */
#line 348 "./generators/moe.y"
                                                                                { snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "<>"); }
#line 1737 "./src/moe.tab.c"
    break;

  case 43: /* $@4: %empty  */
#line 352 "./generators/moe.y"
                      { add_symbol('V', "int"); }
#line 1743 "./src/moe.tab.c"
    break;

  case 44: /* loop_statement: TK_FOR TK_LPAREN TK_IDENTIFIER $@4 TK_BETWEEN numeric_variable TK_COMMA numeric_variable TK_RPAREN TK_LBRACE declarations TK_RBRACE  */
#line 354 "./generators/moe.y"
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
#line 1761 "./src/moe.tab.c"
    break;

  case 45: /* open_statement: TK_OPEN TK_LPAREN optional_argument TK_RPAREN TK_SEMICOLON  */
#line 369 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "open"); 
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "OPEN %s", (yyvsp[-2].nd_obj).expr);
                                                                                }
#line 1771 "./src/moe.tab.c"
    break;

  case 46: /* close_statement: TK_CLOSE TK_LPAREN optional_argument TK_RPAREN TK_SEMICOLON  */
#line 377 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "close"); 
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "CLOSE %s", (yyvsp[-2].nd_obj).expr);
                                                                                }
#line 1781 "./src/moe.tab.c"
    break;

  case 47: /* optional_argument: %empty  */
#line 384 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = NULL; 
                                                                                
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "");
                                                                                }
#line 1791 "./src/moe.tab.c"
    break;

  case 48: /* optional_argument: term  */
#line 389 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd; 
                                                                                
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));    
                                                                                
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1803 "./src/moe.tab.c"
    break;

  case 49: /* jaw_statement: TK_JAW TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON  */
#line 398 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, "jaw"); 
                                                                                
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "JAW %s", (yyvsp[-2].nd_obj).expr);
                                                                                }
#line 1813 "./src/moe.tab.c"
    break;

  case 50: /* move_statement: TK_MOVE TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON  */
#line 405 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, "move"); 
                                                                                
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "MOVE %s", (yyvsp[-2].nd_obj).expr);
                                                                                }
#line 1823 "./src/moe.tab.c"
    break;

  case 51: /* moved_statement: TK_AWAIT TK_MOVE TK_LPAREN two_numbers TK_RPAREN TK_SEMICOLON  */
#line 413 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, NULL, "moved"); 

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "MOVED %s", (yyvsp[-2].nd_obj).expr);
                                                                                }
#line 1833 "./src/moe.tab.c"
    break;

  case 52: /* two_numbers: numeric_variable  */
#line 420 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = (yyvsp[0].nd_obj).nd; 

                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));    
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1845 "./src/moe.tab.c"
    break;

  case 53: /* two_numbers: numeric_variable TK_COMMA numeric_variable  */
#line 427 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "two_numbers"); 

                                                                                    if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));    

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1858 "./src/moe.tab.c"
    break;

  case 54: /* delay_statement: TK_DELAY TK_LPAREN term TK_RPAREN TK_SEMICOLON  */
#line 437 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, NULL, "delay");

                                                                                    if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "DELAY %s", (yyvsp[-2].nd_obj).expr); 
                                                                                }
#line 1869 "./src/moe.tab.c"
    break;

  case 55: /* expression: assignment  */
#line 447 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "expression"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                }
#line 1881 "./src/moe.tab.c"
    break;

  case 56: /* $@5: %empty  */
#line 456 "./generators/moe.y"
                                    { check_declaration((yyvsp[0].nd_obj).name); }
#line 1887 "./src/moe.tab.c"
    break;

  case 57: /* assignment: TK_IDENTIFIER $@5 TK_EQUAL assignment  */
#line 457 "./generators/moe.y"
                                                                                {
                                                                                    validate_types(
                                                                                        get_type((yyvsp[-3].nd_obj).name), 
                                                                                        get_type((yyvsp[0].nd_obj).name), 
                                                                                        "Line %d: Incorrectly assigned value (expected %s, got %s).\n"
                                                                                    ); 
                                                                                    
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "assignment");
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "SET %s = %s", (yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj).expr);
                                                                                    (yyval.nd_obj).is_presolved = 0;
                                                                                    
                                                                                    if (stepdebug) printf("%d: solved assignment at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                }
#line 1908 "./src/moe.tab.c"
    break;

  case 58: /* assignment: logic  */
#line 473 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "assignment"); 
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved assignment at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved assignment at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1930 "./src/moe.tab.c"
    break;

  case 59: /* logic: logic TK_OR equality  */
#line 492 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "logic"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved || (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved OR logic at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s || %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved OR logic at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1956 "./src/moe.tab.c"
    break;

  case 60: /* logic: logic TK_AND equality  */
#line 513 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "logic"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved && (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved AND logic at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s && %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved AND logic at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 1982 "./src/moe.tab.c"
    break;

  case 61: /* logic: equality  */
#line 534 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "logic"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved logic at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved logic at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2005 "./src/moe.tab.c"
    break;

  case 62: /* equality: equality TK_EQUAL_EQUAL comparison  */
#line 555 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "equality"); 
                                                                                
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved == (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s = %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2031 "./src/moe.tab.c"
    break;

  case 63: /* equality: equality TK_BANG_EQUAL comparison  */
#line 576 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "equality"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved != (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved inequality at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s <> %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved inequality at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2057 "./src/moe.tab.c"
    break;

  case 64: /* equality: comparison  */
#line 597 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "equality"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved equality at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2080 "./src/moe.tab.c"
    break;

  case 65: /* comparison: comparison comparison_operator term  */
#line 617 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "comparison"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        if (!strcmp((yyvsp[-1].nd_obj).name, ">=")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved >= (yyvsp[0].nd_obj).presolved;
                                                                                        else if (!strcmp((yyvsp[-1].nd_obj).name, ">")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved > (yyvsp[0].nd_obj).presolved;
                                                                                        else if (!strcmp((yyvsp[-1].nd_obj).name, "<")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved < (yyvsp[0].nd_obj).presolved;
                                                                                        else if (!strcmp((yyvsp[-1].nd_obj).name, "<=")) (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved <= (yyvsp[0].nd_obj).presolved;
                                                                                    
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s %s %s", (yyvsp[-2].nd_obj).expr, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2110 "./src/moe.tab.c"
    break;

  case 66: /* comparison: term  */
#line 642 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "comparison"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;

                                                                                        if (stepdebug) printf("%d: solved comparison at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2133 "./src/moe.tab.c"
    break;

  case 67: /* term: term TK_PLUS factor  */
#line 662 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "term"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved + (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s + %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved term at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2159 "./src/moe.tab.c"
    break;

  case 68: /* term: term TK_MINUS factor  */
#line 683 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "term"); 
                                                                                    
                                                                                    if ((yyvsp[-2].nd_obj).is_presolved && (yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-2].nd_obj).presolved - (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s - %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2185 "./src/moe.tab.c"
    break;

  case 69: /* term: factor  */
#line 704 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "term"); 
                                                                                    
                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved term at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved term at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2208 "./src/moe.tab.c"
    break;

  case 70: /* factor: factor TK_STAR unary  */
#line 724 "./generators/moe.y"
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

                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s * %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2245 "./src/moe.tab.c"
    break;

  case 71: /* factor: factor TK_SLASH unary  */
#line 756 "./generators/moe.y"
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

                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        if ((yyvsp[-2].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[-2].nd_obj));
                                                                                        if ((yyvsp[0].nd_obj).is_presolved) presolved_to_expr(&(yyvsp[0].nd_obj));

                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s / %s", (yyvsp[-2].nd_obj).expr, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2283 "./src/moe.tab.c"
    break;

  case 72: /* factor: unary  */
#line 789 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "factor");

                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved factor at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    } 
                                                                                }
#line 2306 "./src/moe.tab.c"
    break;

  case 73: /* unary: TK_MINUS unary  */
#line 809 "./generators/moe.y"
                                                                                {
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "unary"); 
                                                                                    snprintf((yyval.nd_obj).name, sizeof((yyval.nd_obj).name), "%s", (yyvsp[0].nd_obj).name);

                                                                                    if ((yyvsp[0].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;

                                                                                        if (!strcmp((yyvsp[-1].nd_obj).name, "-")) 
                                                                                            (yyval.nd_obj).presolved = -(yyval.nd_obj).presolved;

                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else 
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s%s", (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    } 
                                                                                }
#line 2334 "./src/moe.tab.c"
    break;

  case 74: /* unary: primary  */
#line 832 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode((yyvsp[0].nd_obj).nd, NULL, "unary"); 

                                                                                    if ((yyvsp[0].nd_obj).is_presolved) 
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[0].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                        (yyval.nd_obj).is_presolved = 0;
                                                                                        
                                                                                        if (stepdebug) printf("%d: solved unary at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    } 
                                                                                }
#line 2357 "./src/moe.tab.c"
    break;

  case 75: /* primary: TK_TRUE  */
#line 852 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "int"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    (yyval.nd_obj).presolved = 1;
                                                                                    (yyval.nd_obj).is_presolved = 1; 
                                                                                }
#line 2368 "./src/moe.tab.c"
    break;

  case 76: /* primary: TK_FALSE  */
#line 858 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "int"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    (yyval.nd_obj).presolved = 1;
                                                                                    (yyval.nd_obj).is_presolved = 1;
                                                                                }
#line 2379 "./src/moe.tab.c"
    break;

  case 77: /* primary: TK_NUMBER  */
#line 864 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "int"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    (yyval.nd_obj).presolved = atoi((yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).is_presolved = 1;
                                                                                }
#line 2390 "./src/moe.tab.c"
    break;

  case 78: /* primary: TK_STRING_LITERAL  */
#line 870 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "string");
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                }
#line 2400 "./src/moe.tab.c"
    break;

  case 79: /* primary: TK_IDENTIFIER  */
#line 875 "./generators/moe.y"
                                                                                { 
                                                                                    check_declaration((yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                }
#line 2410 "./src/moe.tab.c"
    break;

  case 80: /* primary: TK_LPAREN logic TK_RPAREN  */
#line 880 "./generators/moe.y"
                                                                                {
                                                                                    snprintf((yyval.nd_obj).name, sizeof((yyval.nd_obj).name), "%s", (yyvsp[-1].nd_obj).name);
                                                                                    if ((yyvsp[-1].nd_obj).is_presolved)
                                                                                    {
                                                                                        (yyval.nd_obj).presolved = (yyvsp[-1].nd_obj).presolved;
                                                                                        (yyval.nd_obj).is_presolved = 1;

                                                                                        if (stepdebug) printf("%d: solved grouped primary at line %d: %d\n", ++cstep, lineno + 1, (yyval.nd_obj).presolved);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[-1].nd_obj).expr);
                                                                                        (yyval.nd_obj).is_presolved = 0;

                                                                                        if (stepdebug) printf("%d: solved grouped primary at line %d: %s\n", ++cstep, lineno + 1, (yyval.nd_obj).expr);
                                                                                    }
                                                                                }
#line 2432 "./src/moe.tab.c"
    break;

  case 81: /* numeric_variable: TK_NUMBER  */
#line 899 "./generators/moe.y"
                                                                                { 
                                                                                    add_symbol('C', "int"); 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).presolved = atoi((yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).is_presolved = 1;
                                                                                }
#line 2443 "./src/moe.tab.c"
    break;

  case 82: /* numeric_variable: TK_IDENTIFIER  */
#line 905 "./generators/moe.y"
                                                                                { 
                                                                                    check_declaration((yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "%s", (yyvsp[0].nd_obj).name);
                                                                                    (yyval.nd_obj).is_presolved = 0;
                                                                                }
#line 2455 "./src/moe.tab.c"
    break;

  case 83: /* comparison_operator: TK_GREATER  */
#line 914 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), ">");
                                                                                }
#line 2465 "./src/moe.tab.c"
    break;

  case 84: /* comparison_operator: TK_LESSER  */
#line 919 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "<");
                                                                                }
#line 2475 "./src/moe.tab.c"
    break;

  case 85: /* comparison_operator: TK_GREATER_EQUAL  */
#line 924 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 

                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), ">=");
                                                                                }
#line 2485 "./src/moe.tab.c"
    break;

  case 86: /* comparison_operator: TK_LESSER_EQUAL  */
#line 929 "./generators/moe.y"
                                                                                { 
                                                                                    (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
                                                                                    
                                                                                    snprintf((yyval.nd_obj).expr, sizeof((yyval.nd_obj).expr), "<=");
                                                                                }
#line 2495 "./src/moe.tab.c"
    break;


#line 2499 "./src/moe.tab.c"

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

#line 936 "./generators/moe.y"


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
