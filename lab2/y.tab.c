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
#line 1 "syntax_analyzer.y"


#include "symbol_table.h"

#define YYSTYPE symbol_info*

extern FILE *yyin;
int yyparse(void);
int yylex(void);
extern YYSTYPE yylval;

// create your symbol table here.
// You can store the pointer to your symbol table in a global variable
// or you can create an object

symbol_table* sym_table;

int lines = 1;

ofstream outlog;

// you may declare other necessary variables here to store necessary info
// such as current variable type, variable list, function name, return type, function parameter types, parameters names etc.

string current_var_type;
stack<symbol_info*> fn_name;


symbol_info* addSymbol(string name, string type, symbol_type symType, int arrSize = 0, list<symbol_info*> params = {}){
	return new symbol_info(name, type, symType, arrSize, params);
}

void enterFn(string name, string return_type){
	fn_name.push(addSymbol(name, return_type, symbol_type::FUNCTION));
	sym_table->enter_scope();	
}

void enterScopeDecl(){
	outlog<<"Entering new scope for declaration at line "<<lines<<endl<<endl;
} 


void exitScopeDecl(){
	
	sym_table->print_all_scopes(outlog);
	outlog<<"Exiting scope for declaration at line "<<lines<<endl<<endl;
	sym_table->exit_scope();
}




void yyerror(char *s)
{
	outlog<<"At line "<<lines<<" "<<s<<endl<<endl;

    // you may need to reinitialize variables if you find an error
}


#line 132 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    BREAK = 263,                   /* BREAK  */
    INT = 264,                     /* INT  */
    CHAR = 265,                    /* CHAR  */
    FLOAT = 266,                   /* FLOAT  */
    DOUBLE = 267,                  /* DOUBLE  */
    VOID = 268,                    /* VOID  */
    RETURN = 269,                  /* RETURN  */
    SWITCH = 270,                  /* SWITCH  */
    CASE = 271,                    /* CASE  */
    DEFAULT = 272,                 /* DEFAULT  */
    CONTINUE = 273,                /* CONTINUE  */
    PRINTLN = 274,                 /* PRINTLN  */
    ADDOP = 275,                   /* ADDOP  */
    MULOP = 276,                   /* MULOP  */
    INCOP = 277,                   /* INCOP  */
    DECOP = 278,                   /* DECOP  */
    RELOP = 279,                   /* RELOP  */
    ASSIGNOP = 280,                /* ASSIGNOP  */
    LOGICOP = 281,                 /* LOGICOP  */
    NOT = 282,                     /* NOT  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    LCURL = 285,                   /* LCURL  */
    RCURL = 286,                   /* RCURL  */
    LTHIRD = 287,                  /* LTHIRD  */
    RTHIRD = 288,                  /* RTHIRD  */
    COMMA = 289,                   /* COMMA  */
    SEMICOLON = 290,               /* SEMICOLON  */
    CONST_INT = 291,               /* CONST_INT  */
    CONST_FLOAT = 292,             /* CONST_FLOAT  */
    ID = 293,                      /* ID  */
    LOWER_THAN_ELSE = 294          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define DO 262
