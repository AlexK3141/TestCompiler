%skeleton "lalr1.cc"
%output "parser.tab.cpp"
%defines "parser.tab.hpp"
%define api.parser.class {Parser}
%require "3.0"
%debug 
%define api.namespace {SimpleCompiler}
%define api.value.type variant
%define parse.assert
%define parse.error verbose

%code requires{
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

#include "ast.hpp"

class Scanner;

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif
}

%param { Scanner &scanner }
%param { Node*& ast_root }

%code {
    #include "scanner.hpp"
    static auto yylex(Parser::value_type* yylval, Parser::location_type* yylloc, Scanner& lexer, Node* ast_root) -> int
    {
        return lexer.yylex(yylval, yylloc);
    }
}

// Token declarations
%token INT FLOAT CHAR VOID IF ELSE FOR WHILE RETURN
%token EQ NE LE GE AND OR
%token <std::string> IDENTIFIER NUMBER CHAR_LITERAL
%token '(' ')' '{' '}' ';' ',' '=' '+' '-' '*' '/' '<' '>' '!'

// Non-terminal types
%type <Node*> program statement_list statement function_def param_list param
%type <Node*> declaration declaration_no_semi assignment if_stmt for_stmt
%type <Node*> for_init while_stmt return_stmt expression logical_or_expr assignment_expr
%type <Node*> logical_and_expr equality_expr relational_expr arithmetic_expr
%type <Node*> term factor function_call arg_list type

/* Define operator precedence and associativity to resolve ambiguity */
%right '='
%right UMINUS /* For unary minus */
%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/'
%right '!'

%locations

%%

program:
    statement_list { ast_root = $$ = new Node("program"); $$->children.push_back($1); }
    ;

statement_list:
    statement { $$ = new Node("statement_list"); $$->children.push_back($1); }
    | statement_list statement { $$ = $1; $$->children.push_back($2); }
    ;

statement:
    function_def { $$ = $1; }
    | declaration { $$ = $1; }
    | assignment { $$ = $1; }
    | if_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    | expression ';' { $$ = new Node("expression_stmt"); $$->children.push_back($1); }
    ;

function_def:
    type IDENTIFIER '(' param_list ')' '{' statement_list '}' {
        $$ = new Node("function_def"); 
        $$->children.push_back($1);
        $$->children.push_back(new Node("identifier", $2));
        $$->children.push_back($4);
        $$->children.push_back($7);
    }
    ;

param_list:
    /* empty */ { $$ = new Node("param_list"); }
    | param { $$ = new Node("param_list"); $$->children.push_back($1); }
    | param_list ',' param { $$ = $1; $$->children.push_back($3); }
    ;

param:
    type IDENTIFIER { 
        $$ = new Node("param"); 
        $$->children.push_back($1); 
        $$->children.push_back(new Node("identifier", $2)); 
    }
    ;

declaration:
    declaration_no_semi ';' { $$ = $1; }
    ;

declaration_no_semi:
    type IDENTIFIER { 
        $$ = new Node("declaration"); 
        $$->children.push_back($1); 
        $$->children.push_back(new Node("identifier", $2)); 
    }
    | type IDENTIFIER '=' expression { 
        $$ = new Node("declaration"); 
        $$->children.push_back($1); 
        $$->children.push_back(new Node("identifier", $2)); 
        $$->children.push_back($4); 
    }
    ;

assignment:
    assignment_expr ';' { $$ = $1; }
    ;

if_stmt:
    IF '(' expression ')' '{' statement_list '}' { 
        $$ = new Node("if_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back($6); 
    }
    | IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}' { 
        $$ = new Node("if_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back($6); 
        $$->children.push_back($10); 
    }
    ;

