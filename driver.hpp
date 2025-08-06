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
   
   /** 
    * parse - parse from a file
    * @param filename - valid string with input file
    */
   void parse( const char * const filename );
   /** 
    * parse - parse from a c++ input stream
    * @param is - std::istream&, valid input stream
    */
   void parse( std::istream &iss );

   std::ostream& print(std::ostream &stream);

   void print_ast(Node* node, int indent = 0);
private:

   void parse_helper( std::istream &stream );

   std::size_t  chars      = 0;
   std::size_t  words      = 0;
   std::size_t  lines      = 0;
   std::size_t  uppercase  = 0;
   std::size_t  lowercase  = 0;
   Parser  *parser  = nullptr;
   Scanner *scanner = nullptr;

   const std::string red   = "\033[1;31m";
   const std::string blue  = "\033[1;36m";
   const std::string norm  = "\033[0m";
};

#endif /* END __DRIVER_HPP__ */