#define BREAK 263
#define INT 264
#define CHAR 265
#define FLOAT 266
#define DOUBLE 267
#define VOID 268
#define RETURN 269
#define SWITCH 270
#define CASE 271
#define DEFAULT 272
#define CONTINUE 273
#define PRINTLN 274
#define ADDOP 275
#define MULOP 276
#define INCOP 277
#define DECOP 278
#define RELOP 279
#define ASSIGNOP 280
#define LOGICOP 281
#define NOT 282
#define LPAREN 283
#define RPAREN 284
#define LCURL 285
#define RCURL 286
#define LTHIRD 287
#define RTHIRD 288
#define COMMA 289
#define SEMICOLON 290
#define CONST_INT 291
#define CONST_FLOAT 292
#define ID 293
#define LOWER_THAN_ELSE 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_CHAR = 10,                      /* CHAR  */
  YYSYMBOL_FLOAT = 11,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 12,                    /* DOUBLE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_PRINTLN = 19,                   /* PRINTLN  */
  YYSYMBOL_ADDOP = 20,                     /* ADDOP  */
  YYSYMBOL_MULOP = 21,                     /* MULOP  */
  YYSYMBOL_INCOP = 22,                     /* INCOP  */
  YYSYMBOL_DECOP = 23,                     /* DECOP  */
  YYSYMBOL_RELOP = 24,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 25,                  /* ASSIGNOP  */
  YYSYMBOL_LOGICOP = 26,                   /* LOGICOP  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LPAREN = 28,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 29,                    /* RPAREN  */
  YYSYMBOL_LCURL = 30,                     /* LCURL  */
  YYSYMBOL_RCURL = 31,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 32,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 33,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 35,                 /* SEMICOLON  */
  YYSYMBOL_CONST_INT = 36,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 37,               /* CONST_FLOAT  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_LOWER_THAN_ELSE = 39,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_start = 41,                     /* start  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_unit = 43,                      /* unit  */
  YYSYMBOL_func_definition = 44,           /* func_definition  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_46_2 = 46,                      /* $@2  */
  YYSYMBOL_parameter_list = 47,            /* parameter_list  */
  YYSYMBOL_compound_statement = 48,        /* compound_statement  */
  YYSYMBOL_var_declaration = 49,           /* var_declaration  */
  YYSYMBOL_type_specifier = 50,            /* type_specifier  */
  YYSYMBOL_declaration_list = 51,          /* declaration_list  */
  YYSYMBOL_statements = 52,                /* statements  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_expression_statement = 54,      /* expression_statement  */
  YYSYMBOL_variable = 55,                  /* variable  */
  YYSYMBOL_expression = 56,                /* expression  */
  YYSYMBOL_logic_expression = 57,          /* logic_expression  */
  YYSYMBOL_rel_expression = 58,            /* rel_expression  */
  YYSYMBOL_simple_expression = 59,         /* simple_expression  */
  YYSYMBOL_term = 60,                      /* term  */
  YYSYMBOL_unary_expression = 61,          /* unary_expression  */
  YYSYMBOL_factor = 62,                    /* factor  */
  YYSYMBOL_argument_list = 63,             /* argument_list  */
  YYSYMBOL_arguments = 64                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  116

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    79,    86,    95,   102,   111,   111,   125,
     125,   142,   154,   165,   177,   190,   201,   213,   224,   232,
     240,   250,   261,   270,   279,   291,   298,   307,   314,   322,
     329,   336,   343,   350,   357,   364,   371,   380,   387,   396,
     404,   413,   420,   429,   436,   445,   452,   461,   469,   478,
     486,   496,   503,   510,   519,   526,   533,   540,   547,   554,
     561,   570,   578,   586,   593
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "BREAK", "INT", "CHAR", "FLOAT", "DOUBLE", "VOID",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "PRINTLN", "ADDOP",
  "MULOP", "INCOP", "DECOP", "RELOP", "ASSIGNOP", "LOGICOP", "NOT",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA",
  "SEMICOLON", "CONST_INT", "CONST_FLOAT", "ID", "LOWER_THAN_ELSE",
  "$accept", "start", "program", "unit", "func_definition", "$@1", "$@2",
  "parameter_list", "compound_statement", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     114,   -70,   -70,   -70,    12,   114,   -70,   -70,   -70,   -23,
     -70,   -70,    19,   -11,     3,    39,     1,   -70,   -70,   114,
      44,    51,    46,   -15,    53,   -70,    50,    43,   -70,    46,
     114,   -70,    56,    68,    69,    72,    67,    73,    67,    67,
      67,   -70,   -70,   -70,   -70,    32,   -70,   -70,   -70,    79,
     -70,   -70,    36,    76,   -70,    82,    48,    81,   -70,   -70,
     -70,    74,   -70,    67,   -10,    67,    78,    84,    15,   -70,
     -70,    90,    67,    67,   -70,   -70,   -70,   -70,    67,   -70,
      67,    67,    67,    67,   -70,   101,   -10,   102,   -70,   103,
     -70,   -70,   104,   105,   107,   -70,   -70,    81,   116,   -70,
     115,    67,   115,   106,   -70,    67,   -70,   133,   109,   -70,
     -70,   -70,   115,   115,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    18,    19,    20,     0,     2,     4,     6,     5,     0,
       1,     3,    23,     0,     7,     0,     0,    17,     9,     0,
       0,    21,     0,     0,    14,    24,     0,     0,    10,     0,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    37,    57,    58,    39,    28,    30,    27,     0,
      25,    29,    54,     0,    41,    43,    45,    47,    49,    53,
       8,    12,    22,     0,     0,     0,     0,     0,    54,    51,
      52,     0,    62,     0,    15,    26,    59,    60,     0,    38,
       0,     0,     0,     0,    11,     0,     0,     0,    36,     0,
      56,    64,     0,    61,     0,    42,    44,    48,    46,    50,
       0,     0,     0,     0,    55,     0,    40,    32,     0,    34,
      35,    63,     0,     0,    33,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   139,    16,   -70,   -70,   -70,    -9,    30,
      -8,   -70,   -70,   -47,   -57,   -38,   -32,   -69,    66,    65,
      75,   -33,   -70,   -70,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    46,    19,    22,    23,    47,    48,
       9,    13,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    92,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      68,    68,    75,    91,    66,    69,    70,    86,    71,    95,
      38,    24,    10,    28,    29,    12,     7,    39,    40,    30,
      60,     7,    61,    16,    17,    42,    43,    44,    45,   101,
       8,    85,    18,    87,    68,     8,   111,    76,    77,    21,
      68,    94,    68,    68,    68,    68,    33,    14,    34,    35,
      99,    15,     1,   107,     2,   109,     3,    36,    76,    77,
      72,    78,    37,    38,    73,   114,   115,    68,    81,   108,
      39,    40,    82,    27,    41,    20,    27,    25,    42,    43,
      44,    45,    33,    26,    34,    35,    32,    38,     1,    62,
       2,    31,     3,    36,    39,    40,    63,    64,    37,    38,
      65,    67,    83,    43,    44,    45,    39,    40,    80,    27,
      74,    79,    84,    88,    42,    43,    44,    45,    33,    90,
      34,    35,    89,     1,     1,     2,     2,     3,     3,    36,
     100,   102,   103,   104,    37,    38,    81,   112,   113,   105,
     106,   110,    39,    40,    11,    27,    96,    98,     0,     0,
      42,    43,    44,    45,     0,     0,    97
};

