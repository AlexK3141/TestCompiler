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
#include <memory>
#include "ast.hpp"
#include "ast_nodes.hpp"

class Scanner;

using namespace SimpleCompiler;

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
%param { Node* & ast_root }

%code {
    #include "scanner.hpp"
    static auto yylex(Parser::value_type* yylval, Parser::location_type* yylloc, Scanner& lexer, Node* & ast_root) -> int
    {
        return lexer.yylex(yylval, yylloc);
    }
}

// Token declarations
%token INT FLOAT CHAR VOID IF ELSE FOR WHILE RETURN
%token EQ NE LE GE AND OR
%token <std::string> IDENTIFIER NUMBER CHAR_LITERAL
// %token '(' ')' '{' '}' ',' '+' '-' '*' '/' '<' '>' '!'
%token '(' ')' '{' '}' ';' ',' '=' '+' '-' '*' '/' '<' '>' '!'

// Non-terminal types
%type <Node*> program statement_list statement function_def param_list param
%type <Node*> declaration declaration_no_semi assignment if_stmt for_stmt
%type <Node*> for_init while_stmt return_stmt expression logical_or_expr
%type <Node*> logical_and_expr equality_expr relational_expr
%type <Node*> term factor function_call arg_list type
%type <Node*> assignment_expr arithmetic_expr

// %type <Node*> assignment_or_expr expression_opt

/* Define operator precedence and associativity to resolve ambiguity */
//%nonassoc ASSIGN
%right '='
%right UMINUS
%left OR
%left AND
%left EQ NE
%left '<' '>' LE GE
%left '+' '-'
%left '*' '/'
%right '!'
//%nonassoc SEMI

%locations

%%

program:
    statement_list {
        ast_root = new ProgramNode(@1.begin.line); 
        ast_root->children.push_back(($1)); 
    }
    ;

statement_list:
    statement { 
        auto node = new StatementListNode(@1.begin.line); 
        node->children.push_back(($1)); 
        $$ = (node); 
    }
    | statement_list statement { 
        $$ = ($1); 
        $$->children.push_back(($2)); 
    }
    ;

statement:
    function_def { $$ = ($1); }
    | declaration { $$ = ($1); }
    | assignment { $$ = ($1); }
    | if_stmt { $$ = ($1); }
    | for_stmt { $$ = ($1); }
    | while_stmt { $$ = ($1); }
    | return_stmt { $$ = ($1); }
    | expression ';' { 
        auto node = new ExpressionStmtNode(@1.begin.line); 
        node->children.push_back(($1)); 
        $$ = (node); 
    }
    ;

