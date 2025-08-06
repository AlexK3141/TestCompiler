%{
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */ 
#include "scanner.hpp"
#undef  YY_DECL
#define YY_DECL int Scanner::yylex( Parser::semantic_type * const lval, Parser::location_type *loc )

/* typedef to make the returns for the tokens shorter */
using token = Parser::token;

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}


%option noyywrap
%option c++
%option yylineno
%option debug
%option nodefault
%option yyclass="Scanner"

/* Regular expression definitions */
digit       [0-9]
letter      [a-zA-Z_]
identifier  {letter}({letter}|{digit})*
number      {digit}+(\.{digit}+)?
ws          [ \t]+

%%
%{          /** Code executed at the beginning of yylex **/
            yylval = lval;
%}

{ws}        { /* Ignore whitespace */ }
"\n"        { loc->lines(); }

"if"        { return token::token_kind_type::IF; }
"else"      { return token::token_kind_type::ELSE; }
"for"       { return token::token_kind_type::FOR; }
"while"     { return token::token_kind_type::WHILE; }
"return"    { return token::token_kind_type::RETURN; }
"int"       { return token::token_kind_type::INT; }
"float"     { return token::token_kind_type::FLOAT; }
"char"      { return token::token_kind_type::CHAR; }
"void"      { return token::token_kind_type::VOID; }

{identifier} {
    yylval->build< std::string >(yytext);
    return token::token_kind_type::IDENTIFIER;
}

{number} {

    yylval->build< std::string >(yytext);
    return token::token_kind_type::NUMBER;
}

"'"."'" {
    yylval->build< std::string >(yytext);
    return token::token_kind_type::CHAR_LITERAL;
}


"&&"        { return token::token_kind_type::AND; }
"||"        { return token::token_kind_type::OR; }
"=="        { return token::token_kind_type::EQ; }
"!="        { return token::token_kind_type::NE; }
"<="        { return token::token_kind_type::LE; }
">="        { return token::token_kind_type::GE; }

";"         { return ';'; }
","         { return ','; }
"("         { return '('; }
")"         { return ')'; }
"{"         { return '{'; }
"}"         { return '}'; }
"="         { return '='; }
"<"         { return '<'; }
">"         { return '>'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }

.           { 
    // Handle unrecognized characters
    std::cerr << "Lexical Error: Unrecognized character '" << yytext 
              << "' on line " << loc->begin.line << std::endl;
}

%%
// User code section (not used in this simple example)