static const yytype_int8 yycheck[] =
{
      38,    39,    49,    72,    36,    38,    39,    64,    40,    78,
      20,    19,     0,    22,    29,    38,     0,    27,    28,    34,
      29,     5,    30,    34,    35,    35,    36,    37,    38,    86,
       0,    63,    29,    65,    72,     5,   105,    22,    23,    38,
      78,    73,    80,    81,    82,    83,     3,    28,     5,     6,
      83,    32,     9,   100,    11,   102,    13,    14,    22,    23,
      28,    25,    19,    20,    32,   112,   113,   105,    20,   101,
      27,    28,    24,    30,    31,    36,    30,    33,    35,    36,
      37,    38,     3,    32,     5,     6,    36,    20,     9,    33,
      11,    38,    13,    14,    27,    28,    28,    28,    19,    20,
      28,    28,    21,    36,    37,    38,    27,    28,    26,    30,
      31,    35,    38,    35,    35,    36,    37,    38,     3,    29,
       5,     6,    38,     9,     9,    11,    11,    13,    13,    14,
      29,    29,    29,    29,    19,    20,    20,     4,    29,    34,
      33,    35,    27,    28,     5,    30,    80,    82,    -1,    -1,
      35,    36,    37,    38,    -1,    -1,    81
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    11,    13,    41,    42,    43,    44,    49,    50,
       0,    43,    38,    51,    28,    32,    34,    35,    29,    45,
      36,    38,    46,    47,    50,    33,    32,    30,    48,    29,
      34,    38,    36,     3,     5,     6,    14,    19,    20,    27,
      28,    31,    35,    36,    37,    38,    44,    48,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      48,    50,    33,    28,    28,    28,    56,    28,    55,    61,
      61,    56,    28,    32,    31,    53,    22,    23,    25,    35,
      26,    20,    24,    21,    38,    56,    54,    56,    35,    38,
      29,    57,    63,    64,    56,    57,    58,    60,    59,    61,
      29,    54,    29,    29,    29,    34,    33,    53,    56,    53,
      35,    57,     4,    29,    53,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    45,    44,    46,
      44,    47,    47,    47,    47,    48,    48,    49,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    54,    55,
      55,    56,    56,    57,    57,    58,    58,    59,    59,    60,
      60,    61,    61,    61,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     0,     7,     0,
       6,     4,     3,     2,     1,     3,     2,     3,     1,     1,
       1,     3,     6,     1,     4,     1,     2,     1,     1,     1,
       1,     7,     5,     7,     5,     5,     3,     1,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     0,     3,     1
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
  case 2: /* start: program  */
#line 70 "syntax_analyzer.y"
        {
		outlog<<"At line no: "<<lines<<" start : program "<<endl<<endl;
		outlog<<"Symbol Table"<<endl<<endl;
		
		// Print your whole symbol table here
		sym_table->print_all_scopes(outlog);
	}
#line 1392 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 80 "syntax_analyzer.y"
        {
		outlog<<"At line no: "<<lines<<" program : program unit "<<endl<<endl;
		outlog<<yyvsp[-1]->get_name()+"\n"+yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[-1]->get_name()+"\n"+yyvsp[0]->get_name(),"program", symbol_type::VARIABLE);
	}
#line 1403 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 87 "syntax_analyzer.y"
        {
		outlog<<"At line no: "<<lines<<" program : unit "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->get_name(),"program", symbol_type::VARIABLE);
	}
#line 1414 "y.tab.c"
    break;

  case 5: /* unit: var_declaration  */
#line 96 "syntax_analyzer.y"
         {
		outlog<<"At line no: "<<lines<<" unit : var_declaration "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->get_name(),"unit", symbol_type::VARIABLE);
	 }
#line 1425 "y.tab.c"
    break;

  case 6: /* unit: func_definition  */
#line 103 "syntax_analyzer.y"
     {
		outlog<<"At line no: "<<lines<<" unit : func_definition "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[0]->get_name(),"unit", symbol_type::VARIABLE);
	 }
#line 1436 "y.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 111 "syntax_analyzer.y"
                                           {enterFn(yyvsp[-1]->get_name(), yyvsp[-2]->get_name());}