function_def:
    type IDENTIFIER '(' param_list ')' '{' statement_list '}' {
        auto node = new FunctionDefNode(
            static_cast<TypeNode*>($1)->type_value, $2, @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(new IdentifierNode(
            $2, Type{BaseType::Void}, @1.begin.line)); // Type TBD for identifier
        node->children.push_back(($4));
        node->children.push_back(($7));
        $$ = (node);
    }
    ;

param_list:
    /* empty */ { $$ = new StatementListNode(@$.begin.line); } // Reuse StatementListNode for param_list
    | param { 
        auto node = new StatementListNode(@1.begin.line); 
        node->children.push_back(($1)); 
        $$ = (node); 
    }
    | param_list ',' param { 
        $$ = ($1); 
        $$->children.push_back(($3)); 
    }
    ;

param:
    type IDENTIFIER { 
        auto node = new ParamNode(
            static_cast<TypeNode*>($1)->type_value, $2, @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(new IdentifierNode(
            $2, static_cast<TypeNode*>($1)->type_value, @1.begin.line));
        $$ = (node);
    }
    ;

declaration:
    declaration_no_semi ';' { $$ = ($1); }
    ;

declaration_no_semi:
    type IDENTIFIER { 
        auto node = new DeclarationNode(
            static_cast<TypeNode*>($1)->type_value, $2, @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(new IdentifierNode(
            $2, static_cast<TypeNode*>($1)->type_value, @1.begin.line));
        $$ = (node);
    }
    | type IDENTIFIER '=' expression { 
        auto node = new DeclarationNode(
            static_cast<TypeNode*>($1)->type_value, $2, @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(new IdentifierNode(
            $2, static_cast<TypeNode*>($1)->type_value, @1.begin.line));
        node->children.push_back(($4));
        $$ = (node);
    }
    ;

assignment:
    assignment_expr ';' { $$ = $1; }

if_stmt:
    IF '(' expression ')' '{' statement_list '}' { 
        auto node = new IfStmtNode(@1.begin.line);
        node->children.push_back(($3));
        node->children.push_back(($6));
        $$ = (node);
    }
    | IF '(' expression ')' '{' statement_list '}' ELSE '{' statement_list '}' { 
        auto node = new IfStmtNode(@1.begin.line);
        node->children.push_back(($3));
        node->children.push_back(($6));
        node->children.push_back(($10));
        $$ = (node);
    }
    ;

for_stmt:
    FOR '(' for_init ';' expression ';' expression ')' '{' statement_list '}' {
        auto node = new ForStmtNode(@1.begin.line);
        node->children.push_back(($3));
        node->children.push_back($5 ? ($5) : new Node("empty", "", @1.begin.line));
        node->children.push_back($7 ? ($7) : new Node("empty", "", @1.begin.line));
        node->children.push_back(($10));
        $$ = (node);
    }
    | FOR '(' for_init ';' ';' expression ')' '{' statement_list '}' {
        auto node = new ForStmtNode(@1.begin.line);
        $$->children.push_back($3); 
        $$->children.push_back(new Node("empty", "", @1.begin.line));
        $$->children.push_back($6); 
        $$->children.push_back($9);
    }
    | FOR '(' for_init ';' expression ';' ')' '{' statement_list '}' {
        auto node = new ForStmtNode(@1.begin.line);
        $$->children.push_back($3); 
        $$->children.push_back($5); 
        $$->children.push_back(new Node("empty", "", @1.begin.line)); 
        $$->children.push_back($9);
    }
    | FOR '(' for_init ';' ';' ')' '{' statement_list '}' {
        auto node = new ForStmtNode(@1.begin.line);
        $$->children.push_back($3); 
        $$->children.push_back(new Node("empty", "", @1.begin.line)); 
        $$->children.push_back(new Node("empty", "", @1.begin.line)); 
        $$->children.push_back($8);
    }
    ;


for_init:
    /* empty */ { $$ = new Node("empty", "", @$.begin.line); }
    | declaration_no_semi { $$ = ($1); }
    | expression { $$ = ($1); }
    ;

while_stmt:
    WHILE '(' expression ')' '{' statement_list '}' { 
        auto node = new WhileStmtNode(@1.begin.line);
        node->children.push_back(($3));
        node->children.push_back(($6));
        $$ = (node);
    }
    ;

return_stmt:
    RETURN ';' { $$ = new ReturnStmtNode(@1.begin.line); }
    | RETURN expression ';' { 
        auto node = new ReturnStmtNode(@1.begin.line);
        node->children.push_back(($2));
        $$ = (node);
    }
    ;

expression:
    assignment_expr { $$ = $1; }
    | logical_or_expr { $$ = ($1); }
    ;

assignment_expr:
    IDENTIFIER '=' expression { 
        $$ = new AssignmentNode("assignment", @1.begin.line);
        $$->children.push_back(new IdentifierNode($1, Type{BaseType::Void}, @1.begin.line));
        $$->children.push_back($3); 
    }

logical_or_expr:
    logical_and_expr { $$ = ($1); }
    | logical_or_expr OR logical_and_expr { 
        auto node = new BinaryOpNode("||", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

logical_and_expr:
    equality_expr { $$ = ($1); }
    | logical_and_expr AND equality_expr { 
        auto node = new BinaryOpNode("&&", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

equality_expr:
    relational_expr { $$ = ($1); }
    | equality_expr EQ relational_expr { 
        auto node = new BinaryOpNode("==", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    | equality_expr NE relational_expr { 
        auto node = new BinaryOpNode("!=", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

relational_expr:
    arithmetic_expr { $$ = ($1); }
    | relational_expr '<' arithmetic_expr { 
        auto node = new BinaryOpNode("<", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    | relational_expr '>' arithmetic_expr { 
        auto node = new BinaryOpNode(">", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    | relational_expr LE arithmetic_expr { 
        auto node = new BinaryOpNode("<=", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    | relational_expr GE arithmetic_expr { 
        auto node = new BinaryOpNode(">=", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

arithmetic_expr:
    term { $$ = ($1); }
    | arithmetic_expr '+' term { 
        auto node = new BinaryOpNode("+", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    | arithmetic_expr '-' term { 
        auto node = new BinaryOpNode("-", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

term:
    factor { $$ = ($1); }
    | term '*' factor { 
        auto node = new BinaryOpNode("*", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    | term '/' factor { 
        auto node = new BinaryOpNode("/", @1.begin.line);
        node->children.push_back(($1));
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

factor:
    IDENTIFIER { 
        $$ = new IdentifierNode($1, Type{BaseType::Void}, @1.begin.line); // Type TBD
    }
    | NUMBER { 
        Type num_type = $1.find('.') != std::string::npos ? Type{BaseType::Float} : Type{BaseType::Int};
        $$ = new NumberNode($1, num_type, @1.begin.line);
    }
    | CHAR_LITERAL { $$ = new CharLiteralNode($1, @1.begin.line); }
    | '(' expression ')' { $$ = ($2); }
    | function_call { $$ = ($1); }
    | '-' factor { 
        auto node = new UnaryOpNode("-", @1.begin.line);
        node->children.push_back(($2));
        $$ = (node);
    }
    | '!' factor { 
        auto node = new UnaryOpNode("!", @1.begin.line);
        node->children.push_back(($2));
        $$ = (node);
    }
    ;

function_call:
    IDENTIFIER '(' arg_list ')' { 
        auto node = new FunctionCallNode($1, @1.begin.line);
        node->children.push_back(new IdentifierNode(
            $1, Type{BaseType::Void}, @1.begin.line)); // Type TBD
        node->children.push_back(($3));
        $$ = (node);
    }
    ;

arg_list:
    /* empty */ { $$ = new StatementListNode(@$.begin.line); } // Reuse StatementListNode
    | expression { 
        auto node = new StatementListNode(@1.begin.line);
        node->children.push_back(($1));
        $$ = (node);
    }
    | arg_list ',' expression { 
        $$ = ($1);
        $$->children.push_back(($3));
    }
    ;

type:
    INT { $$ = new TypeNode(Type{BaseType::Int}, @1.begin.line); }
    | FLOAT { $$ = new TypeNode(Type{BaseType::Float}, @1.begin.line); }
    | CHAR { $$ = new TypeNode(Type{BaseType::Char}, @1.begin.line); }
    | VOID { $$ = new TypeNode(Type{BaseType::Void}, @1.begin.line); }
    ;

%%

namespace SimpleCompiler {
void Parser::error(const Parser::location_type& l, const std::string& msg)
{
    std::cerr << "Syntax error at line " << l.begin.line << ": " << msg << std::endl;
}
}