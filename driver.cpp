#include <cctype>
#include <fstream>
#include <cassert>

#include "driver.hpp"

Node* ast_root = nullptr;

Driver::~Driver()
{
   clean();
   delete(scanner);
   scanner = nullptr;
   delete(parser);
   parser = nullptr;
}

int Driver::parse( const char * const filename )
{
    int parse_result = -1;
   assert( filename != nullptr );
   std::ifstream in_file( filename );
   if( ! in_file.good() )
   {
       exit( EXIT_FAILURE );
   }
   parse_result = parse_helper( in_file );
   return parse_result;
}

int Driver::parse( std::istream &stream )
{
    int parse_result = -1;
   if( ! stream.good()  && stream.eof() )
   {
       return parse_result;
   }
   //else
   parse_result = parse_helper( stream );
   return parse_result;
}

int Driver::parse_helper( std::istream &stream )
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

   int parse_result = parser->parse();
   return parse_result;
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
    std::cout << "AST:" << std::endl;
    if (ast_root) {
        ast_root->print(std::cout);
    }
    else {
        std::cout << "Empty AST" << std::endl;
    }

    return(stream);
}

void Driver::clean()
{
    if (ast_root != nullptr)
    {
        delete ast_root;
        ast_root = nullptr;
    }
}