#line 1442 "y.tab.c"
    break;

  case 8: /* func_definition: type_specifier ID LPAREN $@1 parameter_list RPAREN compound_statement  */
#line 112 "syntax_analyzer.y"
                {	
			outlog<<"At line no: "<<lines<<" func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement "<<endl<<endl;
			outlog<<yyvsp[-6]->get_name()<<" "<<yyvsp[-5]->get_name()<<"("+yyvsp[-2]->get_name()+")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-6]->get_name()+" "+yyvsp[-5]->get_name()+"("+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"func_def", symbol_type::VARIABLE);	
			
			// The function definition is complete.
            // You can now insert necessary information about the function into the symbol table
            // However, note that the scope of the function and the scope of the compound statement are different.
			sym_table->insert(fn_name.top());
			exitScopeDecl();
			fn_name.pop();
		}
#line 1460 "y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 125 "syntax_analyzer.y"
                                                  {enterFn(yyvsp[-2]->get_name(), yyvsp[-3]->get_name());}
#line 1466 "y.tab.c"
    break;

  case 10: /* func_definition: type_specifier ID LPAREN RPAREN $@2 compound_statement  */
#line 126 "syntax_analyzer.y"
                {
			
			outlog<<"At line no: "<<lines<<" func_definition : type_specifier ID LPAREN RPAREN compound_statement "<<endl<<endl;
			outlog<<yyvsp[-5]->get_name()<<" "<<yyvsp[-4]->get_name()<<"()\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-5]->get_name()+" "+yyvsp[-4]->get_name()+"()\n"+yyvsp[0]->get_name(),"func_def", symbol_type::VARIABLE);	
			
			// The function definition is complete.
            // You can now insert necessary information about the function into the symbol table
            // However, note that the scope of the function and the scope of the compound statement are different.
			sym_table->insert(fn_name.top());
			exitScopeDecl();
			fn_name.pop();
		}
#line 1485 "y.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 143 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : parameter_list COMMA type_specifier ID "<<endl<<endl;
			outlog<<yyvsp[-3]->get_name()<<","<<yyvsp[-1]->get_name()<<" "<<yyvsp[0]->get_name()<<endl<<endl;
					
			yyval = new symbol_info(yyvsp[-3]->get_name()+","+yyvsp[-1]->get_name()+" "+yyvsp[0]->get_name(),"param_list", symbol_type::VARIABLE);
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table
			fn_name.top()->add_parameter(addSymbol(yyvsp[0]->get_name(), yyvsp[-1]->get_name(), symbol_type::VARIABLE));
			sym_table->insert(addSymbol(yyvsp[0]->get_name(), yyvsp[-1]->get_name(), symbol_type::VARIABLE));
		}
#line 1501 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier  */
#line 155 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : parameter_list COMMA type_specifier "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<","<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+","+yyvsp[0]->get_name(),"param_list", symbol_type::VARIABLE);
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table
			fn_name.top()->add_parameter(addSymbol("", yyvsp[0]->get_name(), symbol_type::VARIABLE));
		}
#line 1516 "y.tab.c"
    break;

  case 13: /* parameter_list: type_specifier ID  */
#line 166 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : type_specifier ID "<<endl<<endl;
			outlog<<yyvsp[-1]->get_name()<<" "<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+" "+yyvsp[0]->get_name(),"param_list", symbol_type::VARIABLE);
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table
			fn_name.top()->add_parameter(addSymbol(yyvsp[0]->get_name(), yyvsp[-1]->get_name(), symbol_type::VARIABLE));
			sym_table->insert(addSymbol(yyvsp[0]->get_name(), yyvsp[-1]->get_name(), symbol_type::VARIABLE));
		}
#line 1532 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier  */
#line 178 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" parameter_list : type_specifier "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"param_list", symbol_type::VARIABLE);
			
            // store the necessary information about the function parameters
            // They will be needed when you want to enter the function into the symbol table
			fn_name.top()->add_parameter(addSymbol("", yyvsp[0]->get_name(), symbol_type::VARIABLE));
		}
#line 1547 "y.tab.c"
    break;

  case 15: /* compound_statement: LCURL statements RCURL  */
#line 191 "syntax_analyzer.y"
                        { 
 		    	outlog<<"At line no: "<<lines<<" compound_statement : LCURL statements RCURL "<<endl<<endl;
				outlog<<"{\n"+yyvsp[-1]->get_name()+"\n}"<<endl<<endl;
				
				yyval = new symbol_info("{\n"+yyvsp[-1]->get_name()+"\n}","comp_stmnt", symbol_type::VARIABLE);
				
                // The compound statement is complete.
                // Print the symbol table here and exit the scope
                // Note that function parameters should be in the current scope
 		    }
#line 1562 "y.tab.c"
    break;

  case 16: /* compound_statement: LCURL RCURL  */