for_stmt:
    FOR '(' for_init ';' expression ';' expression ')' '{' statement_list '}' {
        $$ = new Node("for_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back($5); 
        $$->children.push_back($7); 
        $$->children.push_back($10);
    }
    | FOR '(' for_init ';' ';' expression ')' '{' statement_list '}' {
        $$ = new Node("for_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back(new Node("empty")); 
        $$->children.push_back($6); 
        $$->children.push_back($9);
    }
    | FOR '(' for_init ';' expression ';' ')' '{' statement_list '}' {
        $$ = new Node("for_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back($5); 
        $$->children.push_back(new Node("empty")); 
        $$->children.push_back($9);
    }
    | FOR '(' for_init ';' ';' ')' '{' statement_list '}' {
        $$ = new Node("for_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back(new Node("empty")); 
        $$->children.push_back(new Node("empty")); 
        $$->children.push_back($8);
    }
    ;

for_init:
    /* empty */ { $$ = new Node("empty"); }
    | declaration_no_semi { $$ = $1; }
    | expression { $$ = $1; }
    ;

while_stmt:
    WHILE '(' expression ')' '{' statement_list '}' { 
        $$ = new Node("while_stmt"); 
        $$->children.push_back($3); 
        $$->children.push_back($6); 
    }
    ;

return_stmt:
    RETURN ';' { $$ = new Node("return_stmt"); }
    | RETURN expression ';' { $$ = new Node("return_stmt"); $$->children.push_back($2); }
    ;

expression:
    assignment_expr { $$ = $1; }
    | logical_or_expr { $$ = $1; }
    ;

assignment_expr:
    IDENTIFIER '=' expression { 
        $$ = new Node("assignment"); 
        $$->children.push_back(new Node("identifier", $1)); 
        $$->children.push_back($3); 
    }
    ;

logical_or_expr:
    logical_and_expr { $$ = $1; }
    | logical_or_expr OR logical_and_expr { 
        $$ = new Node("binary_op", "||"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    ;

logical_and_expr:
    equality_expr { $$ = $1; }
    | logical_and_expr AND equality_expr { 
        $$ = new Node("binary_op", "&&"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    ;

equality_expr:
    relational_expr { $$ = $1; }
    | equality_expr EQ relational_expr { 
        $$ = new Node("binary_op", "=="); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    | equality_expr NE relational_expr { 
        $$ = new Node("binary_op", "!="); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    ;

relational_expr:
    arithmetic_expr { $$ = $1; }
    | relational_expr '<' arithmetic_expr { 
        $$ = new Node("binary_op", "<"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    | relational_expr '>' arithmetic_expr { 
        $$ = new Node("binary_op", ">"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    | relational_expr LE arithmetic_expr { 
        $$ = new Node("binary_op", "<="); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    | relational_expr GE arithmetic_expr { 
        $$ = new Node("binary_op", ">="); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    ;

arithmetic_expr:
    term { $$ = $1; }
    | arithmetic_expr '+' term { 
        $$ = new Node("binary_op", "+"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    | arithmetic_expr '-' term { 
        $$ = new Node("binary_op", "-"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    ;

term:
    factor { $$ = $1; }
    | term '*' factor { 
        $$ = new Node("binary_op", "*"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    | term '/' factor { 
        $$ = new Node("binary_op", "/"); 
        $$->children.push_back($1); 
        $$->children.push_back($3); 
    }
    ;

factor:
    IDENTIFIER { $$ = new Node("identifier", $1); }
    | NUMBER { $$ = new Node("number", $1); }
    | CHAR_LITERAL { $$ = new Node("char_literal", $1); }
    | '(' expression ')' { $$ = $2; }
    | function_call { $$ = $1; }
    | '-' factor { $$ = new Node("unary_op", "-"); $$->children.push_back($2); }
    | '!' factor { $$ = new Node("unary_op", "!"); $$->children.push_back($2); }
    ;

function_call:
    IDENTIFIER '(' arg_list ')' { 
        $$ = new Node("function_call"); 
        $$->children.push_back(new Node("identifier", $1)); 
        $$->children.push_back($3); 
    }
    ;

arg_list:
    /* empty */ { $$ = new Node("arg_list"); }
    | expression { $$ = new Node("arg_list"); $$->children.push_back($1); }
    | arg_list ',' expression { $$ = $1; $$->children.push_back($3); }
    ;

type:
    INT { $$ = new Node("type", "int"); }
    | FLOAT { $$ = new Node("type", "float"); }
    | CHAR { $$ = new Node("type", "char"); }
    | VOID { $$ = new Node("type", "void"); }
    ;

%%

namespace SimpleCompiler {
void Parser::error(const Parser::location_type& l, const std::string& msg)
{
    std::cerr << "Syntax error: " << msg << std::endl;
}
}