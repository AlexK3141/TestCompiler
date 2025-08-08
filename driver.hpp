#ifndef __DRIVER_HPP__
#define __DRIVER_HPP__ 1

#include <string>
#include <cstddef>
#include <istream>

#include "scanner.hpp"
#include "parser.tab.hpp"

using namespace SimpleCompiler;

class Driver{
public:
   Driver() = default;

   virtual ~Driver();
   
   static const int ACCEPT = 0;

   int parse( const char * const filename );
   int parse( std::istream &iss );
   void clean();

   std::ostream& print(std::ostream &stream);
   void print_ast(Node* node, int indent = 0);

private:
   int parse_helper( std::istream &stream );

   Parser  *parser  = nullptr;
   Scanner *scanner = nullptr;
};

#endif /* END __DRIVER_HPP__ */