#line 202 "syntax_analyzer.y"
                    { 
 		    	outlog<<"At line no: "<<lines<<" compound_statement : LCURL RCURL "<<endl<<endl;
				outlog<<"{\n}"<<endl<<endl;
				
				yyval = new symbol_info("{\n}","comp_stmnt", symbol_type::VARIABLE);
				
				// The compound statement is complete.
                // Print the symbol table here and exit the scope
 		    }
#line 1576 "y.tab.c"
    break;

  case 17: /* var_declaration: type_specifier declaration_list SEMICOLON  */
#line 214 "syntax_analyzer.y"
                 {
			outlog<<"At line no: "<<lines<<" var_declaration : type_specifier declaration_list SEMICOLON "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<" "<<yyvsp[-1]->get_name()<<";"<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+" "+yyvsp[-1]->get_name()+";","var_dec", symbol_type::VARIABLE);
			
			// Insert necessary information about the variables in the symbol table
		 }
#line 1589 "y.tab.c"
    break;

  case 18: /* type_specifier: INT  */
#line 225 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" type_specifier : INT "<<endl<<endl;
			outlog<<"int"<<endl<<endl;
			
			yyval = new symbol_info("int","type", symbol_type::VARIABLE);
			current_var_type = "int";
	    }
#line 1601 "y.tab.c"
    break;

  case 19: /* type_specifier: FLOAT  */
#line 233 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" type_specifier : FLOAT "<<endl<<endl;
			outlog<<"float"<<endl<<endl;
			
			yyval = new symbol_info("float","type", symbol_type::VARIABLE);
			current_var_type = "float";
	    }
#line 1613 "y.tab.c"
    break;

  case 20: /* type_specifier: VOID  */
#line 241 "syntax_analyzer.y"
                {
			outlog<<"At line no: "<<lines<<" type_specifier : VOID "<<endl<<endl;
			outlog<<"void"<<endl<<endl;
			
			yyval = new symbol_info("void","type", symbol_type::VARIABLE);
			current_var_type = "void";
	    }
#line 1625 "y.tab.c"
    break;

  case 21: /* declaration_list: declaration_list COMMA ID  */
#line 251 "syntax_analyzer.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID "<<endl<<endl;
 		  	outlog<<yyvsp[-2]->get_name()+","<<yyvsp[0]->get_name()<<endl<<endl;

			yyval = new symbol_info(yyvsp[-2]->get_name()+","+yyvsp[0]->get_name(),"decl_list", symbol_type::VARIABLE);

            // you may need to store the variable names to insert them in symbol table here or later
			sym_table->insert(addSymbol(yyvsp[0]->get_name(),current_var_type,symbol_type::VARIABLE));
			
 		  }
#line 1640 "y.tab.c"
    break;

  case 22: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 262 "syntax_analyzer.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
 		  	outlog<<yyvsp[-5]->get_name()+","<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;

            // you may need to store the variable names to insert them in symbol table here or later
			sym_table->insert(addSymbol(yyvsp[-3]->get_name(),current_var_type,symbol_type::ARRAY,stoi(yyvsp[-1]->get_name())));
			yyval = new symbol_info(yyvsp[-5]->get_name()+","+yyvsp[-3]->get_name()+"["+ yyvsp[-1]->get_name()+"]","decl_list", symbol_type::VARIABLE);
 		  }
#line 1653 "y.tab.c"
    break;

  case 23: /* declaration_list: ID  */
#line 271 "syntax_analyzer.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;

            // you may need to store the variable names to insert them in symbol table here or later
			sym_table->insert(addSymbol(yyvsp[0]->get_name(),current_var_type,symbol_type::VARIABLE));
			yyval = new symbol_info(yyvsp[0]->get_name(),"decl_list", symbol_type::VARIABLE);
 		  }
#line 1666 "y.tab.c"
    break;

  case 24: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 280 "syntax_analyzer.y"
                  {
 		  	outlog<<"At line no: "<<lines<<" declaration_list : ID LTHIRD CONST_INT RTHIRD "<<endl<<endl;
			outlog<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;

            // you may need to store the variable names to insert them in symbol table here or later
            sym_table->insert(addSymbol(yyvsp[-3]->get_name(),current_var_type,symbol_type::ARRAY,stoi(yyvsp[-1]->get_name())));
			yyval = new symbol_info(yyvsp[-3]->get_name()+"["+yyvsp[-1]->get_name()+"]","decl_list", symbol_type::VARIABLE);
 		  }
#line 1679 "y.tab.c"
    break;

  case 25: /* statements: statement  */
#line 292 "syntax_analyzer.y"
           {
	    	outlog<<"At line no: "<<lines<<" statements : statement "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnts", symbol_type::VARIABLE);
	   }
#line 1690 "y.tab.c"
    break;

  case 26: /* statements: statements statement  */
