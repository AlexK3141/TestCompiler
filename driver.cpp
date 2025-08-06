#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"

Node* ast_root = nullptr;

Driver::~Driver()
{
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

void Driver::parse( const char * const filename )
{
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
       exit( EXIT_FAILURE );
   }
   parse_helper( in_file );
   return;
}

void Driver::parse( std::istream &stream )
{
   if( ! stream.good()  && stream.eof() )
   {
       return;
   }
   //else
   parse_helper( stream ); 
   return;
}


void Driver::parse_helper( std::istream &stream )
{
   
   delete(scanner);
   try
   {
      scanner = new Scanner( &stream );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate scanner: (" <<
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }
   
   delete(parser); 
   try
   {
      parser = new Parser( (*scanner), ast_root /*(*this) /* driver */ );
   }
   catch( std::bad_alloc &ba )
   {
      std::cerr << "Failed to allocate parser: (" << 
         ba.what() << "), exiting!!\n";
      exit( EXIT_FAILURE );
   }

   scanner->set_debug(1); // Enable Flex debug output
   parser->set_debug_level(1); // Enable Bison debug output
   const int accept( 0 );
   if( parser->parse() != accept )
   {
      std::cerr << "Parse failed!!\n";
   }
   return;
}

void Driver::print_ast(Node* node, int indent)
{
    if (!node) {
        std::cout << std::string(indent, ' ') << "null" << std::endl;
        return;
    }
    // Print current node: type and value (if non-empty)
    std::string node_info = node->type;
    if (!node->value.empty()) {
        node_info += ": " + node->value;
    }
    std::cout << std::string(indent, ' ') << node_info << std::endl;
    // Recursively print children
    for (Node* child : node->children) {
        print_ast(child, indent + 2);
    }
}

std::ostream& Driver::print( std::ostream &stream )
{
   //stream << red  << "Results: " << norm << "\n";
   //stream << blue << "Uppercase: " << norm << uppercase << "\n";
   //stream << blue << "Lowercase: " << norm << lowercase << "\n";
   //stream << blue << "Lines: " << norm << lines << "\n";
   //stream << blue << "Words: " << norm << words << "\n";
   //stream << blue << "Characters: " << norm << chars << "\n";

    print_ast(ast_root);
    return(stream);
}

