/* A Bison parser, made by GNU Bison 3.3.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_PARSE_H_INCLUDED
# define YY_YY_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_LP = 258,
    T_RP = 259,
    T_LB = 260,
    T_RB = 261,
    T_DOT = 262,
    T_COMMA = 263,
    T_COLON = 264,
    T_MUL = 265,
    T_DIV = 266,
    T_UNEQUAL = 267,
    T_NOT = 268,
    T_PLUS = 269,
    T_MINUS = 270,
    T_GE = 271,
    T_GT = 272,
    T_LE = 273,
    T_LT = 274,
    T_EQUAL = 275,
    T_ASSIGN = 276,
    T_MOD = 277,
    T_DOTDOT = 278,
    T_SEMI = 279,
    T_SYS_CON = 280,
    T_SYS_FUNCT = 281,
    T_SYS_PROC = 282,
    T_SYS_TYPE = 283,
    T_READ = 284,
    T_INTEGER = 285,
    T_REAL = 286,
    T_CHAR = 287,
    T_NAME = 288,
    T_AND = 289,
    T_OR = 290,
    T_DOWNTO = 291,
    T_TO = 292,
    T_ARRAY = 293,
    T_BEGIN = 294,
    T_CASE = 295,
    T_CONST = 296,
    T_DO = 297,
    T_ELSE = 298,
    T_END = 299,
    T_FOR = 300,
    T_FUNCTION = 301,
    T_GOTO = 302,
    T_IF = 303,
    T_OF = 304,
    T_PACKED = 305,
    T_PROCEDURE = 306,
    T_PROGRAM = 307,
    T_RECORD = 308,
    T_REPEAT = 309,
    T_THEN = 310,
    T_TYPE = 311,
    T_UNTIL = 312,
    T_VAR = 313,
    T_WHILE = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 10 "parse.y" /* yacc.c:1921  */

    int token;
    AST_pNode_t node;

#line 123 "parse.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSE_H_INCLUDED  */