#line 299 "syntax_analyzer.y"
           {
	    	outlog<<"At line no: "<<lines<<" statements : statements statement "<<endl<<endl;
			outlog<<yyvsp[-1]->get_name()<<"\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+"\n"+yyvsp[0]->get_name(),"stmnts", symbol_type::VARIABLE);
	   }
#line 1701 "y.tab.c"
    break;

  case 27: /* statement: var_declaration  */
#line 308 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : var_declaration "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1712 "y.tab.c"
    break;

  case 28: /* statement: func_definition  */
#line 315 "syntax_analyzer.y"
          {
	  		outlog<<"At line no: "<<lines<<" statement : func_definition "<<endl<<endl;
            outlog<<yyvsp[0]->get_name()<<endl<<endl;

            yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  		
	  }
#line 1724 "y.tab.c"
    break;

  case 29: /* statement: expression_statement  */
#line 323 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : expression_statement "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1735 "y.tab.c"
    break;

  case 30: /* statement: compound_statement  */
#line 330 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : compound_statement "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1746 "y.tab.c"
    break;

  case 31: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 337 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement "<<endl<<endl;
			outlog<<"for("<<yyvsp[-4]->get_name()<<yyvsp[-3]->get_name()<<yyvsp[-2]->get_name()<<")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("for("+yyvsp[-4]->get_name()+yyvsp[-3]->get_name()+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1757 "y.tab.c"
    break;

  case 32: /* statement: IF LPAREN expression RPAREN statement  */
#line 344 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : IF LPAREN expression RPAREN statement "<<endl<<endl;
			outlog<<"if("<<yyvsp[-2]->get_name()<<")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("if("+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1768 "y.tab.c"
    break;

  case 33: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 351 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : IF LPAREN expression RPAREN statement ELSE statement "<<endl<<endl;
			outlog<<"if("<<yyvsp[-4]->get_name()<<")\n"<<yyvsp[-2]->get_name()<<"\nelse\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("if("+yyvsp[-4]->get_name()+")\n"+yyvsp[-2]->get_name()+"\nelse\n"+yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1779 "y.tab.c"
    break;

  case 34: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 358 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : WHILE LPAREN expression RPAREN statement "<<endl<<endl;
			outlog<<"while("<<yyvsp[-2]->get_name()<<")\n"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("while("+yyvsp[-2]->get_name()+")\n"+yyvsp[0]->get_name(),"stmnt", symbol_type::VARIABLE);
	  }
#line 1790 "y.tab.c"
    break;

  case 35: /* statement: PRINTLN LPAREN ID RPAREN SEMICOLON  */
#line 365 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : PRINTLN LPAREN ID RPAREN SEMICOLON "<<endl<<endl;
			outlog<<"printf("<<yyvsp[-2]->get_name()<<");"<<endl<<endl; 
			
			yyval = new symbol_info("printf("+yyvsp[-2]->get_name()+");","stmnt", symbol_type::VARIABLE);
	  }
#line 1801 "y.tab.c"
    break;

  case 36: /* statement: RETURN expression SEMICOLON  */
#line 372 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" statement : RETURN expression SEMICOLON "<<endl<<endl;
			outlog<<"return "<<yyvsp[-1]->get_name()<<";"<<endl<<endl;
			
			yyval = new symbol_info("return "+yyvsp[-1]->get_name()+";","stmnt", symbol_type::VARIABLE);
	  }
#line 1812 "y.tab.c"
    break;

  case 37: /* expression_statement: SEMICOLON  */
#line 381 "syntax_analyzer.y"
                        {
				outlog<<"At line no: "<<lines<<" expression_statement : SEMICOLON "<<endl<<endl;
				outlog<<";"<<endl<<endl;
				
				yyval = new symbol_info(";","expr_stmt", symbol_type::VARIABLE);
	        }
#line 1823 "y.tab.c"
    break;

  case 38: /* expression_statement: expression SEMICOLON  */
#line 388 "syntax_analyzer.y"
                        {
				outlog<<"At line no: "<<lines<<" expression_statement : expression SEMICOLON "<<endl<<endl;
				outlog<<yyvsp[-1]->get_name()<<";"<<endl<<endl;
				
				yyval = new symbol_info(yyvsp[-1]->get_name()+";","expr_stmt", symbol_type::VARIABLE);
	        }
#line 1834 "y.tab.c"
    break;

  case 39: /* variable: ID  */
#line 397 "syntax_analyzer.y"
      {
	    outlog<<"At line no: "<<lines<<" variable : ID "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"varbl", symbol_type::VARIABLE);
		
	 }
#line 1846 "y.tab.c"
    break;

  case 40: /* variable: ID LTHIRD expression RTHIRD  */
#line 405 "syntax_analyzer.y"
         {
	 	outlog<<"At line no: "<<lines<<" variable : ID LTHIRD expression RTHIRD "<<endl<<endl;
		outlog<<yyvsp[-3]->get_name()<<"["<<yyvsp[-1]->get_name()<<"]"<<endl<<endl;
		
		yyval = new symbol_info(yyvsp[-3]->get_name()+"["+yyvsp[-1]->get_name()+"]","varbl", symbol_type::VARIABLE);
	 }
