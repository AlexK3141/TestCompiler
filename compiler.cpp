#include <iostream>
#include <cstdlib>
#include <cstring>

#include "driver.hpp"

int 
main( const int argc, const char **argv )
{
   /** check for the right # of arguments **/
   if( argc != 2 )
   {
      /** exit with failure condition **/
      return ( EXIT_FAILURE );
   }

   if( std::strncmp( argv[ 1 ], "-h", 2 ) == 0 )
   {
      /** simple help menu **/
      std::cout << "use -o for pipe to std::cin\n";
      std::cout << "just give a filename to count from a file\n";
      std::cout << "use -h to get this menu\n";
      return( EXIT_SUCCESS );
   }

   Driver driver;
   int parse_result = -1;
   if( std::strncmp( argv[ 1 ], "-o", 2 ) == 0 )
   {
       parse_result = driver.parse( std::cin );
   }
   else
   {
       parse_result = driver.parse( argv[1] );
   }

   if (parse_result == Driver::ACCEPT)
   {
       driver.print(std::cout) << "\n";
   }
   else
   {
       std::cerr << "Parse failed!!\n";
   }

   // Always delete ast_root to prevent leaks on partial parse
   driver.clean();

   return( EXIT_SUCCESS );
}
