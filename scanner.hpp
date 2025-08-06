#ifndef __SCANNER_HPP__
#define __SCANNER_HPP__ 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "parser.tab.hpp"
//#include "location.hh"

using namespace SimpleCompiler;

class Scanner : public yyFlexLexer
{
public:
    Scanner(std::istream *in) : yyFlexLexer(in)
    {
    };
    virtual ~Scanner() {
    };

    //get rid of override virtual function warning
    using FlexLexer::yylex;

    virtual int yylex(Parser::semantic_type * const lval, Parser::location_type *location );
    //virtual int yylex() override;

private:
    /* yyval ptr */
    Parser::semantic_type *yylval = nullptr;
};


#endif /* END __SCANNER_HPP__ */