#line 1857 "y.tab.c"
    break;

  case 41: /* expression: logic_expression  */
#line 414 "syntax_analyzer.y"
           {
	    	outlog<<"At line no: "<<lines<<" expression : logic_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"expr", symbol_type::VARIABLE);
	   }
#line 1868 "y.tab.c"
    break;

  case 42: /* expression: variable ASSIGNOP logic_expression  */
#line 421 "syntax_analyzer.y"
           {
	    	outlog<<"At line no: "<<lines<<" expression : variable ASSIGNOP logic_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<"="<<yyvsp[0]->get_name()<<endl<<endl;

			yyval = new symbol_info(yyvsp[-2]->get_name()+"="+yyvsp[0]->get_name(),"expr", symbol_type::VARIABLE);
	   }
#line 1879 "y.tab.c"
    break;

  case 43: /* logic_expression: rel_expression  */
#line 430 "syntax_analyzer.y"
             {
	    	outlog<<"At line no: "<<lines<<" logic_expression : rel_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"lgc_expr", symbol_type::VARIABLE);
	     }
#line 1890 "y.tab.c"
    break;

  case 44: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 437 "syntax_analyzer.y"
                 {
	    	outlog<<"At line no: "<<lines<<" logic_expression : rel_expression LOGICOP rel_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"lgc_expr", symbol_type::VARIABLE);
	     }
#line 1901 "y.tab.c"
    break;

  case 45: /* rel_expression: simple_expression  */
#line 446 "syntax_analyzer.y"
                {
	    	outlog<<"At line no: "<<lines<<" rel_expression : simple_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"rel_expr", symbol_type::VARIABLE);
	    }
#line 1912 "y.tab.c"
    break;

  case 46: /* rel_expression: simple_expression RELOP simple_expression  */
#line 453 "syntax_analyzer.y"
                {
	    	outlog<<"At line no: "<<lines<<" rel_expression : simple_expression RELOP simple_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"rel_expr", symbol_type::VARIABLE);
	    }
#line 1923 "y.tab.c"
    break;

  case 47: /* simple_expression: term  */
#line 462 "syntax_analyzer.y"
          {
	    	outlog<<"At line no: "<<lines<<" simple_expression : term "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"simp_expr", symbol_type::VARIABLE);
			
	      }
#line 1935 "y.tab.c"
    break;

  case 48: /* simple_expression: simple_expression ADDOP term  */
#line 470 "syntax_analyzer.y"
                  {
	    	outlog<<"At line no: "<<lines<<" simple_expression : simple_expression ADDOP term "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"simp_expr", symbol_type::VARIABLE);
	      }
#line 1946 "y.tab.c"
    break;

  case 49: /* term: unary_expression  */
#line 479 "syntax_analyzer.y"
     {
	    	outlog<<"At line no: "<<lines<<" term : unary_expression "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"term", symbol_type::VARIABLE);
			
	 }
#line 1958 "y.tab.c"
    break;

  case 50: /* term: term MULOP unary_expression  */
#line 487 "syntax_analyzer.y"
     {
	    	outlog<<"At line no: "<<lines<<" term : term MULOP unary_expression "<<endl<<endl;
			outlog<<yyvsp[-2]->get_name()<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-2]->get_name()+yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"term", symbol_type::VARIABLE);
			
	 }
#line 1970 "y.tab.c"
    break;

  case 51: /* unary_expression: ADDOP unary_expression  */
#line 497 "syntax_analyzer.y"
                 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : ADDOP unary_expression "<<endl<<endl;
			outlog<<yyvsp[-1]->get_name()<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[-1]->get_name()+yyvsp[0]->get_name(),"un_expr", symbol_type::VARIABLE);
	     }
#line 1981 "y.tab.c"
    break;

  case 52: /* unary_expression: NOT unary_expression  */
#line 504 "syntax_analyzer.y"
                 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : NOT unary_expression "<<endl<<endl;
			outlog<<"!"<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info("!"+yyvsp[0]->get_name(),"un_expr", symbol_type::VARIABLE);
	     }
#line 1992 "y.tab.c"
    break;

  case 53: /* unary_expression: factor  */
#line 511 "syntax_analyzer.y"
                 {
	    	outlog<<"At line no: "<<lines<<" unary_expression : factor "<<endl<<endl;
			outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
			yyval = new symbol_info(yyvsp[0]->get_name(),"un_expr", symbol_type::VARIABLE);
	     }
#line 2003 "y.tab.c"
    break;

  case 54: /* factor: variable  */
#line 520 "syntax_analyzer.y"
    {
	    outlog<<"At line no: "<<lines<<" factor : variable "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"fctr", symbol_type::VARIABLE);
	}
#line 2014 "y.tab.c"
    break;

  case 55: /* factor: ID LPAREN argument_list RPAREN  */
#line 527 "syntax_analyzer.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : ID LPAREN argument_list RPAREN "<<endl<<endl;
		outlog<<yyvsp[-3]->get_name()<<"("<<yyvsp[-1]->get_name()<<")"<<endl<<endl;

		yyval = new symbol_info(yyvsp[-3]->get_name()+"("+yyvsp[-1]->get_name()+")","fctr", symbol_type::VARIABLE);
	}
#line 2025 "y.tab.c"
    break;

  case 56: /* factor: LPAREN expression RPAREN  */
#line 534 "syntax_analyzer.y"
        {
	   	outlog<<"At line no: "<<lines<<" factor : LPAREN expression RPAREN "<<endl<<endl;
		outlog<<"("<<yyvsp[-1]->get_name()<<")"<<endl<<endl;
		
		yyval = new symbol_info("("+yyvsp[-1]->get_name()+")","fctr", symbol_type::VARIABLE);
	}
#line 2036 "y.tab.c"
    break;

  case 57: /* factor: CONST_INT  */
#line 541 "syntax_analyzer.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : CONST_INT "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"fctr", symbol_type::VARIABLE);
	}
#line 2047 "y.tab.c"
    break;

  case 58: /* factor: CONST_FLOAT  */
#line 548 "syntax_analyzer.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : CONST_FLOAT "<<endl<<endl;
		outlog<<yyvsp[0]->get_name()<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[0]->get_name(),"fctr", symbol_type::VARIABLE);
	}
#line 2058 "y.tab.c"
    break;

  case 59: /* factor: variable INCOP  */
#line 555 "syntax_analyzer.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : variable INCOP "<<endl<<endl;
		outlog<<yyvsp[-1]->get_name()<<"++"<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[-1]->get_name()+"++","fctr", symbol_type::VARIABLE);
	}
#line 2069 "y.tab.c"
    break;

  case 60: /* factor: variable DECOP  */
#line 562 "syntax_analyzer.y"
        {
	    outlog<<"At line no: "<<lines<<" factor : variable DECOP "<<endl<<endl;
		outlog<<yyvsp[-1]->get_name()<<"--"<<endl<<endl;
			
		yyval = new symbol_info(yyvsp[-1]->get_name()+"--","fctr", symbol_type::VARIABLE);
	}
#line 2080 "y.tab.c"
    break;

  case 61: /* argument_list: arguments  */
#line 571 "syntax_analyzer.y"
                          {
					outlog<<"At line no: "<<lines<<" argument_list : arguments "<<endl<<endl;
					outlog<<yyvsp[0]->get_name()<<endl<<endl;
						
					yyval = new symbol_info(yyvsp[0]->get_name(),"arg_list", symbol_type::VARIABLE);
			  }
#line 2091 "y.tab.c"
    break;

  case 62: /* argument_list: %empty  */
#line 578 "syntax_analyzer.y"
                          {
					outlog<<"At line no: "<<lines<<" argument_list :  "<<endl<<endl;
					outlog<<""<<endl<<endl;
						
					yyval = new symbol_info("","arg_list", symbol_type::VARIABLE);
			  }
#line 2102 "y.tab.c"
    break;

  case 63: /* arguments: arguments COMMA logic_expression  */
#line 587 "syntax_analyzer.y"
                  {
				outlog<<"At line no: "<<lines<<" arguments : arguments COMMA logic_expression "<<endl<<endl;
				outlog<<yyvsp[-2]->get_name()<<","<<yyvsp[0]->get_name()<<endl<<endl;
						
				yyval = new symbol_info(yyvsp[-2]->get_name()+","+yyvsp[0]->get_name(),"arg", symbol_type::VARIABLE);
		  }
#line 2113 "y.tab.c"
    break;

  case 64: /* arguments: logic_expression  */
#line 594 "syntax_analyzer.y"
              {
				outlog<<"At line no: "<<lines<<" arguments : logic_expression "<<endl<<endl;
				outlog<<yyvsp[0]->get_name()<<endl<<endl;
						
				yyval = new symbol_info(yyvsp[0]->get_name(),"arg", symbol_type::VARIABLE);
		  }
#line 2124 "y.tab.c"
    break;


#line 2128 "y.tab.c"

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

#line 603 "syntax_analyzer.y"


int main(int argc, char *argv[])
{
	if(argc != 2) 
	{
		cout<<"Please input file name"<<endl;
		return 0;
	}
	yyin = fopen(argv[1], "r");
	outlog.open("my_log.txt", ios::trunc);
	
	if(yyin == NULL)
	{
		cout<<"Couldn't open file"<<endl;
		return 0;
	}
	// Enter the global or the first scope here
	sym_table = new symbol_table(10);

	yyparse();
	
	outlog<<endl<<"Total lines: "<<lines<<endl;
	
	outlog.close();
	
	fclose(yyin);
	
	return 0;
}
